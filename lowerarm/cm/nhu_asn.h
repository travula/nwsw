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

     Name:     LTE RRC Layer

     Type:     C include file

     Desc:     Defines required by RRC

     File:     nhu_asn.h

     Sid:      nhu_asn.h@@/main/3 - Thu Jun 30 17:19:26 2011

     Prg:      pparande

**********************************************************************/

#ifndef __NHUASNH__
#define __NHUASNH__ 
/* nhu_asn_h_001.main_2: Addded new macros REl9 upgrade*/
#ifdef LTERRC_REL9

#define NHUCHKUNPKPTR(func, val, ptr, mBuf) {\
   S16 ret;\
   if ((ret = func(val, mBuf, ptr)) != ROK)\
      RETVALUE(ret);\
}
#define Nhuid_Invalid 0xffffffff

#define SOUNDINGRS_UL_CONFIGCMN_RELEASE 0
#define SOUNDINGRS_UL_CONFIGCMN_SETUP 1

#define SUBFRAMEALLOCN_ONEFRAME 0
#define SUBFRAMEALLOCN_FOURFRAMES 1

#define FOLLOWINGARFCNS_EXPLICITLSTOFARFCNS 0
#define FOLLOWINGARFCNS_EQUALLYSPACEDARFCNS 1
#define FOLLOWINGARFCNS_VARIABLEBITMAPOFARFCNS 2

#define CDMA_SYSTIME_SYNCHRONOUSSYSTIME 0
#define CDMA_SYSTIME_ASYNCHRONOUSSYSTIME 1

#define MEMBER_SIB2 0
#define MEMBER_SIB3 1
#define MEMBER_SIB4 2
#define MEMBER_SIB5 3
#define MEMBER_SIB6 4
#define MEMBER_SIB7 5
#define MEMBER_SIB8 6
#define MEMBER_SIB9 7
#define MEMBER_SIB10 8
#define MEMBER_SIB11 9
#define MEMBER_SIB12_V920 10
#define MEMBER_SIB13_V920 11

#define CRITICALEXTNS_SYSTEMINFO_R8 0

#define C1_SYSTEMINFO 0
#define C1_SYSTEMINFOBLOCKTYP1 1
#define BCCH_DL_SCH_MSGTYP_C1 0
#define BCCH_DL_SCH_MSGTYP_MESSAGECLASSEXTN 1
#define PLMN_ID_R9_PLMN_IDX_R9 0
#define PLMN_ID_R9_EXPLICITVALUE_R9 1

#define C26_MBSFNAREACFG_R9 0
#define MCCH_MSGTYP_C26 0
#define MCCH_MSGTYP_MESSAGECLASSEXTN 1

#define PAGUE_IDENTITY_S_TMSI 0
#define PAGUE_IDENTITY_IMSI 1

#define C2_PAGING 0
#define PCCH_MSGTYP_C2 0
#define PCCH_MSGTYP_MESSAGECLASSEXTN 1

#define RLC_CONFIG_AM 0
#define RLC_CONFIG_UM_BI_DIRECTIONAL 1
#define RLC_CONFIG_UM_UNI_DIRECTIONAL_UL 2
#define RLC_CONFIG_UM_UNI_DIRECTIONAL_DL 3

#define RLC_CONFIG_EXPLICITVALUE 0
#define RLC_CONFIG_DEFAULTVALUE 1
#define LOGICALCHANNELCONFIG_EXPLICITVALUE 0
#define LOGICALCHANNELCONFIG_DEFAULTVALUE 1
#define HEADERCOMPRESSION_NOTUSED 0
#define HEADERCOMPRESSION_ROHC 1

#define LONGDRX_CYCLESTARTOFFSET_SF10 0
#define LONGDRX_CYCLESTARTOFFSET_SF20 1
#define LONGDRX_CYCLESTARTOFFSET_SF32 2
#define LONGDRX_CYCLESTARTOFFSET_SF40 3
#define LONGDRX_CYCLESTARTOFFSET_SF64 4
#define LONGDRX_CYCLESTARTOFFSET_SF80 5
#define LONGDRX_CYCLESTARTOFFSET_SF128 6
#define LONGDRX_CYCLESTARTOFFSET_SF160 7
#define LONGDRX_CYCLESTARTOFFSET_SF256 8
#define LONGDRX_CYCLESTARTOFFSET_SF320 9
#define LONGDRX_CYCLESTARTOFFSET_SF512 10
#define LONGDRX_CYCLESTARTOFFSET_SF640 11
#define LONGDRX_CYCLESTARTOFFSET_SF1024 12
#define LONGDRX_CYCLESTARTOFFSET_SF1280 13
#define LONGDRX_CYCLESTARTOFFSET_SF2048 14
#define LONGDRX_CYCLESTARTOFFSET_SF2560 15
#define DRX_CONFIG_RELEASE 0
#define DRX_CONFIG_SETUP 1
#define PHR_CONFIG_RELEASE 0
#define PHR_CONFIG_SETUP 1

#define SPS_CONFIGDL_RELEASE 0
#define SPS_CONFIGDL_SETUP 1

#define SPS_CONFIGUL_RELEASE 0
#define SPS_CONFIGUL_SETUP 1

#define ACKNACKREPETITION_RELEASE 0
#define ACKNACKREPETITION_SETUP 1

#define TPC_IDX_INDEXOFFORMAT3 0
#define TPC_IDX_INDEXOFFORMAT3A 1

#define TPC_PDCCH_CONFIG_RELEASE 0
#define TPC_PDCCH_CONFIG_SETUP 1

#define CQI_FORMATINDICATORPERIODIC_WIDEBANDCQI 0
#define CQI_FORMATINDICATORPERIODIC_SUBBANDCQI 1
#define CQI_REPORTPERIODIC_RELEASE 0
#define CQI_REPORTPERIODIC_SETUP 1
#define SOUNDINGRS_UL_CONFIGDEDICATED_RELEASE 0
#define SOUNDINGRS_UL_CONFIGDEDICATED_SETUP 1

#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM3 0
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM3 1
#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM4 2
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM4 3
#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM5 4
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM5 5
#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM6 6
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM6 7
#define UE_TRANSMITANTENNASELECTION_RELEASE 0
#define UE_TRANSMITANTENNASELECTION_SETUP 1
#define SCHEDULINGRQSTCONFIG_RELEASE 0
#define SCHEDULINGRQSTCONFIG_SETUP 1

#define CODEBOOKSUBSETRESTRN_V920_N2TXANTENNA_TM8_R9 0
#define CODEBOOKSUBSETRESTRN_V920_N4TXANTENNA_TM8_R9 1

#define ANTENNAINFO_EXPLICITVALUE 0
#define ANTENNAINFO_DEFAULTVALUE 1

#define RLF_TMRSANDCONSTS_R9_RELEASE 0
#define RLF_TMRSANDCONSTS_R9_SETUP 1

#define MAC_MAINCONFIG_EXPLICITVALUE 0
#define MAC_MAINCONFIG_DEFAULTVALUE 1

#define C13_RRCCONREESTB_R8 0
#define C13_SPARE7 1
#define C13_SPARE6 2
#define C13_SPARE5 3
#define C13_SPARE4 4
#define C13_SPARE3 5
#define C13_SPARE2 6
#define C13_SPARE1 7
#define CRITICALEXTNS_C13 0
#define CRITICALEXTNS_RRCCONREESTBREJ_R8 0

#define C14_RRCCONREJ_R8 0
#define C14_SPARE3 1
#define C14_SPARE2 2
#define C14_SPARE1 3
#define CRITICALEXTNS_C14 0
#define C16_RRCCONSETUP_R8 0
#define C16_SPARE7 1
#define C16_SPARE6 2
#define C16_SPARE5 3
#define C16_SPARE4 4
#define C16_SPARE3 5
#define C16_SPARE2 6
#define C16_SPARE1 7
#define CRITICALEXTNS_C16 0
#define C3_RRCCONREESTB 0
#define C3_RRCCONREESTBREJ 1
#define C3_RRCCONREJ 2
#define C3_RRCCONSETUP 3
#define DL_CCCH_MSGTYP_C3 0
#define DL_CCCH_MSGTYP_MESSAGECLASSEXTN 1
#define CRITICALEXTNS_CSFBPARAMSRSPCDMA2000_R8 0

#define DEDICATEDINFOTYP_DEDICATEDINFONAS 0
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_1XRTT 1
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_HRPD 2

#define C8_DLINFOTFR_R8 0
#define C8_SPARE3 1
#define C8_SPARE2 2
#define C8_SPARE1 3
#define CRITICALEXTNS_C8 0
#define C9_HANDOVERFROMEUTRAPREPRQST_R8 0
#define C9_SPARE3 1
#define C9_SPARE2 2
#define C9_SPARE1 3
#define CRITICALEXTNS_C9 0
#define SI_ORPSI_GERAN_SI 0
#define SI_ORPSI_GERAN_PSI 1

#define TARGETRAT_TYP_GERAN 0

#define PURPOSE_HANDOVER 0
#define PURPOSE_CELLCHANGEORDER 1

#define PURPOSE_HANDOVER 0
#define PURPOSE_CELLCHANGEORDER 1
#define PURPOSE_E_CSFB_R9 2

#define C11_MOBILITYFROMEUTRACMD_R8 0
#define C11_MOBILITYFROMEUTRACMD_R9 1
#define C11_SPARE2 2
#define C11_SPARE1 3
#define CRITICALEXTNS_C11 0 
#define CELLSTOADDMODLST_CELLSTOADDMODLSTUTRA_FDD 0
#define CELLSTOADDMODLST_CELLSTOADDMODLSTUTRA_TDD 1
#define CELLFORWHICHTOREPORTCGI_UTRA_FDD 0
#define CELLFORWHICHTOREPORTCGI_UTRA_TDD 1
#define MEASOBJECT_MEASOBJECTEUTRA 0
#define MEASOBJECT_MEASOBJECTUTRA 1
#define MEASOBJECT_MEASOBJECTGERAN 2
#define MEASOBJECT_MEASOBJECTCDMA2000 3

#define THRESHOLDEUTRA_THRESHOLD_RSRP 0
#define THRESHOLDEUTRA_THRESHOLD_RSRQ 1

#define EVENTID_EVENTA1 0
#define EVENTID_EVENTA2 1
#define EVENTID_EVENTA3 2
#define EVENTID_EVENTA4 3
#define EVENTID_EVENTA5 4
#define TRIGGERTYP_EVENT 0
#define TRIGGERTYP_PERIODICAL 1
#define THRESHOLDUTRA_UTRA_RSCP 0
#define THRESHOLDUTRA_UTRA_ECN0 1

#define B1_THRESHOLD_B1_THRESHOLDUTRA 0
#define B1_THRESHOLD_B1_THRESHOLDGERAN 1
#define B1_THRESHOLD_B1_THRESHOLDCDMA2000 2
#define B2_THRESHOLD2_B2_THRESHOLD2UTRA 0
#define B2_THRESHOLD2_B2_THRESHOLD2GERAN 1
#define B2_THRESHOLD2_B2_THRESHOLD2CDMA2000 2
#define EVENTID_EVENTB1 0
#define EVENTID_EVENTB2 1
#define TRIGGERTYP_EVENT 0
#define TRIGGERTYP_PERIODICAL 1
#define REPORTCONFIG_REPORTCONFIGEUTRA 0
#define REPORTCONFIG_REPORTCONFIGINTERRAT 1

#define GAPOFFSET_GP0 0
#define GAPOFFSET_GP1 1
#define MEASGAPCONFIG_RELEASE 0
#define MEASGAPCONFIG_SETUP 1
#define SPEEDSTATEPARS_RELEASE 0
#define SPEEDSTATEPARS_SETUP 1

#define HANDOVERTYP_INTRALTE 0
#define HANDOVERTYP_INTERRAT 1

#define C12_RRCCONRECFGN_R8 0
#define C12_SPARE7 1
#define C12_SPARE6 2
#define C12_SPARE5 3
#define C12_SPARE4 4
#define C12_SPARE3 5
#define C12_SPARE2 6
#define C12_SPARE1 7
#define CRITICALEXTNS_C12 0
#define REDIRECTEDCARRIERINFO_EUTRA 0
#define REDIRECTEDCARRIERINFO_GERAN 1
#define REDIRECTEDCARRIERINFO_UTRA_FDD 2
#define REDIRECTEDCARRIERINFO_UTRA_TDD 3
#define REDIRECTEDCARRIERINFO_CDMA2000_HRPD 4
#define REDIRECTEDCARRIERINFO_CDMA2000_1XRTT 5

#define CELLINFOLST_R9_GERAN_R9 0
#define CELLINFOLST_R9_UTRA_FDD_R9 1
#define CELLINFOLST_R9_UTRA_TDD_R9 2

#define C15_RRCCONRLS_R8 0
#define C15_SPARE3 1
#define C15_SPARE2 2
#define C15_SPARE1 3
#define CRITICALEXTNS_C15 0
#define C18_SECURITYMODECMD_R8 0
#define C18_SPARE3 1
#define C18_SPARE2 2
#define C18_SPARE1 3
#define CRITICALEXTNS_C18 0
#define C19_UECAPENQUIRY_R8 0
#define C19_SPARE3 1
#define C19_SPARE2 2
#define C19_SPARE1 3
#define CRITICALEXTNS_C19 0
#define C7_COUNTERCHECK_R8 0
#define C7_SPARE3 1
#define C7_SPARE2 2
#define C7_SPARE1 3
#define CRITICALEXTNS_C7 0
#define C28_UEINFORQST_R9 0
#define C28_SPARE3 1
#define C28_SPARE2 2
#define C28_SPARE1 3
#define CRITICALEXTNS_C28 0
#define C4_CSFBPARAMSRSPCDMA2000 0
#define C4_DLINFOTFR 1
#define C4_HANDOVERFROMEUTRAPREPRQST 2
#define C4_MOBILITYFROMEUTRACMD 3
#define C4_RRCCONRECFGN 4
#define C4_RRCCONRLS 5
#define C4_SECURITYMODECMD 6
#define C4_UECAPENQUIRY 7
#define C4_COUNTERCHECK 8
#define C4_UEINFORQST_R9 9
#define C4_SPARE6 10
#define C4_SPARE5 11
#define C4_SPARE4 12
#define C4_SPARE3 13
#define C4_SPARE2 14
#define C4_SPARE1 15
#define DL_DCCH_MSGTYP_C4 0
#define DL_DCCH_MSGTYP_MESSAGECLASSEXTN 1
#define CRITICALEXTNS_RRCCONREESTBRQST_R8 0

#define INITUE_IDENTITY_S_TMSI 0
#define INITUE_IDENTITY_RANDOMVALUE 1

#define CRITICALEXTNS_RRCCONRQST_R8 0

#define C5_RRCCONREESTBRQST 0
#define C5_RRCCONRQST 1
#define UL_CCCH_MSGTYP_C5 0 
#define UL_CCCH_MSGTYP_MESSAGECLASSEXTN 1
#define CRITICALEXTNS_CSFBPARAMSRQSTCDMA2000_R8 0

#define PHYSCELLID_FDD 0
#define PHYSCELLID_TDD 1

#define CELLGLOBALIDCDMA2000_CELLGLOBALID1XRTT 0
#define CELLGLOBALIDCDMA2000_CELLGLOBALIDHRPD 1

#define MEASRESULTNEIGHCELLS_MEASRESULTLSTEUTRA 0
#define MEASRESULTNEIGHCELLS_MEASRESULTLSTUTRA 1
#define MEASRESULTNEIGHCELLS_MEASRESULTLSTGERAN 2
#define MEASRESULTNEIGHCELLS_MEASRESULTSCDMA2000 3

#define C10_MEASUREMENTREPORT_R8 0
#define C10_SPARE7 1
#define C10_SPARE6 2
#define C10_SPARE5 3
#define C10_SPARE4 4
#define C10_SPARE3 5
#define C10_SPARE2 6
#define C10_SPARE1 7
#define CRITICALEXTNS_C10 0
#define CRITICALEXTNS_RRCCONRECFGNCOMPL_R8 0

#define CRITICALEXTNS_RRCCONREESTBCOMPL_R8 0

#define C17_RRCCONSETUPCOMPL_R8 0
#define C17_SPARE3 1
#define C17_SPARE2 2
#define C17_SPARE1 3
#define CRITICALEXTNS_C17 0
#define CRITICALEXTNS_SECURITYMODECOMPL_R8 0

#define CRITICALEXTNS_SECURITYMODEFAIL_R8 0

#define C20_UECAPINFO_R8 0
#define C20_SPARE7 1
#define C20_SPARE6 2
#define C20_SPARE5 3
#define C20_SPARE4 4
#define C20_SPARE3 5
#define C20_SPARE2 6
#define C20_SPARE1 7
#define CRITICALEXTNS_C20 0
#define C21_ULHOVRPREPTFR_R8 0
#define C21_SPARE3 1
#define C21_SPARE2 2
#define C21_SPARE1 3
#define CRITICALEXTNS_C21 0
#define DEDICATEDINFOTYP_DEDICATEDINFONAS 0
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_1XRTT 1
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_HRPD 2

#define C25_ULINFOTFR_R8 0
#define C25_SPARE3 1
#define C25_SPARE2 2
#define C25_SPARE1 3
#define CRITICALEXTNS_C25 0
#define CRITICALEXTNS_COUNTERCHECKRSP_R8 0

#define C29_UEINFORSP_R9 0
#define C29_SPARE3 1
#define C29_SPARE2 2
#define C29_SPARE1 3
#define CRITICALEXTNS_C29 0
#define CARRIERFREQ_R9_EUTRA_R9 0
#define CARRIERFREQ_R9_UTRA_R9 1

#define C27_PROXIMITYIND_R9 0
#define C27_SPARE3 1
#define C27_SPARE2 2
#define C27_SPARE1 3
#define CRITICALEXTNS_C27 0
#define C6_CSFBPARAMSRQSTCDMA2000 0
#define C6_MEASUREMENTREPORT 1
#define C6_RRCCONRECFGNCOMPL 2
#define C6_RRCCONREESTBCOMPL 3
#define C6_RRCCONSETUPCOMPL 4
#define C6_SECURITYMODECOMPL 5
#define C6_SECURITYMODEFAIL 6
#define C6_UECAPINFO 7
#define C6_ULHOVRPREPTFR 8
#define C6_ULINFOTFR 9
#define C6_COUNTERCHECKRSP 10
#define C6_UEINFORSP_R9 11
#define C6_PROXIMITYIND_R9 12
#define C6_SPARE3 13
#define C6_SPARE2 14
#define C6_SPARE1 15
#define UL_DCCH_MSGTYP_C6 0
#define UL_DCCH_MSGTYP_MESSAGECLASSEXTN 1
#define NhumaxBands 64
#define NhumaxCDMA_BandClass 32
#define NhumaxCellBlack 16
#define NhumaxCellInfoGERAN_r9 32
#define NhumaxCellInfoUTRA_r9 16
#define NhumaxCellInter 16
#define NhumaxCellIntra 16
#define NhumaxCellMeas 32
#define NhumaxCellReport 8
#define NhumaxDRB 11
#define NhumaxEARFCN 65535
#define NhumaxFreq 8
#define NhumaxGERAN_SI 10
#define NhumaxGNFG 16
#define NhumaxMBSFN_Allocns 8
#define NhumaxMBSFN_Area 8
#define NhumaxMeasId 32
#define NhumaxObjectId 32
#define NhumaxPageRec 16
#define NhumaxPhysCellIdRange_r9 4
#define NhumaxPNOffset 511
#define NhumaxPMCH_PerMBSFN 15
#define NhumaxRAT_Capabilities 8
#define NhumaxReportConfigId 32
#define NhumaxSessionPerPMCH 29
#define NhumaxSessionPerPMCH_1 28
#define NhumaxSIB 32
#define NhumaxSIB_1 31
#define NhumaxSI_Msg 32
#define NhumaxUTRA_FDD_Carrier 16
#define NhumaxUTRA_TDD_Carrier 16

#define SPEEDSTATEPARS_RELEASE 0
#define SPEEDSTATEPARS_SETUP 1

#define PHYSCELLIDUTRA_FDD 0
#define PHYSCELLIDUTRA_TDD 1
#define MEMBER_PHYSCELLIDEUTRA 0
#define MEMBER_PHYSCELLIDUTRA 1
#define MEMBER_PHYSCELLIDGERAN 2
#define MEMBER_PHYSCELLIDCDMA2000 3

#define C22_HANDOVERCMD_R8 0
#define C22_SPARE7 1
#define C22_SPARE6 2
#define C22_SPARE5 3
#define C22_SPARE4 4
#define C22_SPARE3 5
#define C22_SPARE2 6
#define C22_SPARE1 7
#define CRITICALEXTNS_C22 0
#define C23_HANDOVERPREPINFO_R8 0
#define C23_SPARE7 1
#define C23_SPARE6 2
#define C23_SPARE5 3
#define C23_SPARE4 4
#define C23_SPARE3 5
#define C23_SPARE2 6
#define C23_SPARE1 7
#define CRITICALEXTNS_C23 0
#define C24_UERADIOACCESSCAPINFO_R8 0
#define C24_SPARE7 1
#define C24_SPARE6 2
#define C24_SPARE5 3
#define C24_SPARE4 4
#define C24_SPARE3 5
#define C24_SPARE2 6
#define C24_SPARE1 7
#define CRITICALEXTNS_C24 0
#define NhumaxReestabInfo 32

#define CRITICALEXTNS_CRITICALEXTNSFUTURE 1

#else /* LTERRC_REL9 */

#define NHUCHKUNPKPTR(func, val, ptr, mBuf) {\
   S16 ret;\
   if ((ret = func(val, mBuf, ptr)) != ROK)\
      RETVALUE(ret);\
}
#define Nhuid_Invalid 0xffffffff

#define SOUNDINGRS_UL_CONFIGCMN_RELEASE 0
#define SOUNDINGRS_UL_CONFIGCMN_SETUP 1

#define SUBFRAMEALLOCN_ONEFRAME 0
#define SUBFRAMEALLOCN_FOURFRAMES 1

#define FOLLOWINGARFCNS_EXPLICITLSTOFARFCNS 0
#define FOLLOWINGARFCNS_EQUALLYSPACEDARFCNS 1
#define FOLLOWINGARFCNS_VARIABLEBITMAPOFARFCNS 2

#define CDMA_SYSTIME_SYNCHRONOUSSYSTIME 0
#define CDMA_SYSTIME_ASYNCHRONOUSSYSTIME 1

#define MEMBER_SIB2 0
#define MEMBER_SIB3 1
#define MEMBER_SIB4 2
#define MEMBER_SIB5 3
#define MEMBER_SIB6 4
#define MEMBER_SIB7 5
#define MEMBER_SIB8 6
#define MEMBER_SIB9 7
#define MEMBER_SIB10 8
#define MEMBER_SIB11 9

#define CRITICALEXTNS_SYSTEMINFO_R8 0

#define C1_SYSTEMINFO 0
#define C1_SYSTEMINFOBLOCKTYP1 1
#define BCCH_DL_SCH_MSGTYP_C1 0
#define BCCH_DL_SCH_MSGTYP_MESSAGECLASSEXTN 1
#define PAGUE_IDENTITY_S_TMSI 0
#define PAGUE_IDENTITY_IMSI 1

#define C2_PAGING 0
#define PCCH_MSGTYP_C2 0
#define PCCH_MSGTYP_MESSAGECLASSEXTN 1

#define RLC_CONFIG_AM 0
#define RLC_CONFIG_UM_BI_DIRECTIONAL 1
#define RLC_CONFIG_UM_UNI_DIRECTIONAL_UL 2
#define RLC_CONFIG_UM_UNI_DIRECTIONAL_DL 3

#define RLC_CONFIG_EXPLICITVALUE 0
#define RLC_CONFIG_DEFAULTVALUE 1
#define LOGICALCHANNELCONFIG_EXPLICITVALUE 0
#define LOGICALCHANNELCONFIG_DEFAULTVALUE 1
#define HEADERCOMPRESSION_NOTUSED 0
#define HEADERCOMPRESSION_ROHC 1

#define LONGDRX_CYCLESTARTOFFSET_SF10 0
#define LONGDRX_CYCLESTARTOFFSET_SF20 1
#define LONGDRX_CYCLESTARTOFFSET_SF32 2
#define LONGDRX_CYCLESTARTOFFSET_SF40 3
#define LONGDRX_CYCLESTARTOFFSET_SF64 4
#define LONGDRX_CYCLESTARTOFFSET_SF80 5
#define LONGDRX_CYCLESTARTOFFSET_SF128 6
#define LONGDRX_CYCLESTARTOFFSET_SF160 7
#define LONGDRX_CYCLESTARTOFFSET_SF256 8
#define LONGDRX_CYCLESTARTOFFSET_SF320 9
#define LONGDRX_CYCLESTARTOFFSET_SF512 10
#define LONGDRX_CYCLESTARTOFFSET_SF640 11
#define LONGDRX_CYCLESTARTOFFSET_SF1024 12
#define LONGDRX_CYCLESTARTOFFSET_SF1280 13
#define LONGDRX_CYCLESTARTOFFSET_SF2048 14
#define LONGDRX_CYCLESTARTOFFSET_SF2560 15
#define DRX_CONFIG_RELEASE 0
#define DRX_CONFIG_SETUP 1
#define PHR_CONFIG_RELEASE 0
#define PHR_CONFIG_SETUP 1

#define SPS_CONFIGDL_RELEASE 0
#define SPS_CONFIGDL_SETUP 1

#define SPS_CONFIGUL_RELEASE 0
#define SPS_CONFIGUL_SETUP 1

#define ACKNACKREPETITION_RELEASE 0
#define ACKNACKREPETITION_SETUP 1

#define TPC_IDX_INDEXOFFORMAT3 0
#define TPC_IDX_INDEXOFFORMAT3A 1

#define TPC_PDCCH_CONFIG_RELEASE 0
#define TPC_PDCCH_CONFIG_SETUP 1

#define CQI_FORMATINDICATORPERIODIC_WIDEBANDCQI 0
#define CQI_FORMATINDICATORPERIODIC_SUBBANDCQI 1
#define CQI_REPORTPERIODIC_RELEASE 0
#define CQI_REPORTPERIODIC_SETUP 1
#define SOUNDINGRS_UL_CONFIGDEDICATED_RELEASE 0
#define SOUNDINGRS_UL_CONFIGDEDICATED_SETUP 1

#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM3 0
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM3 1
#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM4 2
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM4 3
#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM5 4
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM5 5
#define CODEBOOKSUBSETRESTRN_N2TXANTENNA_TM6 6
#define CODEBOOKSUBSETRESTRN_N4TXANTENNA_TM6 7
#define UE_TRANSMITANTENNASELECTION_RELEASE 0
#define UE_TRANSMITANTENNASELECTION_SETUP 1
#define SCHEDULINGRQSTCONFIG_RELEASE 0
#define SCHEDULINGRQSTCONFIG_SETUP 1

#define ANTENNAINFO_EXPLICITVALUE 0
#define ANTENNAINFO_DEFAULTVALUE 1

#define MAC_MAINCONFIG_EXPLICITVALUE 0
#define MAC_MAINCONFIG_DEFAULTVALUE 1

#define C13_RRCCONREESTB_R8 0
#define C13_SPARE7 1
#define C13_SPARE6 2
#define C13_SPARE5 3
#define C13_SPARE4 4
#define C13_SPARE3 5
#define C13_SPARE2 6
#define C13_SPARE1 7
#define CRITICALEXTNS_C13 0
#define CRITICALEXTNS_RRCCONREESTBREJ_R8 0

#define C14_RRCCONREJ_R8 0
#define C14_SPARE3 1
#define C14_SPARE2 2
#define C14_SPARE1 3
#define CRITICALEXTNS_C14 0
#define C16_RRCCONSETUP_R8 0
#define C16_SPARE7 1
#define C16_SPARE6 2
#define C16_SPARE5 3
#define C16_SPARE4 4
#define C16_SPARE3 5
#define C16_SPARE2 6
#define C16_SPARE1 7
#define CRITICALEXTNS_C16 0
#define C3_RRCCONREESTB 0
#define C3_RRCCONREESTBREJ 1
#define C3_RRCCONREJ 2
#define C3_RRCCONSETUP 3
#define DL_CCCH_MSGTYP_C3 0
#define DL_CCCH_MSGTYP_MESSAGECLASSEXTN 1
#define CRITICALEXTNS_CSFBPARAMSRSPCDMA2000_R8 0

#define DEDICATEDINFOTYP_DEDICATEDINFONAS 0
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_1XRTT 1
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_HRPD 2

#define C8_DLINFOTFR_R8 0
#define C8_SPARE3 1
#define C8_SPARE2 2
#define C8_SPARE1 3
#define CRITICALEXTNS_C8 0
#define C9_HANDOVERFROMEUTRAPREPRQST_R8 0
#define C9_SPARE3 1
#define C9_SPARE2 2
#define C9_SPARE1 3
#define CRITICALEXTNS_C9 0
#define SI_ORPSI_GERAN_SI 0
#define SI_ORPSI_GERAN_PSI 1

#define TARGETRAT_TYP_GERAN 0

#define PURPOSE_HANDOVER 0
#define PURPOSE_CELLCHANGEORDER 1

#define C11_MOBILITYFROMEUTRACMD_R8 0
#define C11_SPARE3 1
#define C11_SPARE2 2
#define C11_SPARE1 3
#define CRITICALEXTNS_C11 0
#define CELLSTOADDMODLST_CELLSTOADDMODLSTUTRA_FDD 0
#define CELLSTOADDMODLST_CELLSTOADDMODLSTUTRA_TDD 1
#define CELLFORWHICHTOREPORTCGI_UTRA_FDD 0
#define CELLFORWHICHTOREPORTCGI_UTRA_TDD 1
#define MEASOBJECT_MEASOBJECTEUTRA 0
#define MEASOBJECT_MEASOBJECTUTRA 1
#define MEASOBJECT_MEASOBJECTGERAN 2
#define MEASOBJECT_MEASOBJECTCDMA2000 3

#define THRESHOLDEUTRA_THRESHOLD_RSRP 0
#define THRESHOLDEUTRA_THRESHOLD_RSRQ 1

#define EVENTID_EVENTA1 0
#define EVENTID_EVENTA2 1
#define EVENTID_EVENTA3 2
#define EVENTID_EVENTA4 3
#define EVENTID_EVENTA5 4
#define TRIGGERTYP_EVENT 0
#define TRIGGERTYP_PERIODICAL 1
#define THRESHOLDUTRA_UTRA_RSCP 0
#define THRESHOLDUTRA_UTRA_ECN0 1

#define B1_THRESHOLD_B1_THRESHOLDUTRA 0
#define B1_THRESHOLD_B1_THRESHOLDGERAN 1
#define B1_THRESHOLD_B1_THRESHOLDCDMA2000 2
#define B2_THRESHOLD2_B2_THRESHOLD2UTRA 0
#define B2_THRESHOLD2_B2_THRESHOLD2GERAN 1
#define B2_THRESHOLD2_B2_THRESHOLD2CDMA2000 2
#define EVENTID_EVENTB1 0
#define EVENTID_EVENTB2 1
#define TRIGGERTYP_EVENT 0
#define TRIGGERTYP_PERIODICAL 1
#define REPORTCONFIG_REPORTCONFIGEUTRA 0
#define REPORTCONFIG_REPORTCONFIGINTERRAT 1

#define GAPOFFSET_GP0 0
#define GAPOFFSET_GP1 1
#define MEASGAPCONFIG_RELEASE 0
#define MEASGAPCONFIG_SETUP 1
#define SPEEDSTATEPARS_RELEASE 0
#define SPEEDSTATEPARS_SETUP 1

#define HANDOVERTYP_INTRALTE 0
#define HANDOVERTYP_INTERRAT 1

#define C12_RRCCONRECFGN_R8 0
#define C12_SPARE7 1
#define C12_SPARE6 2
#define C12_SPARE5 3
#define C12_SPARE4 4
#define C12_SPARE3 5
#define C12_SPARE2 6
#define C12_SPARE1 7
#define CRITICALEXTNS_C12 0
#define REDIRECTEDCARRIERINFO_EUTRA 0
#define REDIRECTEDCARRIERINFO_GERAN 1
#define REDIRECTEDCARRIERINFO_UTRA_FDD 2
#define REDIRECTEDCARRIERINFO_UTRA_TDD 3
#define REDIRECTEDCARRIERINFO_CDMA2000_HRPD 4
#define REDIRECTEDCARRIERINFO_CDMA2000_1XRTT 5

#define C15_RRCCONRLS_R8 0
#define C15_SPARE3 1
#define C15_SPARE2 2
#define C15_SPARE1 3
#define CRITICALEXTNS_C15 0
#define C18_SECURITYMODECMD_R8 0
#define C18_SPARE3 1
#define C18_SPARE2 2
#define C18_SPARE1 3
#define CRITICALEXTNS_C18 0
#define C19_UECAPENQUIRY_R8 0
#define C19_SPARE3 1
#define C19_SPARE2 2
#define C19_SPARE1 3
#define CRITICALEXTNS_C19 0
#define C7_COUNTERCHECK_R8 0
#define C7_SPARE3 1
#define C7_SPARE2 2
#define C7_SPARE1 3
#define CRITICALEXTNS_C7 0
#define C4_CSFBPARAMSRSPCDMA2000 0
#define C4_DLINFOTFR 1
#define C4_HANDOVERFROMEUTRAPREPRQST 2
#define C4_MOBILITYFROMEUTRACMD 3
#define C4_RRCCONRECFGN 4
#define C4_RRCCONRLS 5
#define C4_SECURITYMODECMD 6
#define C4_UECAPENQUIRY 7
#define C4_COUNTERCHECK 8
#define C4_SPARE7 9
#define C4_SPARE6 10
#define C4_SPARE5 11
#define C4_SPARE4 12
#define C4_SPARE3 13
#define C4_SPARE2 14
#define C4_SPARE1 15
#define DL_DCCH_MSGTYP_C4 0
#define DL_DCCH_MSGTYP_MESSAGECLASSEXTN 1
#define CRITICALEXTNS_RRCCONREESTBRQST_R8 0

#define INITUE_IDENTITY_S_TMSI 0
#define INITUE_IDENTITY_RANDOMVALUE 1

#define CRITICALEXTNS_RRCCONRQST_R8 0

#define C5_RRCCONREESTBRQST 0
#define C5_RRCCONRQST 1
#define UL_CCCH_MSGTYP_C5 0
#define UL_CCCH_MSGTYP_MESSAGECLASSEXTN 1
#define CRITICALEXTNS_CSFBPARAMSRQSTCDMA2000_R8 0

#define PHYSCELLID_FDD 0
#define PHYSCELLID_TDD 1

#define CELLGLOBALIDCDMA2000_CELLGLOBALID1XRTT 0
#define CELLGLOBALIDCDMA2000_CELLGLOBALIDHRPD 1

#define MEASRESULTNEIGHCELLS_MEASRESULTLSTEUTRA 0
#define MEASRESULTNEIGHCELLS_MEASRESULTLSTUTRA 1
#define MEASRESULTNEIGHCELLS_MEASRESULTLSTGERAN 2
#define MEASRESULTNEIGHCELLS_MEASRESULTSCDMA2000 3

#define C10_MEASUREMENTREPORT_R8 0
#define C10_SPARE7 1
#define C10_SPARE6 2
#define C10_SPARE5 3
#define C10_SPARE4 4
#define C10_SPARE3 5
#define C10_SPARE2 6
#define C10_SPARE1 7
#define CRITICALEXTNS_C10 0
#define CRITICALEXTNS_RRCCONRECFGNCOMPL_R8 0

#define CRITICALEXTNS_RRCCONREESTBCOMPL_R8 0

#define C17_RRCCONSETUPCOMPL_R8 0
#define C17_SPARE3 1
#define C17_SPARE2 2
#define C17_SPARE1 3
#define CRITICALEXTNS_C17 0
#define CRITICALEXTNS_SECURITYMODECOMPL_R8 0

#define CRITICALEXTNS_SECURITYMODEFAIL_R8 0

#define C20_UECAPINFO_R8 0
#define C20_SPARE7 1
#define C20_SPARE6 2
#define C20_SPARE5 3
#define C20_SPARE4 4
#define C20_SPARE3 5
#define C20_SPARE2 6
#define C20_SPARE1 7
#define CRITICALEXTNS_C20 0
#define C21_ULHOVRPREPTFR_R8 0
#define C21_SPARE3 1
#define C21_SPARE2 2
#define C21_SPARE1 3
#define CRITICALEXTNS_C21 0
#define DEDICATEDINFOTYP_DEDICATEDINFONAS 0
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_1XRTT 1
#define DEDICATEDINFOTYP_DEDICATEDINFOCDMA2000_HRPD 2

#define C21_ULINFOTFR_R8 0
#define C21_SPARE3 1
#define C21_SPARE2 2
#define C21_SPARE1 3
#define CRITICALEXTNS_C21 0
#define CRITICALEXTNS_COUNTERCHECKRSP_R8 0

#define C6_CSFBPARAMSRQSTCDMA2000 0
#define C6_MEASUREMENTREPORT 1
#define C6_RRCCONRECFGNCOMPL 2
#define C6_RRCCONREESTBCOMPL 3
#define C6_RRCCONSETUPCOMPL 4
#define C6_SECURITYMODECOMPL 5
#define C6_SECURITYMODEFAIL 6
#define C6_UECAPINFO 7
#define C6_ULHOVRPREPTFR 8
#define C6_ULINFOTFR 9
#define C6_COUNTERCHECKRSP 10
#define C6_SPARE5 11
#define C6_SPARE4 12
#define C6_SPARE3 13
#define C6_SPARE2 14
#define C6_SPARE1 15
#define UL_DCCH_MSGTYP_C6 0
#define UL_DCCH_MSGTYP_MESSAGECLASSEXTN 1
#define NhumaxBands 64
#define NhumaxCDMA_BandClass 32
#define NhumaxCellBlack 16
#define NhumaxCellInter 16
#define NhumaxCellIntra 16
#define NhumaxCellMeas 32
#define NhumaxCellReport 8
#define NhumaxDRB 11
#define NhumaxEARFCN 65535
#define NhumaxFreq 8
#define NhumaxGERAN_SI 10
#define NhumaxGNFG 16
#define NhumaxMBSFN_Allocns 8
#define NhumaxMCS_1 16
#define NhumaxMeasId 32
#define NhumaxObjectId 32
#define NhumaxPageRec 16
#define NhumaxPNOffset 511
#define NhumaxRAT_Capabilities 8
#define NhumaxReportConfigId 32
#define NhumaxSIB 32
#define NhumaxSIB_1 31
#define NhumaxSI_Msg 32
#define NhumaxUTRA_FDD_Carrier 16
#define NhumaxUTRA_TDD_Carrier 16

#define SPEEDSTATEPARS_RELEASE 0
#define SPEEDSTATEPARS_SETUP 1

#define C22_HANDOVERCMD_R8 0
#define C22_SPARE7 1
#define C22_SPARE6 2
#define C22_SPARE5 3
#define C22_SPARE4 4
#define C22_SPARE3 5
#define C22_SPARE2 6
#define C22_SPARE1 7
#define CRITICALEXTNS_C22 0
#define C23_HANDOVERPREPINFO_R8 0
#define C23_SPARE7 1
#define C23_SPARE6 2
#define C23_SPARE5 3
#define C23_SPARE4 4
#define C23_SPARE3 5
#define C23_SPARE2 6
#define C23_SPARE1 7
#define CRITICALEXTNS_C23 0
#define C24_UERADIOACCESSCAPINFO_R8 0
#define C24_SPARE7 1
#define C24_SPARE6 2
#define C24_SPARE5 3
#define C24_SPARE4 4
#define C24_SPARE3 5
#define C24_SPARE2 6
#define C24_SPARE1 7
#define CRITICALEXTNS_C24 0
#define CRITICALEXTNS_CRITICALEXTNSFUTURE 1
#define NhumaxReestabInfo 32
#endif /* LTERRC_REL9 */

#endif
/**********************************************************************
         End of file:     nhu_asn.h@@/main/3 - Thu Jun 30 17:19:26 2011
**********************************************************************/
/**********************************************************************

        Revision history:

**********************************************************************/
/********************************************************************90**

     ver       pat    init                  description
------------ -------- ---- ----------------------------------------------
/main/1      ---                 chebli        1. RRC LTE Initial Release.
/main/3      ---      nhu_asn_h_001.main_2 sbalakrishna  1. Updated for Release of 3.1.
*********************************************************************91*/