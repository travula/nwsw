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


/***********************************************************************

    Name: Source file for filling LM configuration

    Type: C Source

    Desc: 

    File: eg_dbs10.c

    Sid:      eg_dbs10.c@@/main/2 - Fri Feb  4 18:18:02 2011

    Prg: an

************************************************************************/


/***********************************************************************
    This file contains automatically generated code
************************************************************************/
/* Header Include Files (.h) */
#include "envopt.h"            /* Environment Options */
#include "envdep.h"            /* Environment Dependent */
#include "envind.h"            /* Environment Independent */
#include "gen.h"            /* General */
#include "ssi.h"            /* System Services */
#include "cm_tkns.h"         /* Common Tokens */
#include "cm_hash.h"         /* Common Hash List */
#include "cm_mblk.h"         /* Common memory */
#include "cm_llist.h"           /* Common Link List */
#include "cm5.h"               /* Common Structures */
#include "cm_inet.h"           /* Common IP network */
#include "cm_tpt.h"           /* Common Transport */
#include "hit.h"            /* TUCL layer */
#include "egt.h"            /* EU layer */
#include "leg.h"      /* layer manager */
#include "eg_util.h"      /* UTIL */
#include "eg_edm.h"      /* EDM MODULE */
#include "eg_dbs10.h"
#include "eg_dbutl.h"   /* Ie codes are here */

/* Header Include Files (.x) */

#include "gen.x"            /* General */
#include "ssi.x"            /* System Services */
#include "cm_tkns.x"         /* Common Tokens */
#include "cm_hash.x"         /* Common Hash List */
#include "cm_mblk.x"         /* Common memory */
#include "cm_llist.x"           /* Common Link List */
#include "cm5.x"               /* Common Structures */
#include "cm_inet.x"           /* Common IP network */
#include "cm_tpt.x"           /* Common Transport */
#include "hit.x"            /* TUCL layer */
#include "egt.x"            /* EU layer */
#include "leg.x"      /* layer manager */
#include "eg_util.x"      /* UTIL */
#include "eg_edm.x"      /* EDM MODULE */
#include "eg_dbutl.x"      /* Application MODULE */
#include "eg_dbs10.x"

#ifdef EGTP_C

/***********************************************************************

   Func  : egMakes10CFGTFRTNLGmEntry

   Desc  : This function makes the GM Entry for CFGTFRTNL

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10CFGTFRTNLGmEntry
(
LegMsgEntry               *gmCFGTFRTNLCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10CFGTFRTNLGmEntry(gmCFGTFRTNLCb)
LegMsgEntry               *gmCFGTFRTNLCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10CFGTFRTNLGmEntry);

   /* Populate the CFGTFRTNL GM Entry */
   gmCFGTFRTNLCb->msgType = EG_S10_CFGTFRTNL_CMD_CODE;
   gmCFGTFRTNLCb->nmbIeProp = EG_S10_CFGTFRTNL_NMB_IES;
   gmCFGTFRTNLCb->validateIe = (EscFun )NULLP;

   /* Populate CFGTFRTNL IE Properties */

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmCFGTFRTNLCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmCFGTFRTNLCb->posIndex[0][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate TARGET_ID IE Properties */
   egMakeAppIeProp(&gmCFGTFRTNLCb->ieProperties[ieCnt],
                    EG_TARGET_ID_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmCFGTFRTNLCb->posIndex[0][EG_TARGET_ID_IETYPE]  = ieCnt + 1;

} /* End of egMakes10CFGTFRTNLGmEntry */


/***********************************************************************

   Func  : egMakes10CTXACKGmEntry

   Desc  : This function makes the GM Entry for CTXACK

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10CTXACKGmEntry
(
LegMsgEntry               *gmCTXACKCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10CTXACKGmEntry(gmCTXACKCb)
LegMsgEntry               *gmCTXACKCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10CTXACKGmEntry);

   /* Populate the CTXACK GM Entry */
   gmCTXACKCb->msgType = EG_S10_CTXACK_CMD_CODE;
   gmCTXACKCb->nmbIeProp = EG_S10_CTXACK_NMB_IES;
   gmCTXACKCb->validateIe = (EscFun )NULLP;

   /* Populate CTXACK IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmCTXACKCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmCTXACKCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate INDICATION IE Properties */
   egMakeAppIeProp(&gmCTXACKCb->ieProperties[ieCnt],
                    EG_INDICATION_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXACKCb->posIndex[0][EG_INDICATION_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmCTXACKCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmCTXACKCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10CTXACKGmEntry */


/***********************************************************************

   Func  : egMakes10CTXREQGmEntry

   Desc  : This function makes the GM Entry for CTXREQ

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10CTXREQGmEntry
(
LegMsgEntry               *gmCTXREQCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10CTXREQGmEntry(gmCTXREQCb)
LegMsgEntry               *gmCTXREQCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10CTXREQGmEntry);

   /* Populate the CTXREQ GM Entry */
   gmCTXREQCb->msgType = EG_S10_CTXREQ_CMD_CODE;
   gmCTXREQCb->nmbIeProp = EG_S10_CTXREQ_NMB_IES;
   gmCTXREQCb->validateIe = (EscFun )NULLP;

   /* Populate CTXREQ IE Properties */

   /* Populate IMSI IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_IMSI_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_IMSI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GUTI IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_GUTI_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_GUTI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate COMP_REQ_MSG IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_COMP_REQ_MSG_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_COMP_REQ_MSG_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate FTEID IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_FTEID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_FTEID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PORT IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_PORT_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_PORT_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RAT_TYPE IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_RAT_TYPE_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_RAT_TYPE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate INDICATION IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_INDICATION_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_INDICATION_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate HOP_CNTR IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_HOP_CNTR_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_HOP_CNTR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate SERVING_NWK IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_SERVING_NWK_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_SERVING_NWK_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmCTXREQCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmCTXREQCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10CTXREQGmEntry */


/***********************************************************************

   Func  : egMakes10CTXRSPGmEntry

   Desc  : This function makes the GM Entry for CTXRSP

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10CTXRSPGmEntry
(
LegMsgEntry               *gmCTXRSPCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10CTXRSPGmEntry(gmCTXRSPCb)
LegMsgEntry               *gmCTXRSPCb;
#endif
{
   U8 ieCnt = 0;
   U8 grpCnt = 0;
   U8 grpCnt1 = 0;
   U8 ret = RFAILED;
   LegIeProperties **ieProperties;
   TRC2(egMakes10CTXRSPGmEntry);

   /* Populate the CTXRSP GM Entry */
   gmCTXRSPCb->msgType = EG_S10_CTXRSP_CMD_CODE;
   gmCTXRSPCb->nmbIeProp = EG_S10_CTXRSP_NMB_IES;
   gmCTXRSPCb->validateIe = (EscFun )NULLP;

   /* Populate CTXRSP IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IMSI IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_IMSI_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_IMSI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GSM_KEY_TRIP IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_GSM_KEY_TRIP_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_GSM_KEY_TRIP_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_CIPH_QUIN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_CIPH_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_UMTS_KEY_CIPH_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GSM_KEY_CIPH_QUIN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_GSM_KEY_CIPH_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_GSM_KEY_CIPH_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_QUIN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_UMTS_KEY_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate EPS_SEC_QUAD_QUIN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_EPS_SEC_QUAD_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_EPS_SEC_QUAD_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_QUAD_QUIN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_QUAD_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_UMTS_KEY_QUAD_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PDN_CONN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_PDN_CONN_IETYPE,EG_IE_CONDITIONAL,0,TRUE);

   gmCTXRSPCb->posIndex[0][EG_PDN_CONN_IETYPE]  = ieCnt + 1;

   grpCnt = 0;
   ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmCTXRSPCb->ieProperties[ieCnt].groupedIe) ,sizeof(LegGroupedIe));

   if( ret == ROK && (gmCTXRSPCb->ieProperties[ieCnt].groupedIe) != NULLP)
   {
     /*
      * here allocate memory for each IE Property and use it */
     ieProperties = &gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties;
     ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties) *(EG_CTXRSP_PDN_CONN0_GRP_NMB_IES )));
     if( ret == ROK && *ieProperties != NULLP)
     {
       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_APN_IETYPE,EG_IE_MANDATORY,0,FALSE,
           EG_CTXRSP_PDN_CONN0_GRP_NMB_IES);

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_APN_RESTRICT_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_SEL_MODE_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,1,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_EBI_IETYPE,EG_IE_MANDATORY,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_MANDATORY,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FQDN_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt, EG_BEARER_CNTX_IETYPE,EG_IE_MANDATORY,0,TRUE,
           0 );

       ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe) ,sizeof(LegGroupedIe));

       if( ret == ROK && &(gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe) != NULLP)
       {
         ieProperties = &gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe->ieProperties;
         ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties) *(EG_CTXRSP_BEARER_CNTX00_GRP_NMB_IES)));
         if( ret == ROK && *ieProperties != NULLP)
         {
           grpCnt1 = 0;

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_EBI_IETYPE,EG_IE_MANDATORY,0,FALSE,
               EG_CTXRSP_BEARER_CNTX00_GRP_NMB_IES);

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_BEARER_TFT_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_FTEID_IETYPE,EG_IE_MANDATORY,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,1,FALSE,
               0 );

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_BEARER_QOS_IETYPE,EG_IE_MANDATORY,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_TRANS_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
               0 );
         }
       }

       grpCnt++;

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_AMBR_IETYPE,EG_IE_MANDATORY,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_CHARGING_CHAR_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmCTXRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_CNG_RPT_ACT_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );
     }
   }
   ieCnt++;

   /* Populate FTEID IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_FTEID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_FTEID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate FTEID IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_FTEID_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmCTXRSPCb->posIndex[1][EG_FTEID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate FQDN IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_FQDN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_FQDN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate INDICATION IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_INDICATION_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_INDICATION_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate TRACE_INFO IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_TRACE_INFO_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_TRACE_INFO_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IPADDR IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_IPADDR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IPADDR IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmCTXRSPCb->posIndex[1][EG_IPADDR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RFSP_ID IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_RFSP_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_RFSP_ID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RFSP_ID IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_RFSP_ID_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmCTXRSPCb->posIndex[1][EG_RFSP_ID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmCTXRSPCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmCTXRSPCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10CTXRSPGmEntry */


/***********************************************************************

   Func  : egMakes10FWDACCSCTXACKGmEntry

   Desc  : This function makes the GM Entry for FWDACCSCTXACK

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10FWDACCSCTXACKGmEntry
(
LegMsgEntry               *gmFWDACCSCTXACKCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10FWDACCSCTXACKGmEntry(gmFWDACCSCTXACKCb)
LegMsgEntry               *gmFWDACCSCTXACKCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10FWDACCSCTXACKGmEntry);

   /* Populate the FWDACCSCTXACK GM Entry */
   gmFWDACCSCTXACKCb->msgType = EG_S10_FWDACCSCTXACK_CMD_CODE;
   gmFWDACCSCTXACKCb->nmbIeProp = EG_S10_FWDACCSCTXACK_NMB_IES;
   gmFWDACCSCTXACKCb->validateIe = (EscFun )NULLP;

   /* Populate FWDACCSCTXACK IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDACCSCTXACKCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDACCSCTXACKCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmFWDACCSCTXACKCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDACCSCTXACKCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10FWDACCSCTXACKGmEntry */


/***********************************************************************

   Func  : egMakes10FWDACCSCTXNTFGmEntry

   Desc  : This function makes the GM Entry for FWDACCSCTXNTF

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10FWDACCSCTXNTFGmEntry
(
LegMsgEntry               *gmFWDACCSCTXNTFCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10FWDACCSCTXNTFGmEntry(gmFWDACCSCTXNTFCb)
LegMsgEntry               *gmFWDACCSCTXNTFCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10FWDACCSCTXNTFGmEntry);

   /* Populate the FWDACCSCTXNTF GM Entry */
   gmFWDACCSCTXNTFCb->msgType = EG_S10_FWDACCSCTXNTF_CMD_CODE;
   gmFWDACCSCTXNTFCb->nmbIeProp = EG_S10_FWDACCSCTXNTF_NMB_IES;
   gmFWDACCSCTXNTFCb->validateIe = (EscFun )NULLP;

   /* Populate FWDACCSCTXNTF IE Properties */

   /* Populate SRC_RNC_PDCP_CTX IE Properties */
   egMakeAppIeProp(&gmFWDACCSCTXNTFCb->ieProperties[ieCnt],
                    EG_SRC_RNC_PDCP_CTX_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDACCSCTXNTFCb->posIndex[0][EG_SRC_RNC_PDCP_CTX_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDACCSCTXNTFCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDACCSCTXNTFCb->posIndex[0][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmFWDACCSCTXNTFCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDACCSCTXNTFCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10FWDACCSCTXNTFGmEntry */


/***********************************************************************

   Func  : egMakes10FWDRELCMPACKGmEntry

   Desc  : This function makes the GM Entry for FWDRELCMPACK

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10FWDRELCMPACKGmEntry
(
LegMsgEntry               *gmFWDRELCMPACKCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10FWDRELCMPACKGmEntry(gmFWDRELCMPACKCb)
LegMsgEntry               *gmFWDRELCMPACKCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10FWDRELCMPACKGmEntry);

   /* Populate the FWDRELCMPACK GM Entry */
   gmFWDRELCMPACKCb->msgType = EG_S10_FWDRELCMPACK_CMD_CODE;
   gmFWDRELCMPACKCb->nmbIeProp = EG_S10_FWDRELCMPACK_NMB_IES;
   gmFWDRELCMPACKCb->validateIe = (EscFun )NULLP;

   /* Populate FWDRELCMPACK IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELCMPACKCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELCMPACKCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RECOVERY IE Properties */
   egMakeAppIeProp(&gmFWDRELCMPACKCb->ieProperties[ieCnt],
                    EG_RECOVERY_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDRELCMPACKCb->posIndex[0][EG_RECOVERY_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmFWDRELCMPACKCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDRELCMPACKCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10FWDRELCMPACKGmEntry */


/***********************************************************************

   Func  : egMakes10FWDRELCMPNTFGmEntry

   Desc  : This function makes the GM Entry for FWDRELCMPNTF

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10FWDRELCMPNTFGmEntry
(
LegMsgEntry               *gmFWDRELCMPNTFCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10FWDRELCMPNTFGmEntry(gmFWDRELCMPNTFCb)
LegMsgEntry               *gmFWDRELCMPNTFCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10FWDRELCMPNTFGmEntry);

   /* Populate the FWDRELCMPNTF GM Entry */
   gmFWDRELCMPNTFCb->msgType = EG_S10_FWDRELCMPNTF_CMD_CODE;
   gmFWDRELCMPNTFCb->nmbIeProp = EG_S10_FWDRELCMPNTF_NMB_IES;
   gmFWDRELCMPNTFCb->validateIe = (EscFun )NULLP;

   /* Populate FWDRELCMPNTF IE Properties */

   /* Populate INDICATION IE Properties */
   egMakeAppIeProp(&gmFWDRELCMPNTFCb->ieProperties[ieCnt],
                    EG_INDICATION_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELCMPNTFCb->posIndex[0][EG_INDICATION_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmFWDRELCMPNTFCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDRELCMPNTFCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10FWDRELCMPNTFGmEntry */


/***********************************************************************

   Func  : egMakes10FWDRELREQGmEntry

   Desc  : This function makes the GM Entry for FWDRELREQ

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10FWDRELREQGmEntry
(
LegMsgEntry               *gmFWDRELREQCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10FWDRELREQGmEntry(gmFWDRELREQCb)
LegMsgEntry               *gmFWDRELREQCb;
#endif
{
   U8 ieCnt = 0;
   U8 grpCnt = 0;
   U8 grpCnt1 = 0;
   U8 ret = RFAILED;
   LegIeProperties **ieProperties;
   TRC2(egMakes10FWDRELREQGmEntry);

   /* Populate the FWDRELREQ GM Entry */
   gmFWDRELREQCb->msgType = EG_S10_FWDRELREQ_CMD_CODE;
   gmFWDRELREQCb->nmbIeProp = EG_S10_FWDRELREQ_NMB_IES;
   gmFWDRELREQCb->validateIe = (EscFun )NULLP;

   /* Populate FWDRELREQ IE Properties */

   /* Populate IMSI IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_IMSI_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_IMSI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate FTEID IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_FTEID_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_FTEID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PDN_CONN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_PDN_CONN_IETYPE,EG_IE_MANDATORY,0,TRUE);

   gmFWDRELREQCb->posIndex[0][EG_PDN_CONN_IETYPE]  = ieCnt + 1;

   grpCnt = 0;
   ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmFWDRELREQCb->ieProperties[ieCnt].groupedIe) ,sizeof(LegGroupedIe));

   if( ret == ROK && (gmFWDRELREQCb->ieProperties[ieCnt].groupedIe) != NULLP)
   {
     ieProperties = &gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties;
     ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties)*(EG_FWDRELREQ_PDN_CONN0_GRP_NMB_IES)));
     if( ret == ROK && *ieProperties != NULLP)
     {
       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_APN_IETYPE,EG_IE_MANDATORY,0,FALSE,
           EG_FWDRELREQ_PDN_CONN0_GRP_NMB_IES);

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_APN_RESTRICT_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_SEL_MODE_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,1,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_EBI_IETYPE,EG_IE_MANDATORY,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_MANDATORY,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FQDN_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt, EG_BEARER_CNTX_IETYPE,EG_IE_CONDITIONAL,0,TRUE,
           0 );

       ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe) ,sizeof(LegGroupedIe));

       if( ret == ROK && (gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe) != NULLP)
       {
         ieProperties = &gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe->ieProperties;
         ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties)*(EG_FWDRELREQ_BEARER_CNTX00_GRP_NMB_IES)));
         if( ret == ROK && *ieProperties != NULLP)
         {
           grpCnt1 = 0;

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_EBI_IETYPE,EG_IE_MANDATORY,0,FALSE,
               EG_FWDRELREQ_BEARER_CNTX00_GRP_NMB_IES);

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_BEARER_TFT_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_FTEID_IETYPE,EG_IE_MANDATORY,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,1,FALSE,
               0 );

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_BEARER_QOS_IETYPE,EG_IE_MANDATORY,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_F_CONTAINER_IETYPE,EG_IE_OPTIONAL,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_TRANS_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
               0 );

           egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe->ieProperties[grpCnt].groupedIe), grpCnt1++, EG_BEARER_FLAGS_IETYPE,EG_IE_OPTIONAL,0,FALSE,
               0 );
         }
       }
       grpCnt++;

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_AMBR_IETYPE,EG_IE_MANDATORY,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_CHARGING_CHAR_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELREQCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_CNG_RPT_ACT_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );
     }
   }
   ieCnt++;

   /* Populate FTEID IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_FTEID_IETYPE,EG_IE_MANDATORY,1,FALSE);

   gmFWDRELREQCb->posIndex[1][EG_FTEID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate FQDN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_FQDN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_FQDN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GSM_KEY_TRIP IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_GSM_KEY_TRIP_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_GSM_KEY_TRIP_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_CIPH_QUIN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_CIPH_QUIN_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_UMTS_KEY_CIPH_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GSM_KEY_CIPH_QUIN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_GSM_KEY_CIPH_QUIN_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_GSM_KEY_CIPH_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_QUIN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_QUIN_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_UMTS_KEY_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate EPS_SEC_QUAD_QUIN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_EPS_SEC_QUAD_QUIN_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_EPS_SEC_QUAD_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_QUAD_QUIN IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_QUAD_QUIN_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_UMTS_KEY_QUAD_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate INDICATION IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_INDICATION_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_INDICATION_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmFWDRELREQCb->posIndex[1][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate TARGET_ID IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_TARGET_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_TARGET_ID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IPADDR IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_IPADDR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IPADDR IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_IPADDR_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmFWDRELREQCb->posIndex[1][EG_IPADDR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmFWDRELREQCb->posIndex[1][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,2,FALSE);

   gmFWDRELREQCb->posIndex[2][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,2,FALSE);

   gmFWDRELREQCb->posIndex[2][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate SEL_PLMN_ID IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_SEL_PLMN_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_SEL_PLMN_ID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RECOVERY IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_RECOVERY_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_RECOVERY_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate TRACE_INFO IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_TRACE_INFO_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_TRACE_INFO_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RFSP_ID IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_RFSP_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_RFSP_ID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate RFSP_ID IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_RFSP_ID_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmFWDRELREQCb->posIndex[1][EG_RFSP_ID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmFWDRELREQCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDRELREQCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10FWDRELREQGmEntry */


/***********************************************************************

   Func  : egMakes10FWDRELRSPGmEntry

   Desc  : This function makes the GM Entry for FWDRELRSP

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10FWDRELRSPGmEntry
(
LegMsgEntry               *gmFWDRELRSPCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10FWDRELRSPGmEntry(gmFWDRELRSPCb)
LegMsgEntry               *gmFWDRELRSPCb;
#endif
{
   U8 ieCnt = 0;
   U8 grpCnt = 0;
   U8 ret = RFAILED;
   LegIeProperties **ieProperties;
   TRC2(egMakes10FWDRELRSPGmEntry);

   /* Populate the FWDRELRSP GM Entry */
   gmFWDRELRSPCb->msgType = EG_S10_FWDRELRSP_CMD_CODE;
   gmFWDRELRSPCb->nmbIeProp = EG_S10_FWDRELRSP_NMB_IES;
   gmFWDRELRSPCb->validateIe = (EscFun )NULLP;

   /* Populate FWDRELRSP IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmFWDRELRSPCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate FTEID IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_FTEID_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELRSPCb->posIndex[0][EG_FTEID_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate INDICATION IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_INDICATION_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELRSPCb->posIndex[0][EG_INDICATION_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate BEARER_CNTX IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_BEARER_CNTX_IETYPE,EG_IE_CONDITIONAL,0,TRUE);

   gmFWDRELRSPCb->posIndex[0][EG_BEARER_CNTX_IETYPE]  = ieCnt + 1;

   grpCnt = 0;
   ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe) ,sizeof(LegGroupedIe));

   if( ret == ROK && (gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe) != NULLP)
   {
     ieProperties = &gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe->ieProperties;
     ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties)*(EG_FWDRELRSP_BEARER_CNTX0_GRP_NMB_IES)));
     if( ret == ROK && *ieProperties != NULLP)
     {
       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_EBI_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           EG_FWDRELRSP_BEARER_CNTX0_GRP_NMB_IES);

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_PKT_FLOW_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_OPTIONAL,1,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,2,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,3,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,4,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_OPTIONAL,5,FALSE,
           0 );
     }
   }
   ieCnt++;

   /* Populate BEARER_CNTX IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_BEARER_CNTX_IETYPE,EG_IE_CONDITIONAL,1,TRUE);

   gmFWDRELRSPCb->posIndex[1][EG_BEARER_CNTX_IETYPE]  = ieCnt + 1;

   grpCnt = 0;
   ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe) ,sizeof(LegGroupedIe));

   if( ret == ROK && (gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe) != NULLP)
   {
     ieProperties = &gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe->ieProperties;
     ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties)*(EG_FWDRELRSP_BEARER_CNTX1_GRP_NMB_IES)));
     if( ret == ROK && *ieProperties != NULLP)
     {
       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_EBI_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           EG_FWDRELRSP_BEARER_CNTX1_GRP_NMB_IES);

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_PKT_FLOW_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_OPTIONAL,1,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,2,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,3,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,4,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_OPTIONAL,5,FALSE,
           0 );
     }
   }
   ieCnt++;

   /* Populate BEARER_CNTX IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_BEARER_CNTX_IETYPE,EG_IE_OPTIONAL,2,FALSE);

   gmFWDRELRSPCb->posIndex[2][EG_BEARER_CNTX_IETYPE]  = ieCnt + 1;

   grpCnt = 0;
   ret = SGetSBuf(DFLT_REGION,DFLT_POOL,(Data **)&(gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe) ,sizeof(LegGroupedIe));

   if( ret == ROK && (gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe) != NULLP)
   {
     ieProperties = &gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe->ieProperties; 
     ret = SGetSBuf(DFLT_REGION,DFLT_POOL ,(Data **)(ieProperties) ,(sizeof(LegIeProperties)*(EG_FWDRELRSP_BEARER_CNTX2_GRP_NMB_IES)));
     if( ret == ROK && *ieProperties != NULLP)
     {
       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_EBI_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           EG_FWDRELRSP_BEARER_CNTX2_GRP_NMB_IES);

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_PKT_FLOW_ID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,0,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_OPTIONAL,1,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,2,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,3,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_CONDITIONAL,4,FALSE,
           0 );

       egMakeAppChildIeEntry((gmFWDRELRSPCb->ieProperties[ieCnt].groupedIe), grpCnt++, EG_FTEID_IETYPE,EG_IE_OPTIONAL,5,FALSE,
           0 );
     }
   }
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELRSPCb->posIndex[0][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmFWDRELRSPCb->posIndex[1][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmFWDRELRSPCb->posIndex[0][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,1,FALSE);

   gmFWDRELRSPCb->posIndex[1][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CONTAINER IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_F_CONTAINER_IETYPE,EG_IE_CONDITIONAL,2,FALSE);

   gmFWDRELRSPCb->posIndex[2][EG_F_CONTAINER_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,2,FALSE);

   gmFWDRELRSPCb->posIndex[2][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmFWDRELRSPCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmFWDRELRSPCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10FWDRELRSPGmEntry */


/***********************************************************************

   Func  : egMakes10IDENTREQGmEntry

   Desc  : This function makes the GM Entry for IDENTREQ

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10IDENTREQGmEntry
(
LegMsgEntry               *gmIDENTREQCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10IDENTREQGmEntry(gmIDENTREQCb)
LegMsgEntry               *gmIDENTREQCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10IDENTREQGmEntry);

   /* Populate the IDENTREQ GM Entry */
   gmIDENTREQCb->msgType = EG_S10_IDENTREQ_CMD_CODE;
   gmIDENTREQCb->nmbIeProp = EG_S10_IDENTREQ_NMB_IES;
   gmIDENTREQCb->validateIe = (EscFun )NULLP;

   /* Populate IDENTREQ IE Properties */

   /* Populate GUTI IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_GUTI_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_GUTI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate COMP_REQ_MSG IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_COMP_REQ_MSG_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_COMP_REQ_MSG_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IPADDR IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_IPADDR_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_IPADDR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PORT IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_PORT_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_PORT_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate HOP_CNTR IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_HOP_CNTR_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_HOP_CNTR_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate SERVING_NWK IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_SERVING_NWK_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_SERVING_NWK_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmIDENTREQCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmIDENTREQCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10IDENTREQGmEntry */


/***********************************************************************

   Func  : egMakes10IDENTRSPGmEntry

   Desc  : This function makes the GM Entry for IDENTRSP

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10IDENTRSPGmEntry
(
LegMsgEntry               *gmIDENTRSPCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10IDENTRSPGmEntry(gmIDENTRSPCb)
LegMsgEntry               *gmIDENTRSPCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10IDENTRSPGmEntry);

   /* Populate the IDENTRSP GM Entry */
   gmIDENTRSPCb->msgType = EG_S10_IDENTRSP_CMD_CODE;
   gmIDENTRSPCb->nmbIeProp = EG_S10_IDENTRSP_NMB_IES;
   gmIDENTRSPCb->validateIe = (EscFun )NULLP;

   /* Populate IDENTRSP IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate IMSI IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_IMSI_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_IMSI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GSM_KEY_TRIP IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_GSM_KEY_TRIP_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_GSM_KEY_TRIP_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_CIPH_QUIN IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_CIPH_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_UMTS_KEY_CIPH_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate GSM_KEY_CIPH_QUIN IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_GSM_KEY_CIPH_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_GSM_KEY_CIPH_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_QUIN IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_UMTS_KEY_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate EPS_SEC_QUAD_QUIN IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_EPS_SEC_QUAD_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_EPS_SEC_QUAD_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate UMTS_KEY_QUAD_QUIN IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_UMTS_KEY_QUAD_QUIN_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_UMTS_KEY_QUAD_QUIN_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate TRACE_INFO IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_TRACE_INFO_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_TRACE_INFO_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmIDENTRSPCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmIDENTRSPCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10IDENTRSPGmEntry */


/***********************************************************************

   Func  : egMakes10RELCANCELREQGmEntry

   Desc  : This function makes the GM Entry for RELCANCELREQ

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10RELCANCELREQGmEntry
(
LegMsgEntry               *gmRELCANCELREQCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10RELCANCELREQGmEntry(gmRELCANCELREQCb)
LegMsgEntry               *gmRELCANCELREQCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10RELCANCELREQGmEntry);

   /* Populate the RELCANCELREQ GM Entry */
   gmRELCANCELREQCb->msgType = EG_S10_RELCANCELREQ_CMD_CODE;
   gmRELCANCELREQCb->nmbIeProp = EG_S10_RELCANCELREQ_NMB_IES;
   gmRELCANCELREQCb->validateIe = (EscFun )NULLP;

   /* Populate RELCANCELREQ IE Properties */

   /* Populate IMSI IE Properties */
   egMakeAppIeProp(&gmRELCANCELREQCb->ieProperties[ieCnt],
                    EG_IMSI_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmRELCANCELREQCb->posIndex[0][EG_IMSI_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate F_CAUSE IE Properties */
   egMakeAppIeProp(&gmRELCANCELREQCb->ieProperties[ieCnt],
                    EG_F_CAUSE_IETYPE,EG_IE_CONDITIONAL,0,FALSE);

   gmRELCANCELREQCb->posIndex[0][EG_F_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmRELCANCELREQCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmRELCANCELREQCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10RELCANCELREQGmEntry */


/***********************************************************************

   Func  : egMakes10RELCANCELRSPGmEntry

   Desc  : This function makes the GM Entry for RELCANCELRSP

   Ret   : None

   File  : smegs10.c

************************************************************************/




#ifdef ANSI
PRIVATE void egMakes10RELCANCELRSPGmEntry
(
LegMsgEntry               *gmRELCANCELRSPCb                         /* GM Control Block */
)
#else
PRIVATE void egMakes10RELCANCELRSPGmEntry(gmRELCANCELRSPCb)
LegMsgEntry               *gmRELCANCELRSPCb;
#endif
{
   U8 ieCnt = 0;
   TRC2(egMakes10RELCANCELRSPGmEntry);

   /* Populate the RELCANCELRSP GM Entry */
   gmRELCANCELRSPCb->msgType = EG_S10_RELCANCELRSP_CMD_CODE;
   gmRELCANCELRSPCb->nmbIeProp = EG_S10_RELCANCELRSP_NMB_IES;
   gmRELCANCELRSPCb->validateIe = (EscFun )NULLP;

   /* Populate RELCANCELRSP IE Properties */

   /* Populate CAUSE IE Properties */
   egMakeAppIeProp(&gmRELCANCELRSPCb->ieProperties[ieCnt],
                    EG_CAUSE_IETYPE,EG_IE_MANDATORY,0,FALSE);

   gmRELCANCELRSPCb->posIndex[0][EG_CAUSE_IETYPE]  = ieCnt + 1;
   ieCnt++;

   /* Populate PRIVATE_EXT IE Properties */
   egMakeAppIeProp(&gmRELCANCELRSPCb->ieProperties[ieCnt],
                    EG_PRIVATE_EXT_IETYPE,EG_IE_OPTIONAL,0,FALSE);

   gmRELCANCELRSPCb->posIndex[0][EG_PRIVATE_EXT_IETYPE]  = ieCnt + 1;

} /* End of egMakes10RELCANCELRSPGmEntry */
/***********************************************************************

   Func  : egMakes10GmDict

   Desc  : This functions populates eGTP Messages in GM Dictionary

   Ret   : EG_ROK

   File  : smegs10.c

************************************************************************/


#ifdef ANSI
PUBLIC S16 egMakes10GmDict
(
LegMsgEntry *gmEntry,
U8        *nmbGmMsgs
)
#else
PUBLIC S16 egMakes10GmDict(gmEntry,nmbGmMsgs)
LegMsgEntry *gmEntry;
U8        *nmbGmMsgs;
#endif
{
   U8  gmMsgCount;                  /* Number of eGTP Messages inserted */
   gmMsgCount = 0;

   TRC2(egMakes10GmDict);

   /* Populating CFGTFRTNL GM Entry */
   egMakes10CFGTFRTNLGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating CTXACK GM Entry */
   egMakes10CTXACKGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating CTXREQ GM Entry */
   egMakes10CTXREQGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating CTXRSP GM Entry */
   egMakes10CTXRSPGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating FWDACCSCTXACK GM Entry */
   egMakes10FWDACCSCTXACKGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating FWDACCSCTXNTF GM Entry */
   egMakes10FWDACCSCTXNTFGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating FWDRELCMPACK GM Entry */
   egMakes10FWDRELCMPACKGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating FWDRELCMPNTF GM Entry */
   egMakes10FWDRELCMPNTFGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating FWDRELREQ GM Entry */
   egMakes10FWDRELREQGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating FWDRELRSP GM Entry */
   egMakes10FWDRELRSPGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating IDENTREQ GM Entry */
   egMakes10IDENTREQGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating IDENTRSP GM Entry */
   egMakes10IDENTRSPGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating RELCANCELREQ GM Entry */
   egMakes10RELCANCELREQGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;

   /* Populating RELCANCELRSP GM Entry */
   egMakes10RELCANCELRSPGmEntry(&gmEntry[gmMsgCount]);
   gmMsgCount++;
   *nmbGmMsgs = gmMsgCount;
   RETVALUE(ROK);
} /* End of geMakes10GmDict */

#endif

/********************************************************************30**

         End of file:     eg_dbs10.c@@/main/2 - Fri Feb  4 18:18:02 2011

*********************************************************************31*/

/********************************************************************40**

        Notes:

*********************************************************************41*/

/********************************************************************50**

*********************************************************************51*/


/********************************************************************60**

        Revision history:

*********************************************************************61*/

/********************************************************************80**

*********************************************************************81*/

/********************************************************************90**

    ver       pat    init                  description
----------- -------- ---- -----------------------------------------------
/main/1      ---      an                1. Initial Release
/main/1      ---      kchaitanya        1. Initial for eGTP 1.2 Release
/main/2      ---      svenkat           1. Initial for eGTP 2.1 Release
*********************************************************************91*/

