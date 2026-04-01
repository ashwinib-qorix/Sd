/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Cbk.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the callback functions of Service Discovery**
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
** Prev. AUTOSAR Version : R23-11                                             **
**                                                                            **
** Prev. Software Version : 1.0.0                                             **
**                                                                            **
**  Design ID : SD_SDD_0335                                                   **
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Date         Changed By          Description                               **
********************************************************************************
** 07-Jul-2025  Gourav Purohit      Initial Release.                          **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                          Parasoft violations Section                       **
*******************************************************************************/

/* parasoft-begin-suppress MISRAC2012-RULE_20_1-a-4 "Reason: The warning is 
* getting reported for the inclusion of 'Sd_MemMap.h', this inclusion can 
* not be avoided, so this warning needs to be deviated." */

/* parasoft-begin-suppress MISRAC2012-RULE_5_4-c-2 "Reason: The warning is 
* getting reported for the memory section declaration which can not be 
* avoided, These macros are part of AUTOSAR Specific definitions for
* inclusion of memory map files for Code and Global data sections and
* configuration Specific macros present in .h, so this warning needs to be
* deviated." */

/* parasoft-begin-suppress MISRAC2012-RULE_5_4-d-2 "Reason: The warning is 
* getting reported for the memory section declaration which can not be avoided,
* These macros are part of AUTOSAR Specific definitions for inclusion of 
* memory map files for Code and Global data sections and configuration 
* Specific macros present in .h, so this warning needs to be deviated ,so 
* this warning needs to be deviated." */

/*******************************************************************************
**                   MISRA-C:2012 violations Section                          **
*******************************************************************************/
/** At section SD_Cbk_c_REF_1
* Violates MISRA 2012 Advisory Rule 2.2, This statement has no side effects.
* This statement is required for polyspace.
* Justification: For the unused variables or variables which are set but not
* used for specific configuration compiler shows warning. QAC shows dead code
* for the steps which are implemented to avoid such compiler warnings.

* #section SD_Cbk_C_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* All the #include statements in a particular code file should be grouped
* together near the head of the file. The rule states that the only items which
* may precede a #include in a file are other preprocessor directives or comments
* Justification: As per RS_BSW_00437 in AUTOSAR_SRS_BSWGeneral document Memory
* mapping is provided as start and stop memory sections. This is approved
* by AUTOSAR.

* #section SD_Cbk_C_REF_3
* Violates MISRA 2012 Required Dir-1.1, [L] Number of macro definitions exceeds
* 4095 - program does not conform strictly to ISO:C99.
**/
/*
 * LpTimer fetches pEraTimer from Pnchannel Info
 * Structure of different type
 MISRA Rule         : 10.1
 Message            : Implicit conversion from one type to
 another type ucnodeid
 Reason             : This is to achieve throughput in the code.
 Verification       : However, part of the code is verified
 manually and it is not having any impact.
 */
/*
 * LucMask fecthes from pointer Pnmask to
 * array of different type
 MISRA Rule         : 10.1
 Message            : Implicit conversion from one type to
 another type Pnmask
 Reason             : This is to achieve throughput in the code.
 Verification       : However, part of the code is verified
 manually and it is not having any impact.
*/
/*******************************************************************************
**                      CERT-C Violations Section                             **
*******************************************************************************/
/**
* violates #ref SD_Cbk_c_REF_1 Violates MISRA 2012 Required Rule 20.1
* PRQA S 5087 EOF
*As per KPIT coding guidelines, macro name should start from module name
*(upper case) and hence this violation is suppressed as it does not impact the module funtionality

* #violates #ref SD_Cbk_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)
* PRQA S 0857 EOF
* Part of common deviation.
* violates #ref SD_Cbk_c_REF_3 Violates MISRA 2012 Dir-1.1
* PRQA S 0380 EOF
* Part of common deviation.
* #Violates #ref SD_Cbk_c_REF_7, DCL00 Msg(qac-10.1.0-3227)
* PRQA S 3227 EOF
*The message can be suppressed in case of AUTOSAR provided Standard API input arguments:
*Since the function parameters that are pointers to values of standard API are
*provided by AUTOSAR specifications, it cannot be modified.
*It does not impact the module funtionality and hence this violation is suppressed.
*2. The message can be suppressed case to case deviation in case of internal functions:
*The function argument is not used in the current function, but inturn passed
*to another function to retrieve data. Hence the argument is still used as
*pointer to variable instead of pointer to constant. It can be suppressed and
*hence does'nt have impact on functionality.
*
*
* #Violates #ref SD_Cbk_c_REF_4,INT30 Msg(qac-10.1.0-3383)
* PRQA S 3383 EOF
Wrap around condition shall be written before performing
arithmetic operation on unsigned integer to prevent rollover result.
*
*
* #Violates #ref SD_Cbk_c_REF_6,INT02 Msg(qac-10.1.0-2100)
* PRQA S 2100 EOF
* This is waived Off whenever the Conversion  required accoding
*  to design of  functionality .
*
* #Violates #ref SD_Cbk_c_REF_7,INT02 Msg(qac-10.1.0-2101)
* PRQA S 2101 EOF
*  This is waived Off whenever the Conversion  required accoding
*  to design of  functionality .
*
* #Violates #ref SD_Cbk_c_REF_8,INT02 Msg(qac-10.1.0-1251)
* PRQA S 1251 EOF
*  This is waived Off whenever the Conversion  required accoding
*  to design of  functionality
*
* #Violates #ref SD_Cbk_c_REF_9,PRE04 Msg(certccm-2.1.0-5001)
* PRQA S 5001 EOF
*  This due use of header files with same names.
*
* #Violates #ref SD_Cbk_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)
* PRQA S 5002 EOF
*  All the header files have unique names
* #Violates #ref SD_Cbk_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)
* PRQA S 2017,3198,3408,3447 ++
*  All the header files have unique names
*
* #Violates #ref SD_Cbk_c_REF_4,MSC01 Msg(qac-10.1.0-2000)
* PRQA S 2000 EOF
* Deviation:77966
* #Violates #ref SD_Cbk_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)
* PRQA S 4810 EOF
* Deviation:77966
*
**/
/* violates #ref SD_Cbk_c_REF_1 Violates MISRA 2012 Required Rule 20.1 */
/* PRQA S 5087 EOF */

/*#violates #ref SD_Cbk_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)*/
/*PRQA S 0857 EOF*/

/* violates #ref SD_Cbk_c_REF_3 Violates MISRA 2012 Dir-1.1 */
/* PRQA S 0380 EOF */

/* #Violates #ref SD_Cbk_c_REF_7, DCL00 Msg(qac-10.1.0-3227) */
/* PRQA S 3227 EOF */

/* #Violates #ref SD_Cbk_c_REF_4,INT30 Msg(qac-10.1.0-3383) */
/*PRQA S 3383 EOF*/

/* #Violates #ref SD_Cbk_c_REF_4,MSC01 Msg(qac-10.1.0-2000) */
/*PRQA S 2000 EOF*/

/* #Violates #ref SD_Cbk_c_REF_6,INT02 Msg(qac-10.1.0-2100) */
/*PRQA S 2100 EOF*/

/* #Violates #ref SD_Cbk_c_REF_7,INT02 Msg(qac-10.1.0-2101) */
/*PRQA S 2101 EOF*/

/* #Violates #ref SD_Cbk_c_REF_8,INT02 Msg(qac-10.1.0-1251) */
/*PRQA S 1251 EOF*/

/* #Violates #ref SD_Cbk_c_REF_9,PRE04 Msg(certccm-2.1.0-5001) */
/*PRQA S 5001 EOF*/

/* #Violates #ref SD_Cbk_c_REF_9,PRE08 Msg(certccm-2.1.0-5002) */
/*PRQA S 5002 EOF*/
/* #Violates #ref SD_Cbk_c_REF_9,PRE08 Msg(certccm-2.1.0-5002) */
/*PRQA S 2017,3198,3408,3447 ++ */

/* #Violates #ref SD_Cbk_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
/*PRQA S 4810 EOF */
/* #Violates #ref SD_Cbk_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 (qac-10.1.0-0488)   */
/*PRQA S 0488 EOF*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
#include "Sd.h"
#include "Sd_IntTypes.h"
#include "Sd_Internal.h"
#include "Dem.h"
#include "SchM_Sd.h"
#include "BswM_Sd.h"

#if (STD_ON == SD_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*******************************************************************************
**                                Version Check                               **
*******************************************************************************/

/*******************************************************************************
**                                 Global Data                                **
*******************************************************************************/

/*******************************************************************************
**                              In-line Functions                             **
*******************************************************************************/

/*******************************************************************************
**                      	Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Sd_Rxindication                                     **
**                                                                            **
** Service ID           : 0x42                                                **
**                                                                            **
** Description          : Indication of a received I-PDU from a lower layer   **
**                      :   communication interface module.                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different PduIds.                     **
**                        Non reentrant for the same PduId.                   **
**                                                                            **
** Input Parameters     : RxPduId : ID of the received I-PDU                  **
**                        PduInfoPtr : Contains the length (SduLength) of the **
**                          received I-PDU and a pointer to a buffer          **
**                          (SduDataPtr) containing the I-PDU.                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GblInitCalled,             **
**                          Sd_GaaRxPduMapArray, Sd_GaaInstance,              **
**                          Sd_GaaInstanceStatic, Sd_GaaRxOptionsData         **
**                                                                            **
**                        Function(s) invoked : Det_ReportError,              **
**                          Dem_SetEventStatus,Dem_ReportErrorStatus,         **
**                          Sd_RxCheckHeader,                                 **
**                          Sd_RxGetAllOptions, Sd_RxGetRemoteAddr,           **
**                          Sd_DetectReboot, Sd_NettohostlPtr,                **
**                          Sd_RxGetEntry, Sd_RxIndicationProcessEntry,       **
**                         Sd_RebootActions                                   **
**                                                                            **
** Design ID            : SD_SDD_0211,SD_SDD_0003,SD_SDD_0335                 **
*******************************************************************************/
#define SD_START_SEC_CODE

#include "Sd_MemMap.h"
void Sd_RxIndication(PduIdType RxPduId,
                const PduInfoType * PduInfoPtr)
{
  Sd_InstanceStaticType const *LpInstanceStatic;
  uint8 const *LpSduDataPtr;
  Sd_OptionsDataType *LpRxOptionData;
  Sd_InstanceType const *LpInstance;
  Std_ReturnType LddEntryReturn;
  Std_ReturnType LddHeaderReturn;
  Std_ReturnType LddOptionReturn;
  Std_ReturnType LddRebootReturn;
  Sd_ServicesType LddInstanceIndex;
  TcpIp_SockAddrType LstRemoteAddr;
  Sd_EntryType LstEntry;
  uint32 LulLengthofEntry;
  uint32 LulLengthOfOptions;
  uint16 LusCount;
  uint16 LusSessionId;
  uint8 LucNoOfEntries;
  uint8 LucNoOfOptions;
  boolean LblUnicast;
  boolean LblRebootFlag;
  /*[SWS_SD_00482] [SWS_SD_00129c] [SWS_SD_00129e] [SWS_SD_00129f] */
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  if (RxPduId >= (SD_TWO * SD_NO_OF_INSTANCES))
#else
  if (RxPduId >= (SD_TWO * (SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS)))
#endif
  {
    LddReturnValue = E_NOT_OK;

#if (STD_ON == SD_DEV_ERROR_DETECT)
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID, SD_RX_INDICATION_SID,
                          SD_E_INV_ID);
#endif
  }
/*SWS_SD_00473*/
/* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be False when
 the sd module is in INITIALIZED state.
 Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00473" */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  if (!Sd_GblInitCalled)
  {
    LddReturnValue = E_NOT_OK;

    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID, SD_RX_INDICATION_SID,
                          SD_E_UNINIT);
  }
#endif
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
  the PduInfoPtr is equal to NULL ptr.
  Module Test Case Reference SD_ETC_002, SWS ID SWS_SD_00475" */
  /*SWS_SD_00475 [SWS_SD_00474a][SWS_SD_00474b]*/
  if ((SD_NULL_PTR == PduInfoPtr) || (SD_NULL_PTR == PduInfoPtr->SduDataPtr))
  {
    LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID, SD_RX_INDICATION_SID,
                          SD_E_PARAM_POINTER);
#endif
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be true when
  the LddReturnValue is  equal to E_OK .
  Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00475" */
  if (E_OK == LddReturnValue)
  {
    LpSduDataPtr = PduInfoPtr->SduDataPtr;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LddInstanceIndex = Sd_GaaRxPduMapArray[RxPduId];
#else
    LddInstanceIndex = Sd_GpConfigPtr->pRxPduMapArray[RxPduId];
#endif
    LpInstance = &Sd_GaaInstance[LddInstanceIndex];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)

    LpInstanceStatic = &Sd_GaaInstanceStatic[LddInstanceIndex];
#else
    LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LddInstanceIndex);
#endif

    if (LpInstanceStatic->ddUnicastRxPduId == RxPduId)
    {
      LblUnicast = (boolean)SD_TRUE;
    }
    else
    {
      LblUnicast = (boolean)SD_FALSE;
    }
    /*SWS_SD_00479*/
    LddHeaderReturn = Sd_RxCheckHeader(LpSduDataPtr,
                                       PduInfoPtr->SduLength, &LusSessionId, &LblRebootFlag);

    /* polyspace +7 RTE:UNR [Justified:Low] "This condition shall be True when
      LddHeaderReturn value is E_NOT_OK.
      Module Test Case Reference SD_ETC_639, SWS ID SWS_SD_00479" */
    if (E_OK != LddHeaderReturn)
    {
      SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
    }
    else
    {
      LpRxOptionData = &Sd_GaaRxOptionsData[SD_ZERO];
      LulLengthofEntry = Sd_NettohostlPtr(&LpSduDataPtr[SD_TWELVE]);
      LulLengthOfOptions = Sd_NettohostlPtr(&LpSduDataPtr[(uint32)SD_SIXTEEN +
                                                          LulLengthofEntry]);

      LddOptionReturn = Sd_RxGetAllOptions(
          LpInstanceStatic,
          &LpSduDataPtr[(uint32)SD_TWENTY + (uint32)LulLengthofEntry],
          LulLengthOfOptions, LpRxOptionData,
          &LucNoOfOptions);

      if (E_OK == LddOptionReturn)
      {

        (void)Sd_RxGetRemoteAddr(LpInstanceStatic, LpRxOptionData,
                                 LucNoOfOptions, LblUnicast, &LstRemoteAddr);

        LddRebootReturn = Sd_DetectReboot(LpInstanceStatic,
                                          &LstRemoteAddr, LblUnicast, LusSessionId, LblRebootFlag);

        if (E_OK != LddRebootReturn)
        {
#if (STD_OFF == SD_EV_HANDLER_CONFIGURED) && (STD_OFF == SD_CLIENT_CONFIGURED)
          Sd_RebootActions(LpInstanceStatic);
#else
          Sd_RebootActions(LpInstanceStatic, &LstRemoteAddr);
#endif
        }

        LucNoOfEntries = (uint8)(LulLengthofEntry / (uint32)SD_SIXTEEN);

        for (LusCount = SD_ZERO; LusCount < LucNoOfEntries; LusCount++)
        {

          LddEntryReturn = Sd_RxGetEntry(
              &LpSduDataPtr[SD_SIXTEEN + (LusCount * SD_SIXTEEN)],
              &LstEntry, LucNoOfOptions);
          /* Design ID : SD_SDD_0444,SD_SDD_0446,SD_SDD_0350,SD_SDD_0353,SD_SDD_0352,SD_SDD_0354*/
          /* polyspace +11 RTE:UNR [Justified:Low] "This condition shall be True when
           LddEntryReturn value is E_OK.
        Module Test Case Reference SD_ETC_639, SWS ID SWS_SD_00479" */
          if (E_OK == LddEntryReturn)
          {
            Sd_RxIndicationProcessEntry(LpInstance, LpInstanceStatic,
                                        &LstEntry, &LstRemoteAddr,
                                        LpSduDataPtr, LucNoOfOptions, LucNoOfEntries, LblUnicast);
          }
          else
          {
            SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
          }
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_LocalIpAddrAssignmentChg                         **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This function gets called by the SoAd if an IP      **
**                        address assignment related to a socket connection   **
**                        changes (i.e. new address assigned or assigned      **
**                        address becomes invalid).                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different SoConIds.                   **
**                        Non Reentrant for the same SoConId.                 **
**                                                                            **
** Input Parameters     : SoConId : socket connection index specifying the    **
**                           socket connection where the IP address assigment **
**                           has changed.                                     **
**                        State : state of IP address assignment.             **
**                                                                            **
**                      : ConsumedEventGroupState : The state the             **
**                      : Eventgroup shall be set to.                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd must be initialised                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GblInitCalled,             **
**                          Sd_GaaInstance, Sd_GaaInstanceStatic              **
**                                                                            **
**                        Function(s) invoked : Det_ReportError,              **
**                          SoAd_GetLocalAddr,                                **
**                          Sd_NetmaskToIpAddr, Sd_LocalIpAssignmentServer,   **
**                          Sd_LocalIpAssignmentClient                        **
**                                                                            **
** Design ID              : SD_SDD_0299                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_LocalIpAddrAssignmentChg(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State)
{
  uint16 LusCount;
  uint16 LusBaseIndex;

  Std_ReturnType LddReturnValue;
  boolean LblMatchRecd;
  TcpIp_IpAddrStateType LenPrevState = TCPIP_IPADDR_STATE_ASSIGNED;
  Sd_InstanceType *LpInstance;
  Sd_InstanceStaticType const *LpInstanceStatic;

  uint8 LucSubnetNetmask;

  TcpIp_SockAddrType LstDefaultRouterDummy;

  /* [SWS_SD_00471] [SWS_SD_00325] [SWS_SD_00412c] [SWS_SD_00412e]
    [SWS_SD_00412f]*/
  LddReturnValue = E_OK;

  LucSubnetNetmask = SD_ZERO;
  /* polyspace +8 RTE:UNR [Justified:Low] "This condition shall be False when
  the sd module is in INITIALIZED state.
  Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00471" */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  if (!Sd_GblInitCalled)
  {
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_LOCAL_IP_ADDR_ASSIGNMENT_CHANGE_SID, SD_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
   the sd module is in INITIALIZED state.
   Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00471" */
  if (E_OK == LddReturnValue)
#endif
  {
    /* [SWS_SD_00472] */
    /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall false when
        the sd module state not equal.
       Module Test Case Reference SD_ETC_416, SWS ID SWS_SD_00472*/
    if ((State != TCPIP_IPADDR_STATE_ASSIGNED) &&
        (State != TCPIP_IPADDR_STATE_ONHOLD) &&
        (State != TCPIP_IPADDR_STATE_UNASSIGNED))
    {
      LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
      (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                            SD_LOCAL_IP_ADDR_ASSIGNMENT_CHANGE_SID, SD_E_INV_MODE);
#endif
    }
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
    the LddReturnValue is  equal to E_OK . */
    if (E_OK == LddReturnValue)
    {
      /* [SWS_SD_00610] */
      LusBaseIndex = SD_ZERO;

      LblMatchRecd = (boolean)SD_FALSE;
      LusCount = LusBaseIndex;
#if (SD_NO_OF_INSTANCES != SD_ONE)
      do
      {
#endif
        LpInstance = &Sd_GaaInstance[LusCount];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpInstanceStatic = &Sd_GaaInstanceStatic[LusCount];
#else
      LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LusCount);
#endif

        if (LpInstanceStatic->ddIpAddrSoConId == SoConId)
        {

          LblMatchRecd = (boolean)SD_TRUE;
          LenPrevState = LpInstance->enIpAddrState;
          LpInstance->enIpAddrState = State;
        }
#if (SD_NO_OF_INSTANCES != SD_ONE)
        LusCount++;
      }
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      while ((LusCount < SD_NO_OF_INSTANCES) && (!LblMatchRecd));
#else
      while ((LusCount < (SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS)) && (!LblMatchRecd));
#endif
#endif

      /* [SWS_SD_00610] [SWS_SD_00357c] [SWS_SD_00610b] */
      if (!LblMatchRecd)
      {
        LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
        (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                              SD_LOCAL_IP_ADDR_ASSIGNMENT_CHANGE_SID, SD_E_INV_ID);
#endif
      }

      if (E_OK == LddReturnValue)
      {
        if (TCPIP_IPADDR_STATE_ASSIGNED == State)
        {
          SchM_Enter_Sd_MODE_STATUS_PROTECTION();
          /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be false
        when the LpInstanceStatic->blDomainIpv4 is  equal to SD_FALSE . */
          if (LpInstanceStatic->blDomainIpv4)
          {
            (LpInstance->stSubnetAddr).domain = TCPIP_AF_INET;
            LstDefaultRouterDummy.domain = TCPIP_AF_INET;
          }
          else
          {
            (LpInstance->stSubnetAddr).domain = TCPIP_AF_INET6;
            LstDefaultRouterDummy.domain = TCPIP_AF_INET6;
          }
          SchM_Exit_Sd_MODE_STATUS_PROTECTION();

          (void)SoAd_GetLocalAddr(SoConId, &LpInstance->stSubnetAddr,
                                  &LucSubnetNetmask, &LstDefaultRouterDummy);

#if (STD_OFF == SD_IPV6_ENABLED)
          /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be
       false when the LpInstanceStatic->blDomainIpv4 is  equal to SD_FALSE . */
          if (LpInstanceStatic->blDomainIpv4)
          {
            Sd_Ipv4NetmaskToIpAddr(LucSubnetNetmask,
                                   &LpInstance->stSubnetNetmask);
          }
#else
          {
            Sd_Ipv6NetmaskToIpAddr(LucSubnetNetmask,
                                   LpInstanceStatic->blDomainIpv4, &LpInstance->stSubnetNetmask);
          }
#endif
        }

        if ((TCPIP_IPADDR_STATE_ASSIGNED == LenPrevState) &&
            (TCPIP_IPADDR_STATE_ASSIGNED != State))
        {
#if (STD_ON == SD_SERVER_CONFIGURED)

          Sd_LocalIpAssignmentServer(LpInstanceStatic);
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)

          Sd_LocalIpAssignmentClient(LpInstanceStatic);
#endif
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_SoConChg                                         **
**                                                                            **
** Service ID           : 0x43                                                **
**                                                                            **
** Description          : This function gets called by the SoAd if the state  **
**                        of socket connection changes.                       **
**                        e.g. socket connection gets online                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different SoConIds.                   **
**                        Non Reentrant for the same SoConId.                 **
**                                                                            **
** Input Parameters     : SoConId : socket connection index specifying the    **
**                           socket connection where the IP address assigment **
**                           has changed.                                     **
**                        Mode : New mode of respective connection.           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoCon                   **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
** Design ID            : SD_SDD_0458                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SoConModeChg(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType Mode)
{
  uint16 LusCount;
  LusCount = SD_ZERO;

  while (LusCount < SD_NO_OF_SOCKET_CONNECTIONS)
  {
    if (Sd_GaaSoConId[LusCount] == SoConId)
    {
      SchM_Enter_Sd_MODE_STATUS_PROTECTION();
      Sd_GaaSoCon[LusCount].ddSoaASoConMode = Mode;
      SchM_Exit_Sd_MODE_STATUS_PROTECTION();

      LusCount = SD_NO_OF_SOCKET_CONNECTIONS;
    }
    LusCount++;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/****************************************************************************
**                   Parasoft violations end Section                       **
****************************************************************************/

/* parasoft-end-suppress MISRAC2012-RULE_20_1-a-4 */
/* parasoft-end-suppress MISRAC2012-RULE_5_4-c-2 */
/* parasoft-end-suppress MISRAC2012-RULE_5_4-d-2 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
