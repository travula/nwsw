/********************************************************************16**

                         (c) COPYRIGHT 2009 by 
                         Continuous Computing Corporation.
                         All rights reserved.

     This software is confidential and proprietary to Continuous Computing 
     Corporation (CCPU).  No part of this software may be reproduced,
     stored, transmitted, disclosed or used in any form or by any means
     other than as expressly provided by the written Software License 
     Agreement between CCPU and its licensee.

     CCPU warrants that for a period, as provided by the written
     Software License Agreement between CCPU and its licensee, this
     software will perform substantially to CCPU specifications as
     published at the time of shipment, exclusive of any updates or 
     upgrades, and the media used for delivery of this software will be 
     free from defects in materials and workmanship.  CCPU also warrants 
     that has the corporate authority to enter into and perform under the   
     Software License Agreement and it is the copyright owner of the software 
     as originally delivered to its licensee.

     CCPU MAKES NO OTHER WARRANTIES, EXPRESS OR IMPLIED, INCLUDING
     WITHOUT LIMITATION WARRANTIES OF MERCHANTABILITY OR FITNESS FOR
     A PARTICULAR PURPOSE WITH REGARD TO THIS SOFTWARE, SERVICE OR ANY RELATED
     MATERIALS.

     IN NO EVENT SHALL CCPU BE LIABLE FOR ANY INDIRECT, SPECIAL,
     CONSEQUENTIAL DAMAGES, OR PUNITIVE DAMAGES IN CONNECTION WITH OR ARISING
     OUT OF THE USE OF, OR INABILITY TO USE, THIS SOFTWARE, WHETHER BASED
     ON BREACH OF CONTRACT, TORT (INCLUDING NEGLIGENCE), PRODUCT
     LIABILITY, OR OTHERWISE, AND WHETHER OR NOT IT HAS BEEN ADVISED
     OF THE POSSIBILITY OF SUCH DAMAGE.

                       Restricted Rights Legend

     This software and all related materials licensed hereby are
     classified as "restricted computer software" as defined in clause
     52.227-19 of the Federal Acquisition Regulation ("FAR") and were
     developed entirely at private expense for nongovernmental purposes,
     are commercial in nature and have been regularly used for
     nongovernmental purposes, and, to the extent not published and
     copyrighted, are trade secrets and confidential and are provided
     with all rights reserved under the copyright laws of the United
     States.  The government's rights to the software and related
     materials are limited and restricted as provided in clause
     52.227-19 of the FAR.

                    IMPORTANT LIMITATION(S) ON USE

     The use of this software is limited to the use set
     forth in the written Software License Agreement between CCPU and
     its Licensee. Among other things, the use of this software
     may be limited to a particular type of Designated Equipment, as 
     defined in such Software License Agreement.
     Before any installation, use or transfer of this software, please
     consult the written Software License Agreement or contact CCPU at
     the location set forth below in order to confirm that you are
     engaging in a permissible use of the software.

                    Continuous Computing Corporation
                    9450, Carroll Park Drive
                    San Diego, CA-92121, USA

                    Tel: +1 (858) 882 8800
                    Fax: +1 (858) 777 3388

                    Email: support@trillium.com
                    Web: http://www.ccpu.com

*********************************************************************17*/


/**********************************************************************

     Name:     LTE-RLC Layer 
  
     Type:     C file
  
     Desc:     Source code for RLC Utility Module
               This file contains following functions

                  --kwUtlSndToLi
                  --kwUtlRcvFrmLi
                  --kwUtlEmptySduQ
                  --kwUtlSndDStaRsp
                  --kwUtlSndDatInd 
                  --kwUtlShutDown
     File:     gp_utl.c

     Sid:      gp_utl.c@@/main/2 - Fri Nov 13 14:14:08 2009

     Prg:      vp 

**********************************************************************/
/** @file gp_utl.c
@brief RLC Utility Module 
*/


#ifndef __GPX__
#define __GPX__
#endif
/*
 *      This software may be combined with the following TRILLIUM
 *      software:
 *
 *      part no.                      description
 *      --------    ----------------------------------------------
 *      1000241     LTE-MAC
 *      1000369     LTE-RRC
 */

/* header (.h) include files */
#include "envopt.h"        /* environment options */
#include "envdep.h"        /* environment dependent */
#include "envind.h"        /* environment independent */

#include "gen.h"           /* general */
#include "ssi.h"           /* system services */
#include "cm5.h"           /* common timer defines */
#include "cm_tkns.h"       /* common tokens defines */
#include "cm_mblk.h"       /* common memory allocation library defines */
#include "cm_llist.h"      /* common link list  defines  */
#include "cm_hash.h"       /* common hash list  defines */
#include "cm_lte.h"        /* common LTE defines */
#include "ckw.h"
#include "kwu.h"
#include "lkw.h"
#include "rgu.h"
#ifdef KW_PDCP
#include "lpj.h"           /* LPJ defines */
#include "cpj.h"           /* CPJ defines */
#include "pju.h"           /* PJU defines */
#endif

#include "kw_env.h"        /* RLC environment options */
#include "kw.h"            /* RLC defines */
#include "kw_err.h"        /* Error defines */

/* extern (.x) include files */
#include "gen.x"           /* general */
#include "ssi.x"           /* system services */

#include "cm5.x"           /* common timer library */
#include "cm_tkns.x"       /* common tokens */
#include "cm_mblk.x"       /* common memory allocation */
#include "cm_llist.x"      /* common link list */
#include "cm_hash.x"       /* common hash list */
#include "cm_lte.x"        /* common LTE includes */
#include "cm_lib.x"        /* common memory allocation library */
#include "ckw.x"
#include "kwu.x"
#include "lkw.x"
#include "rgu.x"
#ifdef KW_PDCP
#include "lpj.x"           /* LPJ defines */
#include "cpj.x"           /* CPJ defines */
#include "pju.x"           /* PJU defines */
#endif

#include "kw.x"

#ifdef __cplusplus
EXTERN "C" {
#endif /* __cplusplus */

EXTERN U32 ysMsAmmNumReassemblyRbLstCount, ysMsAmmNumReassemblyLstCount;

/* Private functions declarations */
PRIVATE Void kwUtlGetNumRbInReestablishLst ARGS ((U16 *numRb));
PRIVATE Void kwUtlGetRbFrmReestablishLst ARGS ((KwRbCb **rbCb));
#ifdef LTE_L2_MEAS
#ifdef LTE_RLC_R9
PRIVATE Void kwUtlResetL2MeasInKwRb ARGS ((KwL2MeasCb *measCb));
PRIVATE Void kwUtlPlcMeasDatInL2Sts ARGS((KwL2Cntr *measData,
                                         KwL2MeasRbCb *rbL2Cb ,U8  measType));
#endif /* LTE_RLC_R9 */
#endif /* LTE_L2_MEAS */

PUBLIC U32 kwUlSelfMsgPosted;

/**
 *
 * @brief 
 *
 *        Handler for sending the data to multiple logical channels of a UE.
 *
 * @b Description:
 *
 *        This function sends the data for one or more logical channels
 *        after processing the SDUs and forming the PDUs.It calls
 *        UMM or AMM functions to form the PDUs for the requested sizes
 *        by MAC. 
 *
 *  @param[in] staIndInfo   Status Indication Information containing the 
 *                          size of PDU(s) for one or more logical channels  
 *
 *  @return  S16
 *      -# ROK 
 *      -# RFAILED
 *
 */
#ifdef ANSI
PUBLIC S16 kwUtlSndToLi
(
KwDStaIndInfo           *staIndInfo
)
#else
PUBLIC S16 kwUtlSndToLi(staIndInfo)
KwDStaIndInfo           *staIndInfo;
#endif
{
   KwUeCb               *ueCb;
   U8                   count;
   U8                   numTb;
   KwRbCb               *rbCb;
   KwDatReq             datReq;
   RguDDatReqInfo       *datReqInfo;
   KwRguSapCb           *rguSap;
   KwUeKey              ueKey;
   S16                  ret;
   U32                  totNumPdu;
#ifdef MSPD_MLOG_NEW   
   VOLATILE  U32        t=0, t2=0;
#endif   
#ifdef LTE_L2_MEAS
   KwTbSnMap            *tbSnMap;
   U8                   snIdx1;
   U8                   snIdx2;
#endif

#ifdef MSPD_MLOG_NEW
   t = GetTIMETICK();
#endif   
   TRC2(kwUtlSndToLi)
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_DL ),
          (_kwPBuf, "kwUtlSndToLi(staIndInfo)\n"));
   count     = 0;
   rguSap    = &(kwCb.rguSap);
   ueCb      = NULLP;
   totNumPdu = 0;

   ueKey.cellId = staIndInfo->cellId;
   ueKey.ueId   = staIndInfo->rnti;

   ret = kwDbmFetchUeCb(ueKey.ueId, ueKey.cellId, &ueCb);
   if (ret != ROK )
   {
      /* Fetch UeCb failed */
      KWLOGERROR(ERRCLS_ADD_RES, EKW217, (ErrVal) RFAILED,
            "kwDbmFetchUeCb : Fetch UeCb Failed.");
      MSPD_ERR("FetchUeCb failed for crnti %d in cellId %d\n", ueKey.ueId,
                ueKey.cellId);
      RETVALUE(RFAILED);
   }
   KW_ALLOC(datReqInfo,sizeof(RguDDatReqInfo));
   cmMemset( (U8 *)&datReq, 0, sizeof(KwDatReq) ); 

#if (ERRCLASS & ERRCLS_ADD_RES)
   if ( datReqInfo == NULLP )
   {
      KWLOGERROR(ERRCLS_ADD_RES, EKW218, (ErrVal) RFAILED,
                 "KwDatReq: kwDatReq allocation Failed.");

      RETVALUE(RFAILED);
   }
#endif /* ERRCLASS & ERRCLS_ADD_RES */ 
#ifdef MSPD_MLOG_NEW
   MLogTask(PID_RLC_STA_IND_MEMSET, RESOURCE_LARM, t , GetTIMETICK());
#endif   

   for (numTb = 0; numTb < staIndInfo->nmbOfTbs; numTb++)
   {
      RguStaIndTb  *staIndTb = &(staIndInfo->staIndTb[numTb]);
      RguDatReqTb  *datReqTb = &(datReqInfo->datReqTb[numTb]);

#ifdef LTE_L2_MEAS
      KW_ALLOC(tbSnMap,sizeof(KwTbSnMap));
      tbSnMap->tbId  =  ++kwCb.kwL2Cb.tbId;
      kwCb.kwL2Cb.curTbSnMap = tbSnMap;
      datReqTb->snMapPres = TRUE;
      KW_ALLOC(datReqTb->rguSnInfo,sizeof(RguSnMapInfo));
      datReqTb->rguSnInfo->tbId = tbSnMap->tbId;
      datReqTb->rguSnInfo->numLch = staIndTb->nmbLch;
#endif /* LTE_L2_MEAS */
#ifdef MSPD_MLOG_NEW
      t = GetTIMETICK();
#endif	  
      for (count = 0;count < staIndTb->nmbLch; count++)
      {
         rbCb = ueCb->lCh[staIndTb->lchStaInd[count].lcId - 1].dlRbCb;

         if ( rbCb != NULLP )
         { 
            datReq.pduSz = staIndTb->lchStaInd[count].totBufSize;
            if ( rbCb->mode == CM_LTE_MODE_UM )
            {
               ret = kwUmmProcessSdus(rbCb,&datReq);
#if (ERRCLASS & ERRCLS_DEBUG)
               if ( ret != ROK )
               {
                  KWLOGERROR(ERRCLS_ADD_RES, EKW219, (ErrVal) RFAILED,
                            "kwUmmProcessSdus Failed.");
                  RETVALUE(RFAILED);
               }
#endif /* ERRCLASS & ERRCLS_DEBUG */
            }
            else if ( rbCb->mode == CM_LTE_MODE_AM )
            {
               /* Prepare DDATREQ only if DRB is not stalled           */
               if (!((CM_LTE_DRB == KW_RBTYPE) && (TRUE == AMDL.isRbstalled)))
               {
                  ret = kwAmmProcessSdus(rbCb,&datReq);
               }
               else
               { 			   	
                  MSPD_DBG_RLC("[%d][%d][%d] Drop StaInd in RLC from MAC\n",
                                KW_UEID, KW_RBTYPE, KW_RBID);
               }
#if (ERRCLASS & ERRCLS_DEBUG)
               if ( ret != ROK )
               {
                   KWLOGERROR(ERRCLS_ADD_RES, EKW220, (ErrVal) RFAILED,
                              "kwAmmProcessSdus Failed.");
                   RETVALUE(RFAILED);
               }
#endif /* ERRCLASS & ERRCLS_DEBUG */
            }
   
            if (datReq.pduInfo.numPdu == 0)
            {
/* TODO: This code need to be reviewed when H8+ is merged */
#ifdef PWAV
               datReqTb->lchData[count].pdu.numPdu = 0;
               datReqTb->lchData[count].boReport.bo = 0;
	           datReqTb->lchData[count].lcId = staIndTb->lchStaInd[count].lcId;
#endif
               MSPD_ERR("No Data from RLC for UeId %d cellId %d\n", 
                        ueKey.ueId, ueKey.cellId);
               continue;
            }
            totNumPdu += datReq.pduInfo.numPdu;
            cmMemcpy((U8 *)(&(datReqTb->lchData[count].pdu)),
                     (U8 *)(&(datReq.pduInfo)), sizeof(KwPduInfo));
            datReqTb->lchData[count].boReport.bo = datReq.boRep.bo;

#ifdef CCPU_OPT
            datReqTb->lchData[count].boReport.estRlcHdrSz =
                                                   datReq.boRep.estHdrSz;
            datReqTb->lchData[count].boReport.staPduPrsnt =
                                                   datReq.boRep.staPduPrsnt;
#endif

            datReqTb->lchData[count].lcId = staIndTb->lchStaInd[count].lcId;
#ifdef LTE_L2_MEAS
            datReqTb->rguSnInfo->lchMap[count].lChId =
                                            staIndTb->lchStaInd[count].lcId;
            /* In some cases L2 Measurement for few of the lcId may be off, *
             * in this case we are assigning snList to 0xffff               */
            for (snIdx1 = 0; snIdx1 < RGU_MAX_PDU; snIdx1++)
            {
               datReqTb->rguSnInfo->lchMap[count].snList[snIdx1] = 0xffff;
            }
            if (tbSnMap->numSn != 0)
            {
               snIdx2 = 0;
               for(snIdx1 = tbSnMap->prevNumSn; snIdx1 < tbSnMap->numSn;
                                                                    snIdx1++)
               {
                   datReqTb->rguSnInfo->lchMap[count].snList[snIdx2++] = 
                   tbSnMap->snSduMap[snIdx1].sn;
               }
               tbSnMap->prevNumSn = tbSnMap->numSn;
            }
#endif
            cmMemset( (U8 *)&datReq, 0, sizeof(KwDatReq) ); 
         }
      }
      datReqTb->nmbLch = staIndTb->nmbLch; 
#ifdef MSPD_MLOG_NEW
      MLogTask(PID_RLC_STA_IND_PRC, RESOURCE_LARM, t , GetTIMETICK());
#endif	  
#ifdef LTE_L2_MEAS
      if(tbSnMap->numSn == 0)
      {
         KW_FREE(tbSnMap,sizeof(KwTbSnMap));
         KW_FREE(datReqTb->rguSnInfo,sizeof(RguSnMapInfo));
         datReqTb->rguSnInfo = NULLP;
         kwCb.kwL2Cb.curTbSnMap = NULLP;
         datReqTb->snMapPres = FALSE;
      }
      else
      {
         cmHashListInsert(&(kwCb.kwL2Cb.tbHlCp),(PTR)tbSnMap,
               (U8 *) &(tbSnMap->tbId), (U16)sizeof(tbSnMap->tbId));
         kwCb.kwL2Cb.curTbSnMap = NULLP;
      }
#endif /* LTE_L2_MEAS */
   }
   
   /* MSPD_FIX: Sending Data request even when numPdus=0 */   
   if (totNumPdu == 0)
   {
      static U32 cntr = 0;
      ++cntr;
      MSPD_ERR("No Data from RLC for UeId %d cellId %d: MAC sent Padding %u\
               times\n", ueKey.ueId, ueKey.cellId, cntr);
   } 
  
   datReqInfo->nmbOfTbs = staIndInfo->nmbOfTbs;
   datReqInfo->transId  = staIndInfo->transId;
   datReqInfo->cellId   = staIndInfo->cellId;
   datReqInfo->rnti     = staIndInfo->rnti; 
   /* If trace flag is enabled send the trace indication */
   if(kwCb.init.trc == TRUE)
   {
      /* Populate the trace params */
      kwLmmSendTrc(EVTRGUDDATREQ, NULLP);
   }

   KwLiRguDDatReq(&rguSap->pst,rguSap->spId,datReqInfo); 
   RETVALUE(ROK);
}

/**
 *
 * @brief 
 *
 *        Handler for receiving data for multiple logical channels from MAC.
 *
 * @b Description:
 *
 *        This function receives the data sent by MAC for one or more 
 *        logical channels.It calls the UMM or AMM functions to process
 *        the PDUs and send them to the uppper layer.  
 *
 *  @param[in] datIndInfo     Data Indication Information containing the PDU(s)
 *                            for one or more logical channels  
 *
 *  @return  S16
 *      -# ROK 
 *      -# RFAILED
 *
 */
#ifdef ANSI
PUBLIC S16 kwUtlRcvFrmLi
(
KwDatIndInfo            *datIndInfo
)
#else
PUBLIC S16 kwUtlRcvFrmLi(datIndInfo)
KwDatIndInfo            *datIndInfo;
#endif
{
   U8                   count;
   KwPduInfo            *pduInfo;
   KwRbCb               *rbCb;
   KwUeCb               *ueCb;
   KwUeKey              ueKey;
   S16                  ret;
#ifdef LTE_L2_MEAS
#ifdef LTE_RLC_R9
   KwL2MeasUlThrpTimInfo *ulTimeInfo = NULLP;
#endif
#endif

   TRC2(kwUtlRcvFrmLi)
#ifdef DEBUGP
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_UL),
          (_kwPBuf, "kwUtlRcvFrmLi(datIndInfo)\n"));
#endif
   ueKey.cellId = datIndInfo->cellId;
   ueKey.ueId   = datIndInfo->rnti;
   ueCb = NULLP;

   ret = kwDbmFetchUeCb(ueKey.ueId,ueKey.cellId,&(ueCb));
   if (ret != ROK)
   {
      /* Fetch UeCb failed */
      KWLOGERROR(ERRCLS_ADD_RES, EKW221, (ErrVal) RFAILED,
                 "kwDbmFetchUeCb Failed.");
      MSPD_ERR("FetchUeCb failed for crnti %d in cellId %d\n", ueKey.ueId,
                ueKey.cellId);
      RETVALUE(RFAILED);
   }

   for (count = 0;count < datIndInfo->numLch; count++)
   {
      rbCb = ueCb->lCh[datIndInfo->lchData[count].lcId - 1].ulRbCb;
      pduInfo = &(datIndInfo->lchData[count].pdu); 
	  MSPD_DBG1("PWAV: (In kwUtlRcvFrmLi) Mode = %d, rbtype=%d, rbId=%d, UEID=%d\n",rbCb->mode, rbCb->rlcId.rbType, rbCb->rlcId.rbId, rbCb->rlcId.ueId);
   
      if ( rbCb->mode == CM_LTE_MODE_UM )
      {
#ifdef LTE_L2_MEAS
#ifdef LTE_RLC_R9
         ulTimeInfo = &(datIndInfo->lchData[count].timeInfo);
         ret = kwUmmProcessPdus(rbCb,pduInfo,ulTimeInfo);
#else
         ret = kwUmmProcessPdus(rbCb,pduInfo);
#endif
#else
         ret = kwUmmProcessPdus(rbCb,pduInfo);
#endif
#if (ERRCLASS & ERRCLS_DEBUG)
         if ( ret != ROK )
         {
            KWLOGERROR(ERRCLS_ADD_RES, EKW222, (ErrVal) RFAILED,
                       "kwUmmProcessPdus Failed.");
            RETVALUE(RFAILED);
         }
#endif /* ERRCLASS & ERRCLS_DEBUG */
      }
      else if (rbCb->mode == CM_LTE_MODE_AM)
      {
#ifdef LTE_L2_MEAS
#ifdef LTE_RLC_R9
         ulTimeInfo = &(datIndInfo->lchData[count].timeInfo);
         ret = kwAmmProcessPdus(rbCb,pduInfo,ulTimeInfo);
#else
         ret = kwAmmProcessPdus(rbCb,pduInfo);
#endif
#else
         ret = kwAmmProcessPdus(rbCb,pduInfo);
#endif
#if (ERRCLASS & ERRCLS_DEBUG)
         if (ret != ROK)
         {
            KWLOGERROR(ERRCLS_ADD_RES, EKW223, (ErrVal) RFAILED,
                       "kwAmmProcessPdus Failed.");
            RETVALUE(RFAILED);
         }
#endif /* ERRCLASS & ERRCLS_DEBUG */
      }
   }
   RETVALUE(ROK);
}

/**
 *
 * @brief 
 *
 *        Handler for sending Status Response to MAC. 
 *
 * @b Description:
 *
 *        This function is used by  RLC entity for sending
 *        status response to MAC after receiving a SDU from
 *        PDCP.
 *
 *  @param[in]  rbCb               Radio Bearer Control Block 
 *  @param[in]  bo                 BO
 *  @param[in]  estHdrSz           Estimated Header Size
 *  @param[in]  staPduPrsnt        Status PDU present or not
 *
 *  @return  S16
 *      -# ROK 
 *      -# RFAILED
 */
#ifdef ANSI
PUBLIC S16 kwUtlSndDStaRsp
(
KwRbCb                  *rbCb,
S32                     bo,
S32                     estHdrSz,
Bool                    staPduPrsnt
)
#else
PUBLIC S16 kwUtlSndDStaRsp(rbCb,bo,estHdrSz,staPduPrsnt)
KwRbCb                  *rbCb;
S32                     bo;
S32                     estHdrSz;
Bool                    staPduPrsnt;
#endif
{
   RguDStaRspInfo       *staRspInfo;
   KwRguSapCb           *rguSap;

   TRC3(kwUtlSndDStaRsp)
#ifdef DEBUGP
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_DL),
          (_kwPBuf, "kwUtlSndDStaRsp(rbCb)\n"));
#endif
   KW_ALLOC(staRspInfo,sizeof(RguDStaRspInfo)); 
#if (ERRCLASS & ERRCLS_ADD_RES)
   if (staRspInfo == NULLP )
   {
      KWLOGERROR(ERRCLS_ADD_RES, EKW224, (ErrVal) RFAILED,
               " KW_ALLOC failed for staRspInfo.");
      RETVALUE(RFAILED);
   }
#endif /* ERRCLASS & ERRCLS_ADD_RES */
   rguSap = &(kwCb.rguSap);

#ifdef CCPU_OPT
   staRspInfo->boReport.estRlcHdrSz = (U16)estHdrSz;
   staRspInfo->boReport.staPduPrsnt = staPduPrsnt;
#endif

   staRspInfo->boReport.bo = bo;
   staRspInfo->cellId      = rbCb->rlcId.cellId;
   staRspInfo->rnti        = rbCb->rlcId.ueId;
   staRspInfo->lcId        = rbCb->lch[0].lChId;

   /* If trace flag is enabled send the trace indication */
   if(kwCb.init.trc == TRUE)
   {
      /* Populate the trace params */
      kwLmmSendTrc(EVTRGUDSTARSP, NULLP);
   }

   KwLiRguDStaRsp(&rguSap->pst,rguSap->spId,staRspInfo);

   RETVALUE(ROK);
}

/**
 *
 * @brief 
 * 
 *        Handler for emptying the SDU queue. 
 * 
 * @b Description:
 *
 *        This function is used to empty the SDU queue when
 *        a re-establishment request is received from the 
 *        upper layer.
 *
 *  @param[in]  sduQ        SDU queue to be emptied
 *
 *  @return  S16
 *      -# ROK 
 */
/* kw005.201 added support for L2 Measurement */
#ifdef ANSI
PUBLIC S16 kwUtlEmptySduQ
(
KwRbCb                  *rbCb,
CmLListCp               *sduQ
)
#else
PUBLIC S16 kwUtlEmptySduQ(rbCb, sduQ)
KwRbCb                  *rbCb;
CmLListCp               *sduQ;
#endif
{
   CmLList              *firstNode;     /* First Node in SDU Queue */
   KwSdu                *sdu;           /* Pointer to a SDU */
#ifdef LTE_L2_MEAS
   CmLListCp            *sduSnMapQ;     /* SDU Sequence number map queue */
   CmLList              *firstSduSnMap; /* First Node in SDU SnMap Queue */
   KwSduSnMap           *sduSnMap;      /* SDU Sn Map */
#endif

   TRC2(kwUtlEmptySduQ)
   MSPD_DBG_RLC("[%d][%d][%d]Emptying the SDU Q\n", KW_UEID, KW_RBTYPE, KW_RBID);
#ifdef LTE_L2_MEAS
   sduSnMapQ = NULLP;
   firstSduSnMap = NULLP;
   sduSnMap = NULLP;
#endif
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_DL),
          (_kwPBuf, "kwUtlEmptySduQ(sduQ)\n"));

#ifdef LTE_L2_MEAS
   sduSnMapQ = &rbCb->sduSnMapQ;
   CM_LLIST_FIRST_NODE(sduSnMapQ, firstSduSnMap);

   while(firstSduSnMap)
   {
      sduSnMap = (KwSduSnMap *)firstSduSnMap->node;
      if(sduSnMap != NULLP)
      {
         cmLListDelFrm(&(rbCb->sduSnMapQ), &(sduSnMap->lstEnt));
         KW_FREE(sduSnMap, sizeof(KwSduSnMap));
         CM_LLIST_FIRST_NODE(sduSnMapQ, firstSduSnMap);
      }
      else
      {
         CM_LLIST_NEXT_NODE(sduSnMapQ, firstSduSnMap);
      }
   }
#endif
   if(rbCb->mode == CM_LTE_MODE_AM)
   {
      while(sduQ->first)
      { 
         sdu = (KwSdu *)(sduQ->first->node);
         cmLListDelFrm(sduQ, sduQ->first);
         KW_FREE_BUF(sdu->mBuf);
         KW_FREE(sdu, sizeof(KwSdu));
      }
      AMDL.bo = 0;
   }
   else
   {
      firstNode = sduQ->first;
      while(firstNode)
      { 
         sdu = (KwSdu *)firstNode->node;
         KW_RMV_SDU(sduQ,sdu);
         firstNode = sduQ->first;
      }
   }
   RETVALUE(ROK);
}

/**
 *
 * @brief 
 * 
 *        Handler for sending Data Indication to the upper layer. 
 * 
 * @b Description:
 *
 *        This function is used to send re-assembled SDU
 *        to the upper layer.
 *
 *  @param[in]  rbCb               RB Control Block 
 *  @param[in]  sdu                SDU to be freed
 *
 *  @return  S16
 *      -# ROK 
 */
#ifdef ANSI
PUBLIC S16 kwUtlSndDatInd
(
KwRbCb                  *rbCb,
Buffer                  *sdu
)
#else
PUBLIC S16 kwUtlSndDatInd(rbCb,sdu)
KwRbCb                  *rbCb;
Buffer                  *sdu;
#endif
{
#ifdef KW_PDCP
   PjRbCb               *pjRbCb = NULLP;
#else
   KwKwuSapCb           *kwKwSap = NULLP;
   KwuDatIndInfo        *datIndInfo = NULLP;
#endif
#ifdef MSPD
   U32                  startTick  = GetTIMETICK();
#endif

   TRC3(kwUtlSndDatInd)

#ifdef DEBUGP
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_UL),
          (_kwPBuf, "kwUtlSndDatInd(rbCb,sdu)\n"));
#endif

#ifndef KW_PDCP
   KW_ALLOC( datIndInfo, sizeof(KwuDatIndInfo));

#if (ERRCLASS & ERRCLS_ADD_RES )
   if (datIndInfo == NULLP)
   {
      KWLOGERROR(ERRCLS_ADD_RES, EKW225, (ErrVal) RFAILED,
                 "KW_ALLOC failed for datIndInfo .");
      KW_FREE_BUF(sdu);
      RETVALUE(RFAILED);
   }
#endif /* ERRCLASS & ERRCLS_ADD_RES */

   KW_MEM_CPY(&(datIndInfo->rlcId),&(rbCb->rlcId),sizeof(CmLteRlcId));
#endif /* KW_PDCP */
   
   /* If trace flag is enabled send the trace indication */
   if(kwCb.init.trc == TRUE)
   {
      /* Populate the trace params */
      kwLmmSendTrc(KWU_EVT_DAT_IND, sdu);
   }
#ifdef KW_PDCP
   if ( rbCb->pjRbCb != NULLP )
   {
       pjRbCb = rbCb->pjRbCb;
   }
   else
   {
      RETVALUE(RFAILED);
   }
   //MSPD_DBG("[%d][%d] Send SDU to PDCP\n", KW_UEID, KW_RBID);
   pjLimDatInd(pjRbCb,sdu);
#else
   kwKwSap = kwCb.kwuSap + KW_UI_PDCP;

   KwUiKwuDatInd(&kwKwSap->pst, kwKwSap->suId, datIndInfo, sdu);
#endif   
#ifdef MSPD_MLOG_NEW
   MLogTask(PID_RLC_KWUDAT_IND, RESOURCE_LARM, startTick, GetTIMETICK());
#endif
   RETVALUE(ROK);
} /* kwUtlSndDatInd */

/**
 *
 * @brief 
 * 
 *        Handler for calculating the LI length for a SDU. 
 * 
 * @b Description:
 *
 *        This function is used to calculate the LI length
 *        which has to be substracted from the pduSize to 
 *        correctly match the formed PDU(s) size with the 
 *        size requested by MAC.
 *
 *  @param[in]  numLi               Number of LIs already present 
 *  @param[in]  msgLen              Size of the SDU
 *  @param[in]  pduSz               Size of the pDU to be formed
 *
 *  @return  S16
 *      -# ROK 
 */
#ifdef ANSI
PUBLIC S16 kwUtlCalcLiForSdu
(
U16     numLi,                          /* Number of LIs */
MsgLen  msgLen,                         /* SDU size */
S16     *pduSz                          /* Remaining PDU size */
)
#else
PUBLIC S16 kwUtlCalcLiForSdu(numLi,msgLen,pduSz)
U16     numLi;                          /* Number of LIs */
MsgLen  msgLen;                         /* SDU size */
S16     *pduSz;                         /* Remaining PDU size */
#endif 
{
   TRC2(kwUtlCalcLiForSdu)
#ifdef DEBUGP
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_DL),
          (_kwPBuf, "kwUtlCalcLiForSdu(rbCb, msgLen, pduSz)\n"));
#endif
   if (*pduSz > msgLen)
   {
      if (msgLen < 2048)
      {
         if (numLi % 2 == 0)
            *pduSz -= 2;
         else
            *pduSz -= 1;
      }
   }
   RETVALUE(ROK);
}


/** @details
 * This primitive Frees the UM/AM RbCb transmission Buffer, retransmission
 * Buffer and reciption Buffers
 *
 * @param [out]   rbCb     -  RB Control Block
 *
 * @return
 *          - ROK
 *          - RFAILED
 */
#ifdef ANSI
PUBLIC Void kwUtlFreeRbCb
(
KwRbCb               *rbCb
)
#else
PUBLIC Void kwUtlFreeRbCb(rbCb)
KwRbCb               *rbCb;
#endif
{
   KwSn              curSn = 0;
   KwSn              windSz = 0;
   KwUmRecBuf        **umRecBuf;
   U32               pduListCnt;
   U32               reasmblyRbListCnt;

   TRC2(kwUtlFreeRbCb)
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF | KW_DBGMASK_DL | KW_DBGMASK_UL),
          (_kwPBuf, "kwUtlFreeRbCb(rbCb)\n")); 

   if (rbCb->mode == CM_LTE_MODE_UM)
   {
#if 0	   
      if (rbCb->dir & KW_DIR_DL)
      {
         kwUtlEmptySduQ(rbCb, &rbCb->m.um.umDl.sduQ);
      }
      if (rbCb->dir & KW_DIR_UL)
      {
         /* Get the number of nodes in toBeReasmbldUmPduLst */
         pduListCnt = UMUL.reassemblyLst.count;
         reasmblyRbListCnt = kwCb.reassemblyRbLst.count;
         /* Set the bit 3 of rbOp flag to 1 which indicates that delete *
          * Rb request for this RB is received.                         */
         rbCb->rbOp |= 0x08;
         KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF |
                 KW_DBGMASK_DL  | KW_DBGMASK_UL),
                (_kwPBuf, "kwUtlFreeRbCb:Count(%lu) in toBeReasmbldUmPduLst\n",
                 pduListCnt));

         windSz  = rbCb->m.um.umUl.umWinSz << 1;
         umRecBuf =  rbCb->m.um.umUl.recBuf;
        
	 /* MS_FIX : Moving all the timer processing in One core.
	  * kwCfgDelUe will handle this now. */

         while ( curSn < windSz )
         {
            if ( umRecBuf[curSn] != NULLP )
            {
               if (umRecBuf[curSn] && (umRecBuf[curSn]->pdu != NULLP))
               {
                  /* Adding the received PDU to UmPduList. It will get  *
                   * freed when the self post message will be processed.*/
                  cmLListAdd2Tail(&UMUL.reassemblyLst,
                                  &umRecBuf[curSn]->reassemblyLnk);
                  umRecBuf[curSn]->reassemblyLnk.node = (PTR)umRecBuf[curSn];
                  umRecBuf[curSn] = NULLP;
               }
            }
            curSn++;
         }
         KW_FREE(rbCb->m.um.umUl.recBuf, (windSz ) *
               sizeof(KwUmRecBuf*));
         /* Add this RB to the RbList. Multiple entries of same RB should  *
          * be avoided. pduListCnt will be ZERO only if this RB is not in  *
          * RbList.So, if this count is 0 and current count is more than 0,*
          * then RB is added to RbList and self post message is posted to  *
          * RLC.                                                           */
         if ((0 == pduListCnt) && (UMUL.reassemblyLst.count > 0))
         {
            cmLListAdd2Tail(&kwCb.reassemblyRbLst, &rbCb->reassemblyRbLnk);
            rbCb->reassemblyRbLnk.node = (PTR)rbCb;
         }
         /* Post the self message to RLC only when the 1st Rb is added to *
          * the Rb list.                                                  */
         if ((0 == reasmblyRbListCnt) && (1 == kwCb.reassemblyRbLst.count))
         {
            kwUtlPostSelfMsgUl(1);
         }
         /* If there are no PDUs in the toBeReasmbldUmPduLst, then *
          * reset bit 3 of rbOp flag to 0.                         */
         if (0 == UMUL.reassemblyLst.count)
         {
            rbCb->rbOp &= 0xf7;
         }
         KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_BRIEF |
                 KW_DBGMASK_DL  | KW_DBGMASK_UL),
                (_kwPBuf, "kwUtlFreeRbCb:Count(%lu) in reassemblyLst\n",
                 UMUL.reassemblyLst.count));
      }
#endif
      kwUmmDeleteRb(rbCb);      
   }
   else if (rbCb->mode == CM_LTE_MODE_AM)
   {
      kwAmmDeleteRb(rbCb);
   }
   else 
   {
      kwUtlEmptySduQ(rbCb, &rbCb->m.tm.sduQ);
   }

   RETVOID;
}

#ifdef LTE_L2_MEAS
/**
 * @brief Handler for L2 Measurement timer expiry.
 *
 * @b Description
 *        This function is called when the l2 measurement timer expires. 
 *        This function sends a consolidates the mesaurements taken during
 *        this time and sends the confirm .
 *
 *  @param[in] measEvtCb    Measurement Event Control Block.
 *
 *  @return  S16
 *      -# ROK
 */
#ifdef ANSI
PUBLIC S16 kwUtlHdlL2TmrExp
(
KwL2MeasEvtCb *measEvtCb
)
#else
PUBLIC S16 kwUtlHdlL2TmrExp(measEvtCb)
KwL2MeasEvtCb *measEvtCb;
#endif
{
   U16             qciIdx;
   KwL2MeasCb     *measCb;

   TRC3(kwUtlHdlL2TmrExp)
   /* kw006.201 ccpu00120058 removed 64 bit compilation warning */
#ifndef ALIGN_64BIT
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlHdlL2TmrExp(transId(%ld))\n", measEvtCb->transId));
#else
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlHdlL2TmrExp(transId(%d))\n", measEvtCb->transId));
#endif
   /* Clean up the RB data structures */
   if((measEvtCb->measCb.measType & LKW_L2MEAS_ACT_UE) &&
      (measEvtCb->measCb.numSamples))
   {
      measCb = &measEvtCb->measCb;

      for(qciIdx = 0; qciIdx < measCb->numQci;qciIdx++)
      {
         measCb->measData[measCb->qci[qciIdx]].actUe.numActvUe   +=   
                     kwCb.kwL2Cb.numActUe[measCb->qci[qciIdx]];
         measCb->measData[measCb->qci[qciIdx]].actUe.sampOc++;
      }
      measEvtCb->measCb.numSamples--;
      kwStartTmr((PTR)measEvtCb, KW_EVT_L2_TMR); 
      RETVALUE(ROK);
   }

   kwUtlSndL2MeasCfm(measEvtCb);

   RETVALUE(ROK);
} /* kwUtlHdlL2TmrExp */

/* kw006.201 CR:ccpu00120058, added new function */
/**
 *
 * @brief Handler for resetting the RB data structures
 *
 *
 * @b Description
 *        This function resets the RB data structure after the expiry of 
 *        measurement timer.
 *
 *  @param[in] measCb    Measurement Control Block.
 *
 *
 *  @return  Void
 */
#ifdef ANSI
PRIVATE Void kwUtlResetL2MeasInKwRb
(
KwL2MeasCb *measCb
)
#else
PRIVATE Void kwUtlResetL2MeasInKwRb(measCb)
KwL2MeasCb *measCb;
#endif
{
   U16           seqNum;
   U32           qciIdx;
   KwRbCb        *kwRbCb;

   seqNum = 0;

   for(qciIdx = 0; qciIdx < measCb->numQci; qciIdx++)
   {
      while (cmHashListFind(&(kwCb.kwL2Cb.qciHlCp), (U8 *) &measCb->qci[qciIdx], 
               sizeof(measCb->qci[qciIdx]),  seqNum++, (PTR *)&kwRbCb) == ROK)
      {
         if((kwRbCb->rbL2Cb.measOn & measCb->measType) &&
            (kwRbCb->rlcId.rbType == CM_LTE_DRB))
         {
            kwRbCb->rbL2Cb.measOn &= ~measCb->measType;
         }
      }
      seqNum = 0;
      kwCb.kwL2Cb.measOn[measCb->qci[qciIdx]] &= ~measCb->measType;
   }
} /* kwUtlResetL2MeasInKwRb */
#ifdef LTE_RLC_R9
/* kw006.201 CR:ccpu00120058, added new function */
/**
 *
 * @brief Handler for Sending L2 Measurement Disable Request to MAC
 *
 *
 * @b Description
 *        This function sends a L2 Measurement Disable Request to MAC
 *        For the LCHs corresponding to a UE.
 *
 *  @param[in] measCb    Measurement Control Block.
 *
 *
 *  @return  Void
 */
#ifdef ANSI
PUBLIC S16 kwUtlNotifyMacUlIp
(
KwL2MeasCb *measCb,
Bool       enable,
CmLteLcId  *lChId,
U8         *numLCh
)
#else
PUBLIC S16 kwUtlNotifyMacUlIp(measCb, enable, lChId, numLCh)
KwL2MeasCb *measCb;
Bool       enable;
CmLteLcId  *lChId;
U8         *numLCh;
#endif
{
   U8                      lcIdIdx;
   RguL2MUlThrpMeasReqInfo *ulThrpMeasReqInfo = NULLP;
   KwRguSapCb              *rguSap = &(kwCb.rguSap);

   if(measCb->measType & LKW_L2MEAS_UL_IP)
   {
      /*Send req to MAC to stop taking timings for these LChs*/
      KW_ALLOC(ulThrpMeasReqInfo, sizeof(RguL2MUlThrpMeasReqInfo));
#if (ERRCLASS & ERRCLS_ADD_RES)
      if(NULLP == ulThrpMeasReqInfo)
      {
         KWLOGERROR(ERRCLS_ADD_RES, EKWXXX, (ErrVal) RFAILED,
            "kwUtlSndL2MeasCfm: KW_ALLOC Failed for ulThrpMeasReqInfo.");
         RETVALUE(RFAILED);
      }
#endif /* ERRCLASS & ERRCLS_ADD_RES */
      ulThrpMeasReqInfo->cellId = measCb->cellId;
      ulThrpMeasReqInfo->rnti = measCb->ueId;
      if(FALSE == enable)
      {
         ulThrpMeasReqInfo->numLcId = measCb->numLcId;
         ulThrpMeasReqInfo->enbMeas = FALSE;
         for(lcIdIdx = 0; lcIdIdx < measCb->numLcId; lcIdIdx++)
         {
            ulThrpMeasReqInfo->lcId[lcIdIdx] = measCb->lcId[lcIdIdx];
         }
      }
      else
      {
         ulThrpMeasReqInfo->numLcId = *numLCh;
         ulThrpMeasReqInfo->enbMeas = TRUE;
         for(lcIdIdx = 0; lcIdIdx < *numLCh; lcIdIdx++)
         {
            ulThrpMeasReqInfo->lcId[lcIdIdx] = lChId[lcIdIdx];
            measCb->lcId[lcIdIdx] = lChId[lcIdIdx];
         }
         /*Storing numLCh and lcId list in measCb so that the same can be used*
          *while sending the indication to MAC for disabling measurement after*
          *the timer expiry.                                                  */
         measCb->numLcId = *numLCh;
      }
      /*Send ulThrpMeasReqInfo to MAC*/
      KwLiRguL2MUlThrpMeasReq(&rguSap->pst,rguSap->spId, ulThrpMeasReqInfo);
   }
   RETVALUE(ROK);
} /* end of kwUtlNotifyMacUlIp */
#endif /* LTE_RLC_R9 */

/**
 *
 * @brief Handler for Sending L2 Measurement confirm.
 *
 *
 * @b Description
 *        This function sends a consolidates the mesaurements taken during
 *        this time and sends the confirm .
 *
 *  @param[in] measEvtCb    Measurement Event Control Block.
 *
 *
 *  @return  S16
 *      -# ROK
 */
#ifdef ANSI
PUBLIC S16 kwUtlSndL2MeasCfm
(
KwL2MeasEvtCb *measEvtCb
)
#else
PUBLIC S16 kwUtlSndL2MeasCfm(measEvtCb)
KwL2MeasEvtCb *measEvtCb;
#endif
{
   U32                     qciIdx;
   KwL2MeasCb              *measCb;
   KwL2MeasCfmEvt          measCfmEvt;
   U32                     posPkts;
   U32                     dLoss;
#ifdef LTE_RLC_R9
   U32                     dlDataVol;
   U32                     dlTime;
   U32                     ulDataVol;
   U32                     ulTime;
#endif /* LTE_RLC_R9 */

   TRC3(kwUtlSndL2MeasCfm)

   /* kw006.201 ccpu00120058 emoved 64 bit compilation warning */
#ifndef ALIGN_64BIT
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlSndL2MeasCfm(transId(%ld))\n", measEvtCb->transId));
#else
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlSndL2MeasCfm(transId(%d))\n", measEvtCb->transId));
#endif
   
   /* Clean up the RB data structures */
   /* kw006.201 CR:ccpu00120058, reduced code complexity */
   measCb = &measEvtCb->measCb;
   kwUtlResetL2MeasInKwRb(measCb);

#ifdef LTE_RLC_R9
   /* kw006.201 CR:ccpu00120058, reduced code complexity */
   /*Send notification to MAC to stop Ul Ip measurement for given LChs*/
   if( ROK != kwUtlNotifyMacUlIp(measCb, FALSE, NULLP, NULLP) )
   {
      RETVALUE(RFAILED);
   }
#endif /* LTE_RLC_R9 */
   
   cmMemset((U8*)&measCfmEvt, 0, sizeof(KwL2MeasCfmEvt));
   measCfmEvt.transId = measEvtCb->transId;
   measCfmEvt.numCfm = 0;

   measCb = &measEvtCb->measCb;
   measCfmEvt.measType = measCb->measType;
   measCfmEvt.status.status = LCM_PRIM_OK;
   measCfmEvt.status.reason = LCM_REASON_NOT_APPL;

   if((measCb->measType & LKW_L2MEAS_DL_IP) ||
      (measCb->measType & LKW_L2MEAS_UL_IP) )
   {
#ifdef LTE_RLC_R9
      measCfmEvt.ueId = measCb->ueId;
      measCfmEvt.cellId = measCb->cellId;
      for(qciIdx = 0; qciIdx < measCb->numQci; qciIdx++)
      {
         measCfmEvt.measCfm[measCfmEvt.numCfm].qci = measCb->qci[qciIdx];
         if(measCb->measType & LKW_L2MEAS_DL_IP)
         {
            dlDataVol = measCb->measData[measCb->qci[qciIdx]].dlIpThruput.volSummation;
            dlTime = measCb->measData[measCb->qci[qciIdx]].dlIpThruput.timeSummation;
            if(0 == dlTime)
            {
               measCfmEvt.measCfm[measCfmEvt.numCfm].val.ipThrput.dlIpThPut = 0;
            }
            else
            {
               measCfmEvt.measCfm[measCfmEvt.numCfm].val.ipThrput.dlIpThPut  =
               (dlDataVol / dlTime);
            }
         }
         if(measCb->measType & LKW_L2MEAS_UL_IP)
         {
            ulDataVol = measCb->measData[measCb->qci[qciIdx]].ulIpThruput.volSummation;
            ulTime = measCb->measData[measCb->qci[qciIdx]].ulIpThruput.timeSummation;
            if(0 == ulTime)
            {
               measCfmEvt.measCfm[measCfmEvt.numCfm].val.ipThrput.ulIpThPut = 0;
            }
            else
            {
               measCfmEvt.measCfm[measCfmEvt.numCfm].val.ipThrput.ulIpThPut  =
               (ulDataVol / ulTime);
            }
         }
         measCfmEvt.numCfm++;
      }
#else
      KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_ERROR),
          (_kwPBuf, "kwUtlSndL2MeasCfm:LTE_RLC_R9 is OFF but IP measurement bit is ON\n"));
#endif
   }
   else
   {
      for(qciIdx = 0; qciIdx < measCb->numQci; qciIdx++)
      {
         measCfmEvt.measCfm[measCfmEvt.numCfm].qci = measCb->qci[qciIdx];
         if(measCb->measType & LKW_L2MEAS_UU_LOSS)
         {
            dLoss = measCb->measData[measCb->qci[qciIdx]].uuLoss.dLoss;
            posPkts = measCb->measData[measCb->qci[qciIdx]].uuLoss.posPkts;
            if(((posPkts + dLoss) != 0))
            {
               measCfmEvt.measCfm[measCfmEvt.numCfm].val.nonIpThrput.uuLoss  =
               ((dLoss  * 1000000) / (posPkts + dLoss));
            }
         }
         if(measCb->measType & LKW_L2MEAS_ACT_UE)
         { 
            measCfmEvt.measCfm[measCfmEvt.numCfm].val.nonIpThrput.numActUe  =
            measCb->measData[measCb->qci[qciIdx]].actUe.numActvUe /
            measCb->measData[measCb->qci[qciIdx]].actUe.sampOc;
         }
         measCfmEvt.numCfm++;
      }
   }
   kwCb.kwL2Cb.kwL2EvtCb[measEvtCb->cbIdx] = NULLP;
   kwCb.kwL2Cb.kwNumMeas--;
   KW_FREE(measEvtCb, sizeof(KwL2MeasEvtCb));
   KwMiLkwL2MeasCfm(&kwCb.genCfg.lmPst, &measCfmEvt);
   RETVALUE(ROK);
} /* kwUtlSndL2MeasCfm */
/**
 *
 * @brief Handler for Sending Negative confirm .
 *
 *
  @b Description
 *        This function is called when the l2 measurement cannot be started
 *        This function sends  negative confirm for all the requests
 *
 *  @param[in] measReqEvt    Measurement Req Structure
 *
 *
 *  @return  S16
 *      -# ROK
 */

#ifdef ANSI
PUBLIC S16 kwUtlSndL2MeasNCfm
(
KwL2MeasReqEvt *measReqEvt,
KwL2MeasCfmEvt *measCfmEvt
)
#else
PUBLIC S16 kwUtlSndL2MeasNCfm(measReqEvt, measCfmEvt)
KwL2MeasReqEvt *measReqEvt;
KwL2MeasCfmEvt *measCfmEvt;
#endif
{
   TRC3(kwUtlSndL2MeasNCfm)
   /* kw006.201 ccpu00120058 removed 64 bit compilation warning */
#ifndef ALIGN_64BIT
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlSndL2MeasNCfm(transId(%ld))\n", measReqEvt->transId));
#else
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlSndL2MeasNCfm(transId(%d))\n", measReqEvt->transId));
#endif
   KwMiLkwL2MeasCfm(&kwCb.genCfg.lmPst, measCfmEvt);
   RETVALUE(ROK);
} /* kwUtlSndL2MeasNCfm */
/**
 *
 * @brief Handler for sending Sdu Disc Cfm 
 *
 *
 * @b Description
 *        This function is called when the RLC sends a  DiscSduCfm.
 *        differentiates between seding on the RGU interface and calling 
 *        the respective pdcp function.
 *
 *  @param[in] kwRbCb      RLC RbCb 
 *  @param[in] sduId       SDU Id of the SDU that was discarded.
 *
 *
 *  @return  S16
 *      -# ROK
 */

#ifdef ANSI
PUBLIC S16 kwUtlSndDiscSduCfm
(
KwRbCb *kwRbCb,
U32    sduId
)
#else
PUBLIC S16 kwUtlSndDiscSduCfm(kwRbCb, sduId)
KwRbCb *kwRbCb;
U32    sduId;
#endif
{
#ifdef KW_PDCP
   PjRbCb *pjRbCb;
#else
   KwuDiscSduInfo  *discCfmInfo;
   KwKwuSapCb      *kwuSap = NULLP;
#endif 

   TRC3(kwUtlSndDiscSduCfm)

   /* kw006.201 ccpu00120058 removed 64 bit compilation warning */
#ifndef ALIGN_64BIT
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlSndDiscSduCfm(sduId(%ld))\n", sduId));
#else
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlSndDiscSduCfm(sduId(%d))\n", sduId));
#endif
#ifdef KW_PDCP
   if ( kwRbCb->pjRbCb != NULLP )
   {
       pjRbCb = kwRbCb->pjRbCb;
   }
   else
   {
      KWLOGERROR(ERRCLS_ADD_RES, EKWXXX, (ErrVal)0,
            "kwUtlSndDiscSduCfm: PDCP CB is Null. Cannot send a Disc cfm \n");
      RETVALUE(RFAILED);
   }
   pjLimDiscSduCfm(pjRbCb, sduId);
#else
   discCfmInfo = NULLP;
   KW_ALLOC(discCfmInfo, sizeof(KwuDiscSduInfo));
#if (ERRCLASS & ERRCLS_ADD_RES)
   if ( discCfmInfo == NULLP )
   {
      KWLOGERROR(ERRCLS_ADD_RES, EKWXXX, (ErrVal)0,
            "kwUtlSndDiscSduCfm: Allocation failed for discCfmInfo \n");
      RETVALUE(RFAILED);
   }
#endif
   /* Fill datCfm Info */
   KW_MEM_CPY(&discCfmInfo->rlcId, &kwRbCb->rlcId, sizeof(CmLteRlcId));
   discCfmInfo->sduId = sduId;
   kwuSap = kwCb.kwuSap + KW_UI_PDCP;
   KwUiKwuDiscSduCfm(&kwuSap->pst, kwuSap->suId, discCfmInfo);
#endif /* KW_PDCP */
   
   RETVALUE(ROK);
} /* kwUtlSndDiscSduCfm */

/**
 *
 * @brief Handler for Creating and Managing the Sdu Sn Map 
 *
 *
 * @b Description
 *        This function is called when the RLC sends a Data Mesage.
 *        It creates and updates the SDU SN Map structure.
 *        This is used only for UuLoss and Dl Delay L2 Measurements.
 *
 *  @param[in] kwRbCb      RLC RbCb 
 *  @param[in] sdu         KwSdu
 *  @param[in] kwDatReq    DDatReq to be sent to MAC
 *  @param[in] lastSegSent Whether the SDU has been completely sent.
 *
 *
 *  @return  S16
 *      -# ROK
 */

#ifdef ANSI
PUBLIC S16 kwUtlUpdSduSnMap
(
KwRbCb *kwRbCb,
KwSdu  *sdu,
KwDatReq *kwDatReq,
Bool   lastSegSent
)
#else
PUBLIC S16 kwUtlUpdSduSnMap(kwRbCb, sdu, kwDatReq, lastSegSent)
KwRbCb *kwRbCb;
KwSdu  *sdu;
KwDatReq *kwDatReq;
Bool   lastSegSent;
#endif
{
   U16 sn;
   KwSnSduMap *snSduMap;
   KwTbSnMap  *curTbSnMap;
   TRC3(kwUtlUpdSduSnMap)

   /* kw006.201 ccpu00120058 removed 64 bit compilation warning */
#ifndef ALIGN_64BIT
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlUpdSduSnMap(kwRbCb(%d, %d), sduId(%ld))\n", 
           kwRbCb->rlcId.rbId, kwRbCb->rlcId.rbType, sdu->mode.am.sduId));
#else
   KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL), 
          (_kwPBuf, "kwUtlUpdSduSnMap(kwRbCb(%d, %d), sduId(%d))\n", 
           kwRbCb->rlcId.rbId, kwRbCb->rlcId.rbType, sdu->mode.am.sduId));
#endif

   if(kwRbCb->rlcId.rbType == CM_LTE_SRB)
      RETVALUE(ROK);

#ifndef LTE_RLC_R9
   if(!(kwRbCb->rbL2Cb.measOn & 
       (LKW_L2MEAS_UU_LOSS | LKW_L2MEAS_DL_DELAY)))
#else
   if(!(kwRbCb->rbL2Cb.measOn & 
       (LKW_L2MEAS_UU_LOSS | LKW_L2MEAS_DL_DELAY | LKW_L2MEAS_DL_IP)))
#endif
      RETVALUE(ROK);

   /* In the case of UM and UuLoss, if we have already received a
    * segment as failed, we have to clean up this pointer. We wait
    * till all segments are sent before cleaning up the pointer since
    * we dont want a dangling pointer situation  */
   if((lastSegSent == TRUE) &&
      (kwRbCb->mode  == CM_LTE_MODE_UM) &&
      (kwRbCb->rbL2Cb.measOn & LKW_L2MEAS_UU_LOSS) &&
      (sdu->snMap != NULLP) &&
      (sdu->snMap->failMarked == TRUE))
   {
      cmLListDelFrm(&(kwRbCb->sduSnMapQ), &(sdu->snMap->lstEnt));
      KW_FREE(sdu->snMap, sizeof(KwSduSnMap));
      RETVALUE(ROK);
   }

   if(sdu->snMap == NULLP)                              
   {                                                     
      KW_ALLOC(sdu->snMap, sizeof(KwSduSnMap));         
      sdu->snMap->lstEnt.node = (PTR)sdu->snMap;       
      cmLListAdd2Tail(&(kwRbCb->sduSnMapQ),   
            &(sdu->snMap->lstEnt));                     

      if(kwRbCb->mode == CM_LTE_MODE_UM)
         sdu->snMap->sduId =  sdu->mode.um.sduId;         
      else
         sdu->snMap->sduId =  sdu->mode.am.sduId;         

   }                                                     
   sdu->snMap->fullySent = lastSegSent;


   if(kwRbCb->mode == CM_LTE_MODE_UM)
      sn = kwRbCb->m.um.umDl.vtUs;   
   else
      sn = kwRbCb->m.am.amDl.vtS;   

   /* Add the new SN to the SDUs, sn List*/
   sdu->snMap->snList[sdu->snMap->numSn++] = sn;   

   /* Increment data request sent for this sdu , we will compare this value against
    * number of response(harq ack ) received before deleting this entry 
    * */
   sdu->snMap->reqSent++;
   curTbSnMap = kwCb.kwL2Cb.curTbSnMap;

   if((curTbSnMap->numSn == 0) ||
      (curTbSnMap->snSduMap[curTbSnMap->numSn -1].sn != sn) ||
      (curTbSnMap->snSduMap[curTbSnMap->numSn -1].lChId != 
                        kwRbCb->lch[0].lChId))
   {
      snSduMap        = &curTbSnMap->snSduMap[curTbSnMap->numSn];
      snSduMap->sn    = sn;
      snSduMap->lChId = kwRbCb->lch[0].lChId;
      kwDatReq->lchMapInfo.snList[curTbSnMap->numSn] = sn;
      curTbSnMap->numSn++;
   }
   else
   {
      snSduMap   = &curTbSnMap->snSduMap[curTbSnMap->numSn - 1];
      kwDatReq->lchMapInfo.snList[curTbSnMap->numSn - 1] = sn;
   }

   /* Create and update the SN structure */
   snSduMap->sduList[snSduMap->numSdu++] = sdu->snMap;

   RETVALUE(ROK);
} /* kwUtlUpdSduSnMap */

/**
 * @brief  Validates the measurement request parameters. 
 *
 * @details
 *
 *     Function :kwUtlValidateL2Meas 
 *
 *  @param[in]  measReqEvt L2 measurement request received from layer manager.
 *  @param[out] measCfmEvt L2 measurement confirm to be prepared.
 *  @param[out] lChId      List of LCh for the given Ue corresponding to QCIs
                           given in measurement request.
 *  @param[out] numLCh     Number of LCh in array lChId.
 **/
#ifdef LTE_RLC_R9
#ifdef ANSI
PUBLIC S16 kwUtlValidateL2Meas
(
KwL2MeasReqEvt *measReqEvt,
KwL2MeasCfmEvt *measCfmEvt,
CmLteLcId      *lChId,
U8             *numLCh
)
#else
PUBLIC S16 kwUtlValidateL2Meas(measReqEvt, measCfmEvt, lChId, numLCh)
KwL2MeasReqEvt *measReqEvt;
KwL2MeasCfmEvt *measCfmEvt;
CmLteLcId      *lChId;
U8             *numLCh;
#endif
#else /* LTE_RLC_R9 */
#ifdef ANSI
PUBLIC S16 kwUtlValidateL2Meas
(
KwL2MeasReqEvt *measReqEvt,
KwL2MeasCfmEvt * measCfmEvt
)
#else
PUBLIC S16 kwUtlValidateL2Meas(measReqEvt, measCfmEvt)
KwL2MeasReqEvt *measReqEvt;
KwL2MeasCfmEvt *measCfmEvt;
#endif
#endif /* LTE_RLC_R9 */
{
   U8      measType;
   S16     ret;
   U8      qciIdx;
   U8      qci;
   U8      idx;
   U8      *qciVal;
   U8      numQci;
   KwRbCb  *rbCb;
#ifdef LTE_RLC_R9
   KwUeCb     *ueCb;
   RbCb       **rbCbLst;
   U8         rbIdx;
   U8         lsbNibble = 0;
   U8         msbNibble = 0;
#endif /* LTE_RLC_R9 */


   TRC3(kwUtlValidateL2Meas)
   
   idx = 0;
   rbCb = NULLP;
   ret = ROK;
   measType = measReqEvt->measReq.measType;
   /* Check for the range of measType */
   /* LKW_L2MEAS_DL_IP+ LKW_L2MEAS_UL_IP = 0x0030*/
   if((measType == 0x00) ||
       measType > 0x30)
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_MEASTYPE;
      RETVALUE(RFAILED);
   }
#ifndef LTE_RLC_R9
   /*If LTE_RLC_R9 is not defined, then DL/UL ip throughput can not *
    *be sent in measurement request.                                */
   if((measType & LKW_L2MEAS_DL_IP ) ||
      (measType & LKW_L2MEAS_UL_IP))
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_MEASTYPE;
      RETVALUE(RFAILED);
   }
#else
   /*If LTE_RLC_R9 is defined, then user can either request for Active UE,*
    *Dl delay, Dl discard, Uu Loss OR Dl ip throughput, Ul ip throughput. */
   lsbNibble = measType & 0x0F;
   msbNibble = measType & 0xF0;

   if( (lsbNibble != 0) && (msbNibble != 0) )
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_MEASTYPE;
      RETVALUE(RFAILED);
   }
#endif
   /* Check for total maximum number of Measurement Control Block */
   if(kwCb.kwL2Cb.kwNumMeas >= LKW_MAX_L2MEAS )
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_EXCEED_NUMMEAS;
      RETVALUE(RFAILED);
   }
#ifdef LTE_RLC_R9
   if(((measType & LKW_L2MEAS_DL_IP) ||
       (measType & LKW_L2MEAS_UL_IP)))
   {
      /* Check for number of QCIs in the measurement request */
      if((measReqEvt->measReq.val.ipThMeas.numQci > LKW_MAX_QCI) ||
         (measReqEvt->measReq.val.ipThMeas.numQci == 0))
      {
         measCfmEvt->numCfm = 0;
         measCfmEvt->transId = measReqEvt->transId;
         measCfmEvt->measType = measType;
         measCfmEvt->status.status = LCM_PRIM_NOK;
         measCfmEvt->status.reason = LKW_CAUSE_INVALID_NUMQCI;
         measCfmEvt->ueId = measReqEvt->measReq.val.ipThMeas.ueId;
         measCfmEvt->cellId = measReqEvt->measReq.val.ipThMeas.cellId;
         RETVALUE(RFAILED);
      }
   }
   else if((measReqEvt->measReq.val.nonIpThMeas.numQci > LKW_MAX_QCI) ||
           (measReqEvt->measReq.val.nonIpThMeas.numQci == 0))
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_NUMQCI;
      RETVALUE(RFAILED);
   }
#else
   if((measReqEvt->measReq.val.nonIpThMeas.numQci > LKW_MAX_QCI) ||
       (measReqEvt->measReq.val.nonIpThMeas.numQci == 0))
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_NUMQCI;
      RETVALUE(RFAILED);
   }
#endif
   /* Check that number of samples should be a non-zero value */
   if(((measType & LKW_L2MEAS_ACT_UE) &&
      (measReqEvt->measReq.val.nonIpThMeas.numSamples == 0)))
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_ZERO_NUMSAM;
      RETVALUE(RFAILED);
   }
   /* Check that measurement period  should be completely divisible *
    * number of sample.                                             */
   if(((measType & LKW_L2MEAS_ACT_UE) &&
      ((measReqEvt->measPeriod % 
        measReqEvt->measReq.val.nonIpThMeas.numSamples) != 0)))
   {
      measCfmEvt->numCfm = 0;
      measCfmEvt->transId = measReqEvt->transId;
      measCfmEvt->measType = measType;
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_NUMSAM;
      RETVALUE(RFAILED);
   }
#ifdef LTE_RLC_R9
   if(((measType & LKW_L2MEAS_DL_IP) ||
       (measType & LKW_L2MEAS_UL_IP)))
   {
      /* Check whether UE is valid or not */
      if (kwDbmFetchUeCb(measReqEvt->measReq.val.ipThMeas.ueId, 
                         measReqEvt->measReq.val.ipThMeas.cellId, &ueCb) != ROK)
      {
#ifdef DEBUGP
         KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_ERROR), (_kwPBuf,
                  "kwUtlValidateL2Meas: kwDbmFetchUeCb Failed.\n"));
#endif
         measCfmEvt->numCfm  = 0;
         measCfmEvt->transId = measReqEvt->transId;
         measCfmEvt->measType = measType;
         measCfmEvt->status.status = LCM_PRIM_NOK;
         measCfmEvt->status.reason = LKW_CAUSE_INVALID_UE;
         measCfmEvt->ueId = measReqEvt->measReq.val.ipThMeas.ueId;
         measCfmEvt->cellId = measReqEvt->measReq.val.ipThMeas.cellId;
         RETVALUE(RFAILED);
      }
      numQci = measReqEvt->measReq.val.ipThMeas.numQci;
      qciVal = measReqEvt->measReq.val.ipThMeas.qci;
      rbCbLst = ueCb->drbCb;
   }
   else
#endif
   {
      numQci = measReqEvt->measReq.val.nonIpThMeas.numQci;
      qciVal = measReqEvt->measReq.val.nonIpThMeas.qci;
   }
   /* Check whether qci is configured or not */
   for(qciIdx = 0; qciIdx < numQci; qciIdx++)
   {
      qci = qciVal[qciIdx];
      ret = cmHashListFind(&(kwCb.kwL2Cb.qciHlCp), 
            (U8 *)&qci, (U16)sizeof(qci), 0, (PTR *)&rbCb);
      if(ret != ROK)
      {
         measCfmEvt->measCfm[measCfmEvt->numCfm].qci = qci;
         measCfmEvt->numCfm++;
      }
   }
   if(measCfmEvt->numCfm > 0)
   {
      measCfmEvt->status.status = LCM_PRIM_NOK;
      measCfmEvt->status.reason = LKW_CAUSE_INVALID_QCI;
      measCfmEvt->measType = measType;
      measCfmEvt->transId = measReqEvt->transId;
#ifdef LTE_RLC_R9
     if((measType & LKW_L2MEAS_DL_IP) ||
        (measType & LKW_L2MEAS_UL_IP))
     {
        measCfmEvt->ueId = measReqEvt->measReq.val.ipThMeas.ueId;
        measCfmEvt->cellId = measReqEvt->measReq.val.ipThMeas.cellId;
     }
#endif
      RETVALUE(RFAILED);
   }
#ifdef LTE_RLC_R9
   if((measType & LKW_L2MEAS_DL_IP) ||
      (measType & LKW_L2MEAS_UL_IP))
   {
      for(qciIdx = 0; qciIdx < numQci; qciIdx++)
      {
         qci = qciVal[qciIdx];
         for(rbIdx = 0; rbIdx < KW_MAX_DRB_PER_UE; rbIdx++)
         {
            rbCb = &rbCbLst[rbIdx]->kwRbCb;
            if(rbCb)  
            {
               if((rbCb->qci == qci) && 
                 (rbCb->rbL2Cb.measOn & measType))
               {
                  /* measurement is already ongoing */
                  measCfmEvt->status.status = LCM_PRIM_NOK;
                  measCfmEvt->status.reason = LKW_CAUSE_MEAS_ALREADY_ENA;
                  measCfmEvt->measCfm[measCfmEvt->numCfm].qci = qci;
                  measCfmEvt->measType = measType;
                  measCfmEvt->ueId = measReqEvt->measReq.val.ipThMeas.ueId;
                  measCfmEvt->cellId = measReqEvt->measReq.val.ipThMeas.cellId;
                  measCfmEvt->numCfm++;
                  break;
               }
               /*This lChId calculation is for sending the L2MUlThroughput *
                *Measurement Request to MAC only during ul ip measurement. */
               if((measType & LKW_L2MEAS_UL_IP) && (rbCb->qci == qci))
               {
                  switch(rbCb->mode)
                  {
                     case CM_LTE_MODE_AM:
                     {
                        /*In AM, lch idx 1 is for UL logical channel*/
                        lChId[(*numLCh)++] = rbCb->lch[1].lChId;
                        break;
                     }
                     case CM_LTE_MODE_UM:
                     case CM_LTE_MODE_TM:
                     {
                        lChId[(*numLCh)++] = rbCb->lch[0].lChId;
                        break;
                     }
                  } /* Switch ends */
               } /* if((measType & LKW_L2MEAS_UL_IP) && (rbCb->qci == qci)) ends */
            } /* if(rbCb) ends */
         } /* for(rbIdx) ends */
      } /* for(qciIdx) ends */
   }
   else
#endif
   {
      for(qciIdx = 0; qciIdx < numQci; qciIdx++)
      {
         if(kwCb.kwL2Cb.measOn[qci] & measReqEvt->measReq.measType)
         {
            /* measurement is already ongoing */
            measCfmEvt->status.status = LCM_PRIM_NOK;
            measCfmEvt->status.reason = LKW_CAUSE_MEAS_ALREADY_ENA;
            measCfmEvt->measCfm[measCfmEvt->numCfm].qci = qci;
            measCfmEvt->measType = measType;
            measCfmEvt->numCfm++;
         }
      }
   }
   if(measCfmEvt->numCfm > 0)
   {
      measCfmEvt->transId = measReqEvt->transId;
      RETVALUE(RFAILED);
   }

   RETVALUE(ROK);
}/* kwUtlValidateL2Meas */

/**
 *
 * @brief Handler for Processing TbSnMap
 *
 *
 * @b Description
 *        This function is called from kwUtlProcHarqInd.
 *        This is used only for UuLoss and Dl Delay.
 *
 *  @param[in] snSduMap KwSnSduMap.
 *  @param[in] staInd   Harq status Indication message received from MAC.
 *  @param[in] kwRbCb   KwRbCb for which data was present in the DDatReq
                        corresponding to the received TbId.
 *  @param[in] tbIdx    TB index, 0 for SISO and 0,1 for MIMO.
 *  @param[in] tbSnIdx  SN index which ranges from 0 to < number of SNs in
 *                      KwTbSnMap.
 *
 *
 *  @return  S16
 *      -# ROK
 *       # RFAILED
 */
#ifdef ANSI
PRIVATE S16 kwUtlProcSnMap
(
KwSnSduMap       *snSduMap, 
RguHarqStatusInd *staInd, 
KwRbCb           *kwRbCb,
U8               tbIdx,
U8               tbSnIdx
)
#else
PRIVATE S16 kwUtlProcSnMap(snSduMap, staInd, kwRbCb, tbIdx, tbSnIdx)
KwSnSduMap       *snSduMap;
RguHarqStatusInd *staInd;
KwRbCb           *kwRbCb;
U8               tbIdx;
U8               tbSnIdx;
#endif
{
   U8           sduIdx, snIdx1, snIdx2;
   KwSduSnMap   *sduSnMap;         /* List of SN that the SDU is split into */
#ifndef KW_PDCP
   KwuDatAckInfo *datAckInfo;        /* Data ack info */
   KwKwuSapCb    *kwuSap = NULLP;    /* KWU SAP Information */
#endif
   TRC3(kwUtlProcSnMap);

   for(sduIdx = 0; sduIdx < snSduMap->numSdu; sduIdx++)
   {
      sduSnMap = NULLP;
      sduSnMap  = snSduMap->sduList[sduIdx];
      if(staInd->status[tbIdx] == FALSE) /* If status is HARQ-NACK */
      {
         if(sduSnMap)
         {
            /* if we have not already marked this SDU as failed, we do so now */
            sduSnMap->failMarked = TRUE;
            if(kwRbCb->rbL2Cb.measOn & LKW_L2MEAS_UU_LOSS)
            {
               kwRbCb->rbL2Cb.l2Sts[KW_L2MEAS_UU_LOSS]->uuLoss.dLoss++;
            }
            sduSnMap->rspRcvd++;
         }
      }
      else /* if status == TRUE */
      {
         if(sduSnMap)
         {
            sduSnMap->rspRcvd++;
            /* If the SDU has been fully sent and also marked as failure, remove it */
            if(!sduSnMap->failMarked)
            {
               snIdx2 = 0;
               for(snIdx1 = 0; snIdx1 < sduSnMap->numSn; snIdx1++)
               {
                  for(snIdx2 = 0; snIdx2 < RGU_MAX_PDU; snIdx2++)
                  {
                     if(sduSnMap->snList[snIdx1] == 
                        staInd->rguSnMapInfo[tbIdx]->lchMap[tbSnIdx].snList[snIdx2])
                     {
                         sduSnMap->harqAck++;
                         break;
                     }
                  }
               }
               if((sduSnMap->fullySent == TRUE) && 
                  (sduSnMap->harqAck == sduSnMap->numSn))
               {
                  /* Update total number positively acknowldged packets */

                  if(kwRbCb->rbL2Cb.measOn & LKW_L2MEAS_UU_LOSS)
                  {
                     kwRbCb->rbL2Cb.l2Sts[KW_L2MEAS_UU_LOSS]->uuLoss.posPkts++;
                  }
                  /* Send the data Ack indication to pdcp */
#ifdef KW_PDCP
                  pjLimDatAckInd(kwRbCb->pjRbCb, sduSnMap->sduId);
#endif
#ifndef KW_PDCP
                  if(kwRbCb->rbL2Cb.measOn & LKW_L2MEAS_DL_DELAY)
                  {
                     kwuSap = kwCb.kwuSap + KW_UI_PDCP;
                     KW_ALLOC(datAckInfo, sizeof(KwuDatAckInfo));
#if (ERRCLASS & ERRCLS_ADD_RES )
                     if (datAckInfo == NULLP  )
                     {
                        KWLOGERROR(ERRCLS_ADD_RES, EKW225, (ErrVal) RFAILED,
                             "KW_ALLOC failed for datAckInfo .");
                        RETVALUE(RFAILED);
                     }
#endif /* ERRCLASS & ERRCLS_ADD_RES */
                     KW_MEM_CPY(&(datAckInfo->rlcId),&(kwRbCb->rlcId),
                            sizeof(CmLteRlcId));
                     datAckInfo->sduId = sduSnMap->sduId;
                     KwUiKwuDatAckInd(&kwuSap->pst, kwuSap->suId, datAckInfo);
                  }/* end of if DL_DELAY */
#endif
               }
            }/* end of else */
         }/* end of if(sduSnMap) */
      }/* end of else */
      /* Delete this sduSnMap entry when response is received for all the request */
      if((sduSnMap->rspRcvd == sduSnMap->reqSent) &&
         (sduSnMap->fullySent == TRUE))
      {
         cmLListDelFrm(&kwRbCb->sduSnMapQ, &sduSnMap->lstEnt);
         KW_FREE(sduSnMap, sizeof(KwSduSnMap));
      }
   }/* End of for */
   RETVALUE(ROK);
}

/**
 *
 * @brief Handler for Processing harq status indication
 *
 *
 * @b Description
 *        This function is called when the MAC sends a harq ind Mesage.
 *        This is used only for UuLoss and Dl Delay and DL Ipthoughput
 *        L2 Measurements.
 *
 *  @param[in] staInd Harq status indication received from MAC.
 *  @param[in] ueCb   UeCb corresponding to the Tb Id.
 *  @param[in] tbIdx  TB index, 0 for SISO and 0,1 for MIMO.
 *
 *
 *  @return  S16
 *      -# ROK
 */

#ifdef ANSI
PUBLIC S16 kwUtlProcHarqInd
(
RguHarqStatusInd *staInd,
KwUeCb           *ueCb,
U8               tbIdx
)
#else
PUBLIC S16 kwUtlProcHarqInd(staInd, ueCb, tbIdx)
RguHarqStatusInd *staInd;
KwUeCb           *ueCb;
U8               tbIdx;
#endif
{
   U8            tbSnIdx;
   KwRbCb       *kwRbCb;           /* KW Control Block */
   KwTbSnMap    *tbSnMap;          /* Tb SnMap                         */
   KwSnSduMap   *snSduMap;         /* List of SDUs that the SN maps to */
#ifdef LTE_RLC_R9
   /*kw005.201 Code added for DL IP thruput measurement*/
   EpcTime       t1;		   /* Holds time stamp T1 */
   KwL2MeasIpThruput *l2MeasIpThruput = NULLP;
#endif
   TRC3(kwUtlProcHarqInd)

   if(staInd->rguSnMapInfo[tbIdx] == NULLP)
   {
      RETVALUE(ROK);
   }
   if(cmHashListFind(&(kwCb.kwL2Cb.tbHlCp), (U8 *) &staInd->rguSnMapInfo[tbIdx]->tbId, 
                  sizeof(staInd->rguSnMapInfo[tbIdx]->tbId),  0, (PTR *)&tbSnMap) != ROK)
   {
      RETVALUE(ROK);
   }

   for(tbSnIdx = 0; tbSnIdx < tbSnMap->numSn; tbSnIdx++)
   {
      snSduMap = &tbSnMap->snSduMap[tbSnIdx];
      if((kwRbCb = ueCb->lCh[snSduMap->lChId - 1].dlRbCb) == NULLP)
      {
            continue;
      }
      /* Process the TbSnMap to calculate Dl delay and Uu Loss */
      /* kw006.201 CR:ccpu00120058, reduced code complexity */
      if(ROK != kwUtlProcSnMap(snSduMap, staInd, kwRbCb, tbIdx, tbSnIdx))
      {
         RETVALUE(RFAILED);
      }

#ifdef LTE_RLC_R9
      /*If burst is splitted, it means that the corresponding data volume was*
       *measured and count was incrementd during Tx.                         */
      if(snSduMap->isBurstSplitted)
      {
         /*Check for Ack/Nack*/
         if(TRUE == staInd->status[tbIdx])  /*If status is HARQ-ACK*/
         {
            l2MeasIpThruput = &kwRbCb->l2MeasIpThruput;
            if(l2MeasIpThruput->count > 0)
            {
               /*Decrement the count since one ACK has been received from MAC*/
               l2MeasIpThruput->count--;

               /*Wait for the burst to get completed for calculating the throughput*/
               if( (0 == l2MeasIpThruput->count) && 
                 (KW_DL_IPTHRU_BURST_COMPLETED == l2MeasIpThruput->dlIpThrputSt) )
               {
                  /*Take T1 time stamp.*/
                  SGetEpcTime(&t1);
                  
                  /*Update the l2Sts structure for calculating throughput*/
                  kwRbCb->rbL2Cb.l2Sts[KW_L2MEAS_DL_IP]->dlIpThruput.volSummation
                  += l2MeasIpThruput->dataVol;
                  kwRbCb->rbL2Cb.l2Sts[KW_L2MEAS_DL_IP]->dlIpThruput.timeSummation
                  += t1 - l2MeasIpThruput->timeT2;

                  /*Reset the IP throughput related parameters. Now next burst*
                   *can be taken up if it is splitting across TTIs.           */
                  kwUtlResetKwRbL2Meas(kwRbCb);
               }

               /*Get the temporary T1 time stamp if the burst is still continuing*
                *and it has been ACK-ed till the point it has been sent on air.  */
               if((0 == l2MeasIpThruput->count) && 
                 ( (KW_DL_IPTHRU_BURST_STARTED == l2MeasIpThruput->dlIpThrputSt) || 
                 (KW_DL_IPTHRU_BURST_CONTINUE == l2MeasIpThruput->dlIpThrputSt) ) )
               {
                  /*Take temporary T1 time stamp.*/
                  SGetEpcTime(&t1);

                  l2MeasIpThruput->tempTimeT1 = t1;
               }
            }
            else
            {
#ifdef DEBUGP
               KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_ERROR | KW_DBGMASK_UL),
               (_kwPBuf, "kwUtlProcHarqInd: Count can not be zero if burst is split across TTI\n"));
#endif      
            } 
         } /*End of if(ACK == staInd->status[tbIdx])*/
         else
         {
#ifdef DEBUGP
            KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL | KW_DBGMASK_UL),
            (_kwPBuf, "kwUtlProcHarqInd: Harq status is NACK for this burst\n"));
#endif      
         }
      } /*End of if(snSduMap->isBurstSplitted)*/
      else
      {
#ifdef DEBUGP
         KWDBGP((KW_DBGMASK_DUT | KW_DBGMASK_DETAIL | KW_DBGMASK_UL),
          (_kwPBuf, "kwUtlProcHarqInd: Burst is not split across TTI\n"));
#endif      
      }
#endif /* LTE_RLC_R9 */
   }/* End of  for */
   
   /* Delete entry from hash list */
   cmHashListDelete(&(kwCb.kwL2Cb.tbHlCp), (PTR)tbSnMap);
   KW_FREE(tbSnMap,sizeof(KwTbSnMap));  

   KW_FREE(staInd->rguSnMapInfo[tbIdx],sizeof(RguSnMapInfo));  

   RETVALUE(ROK);
}/* end of  kwUtlProcHarqInd */ 


#ifdef LTE_RLC_R9
/**
 *
 * @brief Function for reseting the KwRbCb members wrt DL IP throughput
 *
 *
 * @b Description
 *        This function is called when dlIpThrputState becomes RESET.
 *
 *  @param[in] rbCb  KwRbCb for which L2 measurement parameters to be reset.
 *
 *
 *  @return  Void
 * 
 */
#ifdef ANSI
PUBLIC Void kwUtlResetKwRbL2Meas
(
KwRbCb	*rbCb
)
#else
PUBLIC Void kwUtlResetKwRbL2Meas(rbCb)
KwRbCb	*rbCb;
#endif
{
   KwL2MeasIpThruput *l2MeasIpThruput = &rbCb->l2MeasIpThruput;

   l2MeasIpThruput->timeT2 = 0;
   l2MeasIpThruput->tempTimeT1 = 0;
   l2MeasIpThruput->dataVol = 0;
   l2MeasIpThruput->count = 0;
   /*prevTbSnMap is freed either in kwUtlProcHarqInd or in kwUtlSndToLi. So*
    *it should not be freed here.                                          */
   l2MeasIpThruput->prevTbSnMap = NULLP;
   l2MeasIpThruput->dlIpThrputSt = KW_DL_IPTHRU_RESET;
}
#endif /* LTE_RLC_R9 */

/**
 *
 * @brief Handler for storing address of MeasData in rbCb at right index
 *
 *
 * @b Description
 *        This function is called when LM sends measReq message to RLC.
 *
 *  @param[in] measData It holds the pointer to KwL2Cntr where all the 
                        measurement calculations are dumped.
 *  @param[in] rbL2Cb   KwL2MeasRbCb pointer for a particular KwRbCb.
 *  @param[in] measType Measurement type received from layer manager.
 *
 *
 *  @return  Void
 */
#ifdef ANSI
PRIVATE Void kwUtlPlcMeasDatInL2Sts
(
KwL2Cntr       *measData, 
KwL2MeasRbCb   *rbL2Cb,
U8             measType
)
#else
PRIVATE Void kwUtlPlcMeasDatInL2Sts(measData, rbL2Cb, measType)
KwL2Cntr       *measData; 
KwL2MeasRbCb   *rbL2Cb;
U8             measType;
#endif
{
   TRC3(kwUtlPlcMeasDatInL2Sts)
   
   /* We should check the number of measType in the request. This can be done 
    * by looking at each bit in the measType. Also store the measData in the 
    * correct index of l2Sts in RbCb.
    * */

    if(measType & LKW_L2MEAS_ACT_UE)
    {
         rbL2Cb->l2Sts[KW_L2MEAS_ACT_UE] = measData;
    }
    if(measType & LKW_L2MEAS_UU_LOSS)
    {
         rbL2Cb->l2Sts[KW_L2MEAS_UU_LOSS] = measData;
    }
    if(measType & LKW_L2MEAS_DL_IP )
    {
         rbL2Cb->l2Sts[KW_L2MEAS_DL_IP] = measData;
    }
    if(measType & LKW_L2MEAS_UL_IP)
    {
         rbL2Cb->l2Sts[KW_L2MEAS_UL_IP] = measData;
    }

}/* End of kwUtlPlcMeasDatInL2Sts */

/**
 *
 * @brief Handler for calculate the Active UE count if data is already
 * present in RbCb.
 *
 * @b Description
 *        This function is called by KwMiLkwL2MeasReq.
 *        It calculates the initial Active Ue count.
 *        It updates the RbCb with the measType.
 *        
 *  @param[in] measCb Measurement Cb which is prepared in Rlc after measurement
 *             request is received from layer manager.
 *
 *  @return Void
 */
#ifdef ANSI
PUBLIC Void kwUtlProcInitialActvUe
(
KwL2MeasCb  *measCb
)
#else
PUBLIC Void kwUtlProcInitialActvUe(measCb)
KwL2MeasCb  *measCb;
#endif
{
   U16            cntr;
   KwRbCb         *kwRbCb;
   U16            seqNum;
   U8             qci;

   kwRbCb   = NULLP;
   seqNum   = 0;
   for(cntr = 0; cntr < measCb->numQci; cntr++)
   {
      qci = measCb->qci[cntr];
      while (cmHashListFind(&(kwCb.kwL2Cb.qciHlCp), (U8 *) &qci,
               (U16) sizeof(qci),  seqNum++, (PTR *)&kwRbCb) == ROK)
      {
         /* If there is allready data in RbCb, then we should increment     *
          * the number of active ue  counter. This has to be done seperatly *
          * for AM and UM.                                                  */
         if (((kwRbCb->rbL2Cb.measOn & measCb->measType) == LKW_L2MEAS_NONE))
         {
            if (measCb->measType & LKW_L2MEAS_ACT_UE)
            {
               if ((kwRbCb->mode == CM_LTE_MODE_UM) &&
                      (kwRbCb->dir & KW_DIR_DL ))
               {
                  if (kwRbCb->m.um.umDl.sduQ.count)
                  {
                     if (kwRbCb->ueCb->numActRb[kwRbCb->qci] == 0)
                     {
                        kwRbCb->ueCb->numActRb[kwRbCb->qci]++;
                        kwCb.kwL2Cb.numActUe[measCb->qci[cntr]]++;
                     }
                  }
               }
               else  if (kwRbCb->mode == CM_LTE_MODE_AM)
               {
                  if ((kwRbCb->m.am.amDl.cntrlBo) ||
                      (kwRbCb->m.am.amDl.retxBo)  ||
                      (kwRbCb->m.am.amDl.bo))
                  {
                     if (kwRbCb->ueCb->numActRb[kwRbCb->qci] == 0)
                     {
                        kwRbCb->ueCb->numActRb[kwRbCb->qci]++;
                        kwCb.kwL2Cb.numActUe[measCb->qci[cntr]]++;
                     }
                  }
               }
            }
         }
         kwUtlPlcMeasDatInL2Sts(&measCb->measData[measCb->qci[cntr]],
                                &kwRbCb->rbL2Cb, measCb->measType);
         kwRbCb->rbL2Cb.measOn |= measCb->measType;
      }
      seqNum = 0;
   }
}
#endif /* LTE_L2_MEAS */

#ifdef ANSI
PUBLIC Void kwUtlUlGetNumRbInReassemblyLst
(
U16                       *numRb
)
#else
PUBLIC Void kwUtlUlGetNumRbInReassemblyLst(numRb)
U16                       *numRb;
#endif
{
   KW_RDWR_LOCK(&kwCb.ulLock);
   {
      *numRb = cmLListLen(&kwCb.reassemblyRbLst);
   }
   KW_RDWR_UNLOCK(&kwCb.ulLock);
}
/**
 * @brief 
 *        Handler to add an RB to the list of RBs that have PDUs
 *        to be reassembled.
 *
 * @b Description: 
 *        This function acquires lock for adding an RB to the list of
 *        RBs which have PDUs to be reassmbled. This is called when a
 *        PDU is received from UE.
 *            
 *  @return  Void
 */
#ifdef ANSI
PUBLIC Void kwUtlUlAddRbToReassemblyLst
(
KwRbCb                       *rbCb
)
#else
PUBLIC Void kwUtlUlAddRbToReassemblyLst(rbCb)
KwRbCb                       *rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.ulLock);
   {
      if (rbCb->reassemblyRbLnk.node == NULLP)
      {
         cmLListAdd2Tail(&kwCb.reassemblyRbLst, &rbCb->reassemblyRbLnk);
         rbCb->reassemblyRbLnk.node = (PTR)rbCb;
         //MSPD_DBG("[%d][%d][%d]RB added to reassembly list\n", KW_UEID,
         //           KW_RBTYPE, KW_RBID);
      }
   }
   KW_RDWR_UNLOCK(&kwCb.ulLock);
 
}

#ifdef ANSI
PUBLIC Void kwUtlUlRemRbFrmReassemblyLst
(
KwRbCb                       *rbCb
)
#else
PUBLIC Void kwUtlUlRemRbFrmReassemblyLst(rbCb)
KwRbCb                       *rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.ulLock);
   {
      if (rbCb->reassemblyRbLnk.node != NULLP)
      {
         cmLListDelFrm(&kwCb.reassemblyRbLst, &rbCb->reassemblyRbLnk);
         rbCb->reassemblyRbLnk.node = NULLP;
      }
   }
   KW_RDWR_UNLOCK(&kwCb.ulLock);
}
/**
 * @brief 
 *        Handler to add retrieve the first RB from the list of RBs
 *        which have PDUs to be reassembled
 *
 * @b Description: 
 *        This function acquires lock and dequeues an RB from the list
 *        of RBs which have PDUs to be reassembled. This function is 
 *        called from function that processes self message for UL.
 *            
 *  @return  Void
 */
#ifdef ANSI
PRIVATE Void kwUtlUlGetRbForReassembly
(
KwRbCb                       **rbCb
)
#else
PRIVATE Void kwUtlUlGetRbForReassembly(rbCb)
KwRbCb                       **rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.ulLock);
   {
      if (kwCb.reassemblyRbLst.first == NULLP)
      {
         *rbCb = NULLP;
      }
      else
      {
         (*rbCb) = (KwRbCb *)(kwCb.reassemblyRbLst.first->node);
         (*rbCb)->reassemblyRbLnk.node = (PTR)NULLP;
         cmLListDelFrm(&kwCb.reassemblyRbLst, kwCb.reassemblyRbLst.first);
      }
   }
   KW_RDWR_UNLOCK(&kwCb.ulLock);
   RETVOID;
}

/**
 *
 * @brief 
 *
 *        Handler to process the self posted message by RLC for 
 *        reassembling of SDUs
 *
 * @b Description: 
 *
 *        This function is used to get the mode of RB and accordingly
 *        call the respective function to reassemble the SDUs.
 *            
 *  @return  Void
 *
 */
#ifdef ANSI
PUBLIC Void kwUtlProcessSelfMsgUl
(
)
#else
PUBLIC Void kwUtlProcessSelfMsgUl()
#endif
{
   U16        numSdus;
   KwRbCb     *rbCb;
   U16        numRb;

   TRC2(kwUtlProcessSelfMsgUl);
   KWDBGP((KW_DBGMASK_UL | KW_DBGMASK_BRIEF),
                                 (_kwPBuf, "kwUtlProcessSelfMsgUl\n"));
   numSdus = 0;
   numRb = 0;
   KW_RDWR_LOCK(&kwCb.selfPstUlLock);
   {
      kwCb.ulSelfMsgPosted = 0;
      kwUlSelfMsgPosted    = 0;
   }
   KW_RDWR_UNLOCK(&kwCb.selfPstUlLock);
   //MSPD_DBG("Self Msg UL handler triggered\n");
   kwUtlUlGetRbForReassembly(&rbCb);
   if (rbCb != NULLP)
   {
      switch (rbCb->mode)
      {
         case CM_LTE_MODE_UM:
         {
            kwUmmProcessSelfMsgUl(rbCb, &numSdus);
            break;
         }
         case CM_LTE_MODE_AM:
         {
            kwAmmUlProcessSelfMsg(rbCb, &numSdus);
            break;
         }
         default:
         {
            KWLOGERROR(ERRCLS_ADD_RES, EKWXXX, (ErrVal) RFAILED,
                       "kwUtlProcessSelfMsgUl: Wrong mode for RbCb\n");
            MSPD_DBG("ERROR: Wrong mode\n");
         }
      }
   }
#ifdef MSPD
   ysMsAmmNumReassemblyRbLstCount = kwCb.reassemblyRbLst.count;
   ysMsAmmNumReassemblyLstCount = AMUL.reassemblyLst.count;
#endif
   kwUtlUlGetNumRbInReassemblyLst(&numRb);
   //MSPD_DBG("Num Rb %d\n", numRb);
   if(numRb < 1)
   {
      RETVOID;
   }
   kwUtlPostSelfMsgUl(1);
}

#ifdef ANSI
PUBLIC Void kwUtlPostSelfMsgUl
(
U8                      coreId
)
#else
PUBLIC Void kwUtlPostSelfMsgUl(coreId)
U8   coreId;
#endif
{
   KW_RDWR_LOCK(&kwCb.selfPstUlLock);
   {
      if (1 != kwCb.ulSelfMsgPosted)
      {
         kwCb.ulSelfMsgPosted = 1;
         kwUlSelfMsgPosted    = 1;
         if (SPstTsk(&selfPstUl, kwCb.mBufUl) != ROK)
         {
            kwCb.ulSelfMsgPosted = 0;
            kwUlSelfMsgPosted    = 0;
         }
      }
      else
      {
         MSPD_DBG("UL self post message already posted%d\n", coreId);
      }
   }
   KW_RDWR_UNLOCK(&kwCb.selfPstUlLock);
}

/***************************************************************************/
/***********Functions related to reestablishment starts*********************/
/***************************************************************************/
/**
 *
 * @brief 
 *
 *        Handler to send the RB Reestablish Complete Indication to PDCP
 *        once all the DL PDUs are deleted and UL PDUs are reassembled.
 *
 * @b Description: 
 *
 *        This function is called from kwAmmUlProcessSelfMsg,
 *        kwUmmProcessSelfMsgUl and kwAmmRlsPdusSet.
 *        It checks the rbOp flag which indicates whether Reestablish
 *        is complete in both DL and UL.
 *        If yes, then complete indication is sent to PDCP, otherwise not.
 *
 *  @param[in] rbCb RB control block which is being processed currently
 *
 *  @return  S16
 *        -# ROK
 *         # RFAILED
 *
 */
#ifdef ANSI
PUBLIC S16 kwUtlSendRbReEstCfm
(
KwRbCb *rbCb
)
#else
PUBLIC S16 kwUtlSendRbReEstCfm(rbCb)
KwRbCb *rbCb;
#endif
{
#ifndef KW_PDCP
   KwKwuSapCb *kwKwSap = NULLP;
#endif

   TRC2(kwUtlSendRbReEstCfm);
#ifdef KW_PDCP
   MSPD_DBG("[%d][%d][%d]Reestablishment DONE, sending CmpInd to PDCP Core Id %d\n",
             KW_UEID, KW_RBTYPE, KW_RBID,MxGetCpuID());
   pjLimReEstCmpInd(rbCb->pjRbCb);
   rbCb->reestInProgress = FALSE;
#else
   KwUiKwuReEstCmpInd(&kwKwSap->pst, kwKwSap->suId, rbCb->rlcId);
#endif
   RETVALUE(ROK);
}

#ifdef ANSI
PRIVATE Void kwUtlGetNumRbInReestablishLst
(
U16                     *numRb
)
#else
PRIVATE Void kwUtlGetNumRbInReestablishLst(numRb)
U16                     *numRb
#endif
{
   KW_RDWR_LOCK(&kwCb.reestRbLstLock);
   {
      *numRb = cmLListLen(&(kwCb.reestablishRbLst));
   }
   KW_RDWR_UNLOCK(&kwCb.reestRbLstLock);
}

#ifdef ANSI
PUBLIC Void kwUtlAddRbToReestablishLst
(
KwRbCb                  *rbCb
)
#else
PUBLIC Void kwUtlAddRbToReestablishLst(rbCb)
KwRbCb                  *rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.reestRbLstLock);
   if (rbCb->reestablishRbLnk.node == NULLP)
   {
      MSPD_DBG_RLC("[%d][%d][%d]Added to Reestablishment List\n", KW_UEID, KW_RBTYPE, KW_RBID);   
      cmLListAdd2Tail(&(kwCb.reestablishRbLst), &(rbCb->reestablishRbLnk));
      rbCb->reestablishRbLnk.node = (PTR)rbCb;
   }
   KW_RDWR_UNLOCK(&kwCb.reestRbLstLock);
   RETVOID;
}

#ifdef ANSI
PRIVATE Void kwUtlGetRbFrmReestablishLst
(
KwRbCb                  **rbCb
)
#else
PRIVATE Void kwUtlGetRbFrmReestablishLst(rbCb)
KwRbCb                  **rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.reestRbLstLock);
   if (kwCb.reestablishRbLst.first == NULLP)
   {
      (*rbCb) = NULLP;
   }
   else
   {
      (*rbCb) = (KwRbCb *)(kwCb.reestablishRbLst.first->node);
      kwCb.reestablishRbLst.first->node = NULLP;
      cmLListDelFrm(&kwCb.reestablishRbLst, kwCb.reestablishRbLst.first);
   }
   KW_RDWR_UNLOCK(&kwCb.reestRbLstLock);
}

#ifdef ANSI
PUBLIC Void kwUtlProcessSelfMsgReest
(
)
#else
PUBLIC Void kwUtlProcessSelfMsgReest()
#endif
{
   KwRbCb   *rbCb;
   U16      numRb;
   TRC2(kwUtlProcessSelfMsgReest);
   KWDBGP((KW_DBGMASK_UL | KW_DBGMASK_BRIEF),
                                 (_kwPBuf, "kwUtlProcessSelfMsgReest\n"));

   kwCb.reestSelfMsgPosted = 0;
   kwUtlGetRbFrmReestablishLst(&rbCb);
   if(rbCb != NULLP)
   {
      switch(rbCb->mode)
      {
         case CM_LTE_MODE_UM:
         {
            kwUmmProcessSelfMsgReest(rbCb);
            break;
         }
         case CM_LTE_MODE_AM:
         {
            kwAmmProcessSelfMsgReest(rbCb);
            break;
         }
         default:
         {
            MSPD_DBG("Wrong mode\n");
         }
      }
   }
   kwUtlGetNumRbInReestablishLst(&numRb);
   if(numRb < 1)
   {
      RETVOID;
   }
   kwUtlPostSelfMsgReest();
}

#ifdef ANSI
PUBLIC Void kwUtlPostSelfMsgReest
(
)
#else
PUBLIC Void kwUtlPostSelfMsgReest()
#endif
{
   KW_RDWR_LOCK(&kwCb.selfPstReestLock);
   if (1 != kwCb.reestSelfMsgPosted)
   {
      kwCb.reestSelfMsgPosted = 1;
      if(SPstTsk(&selfPstReest, kwCb.mBufReest) != ROK)
      {
         kwCb.reestSelfMsgPosted = 0;
      }
      MSPD_DBG_RLC("Posted self message for reestablishment\n");
   }
   KW_RDWR_UNLOCK(&kwCb.selfPstReestLock);
}

/**
 * @brief 
 *
 *
 * @b Description: 
 *
 *
 *  @param[in] rbCb RB control block which is being processed currently
 *
 *  @return  S16
 *        -# ROK
 *         # RFAILED
 */
#ifdef ANSI
PUBLIC S16 kwUtlRbDeletion
(
KwRbCb *rbCb
)
#else
PUBLIC S16 kwUtlRbDeletion(rbCb)
KwRbCb *rbCb;
#endif
{
   TRC2(kwUtlRbDeletion);
   if (rbCb->rb->rbCfgStat == 0)
   {
      KW_FREE(rbCb, sizeof(RbCb));
      RETVALUE(ROK);
   }
}

#ifdef ANSI
PUBLIC Void kwUtlProcessSelfMsgDelete
(
)
#else
PUBLIC Void kwUtlProcessSelfMsgDelete()
#endif
{
   KwRbCb   *rbCb;
   U16      numRb;
   TRC2(kwUtlProcessSelfMsgDelete);
   KWDBGP((KW_DBGMASK_UL | KW_DBGMASK_BRIEF),
                                 (_kwPBuf, "kwUtlProcessSelfMsgDelete\n"));

   kwCb.deleteSelfMsgPosted = 0;
   kwAmmGetRbFrmDeleteLst(&rbCb);
   if(rbCb != NULLP)
   {
      switch(rbCb->mode)
      {
         case CM_LTE_MODE_UM:
         {
            kwUmmProcessSelfMsgDelete(rbCb);
            break;
         }
         case CM_LTE_MODE_AM:
         {
            kwAmmProcessSelfMsgDelete(rbCb);
            break;
         }
         default:
         {
            MSPD_DBG("Wrong mode\n");
         }
      }
   }
   kwAmmGetNumRbInDeleteLst(&numRb);
   if(numRb < 1)
   {
      RETVOID;
   }
   kwUtlPostSelfMsgDelete();
}
#ifdef ANSI
PUBLIC Void kwUtlPostSelfMsgDelete
(
)
#else
PUBLIC Void kwUtlPostSelfMsgDelete()
#endif
{
   KW_RDWR_LOCK(&kwCb.selfPstDeleteLock);
   if (1 != kwCb.deleteSelfMsgPosted)
   {
      kwCb.deleteSelfMsgPosted = 1;
      if(SPstTsk(&selfPstDelete, kwCb.mBufDelete) != ROK)
      {
         kwCb.deleteSelfMsgPosted = 0;
      }
      //MSPD_DBG("Posted self message for delete\n");
   }
   KW_RDWR_UNLOCK(&kwCb.selfPstDeleteLock);
}

/**
 *
 * @brief
 *
 *        Set ReEstablishment in Progress flag for all Rb's. Except SRB1
 *        This flag is used to stop data on SRB2 and DRB's while ReEstablishment
 *        is ongoing.
 *
 * @b Description:
 *
 *        This function is called from kwAmmReEstablish 
 *
 *  @return  Void
 *
 */
PUBLIC Void kwUtlSetReestInProgress(KwUeCb  *ueCb)
{
   U32        rbIdx;
   KwRbCb     *rbCb;
   for(rbIdx = 0;rbIdx < KW_MAX_SRB_PER_UE;rbIdx++)
   {
      if(ueCb->srbCb[rbIdx] != NULLP)
      {
         rbCb = &ueCb->srbCb[rbIdx]->kwRbCb;
         {
            rbCb->reestInProgress = TRUE;
			AMDL.estHdrSz = 0;
            kwUtlSndDStaRsp(rbCb, 0, 
               AMDL.estHdrSz, AMDL.cntrlBo ? TRUE : FALSE);
         }
      }
   }
   for(rbIdx = 0;rbIdx < KW_MAX_DRB_PER_UE;rbIdx++)
   {
      if(ueCb->drbCb[rbIdx] != NULLP)
      {
         rbCb = &ueCb->drbCb[rbIdx]->kwRbCb;
         rbCb->reestInProgress = TRUE;		 
         if(rbCb->mode == PJ_DRB_AM)		 
         {            
			AMDL.estHdrSz = 0;
            kwUtlSndDStaRsp(rbCb, 0, AMDL.estHdrSz, AMDL.cntrlBo ? TRUE : FALSE);			
         }
         else
         {                    
            rbCb->m.um.umDl.estHdrSz = 0;
            kwUtlSndDStaRsp(rbCb, 0,rbCb->m.um.umDl.estHdrSz,FALSE);
         }                		 	
      }
   }
}

#ifdef ANSI
PUBLIC Void kwUtlPostPjDlRbSelfMsg
(
Void
)
#else
PUBLIC Void kwUtlPostPjDlRbSelfMsg(Void)
#endif
{
   KW_RDWR_LOCK(&kwCb.pjDelRbLstLock);
   if (1 != kwCb.pjDelRbSelfMsgPosted)
   {
      kwCb.pjDelRbSelfMsgPosted = 1;
      if(SPstTsk(&pjSelfPstDelRb, kwCb.pjMBufDlRb)!= ROK)
      {
         MSPD_DBG("Failed Sud\n");
         kwCb.pjDelRbSelfMsgPosted = 0;
      }
   }
   else
   {
      MSPD_DBG("Already Posted for Delete RB\n");
   }
   KW_RDWR_UNLOCK(&kwCb.pjDelRbLstLock);
   RETVOID;
}

#ifdef ANSI
PUBLIC Void kwUtlGetNumRbInPjDelRbLst
(
U16                     *numRb
)
#else
PUBLIC Void kwUtlGetNumRbInPjDelRbLst(numRb)
U16                     *numRb
#endif
{
   KW_RDWR_LOCK(&kwCb.pjDelRbLstLock);
   {
      *numRb = cmLListLen(&(kwCb.pjDelRbLst));
      MSPD_DBG("no of Rb to Delete %d\n", *numRb);
   }
   KW_RDWR_UNLOCK(&kwCb.pjDelRbLstLock);
}

#ifdef ANSI
PUBLIC Void kwUtlAddRbToPjDelRbLst
(
KwRbCb                  *rbCb
)
#else
PUBLIC Void kwUtlAddRbToPjDelRbLst(rbCb)
KwRbCb                  *rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.pjDelRbLstLock);
   if (rbCb->pjDelRbLnk.node == NULLP)
   {
      cmLListAdd2Tail(&(kwCb.pjDelRbLst), &(rbCb->pjDelRbLnk));
      rbCb->pjDelRbLnk.node = (PTR)rbCb;
      MSPD_DBG("[%d][%d][%d] RbCb added to DeleteLst\n", KW_UEID, KW_RBTYPE, KW_RBID);
   }
   KW_RDWR_UNLOCK(&kwCb.pjDelRbLstLock);
   RETVOID;
}

#ifdef ANSI
PUBLIC Void kwUtlRemRbFrmPjDelRbLst
(
KwRbCb                  *rbCb
)
#else
PUBLIC Void kwUtlRemRbFrmPjDelRbLst(rbCb)
KwRbCb                  *rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.pjDelRbLstLock);
   cmLListDelFrm(&kwCb.pjDelRbLst, &rbCb->pjDelRbLnk);
   rbCb->pjDelRbLnk.node = NULLP;
   KW_RDWR_UNLOCK(&kwCb.pjDelRbLstLock);
   RETVOID;
}

#ifdef ANSI
PUBLIC Void kwUtlGetRbFrmPjDelRbLst
(
KwRbCb                  **rbCb
)
#else
PUBLIC Void kwUtlGetRbFrmPjDelRbLst(rbCb)
KwRbCb                  **rbCb;
#endif
{
   KW_RDWR_LOCK(&kwCb.pjDelRbLstLock);
   {
      kwCb.pjDelRbSelfMsgPosted = 0;
      if (kwCb.pjDelRbLst.first == NULLP)
      {
         *rbCb = NULLP;
      }
      else
      {
         (*rbCb) = (KwRbCb *)(kwCb.pjDelRbLst.first->node);

         MSPD_DBG("[%d][%d][%d] RbCb Deleted from pjDelRbLst\n", (*rbCb)->rlcId.ueId,
                (*rbCb)->rlcId.rbType,  (*rbCb)->rlcId.rbId);
         kwCb.pjDelRbLst.first->node = NULLP;
         cmLListDelFrm(&kwCb.pjDelRbLst, kwCb.pjDelRbLst.first);         
      }
   }
   KW_RDWR_UNLOCK(&kwCb.pjDelRbLstLock);
   RETVOID;
}

#ifdef ANSI
PUBLIC Void kwUtlProcessSelfMsgPjDelRb
(
)
#else
PUBLIC Void kwUtlProcessSelfMsgPjDelRb()
#endif
{
   KwRbCb   *rbCb;
   U16       numRb;
   TRC2(kwUtlProcessSelfMsgPjDelRb);
   KWDBGP((KW_DBGMASK_UL | KW_DBGMASK_BRIEF),
                                 (_kwPBuf, "kwUtlProcessSelfMsgPjDelRb\n"));
   kwUtlGetRbFrmPjDelRbLst(&rbCb);
   if(rbCb != NULLP)
   {
      pjCfgDelPjRBCb(rbCb->rb);
   }
   kwUtlGetNumRbInPjDelRbLst(&numRb);
   if(numRb < 1)
   {
      RETVOID;
   }
   kwUtlPostPjDlRbSelfMsg();

}

#ifdef __cplusplus
}
#endif /* __cplusplus */
/********************************************************************30**
         End of file:     gp_utl.c@@/main/2 - Fri Nov 13 14:14:08 2009
*********************************************************************31*/

/********************************************************************40**
  
        Notes:
  
*********************************************************************41*/

/********************************************************************50**

*********************************************************************51*/

/********************************************************************60**
  
        Revision history:
  
*********************************************************************61*/

/********************************************************************90**
     ver       pat    init                  description
------------ -------- ---- ----------------------------------------------
/main/1      ---       vp   1. initial release.
/main/2      ---       nm   1. LTERLC Release 2.1
/main/3      kw002.201 vp   1. Patch for optimization,fixes for multi-region
                               and retransmission.
/main/5      kw003.201 vp  1.  Fixes for re-segmentation, segement offset
                               value and optimization 
/main/6      kw004.201 ap  1.  Used SSI function to initialize the variable.
                           2.  Added fn call cmHashListDelete for deleting
                       rd  3.  Code added for DL and UL IP throughput 
                               measurement under flag LTE_L2_MEAS.
                              the entry from tbHlCp.  
                           4.  Added code for DL/UL IP Meas in fn 
                               kwUtlSndL2MeasCfm().
/main/7      kw005.201 ap  1. Added support for L2 Measurement.
/main/8      kw006.201 rd  1. Moved few portions of kwUtlSndL2MeasCfm to 2
                              functions:kwUtlResetL2MeasInKwRb and 
                              kwUtlNotifyMacUlIp.
                           2. Some portions of function kwUtlProcHarqInd is
                              moved to kwUtlProcSnMap.
                           3. Typecasted estHdrSiz to U16 in kwUtlSndDStaRsp.
                       ap  4. Removed 64 bit compilation warning.
                           5. Added fix for stopping the timer.
                           6. Optimization change, ccpu00111716.
                       rd  7. Added a new function kwUtlProcessSelfMsgUl
                              for CR ccpu00117290.
                           8. Added 2 new functions kwUtlSendRbReEstCfm and
                              kwUtlRbDeletion for CR ccpu00111716 and
                              ccpu00117290.
                           9. Self post message to RLC is sent only when a 
                              new RB is added to RbList. Change is done in
                              kwUtlFreeRbCb.
                          10. Added code to post self message in 
                              kwUtlProcessSelfMsgUl().
*********************************************************************91*/
