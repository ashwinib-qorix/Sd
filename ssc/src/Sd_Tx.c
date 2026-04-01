/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Tx.c                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the functions for transmit stream and the  **
**              Queue functions                                               **
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
/** At section SD_Tx_c_REF_1
* Violates MISRA 2012 Advisory Rule 2.2, This statement has no side effects.
* This statement is required for polyspace.
* Justification: For the unused variables or variables which are set but not
* used for specific configuration compiler shows warning. QAC shows dead code
* for the steps which are implemented to avoid such compiler warnings.

* #section SD_Tx_C_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* All the #include statements in a particular code file should be grouped
* together near the head of the file. The rule states that the only items which
* may precede a #include in a file are other preprocessor directives or comments
* Justification: As per RS_BSW_00437 in AUTOSAR_SRS_BSWGeneral document Memory
* mapping is provided as start and stop memory sections. This is approved
* by AUTOSAR.

* #section SD_Tx_C_REF_3
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
 * PRQA S 5087 EOF
 * violates #ref SD_Tx_c_REF_1 Violates MISRA 2012 Required Rule 20.1
 * As per KPIT coding guidelines, macro name should start from module name
 * (upper case) and hence this violation is suppressed as it does not impact the module funtionality
 *
 * #violates #ref SD_Tx_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)
 * PRQA S 0857 EOF
 *Common Deviation
 * violates #ref SD_Tx_c_REF_3 Violates MISRA 2012 Dir-1.1
 * PRQA S 0380 EOF
 * Common Deviation
 *
 * #Violates #ref SD_Tx_REF_7, Rule-10.3 Msg(qac-10.1.0-4461)
 * PRQA S 4461 EOF
 * Deviation #77966
 *
 * * #Violates #ref SD_Tx_REF_7, DCL00 Msg(qac-10.1.0-3227)
 * PRQA S 3227 EOF
 * * The message can be suppressed in case of AUTOSAR provided Standard API input arguments:
 * Since the function parameters that are pointers to values of standard API are
 * provided by AUTOSAR specifications, it cannot be modified.
 * It does not impact the module funtionality and hence this violation is suppressed.
 * 2. The message can be suppressed case to case deviation in case of internal functions:
 * The function argument is not used in the current function, but inturn passed
 * to another function to retrieve data. Hence the argument is still used as
 * pointer to variable instead of pointer to constant. It can be suppressed and
 * hence does'nt have impact on functionality.
 * #Violates #ref SD_Tx_c_REF_4,INT30 Msg(qac-10.1.0-3383)
 *PRQA S 3383 EOF
 * common deviation
 *
 * #Violates #ref SD_Tx_c_REF_5,INT30 Msg(qac-10.1.0-3384)
 * PRQA S 3384 EOF
 * Deviation:77966
 * #Violates #ref SD_Tx_c_REF_4,MSC01 Msg(qac-10.1.0-2000)
 *PRQA S 2000 EOF
 *Deviation:77966
 * #Violates #ref SD_Tx_c_REF_9,MSC09 Msg(qac-10.1.0-0288)
 *PRQA S 2017,3211,3408,3625 EOF
 * Deviation:77966
 * #Violates #ref SD_Tx_c_REF_9,DCL07 Msg(qac-10.1.0-3450)
 *PRQA S 553,2017,3219 EOF
 * Deviation:77966
 *
 * #Violates #ref SD_Tx_c_REF_6,INT02 Msg(qac-10.1.0-2100)
 * PRQA S 2100 EOF
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 *
 * #Violates #ref SD_Tx_c_REF_7,INT02 Msg(qac-10.1.0-2101)
 * PRQA S 2101 EOF
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 * #Violates #ref SD_Tx_c_REF_8,INT02 Msg(qac-10.1.0-2120)
 * PRQA S 2120 EOF
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 * #Violates #ref SD_Tx_c_REF_9,INT02 Msg(qac-10.1.0-1251)
 * PRQA S 1251 EOF
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 *
 *
 * #Violates #ref SD_Tx_c_REF_9,PRE04 Msg(certccm-2.1.0-5001)
 *PRQA S 5001 EOF
 *All the files in the header files  start with a specific format <Sd_xyz.h> due to guidelines of the Autosar.
 *
 * #Violates #ref SD_Tx_c_REF_9,INT02 Msg(qac-10.1.0-1297)
 *PRQA S 1-9999 EOF
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 * #Violates #ref SD_Tx_c_REF_9,INT02 Msg(qac-10.1.0-1297)
 * PRQA S 1297 EOF
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 ** #Violates #ref SD_Tx_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)
 *PRQA S 4810 EOF
 * Common Deviation.
 **/

/* PRQA S 5087 EOF */
/* violates #ref SD_Tx_c_REF_1 Violates MISRA 2012 Required Rule 20.1 */

/*#violates #ref SD_Tx_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)*/
/*PRQA S 0857 EOF*/

/* violates #ref SD_Tx_c_REF_3 Violates MISRA 2012 Dir-1.1 */
/* PRQA S 0380 EOF */

/* #Violates #ref SD_Tx_REF_7, DCL00 Msg(qac-10.1.0-3227) */
/* PRQA S 3227 EOF */

/* #Violates #ref SD_Tx_REF_7, Rule-10.3 Msg(qac-10.1.0-4461) */
/*PRQA S 4461 EOF*/

/* #Violates #ref SD_Tx_c_REF_4,INT30 Msg(qac-10.1.0-3383) */
/*PRQA S 3383 EOF*/

/* #Violates #ref SD_Tx_c_REF_5,INT30 Msg(qac-10.1.0-3384) */
/*PRQA S 3384 EOF*/

/* #Violates #ref SD_Tx_c_REF_4,MSC01 Msg(qac-10.1.0-2000) */
/*PRQA S 2000 EOF*/

/* #Violates #ref SD_Tx_c_REF_6,INT02 Msg(qac-10.1.0-2100) */
/*PRQA S 2100 EOF*/

/* #Violates #ref SD_Tx_c_REF_7,INT02 Msg(qac-10.1.0-2101) */
/*PRQA S 2101 EOF*/

/* #Violates #ref SD_Tx_c_REF_8,INT02 Msg(qac-10.1.0-2120) */
/*PRQA S 2120 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,INT02 Msg(qac-10.1.0-1251) */
/*PRQA S 1251 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,MSC09 Msg(qac-10.1.0-0288) */
/*PRQA S 2017,3211,3408,3625 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,DCL07 Msg(qac-10.1.0-3450) */
/*PRQA S 553,2017,3219 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,PRE04 Msg(certccm-2.1.0-5001) */
/*PRQA S 5001 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,INT02 Msg(qac-10.1.0-1297) */
/*PRQA S 1-9999 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,INT02 Msg(qac-10.1.0-1297) */
/*PRQA S 1297 EOF*/

/* #Violates #ref SD_Tx_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
/*PRQA S 4810 EOF */
/* #Violates #ref SD_Tx_c_REF_9,M3CM-3,03_EXP:Rule-18.4,EXP08 Msg(qac-10.1.0-0488)  */
/*PRQA S 0488 EOF*/
/*******************************************************************************
**                   PolySpace violations Section                             **
*******************************************************************************/
/**
#section Sd_c_Poly_REF_1
* Unreachable Code.
* This occurs in case if Configuration Dependent parameters used in code.
* Boundary checks
* Code has been analysed that all parts of code are reachable.
**/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Sd.h"
#include "Sd_IntTypes.h"
#include "Sd_Internal.h"
#include "BswM_Sd.h"
#include "Dem.h"
#include "SchM_Sd.h"
#include "Sd_Cfg.h"

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
** Function Name        : Sd_AddToQueue                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function will take the queue structure and     **
**                          add it to the queue in the first avaliaible       **
**                          location                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to Queue element to be     **
**                          added                                             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK - Added successfully                           **
**                      : E_NOT_OK - Could not be added (due to queue full)   **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaQueue,Sd_GaaQueueStatus **
**                        Function(s) invoked : Sd_MemCpy                     **
**                                                                            **
** Design ID              : SD_SDD_0252,SD_SDD_0340,SD_SDD_0005               **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static void Sd_AddToQueue(
    const Sd_QueueType * LpQueueElement)
{
  uint16 LusCount;
  boolean LblBreak;
  uint16 LusCurrIndex;
  /* SWS_SD_00651a
     SWS_SD_00651b */
  LblBreak = FALSE;
  LusCurrIndex = SD_ZERO;
#if (SD_QUEUE_SIZE != SD_ONE)
  for (LusCount = SD_ZERO; ((LusCount < SD_QUEUE_SIZE) && (SD_FALSE == LblBreak));
       LusCount++)
#else
  LusCount = SD_ZERO;
#endif
  {
    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
    if (SD_QUEUE_EMPTY == Sd_GaaQueueStatus[LusCount])
    {
      LusCurrIndex = LusCount;
      LblBreak = SD_TRUE;
    }
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  }

  if (SD_FALSE == LblBreak)
  {
  }
  else
  {

    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
    Sd_MemCpy(&Sd_GaaQueue[LusCurrIndex], LpQueueElement);
    Sd_GaaQueueStatus[LusCurrIndex] = SD_QUEUE_FULL;
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  }
  return;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_SendOffer                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to sent the offer entry     **
**                         It adds the service into the queue                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - pointer to server service   **
**                          static structure                                  **
**                      : LpSendAddr - The address that the entry   is to be  **
**                          sent to, if unicast.                              **
**                      : LulDelay - This entry will be sent with a delay     **
**                          given by this parameter,                          **
**                      : blSendUnicast - Indicates wether this entry is to   **
**                          via unicast or multicast                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_CopyIpAddr, Sd_AddToQueue  **
**                                                                            **
** Design ID            : SD_SDD_0193,SD_SDD_0335 ,SD_SDD_0077,SD_SDD_0090,   **
                          SD_SDD_0333 ,SD_SDD_0453 ,SD_SDD_0332 ,             **
                          SD_SDD_0455 ,SD_SDD_0127 , SD_SDD_0329 , SD_SDD_0464**
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendOffer(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay,
    boolean blSendUnicast)
{
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;
  Sd_Entry1DataType *LpEntry1;
  uint8 LusCount;
  LpQueueElement = &LstQueueElement;
  (LpQueueElement->stEntryData).enTypeOfEntry = SD_OFFER_SERVICE_ENTRY;

  LpEntry1 = &((LpQueueElement->stEntryData).unEntryData.stEntry1);
  /* SWS_SD_00254
     SWS_SD_00294 */
  LpEntry1->ucEntryType = SD_ENTRY_TYPE_OFFER;

  LpEntry1->ucIndex1 = SD_ZERO;
  LpEntry1->ucIndex2 = SD_ZERO;
  LpEntry1->ucNoOfOptions1 = SD_ZERO;
  LpEntry1->ucNoOfOptions2 = SD_ZERO;
/* SWS_SD_00509
   SWS_SD_00175 */
#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
  LpEntry1->usServiceId = LpServerServiceStatic->usServiceId;
  /* SWS_SD_00510 */
  LpEntry1->usInstanceId = LpServerServiceStatic->usInstanceId;
  /* SWS_SD_00511 */
  LpEntry1->ucMajorVersion = LpServerServiceStatic->ucMajorVersion;
  /* SWS_SD_00512 */
  LpEntry1->ulMinorVersion = LpServerServiceStatic->ulMinorVersion;
  /* SWS_SD_00513 */
  LpEntry1->ulTtlsec =
      LpServerServiceStatic->pServerTimer->ulServerTimerTtlsec;

  LpQueueElement->ucSdInstanceIndex =
      LpServerServiceStatic->ucSdInstanceIndex;
  LpQueueElement->ddGenericIndex =
      LpServerServiceStatic->usServerSelfIndex;

#else
  LpEntry1->usServiceId = LpServerServiceStatic->usServiceId;
  /* SWS_SD_00510 */
  LpEntry1->usInstanceId = LpServerServiceStatic->usInstanceId;
  /* SWS_SD_00511 */
  LpEntry1->ucMajorVersion = LpServerServiceStatic->ucMajorVersion;
  /* SWS_SD_00512 */
  LpEntry1->ulMinorVersion = LpServerServiceStatic->ulMinorVersion;
  /* SWS_SD_00513 */
  LpEntry1->ulTtlsec =
      LpServerServiceStatic->pServerTimer->ulServerTimerTtlsec;

  LpQueueElement->ucSdInstanceIndex =
      LpServerServiceStatic->ucSdInstanceIndex;
  LpQueueElement->ddGenericIndex = LpServerServiceStatic->usServerSelfIndex;
#endif

  LpQueueElement->ulDelayCount = LulDelay;

  LpQueueElement->blSendUnicast = blSendUnicast;
  LpQueueElement->ddSoConIdUdp = SD_ZERO;
  LpQueueElement->ddSoConIdTcp = SD_ZERO;
#if (SD_IPV6_ENABLED == STD_OFF)
  LpQueueElement->stSendAddr.domain = TCPIP_AF_INET;

#else

  LpQueueElement->stSendAddr.domain = TCPIP_AF_INET6;

#endif
  /* Design ID : SD_SDD_0333 ,SD_SDD_0453 ,SD_SDD_0332 ,SD_SDD_0455 ,SD_SDD_0127 , SD_SDD_0329 , SD_SDD_0464 */
  for (LusCount = SD_ZERO; LusCount < SD_EIGHTTEEN; LusCount++)
  {
    LpQueueElement->stSendAddr.aaSockAddrInetData[LusCount] = SD_WILDCARD_ADDR;
  }

  if (SD_TRUE == blSendUnicast)
  {
    Sd_CopyIpAddr(&(LpQueueElement->stSendAddr), LpSendAddr);
  }
  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SendStopOffer                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function sends the Stop Offer Service          **
**                      : The Stop Offer will only be sent as multicast.      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - pointer to Server Service   **
**                                    static                                  **
**                      : LulDelay - Configurable delay to send the Stop Offer**
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_AddToQueue                 **
**                                                                            **
** Design ID              : SD_SDD_0194                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendStopOffer(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    uint32 LulDelay)
{
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;
  Sd_Entry1DataType *LpEntry1;

  LpQueueElement = &LstQueueElement;

  (LpQueueElement->stEntryData).enTypeOfEntry = SD_STOP_OFFER_SERVICE_ENTRY;
  LpEntry1 = &((LpQueueElement->stEntryData).unEntryData.stEntry1);
  /* SWS_SD_00423 SWS_SD_00422 SWS_SD_00294 */
  LpEntry1->ucEntryType = SD_ENTRY_TYPE_STOP_OFFER;

  LpEntry1->ucIndex1 = SD_ZERO;
  LpEntry1->ucIndex2 = SD_ZERO;
  LpEntry1->ucNoOfOptions1 = SD_ZERO;
  LpEntry1->ucNoOfOptions2 = SD_ZERO;
  /* SWS_SD_00424
     SWS_SD_00178
   SWS_SD_00182*/

  LpEntry1->usServiceId = LpServerServiceStatic->usServiceId;
  LpEntry1->usInstanceId = LpServerServiceStatic->usInstanceId;
  LpEntry1->ucMajorVersion = LpServerServiceStatic->ucMajorVersion;
  LpEntry1->ulMinorVersion = LpServerServiceStatic->ulMinorVersion;
  /* SWS_SD_00425  */
  LpEntry1->ulTtlsec = (uint32)SD_ZERO;

  LpQueueElement->ucSdInstanceIndex =
      LpServerServiceStatic->ucSdInstanceIndex;
  LpQueueElement->ddGenericIndex = LpServerServiceStatic->usServerSelfIndex;

  LpQueueElement->ulDelayCount = LulDelay;
  LpQueueElement->blSendUnicast = FALSE;
  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SendSubscribeAck                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function sends the Subscribe Ack               **
**                      : Subscribe Ack is always sent via Unicast            **
**                      : It can have a confugurable delay to send the entry  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEvHandlerStatic - Pointer to the static event     **
**                         handler structure                                  **
**                      : LpEntryData - Pointer to received entry             **
**                      : LpSendAddr - Pointer to the address to send the     **
**                         entry                                              **
**                      : LulDelay - COnfigurable delay parameter, indicating **
**                          how much time later the entry is to be sent       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic     **
**                        Function(s) invoked : Sd_CopyIpAddr, Sd_AddToQueue  **
**                                                                            **
** Design ID              : SD_SDD_0197                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendSubscribeAck(
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay)
{
  Sd_Entry2DataType const *LpEntry2Input;
  Sd_Entry2DataType *LpEntry2;
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;

  LpQueueElement = &LstQueueElement;

  (LpQueueElement->stEntryData).enTypeOfEntry = SD_SUBSCRIBE_ACK_ENTRY;
  LpEntry2 = &((LpQueueElement->stEntryData).unEntryData.stEntry2);
  LpEntry2Input = &((LpEntryData->unEntryData).stEntry2);

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpServerServiceStatic = &Sd_GaaServerServiceStatic[LpEvHandlerStatic->usServerServiceIndex];
#else
  LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LpEvHandlerStatic->usServerServiceIndex);
#endif

  /* SWS_SD_00314
     SWS_SD_00428*/
  LpEntry2->ucEntryType = SD_ENTRY_TYPE_SUBSCRIBE_ACK;
  LpEntry2->ucIndex1 = SD_ZERO;
  LpEntry2->ucIndex2 = SD_ZERO;
  LpEntry2->ucNoOfOptions1 = SD_ZERO;
  LpEntry2->ucNoOfOptions2 = SD_ZERO;
  /* SWS_SD_00428
     SWS_SD_00693b */
  LpEntry2->usServiceId = LpEntry2Input->usServiceId;
  LpEntry2->usInstanceId = LpEntry2Input->usInstanceId;
  LpEntry2->ucMajorVersion = LpEntry2Input->ucMajorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LpEntry2->usReserved = LpEntry2Input->usReserved;
  LpEntry2->ucCounter = LpEntry2Input->ucCounter;
  LpEntry2->usEventGroupId = LpEntry2Input->usEventGroupId;
  /*SWS_SD_00315*/
  LpEntry2->ulTtlsec = LpEntry2Input->ulTtlsec;

  LpQueueElement->ucSdInstanceIndex =
      LpServerServiceStatic->ucSdInstanceIndex;

  LpQueueElement->ddGenericIndex = LpEvHandlerStatic->usEvHandlerSelfIndex;

  LpQueueElement->ulDelayCount = LulDelay;

  LpQueueElement->blSendUnicast = SD_TRUE;

  Sd_CopyIpAddr(&(LpQueueElement->stSendAddr), LpSendAddr);

  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SendSubscribeNack                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function sends the Subscribe Ack               **
**                      : Subscribe Ack is always sent via Unicast            **
**                      : It can have a confugurable delay to send the entry  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEvHandlerStatic - Pointer to the static event     **
**                         handler structure                                  **
**                      : LpEntryData - Pointer to received entry             **
**                      : LpSendAddr - Pointer to the address to send the     **
**                          entry                                             **
**                      : LulDelay - COnfigurable delay parameter, indicating **
**                          how much time later the entry is to be sent       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_CopyIpAddr, Sd_AddToQueue  **
**                                                                            **
** Design ID            : SD_SDD_0198,SD_SDD_0092                             **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendSubscribeNack(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay)
{
  Sd_Entry2DataType const *LpEntry2Input;
  Sd_Entry2DataType *LpEntry2;
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;

  LpQueueElement = &LstQueueElement;

  (LpQueueElement->stEntryData).enTypeOfEntry = SD_SUBSCRIBE_NACK_ENTRY;

  LpEntry2 = &((LpQueueElement->stEntryData).unEntryData.stEntry2);

  LpEntry2Input = &((LpEntryData->unEntryData).stEntry2);
  /* SWS_SD_00316
     SWS_SD_00290 */
  LpEntry2->ucEntryType = SD_ENTRY_TYPE_SUBSCRIBE_NACK;

  LpEntry2->ucIndex1 = SD_ZERO;
  LpEntry2->ucIndex2 = SD_ZERO;
  LpEntry2->ucNoOfOptions1 = SD_ZERO;
  LpEntry2->ucNoOfOptions2 = SD_ZERO;
  /* SWS_SD_00431  */
  LpEntry2->usServiceId = LpEntry2Input->usServiceId;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LpEntry2->usInstanceId = LpEntry2Input->usInstanceId;
  LpEntry2->ucMajorVersion = LpEntry2Input->ucMajorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LpEntry2->usReserved = LpEntry2Input->usReserved;
  LpEntry2->ucCounter = LpEntry2Input->ucCounter;
  LpEntry2->usEventGroupId = LpEntry2Input->usEventGroupId;
  /* SWS_SD_00432  */
  LpEntry2->ulTtlsec = (uint16)SD_ZERO;

  LpQueueElement->ucSdInstanceIndex = LpInstanceStatic->ucInstanceSelfIndex;

  LpQueueElement->ddGenericIndex = SD_ZERO;

  LpQueueElement->ulDelayCount = LulDelay;

  LpQueueElement->blSendUnicast = SD_TRUE;

  Sd_CopyIpAddr(&(LpQueueElement->stSendAddr), LpSendAddr);

  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_SendFind                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function sends the Find entry                  **
**                      : Find is always sent via Multicast                   **
**                      : It can have a confugurable delay to send the entry  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientServiceStatic - Pointer to the static       **
**                                  client service structure.                 **
**                      : LulDelay - COnfigurable delay parameter, indicating **
**                          how much time later the entry is to be sent       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_AddToQueue                 **
**                                                                            **
** Design ID              : SD_SDD_0192                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendFind(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    uint32 LulDelay)
{
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;
  Sd_Entry1DataType *LpEntry1;
  LpQueueElement = &LstQueueElement;
  (LpQueueElement->stEntryData).enTypeOfEntry = SD_FIND_SERVICE_ENTRY;

  LpEntry1 = &((LpQueueElement->stEntryData).unEntryData.stEntry1);
  /* SWS_SD_00240
     SWS_SD_00294 */
  LpEntry1->ucEntryType = SD_ENTRY_TYPE_FIND;
  LpEntry1->ucIndex1 = SD_ZERO;
  LpEntry1->ucIndex2 = SD_ZERO;
  LpEntry1->ucNoOfOptions1 = SD_ZERO;
  LpEntry1->ucNoOfOptions2 = SD_ZERO;

  LpEntry1->usServiceId = LpClientServiceStatic->usServiceId;
  LpEntry1->usInstanceId = LpClientServiceStatic->usInstanceId;
  LpEntry1->ucMajorVersion = LpClientServiceStatic->ucMajorVersion;

  /* SWS_SD_00503 */
  /*polyspace +15 RTE:UNR [Justified:Low] "This Condition shall be false
                        when EndrivenBehaviour is Set as SD_MINIMUM_VERSION " */
  if (LpClientServiceStatic->EndrivenBehaviour ==
      SD_EXACT_OR_ANY_MINOR_VERSION)
  {
    LpEntry1->ulMinorVersion = LpClientServiceStatic->ulMinorVersion;
  }
  else
  {
    /* [SWS_SD_10503]{DRAFT} */
  }
  /* SWS_SD_00504  */
  LpEntry1->ulTtlsec = LpClientServiceStatic->pClientTimer->ulClientTimerTtlsec;

  LpQueueElement->ucSdInstanceIndex =
      LpClientServiceStatic->ucSdInstanceIndex;

  LpQueueElement->ddGenericIndex = LpClientServiceStatic->usClientSelfIndex;

  LpQueueElement->ulDelayCount = LulDelay;

  LpQueueElement->blSendUnicast = FALSE;

  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SendSubscribe                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function sends the Subscribe entry             **
**                      : Subscribe is always sent via Unicast                **
**                      : It can have a configurable delay to send the entry  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpConsumedEvGrpStatic - Pointer to the static       **
**                                  Consumed event group structure            **
**                      : LpSendAddr - This is the addr that the frame is sent**
**                                  by unicast                                **
**                      : LulDelay - COnfigurable delay parameter, indicating **
**                          how much time later the entry is to be sent       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientServiceStatic     **
**                        Function(s) invoked : Sd_CopyIpAddr, Sd_AddToQueue  **
**                                                                            **
** Design ID              : SD_SDD_0196                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendSubscribe(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay)
{
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;
  Sd_Entry2DataType *LpEntry2;
  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  /* SWS_SD_00300
     SWS_SD_00301
   SWS_SD_00290
   SWS_SD_00303*/
  LpQueueElement = &LstQueueElement;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpClientServiceStatic =
      &Sd_GaaClientServiceStatic[LpConsumedEvGrpStatic->usClientServiceIndex];
#else
  LpClientServiceStatic =
      ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LpConsumedEvGrpStatic->usClientServiceIndex);
#endif
  (LpQueueElement->stEntryData).enTypeOfEntry = SD_SUBSCRIBE_ENTRY;

  LpEntry2 = &((LpQueueElement->stEntryData).unEntryData.stEntry2);
  /* SWS_SD_00312  */
  LpEntry2->ucEntryType = SD_ENTRY_TYPE_SUBSCRIBE;

  LpEntry2->ucIndex1 = SD_ZERO;
  LpEntry2->ucIndex2 = SD_ZERO;
  LpEntry2->ucNoOfOptions1 = SD_ZERO;
  LpEntry2->ucNoOfOptions2 = SD_ZERO;
  /* SWS_SD_00301  */

  LpEntry2->usServiceId = LpClientServiceStatic->usServiceId;
  LpEntry2->usInstanceId = LpClientServiceStatic->usInstanceId;
  LpEntry2->ucMajorVersion = LpClientServiceStatic->ucMajorVersion;

  LpEntry2->ucCounter = LpConsumedEvGrpStatic->ucCounter;
  LpEntry2->usEventGroupId = LpConsumedEvGrpStatic->usEventGroupId;
  /* SWS_SD_00304
     SWS_SD_00200
     SWS_SD_00304b*/
  LpEntry2->ulTtlsec = LpConsumedEvGrpStatic->pClientTimer->ulClientTimerTtlsec;

  LpQueueElement->ucSdInstanceIndex = LpClientServiceStatic->ucSdInstanceIndex;

  LpQueueElement->ddGenericIndex = LpConsumedEvGrpStatic->usConEvGrpSelfIndex;

  LpQueueElement->ulDelayCount = LulDelay;

  LpQueueElement->blSendUnicast = SD_TRUE;

  Sd_CopyIpAddr(&(LpQueueElement->stSendAddr), LpSendAddr);

  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SendStopSubscribe                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function sends the Stop Subscribe entry        **
**                      : Stop Subscribe is always sent via Unicast           **
**                      : It can have a configurable delay to send the entry  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpConsumedEvGrpStatic - Pointer to the static       **
**                                  Consumed event group structure            **
**                      : LpSendAddr - This is the addr that the frame is sent**
**                                  by unicast                                **
**                      : LulDelay - COnfigurable delay parameter, indicating **
**                          how much time later the entry is to be sent       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientServiceStatic     **
**                        Function(s) invoked : Sd_CopyIpAddr, Sd_AddToQueue  **
**                                                                            **
** Design ID              : SD_SDD_0195                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SendStopSubscribe(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const TcpIp_SockAddrType * LpSendAddr,
    uint32 LulDelay)
{
  Sd_QueueType LstQueueElement;
  Sd_QueueType *LpQueueElement;
  Sd_Entry2DataType *LpEntry2;
  Sd_ClientServiceStaticType const *LpClientServiceStatic;

  LpQueueElement = &LstQueueElement;
  (LpQueueElement->stEntryData).enTypeOfEntry = SD_STOP_SUBSCRIBE_ENTRY;

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpClientServiceStatic =
      &Sd_GaaClientServiceStatic[LpConsumedEvGrpStatic->usClientServiceIndex];
#else
  LpClientServiceStatic =
      ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LpConsumedEvGrpStatic->usClientServiceIndex);
#endif

  LpEntry2 = &((LpQueueElement->stEntryData).unEntryData.stEntry2);
  /* SWS_SD_00313 */
  LpEntry2->ucEntryType = SD_ENTRY_TYPE_STOP_SUBSCRIBE;

  LpEntry2->ucIndex1 = SD_ZERO;
  LpEntry2->ucIndex2 = SD_ZERO;
  LpEntry2->ucNoOfOptions1 = SD_ZERO;
  LpEntry2->ucNoOfOptions2 = SD_ZERO;
  /* SWS_SD_00301
     SWS_SD_00178
   SWS_SD_00193
   SWS_SD_00195*/

  LpEntry2->usServiceId = LpClientServiceStatic->usServiceId;
  LpEntry2->usInstanceId = LpClientServiceStatic->usInstanceId;
  /* SWS_SD_00198 */
  LpEntry2->ucMajorVersion = LpClientServiceStatic->ucMajorVersion;

  LpEntry2->ucCounter = LpConsumedEvGrpStatic->ucCounter;
  /* SWS_SD_00204 */
  LpEntry2->usEventGroupId = LpConsumedEvGrpStatic->usEventGroupId;
  /* SWS_SD_00426
     SWS_SD_00200
   SWS_SD_00306 */
  LpEntry2->ulTtlsec = SD_ZERO;
  /*SWS_SD_00426*/

  LpQueueElement->ucSdInstanceIndex =
      LpClientServiceStatic->ucSdInstanceIndex;

  LpQueueElement->ddGenericIndex = LpConsumedEvGrpStatic->usConEvGrpSelfIndex;

  LpQueueElement->ulDelayCount = LulDelay;

  LpQueueElement->blSendUnicast = SD_TRUE;

  Sd_CopyIpAddr(&(LpQueueElement->stSendAddr), LpSendAddr);

  Sd_AddToQueue(LpQueueElement);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_QueueCheckforTransmit                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines if the queue element is to **
**                          be transmitted.                                   **
**                        For the First entry, it stores the SdInstance,      **
**                          Unicast status and Remote Addr.                   **
**                        The remaining entrys should match the details in    **
**                          the first entry. If matching, the output is set   **
**                          TRUE, else false.                                 **
**                        For a unicast entry, SdInstance, unicast status and **
**                          remote addr must match                            **
**                        For a multicast entry, SdInstance and unicast       **
**                          status flag must match                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to queue element to be     **
**                          checked                                           **
**                                                                            **
** InOut parameter      : LpFirstEntry - Pointer to first entry flag          **
**                      : LpInitialSdInstance - Pointer to Initial SdInstance **
**                      : LpInitialFrameUnicast - Pointer to Initial frame    **
**                           unicast flag                                     **
**                      : LpInitialSendAddr - Pointer to Initial Addr         **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : boolean- SD_TRUE - This entry should be transmitted **
**                          SD_FALSE - This entry should not be transmitted   **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_CopyIpAddr, Sd_MatchIpAddr **
**                                                                            **
** Design ID              : SD_SDD_0254                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static boolean Sd_QueueCheckforTransmit(
    const Sd_QueueType * LpQueueElement,
    boolean * LpFirstEntry,
    uint8 * LpInitialSdInstance,
    boolean * LpInitialFrameUnicast,
    TcpIp_SockAddrType * LpInitialSendAddr)
{
  boolean LblTransmitEntry;
  /* SWS_SD_00651a
   SWS_SD_00651b
   SWS_SD_00448c */
  /* polyspace +3 RTE:UNR [Justified:Low] "This check will be true when
  LpFirstEntry is equal to SD_TRUE " */
  if (SD_TRUE == *LpFirstEntry)
  {

    *LpInitialSdInstance = LpQueueElement->ucSdInstanceIndex;

    if (SD_FALSE == LpQueueElement->blSendUnicast)
    {
      *LpInitialFrameUnicast = FALSE;
    }
    else
    {
      *LpInitialFrameUnicast = SD_TRUE;

      Sd_CopyIpAddr(LpInitialSendAddr, &(LpQueueElement->stSendAddr));
    }

    LblTransmitEntry = SD_TRUE;

    *LpFirstEntry = FALSE;
  }
  else
  {

    if ((LpQueueElement->ucSdInstanceIndex == *LpInitialSdInstance) &&
        (LpQueueElement->blSendUnicast == *LpInitialFrameUnicast))
    {
      if (SD_FALSE == LpQueueElement->blSendUnicast)
      {

        LblTransmitEntry = SD_TRUE;
      }
      else
      {

        LblTransmitEntry = Sd_MatchIpAddr(LpInitialSendAddr,
                                          &(LpQueueElement->stSendAddr));
      }
    }
    else
    {
      LblTransmitEntry = FALSE;
    }
  }
  return (LblTransmitEntry);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_QueueFillOptionsRefConfig                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function fils the config pointer parameter of  **
**                          the Sd_GaaOptionsRef array and returns the index  **
**                          of the array where filled                         **
**                        If the config option is present if sets the flag    **
**                          LpConfigOptionPresent                             **
**                        It checks whether the option is already in the array**
**                          If found, it will return that index, otherwise    **
**                          it will add the new option to the options ref     **
**                          array and return the new index.                   **
**                        If the array is overflowing, it sets the flag       **
**                          LpQueueOverflow                                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpElementConfigOption - The pointer to the config   **
**                          option generated by the prev function             **
**                                                                            **
** InOut parameter      : LpNoOfOptionsTx - This is the index of the array    **
**                          Sd_GaaOptionsRef                                  **
**                      : LpQueueOverflow - boolean indicating overflow       **
**                          of the queue                                      **
**                                                                            **
** Output Parameters    : LpConfigOptionPresent - Flag indicating whether     **
**                          the config option is present                      **
**                                                                            **
** Return parameter     : uint8 - This gives the index of the config option   **
**                          in the options array                              **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaOptionsRef              **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0255                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint8 Sd_QueueFillOptionsRefConfig(
    const uint8 * LpElementConfigOption,
    uint8 * LpNoOfOptionsTx,
    boolean * LpQueueOverflow,
    boolean * LpConfigOptionPresent)
{
  uint16 LusCount;
  boolean LblMatch;
  uint16 LusMatchIndex;
  uint8 LucConfigIndex;

  LusMatchIndex = SD_ZERO;
  LucConfigIndex = SD_ZERO;
  /* SWS_SD_00188
     SWS_SD_00626 */
  /*polyspace +5 RTE:UNR [Justified:Low] "This If condition will be false if
  LpElementConfigOption is Set as SD_NULL_PTR" */
  if (SD_NULL_PTR == LpElementConfigOption)
  {
    *LpConfigOptionPresent = FALSE;
  }
  else
  {
    *LpConfigOptionPresent = SD_TRUE;

    LblMatch = FALSE;
    /* polyspace +4 RTE:UNR [Justified:Low] "This check will be false when
     LblMatch is  false" */
    for (LusCount = SD_ZERO; ((LusCount < *LpNoOfOptionsTx) &&
                              (SD_FALSE == LblMatch));
         LusCount++)
    {
      if ((SD_CONFIGURATION_OPTION ==
           Sd_GaaOptionsRef[LusCount].enTypeOfOption) &&
          (LpElementConfigOption ==
           Sd_GaaOptionsRef[LusCount].pConfigOption))
      {
        LblMatch = SD_TRUE;
        LusMatchIndex = LusCount;
      }
    }
    /* polyspace +3 RTE:UNR [Justified:Low] "This check will be true when
   LblMatch is true" */
    if (SD_FALSE == LblMatch)
    {
      /* polyspace +5 RTE:UNR [Justified:Low] "This check will be false when
                                     LpNoOfOptionsTx is less than SD_SIXTEEN " */
      if (*LpNoOfOptionsTx > SD_SIXTEEN)
      {
        *LpQueueOverflow = SD_TRUE;
      }
      else
      {
        /*polyspace +4 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
             made sure that they are within their range by having necessary boundary
             checks in order to prevent them from being out of bounds." */
        Sd_GaaOptionsRef[*LpNoOfOptionsTx].enTypeOfOption =
            SD_CONFIGURATION_OPTION;
        Sd_GaaOptionsRef[*LpNoOfOptionsTx].pConfigOption =
            LpElementConfigOption;

        LucConfigIndex = *LpNoOfOptionsTx;

        *LpNoOfOptionsTx = *LpNoOfOptionsTx + SD_ONE;
      }
    }

    else
    {
      LucConfigIndex = (uint8)LusMatchIndex;
    }
  }
  return (LucConfigIndex);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_QueueFillOptionsRefSingle                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function fils all the parameters of the        **
**                          Sd_GaaOptionsRef array except for the config      **
**                          option pointer and returns the index of the array **
**                        It fills these parameters for case when only single **
**                          endpoint option is to be transmit.                **
**                        It checks whether the option is already in the array**
**                          If found, it will return that index, otherwise    **
**                          it will add the new option to the options ref     **
**                          array and return the new index.                   **
**                        If the array is overflowing, it sets the flag       **
**                          LpQueueOverflow                                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddSoConId1 - The socket Id for the first option    **
**                      : LpProtocol1 - The protocol for the first option     **
**                        LenTypeOfOption - The type of option to be sent     **
**                                                                            **
** InOut parameter      : LpNoOfOptionsTx - This is the index of the array    **
**                          Sd_GaaOptionsRef                                  **
**                      : LpQueueOverflow - boolean indicating overflow       **
**                          of the queue                                      **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : uint8 - This gives the index of the option in the   **
**                          options array                                     **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaOptionsRef              **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID            : SD_SDD_0257,SD_SDD_0049                             **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static uint8 Sd_QueueFillOptionsRefSingle(
    SoAd_SoConIdType LddSoConId1,
    uint8 LucSoCon1Protocol,
    Sd_TypeOfOptionsType LenTypeOfOption,
    uint8 * LpNoOfOptionsTx,
    boolean * LpQueueOverflow)
{
  boolean LblMatch;
  uint16 LusMatchIndex;
  uint16 LusCount;
  uint8 LucSoConIndex;

  LusMatchIndex = SD_ZERO;
  LucSoConIndex = SD_ZERO;

  LblMatch = FALSE;
  for (LusCount = SD_ZERO; ((LusCount < *LpNoOfOptionsTx) &&
                            (SD_FALSE == LblMatch));
       LusCount++)
  {
    /*polyspace +6 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being out of bounds." */
    if ((LenTypeOfOption == Sd_GaaOptionsRef[LusCount].enTypeOfOption) &&
        (LddSoConId1 == Sd_GaaOptionsRef[LusCount].ddLocalAddrSoConId) &&
        (LucSoCon1Protocol == Sd_GaaOptionsRef[LusCount].ucProtocol))
    {
      LblMatch = SD_TRUE;
      LusMatchIndex = LusCount;
    }
  }

  if (SD_TRUE == LblMatch)
  {
    LucSoConIndex = (uint8)LusMatchIndex;
  }
  else
  {
    /* polyspace +4 RTE:UNR [Justified:Low] "This check will be false when
                                LpNoOfOptionsTx is less than SD_SIXTEEN " */
    if (*LpNoOfOptionsTx > SD_SIXTEEN)
    {
      *LpQueueOverflow = SD_TRUE;
    }
    else
    {
      /*polyspace +3 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being out of bounds." */
      Sd_GaaOptionsRef[*LpNoOfOptionsTx].enTypeOfOption = LenTypeOfOption;
      Sd_GaaOptionsRef[*LpNoOfOptionsTx].ddLocalAddrSoConId = LddSoConId1;
      Sd_GaaOptionsRef[*LpNoOfOptionsTx].ucProtocol = LucSoCon1Protocol;
      LucSoConIndex = *LpNoOfOptionsTx;
      *LpNoOfOptionsTx = *LpNoOfOptionsTx + SD_ONE;
    }
  }
  return (LucSoConIndex);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_QueueFillOptionsRefDouble                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function fils all the parameters of the        **
**                          Sd_GaaOptionsRef array except for the config      **
**                          option pointer and returns the index of the array **
**                        It fills these parameters for the case when two     **
**                          endpoint options are to be sent                   **
**                        It checks whether the first option is in the array  **
**                          If found, it will check if the second option is   **
**                          at the next location. If yes it will return the   **
**                          index of that location.                           **
**                        If not, it will add the two options to the end of   **
**                          the array.                                        **
**                        If the array is overflowing, it sets the flag       **
**                          LpQueueOverflow                                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddSoConId1 - The socket Id for the first option    **
**                      : LpProtocol1 - The protocol for the first option     **
**                      : LddSoConId2 - The socket Id for the second option   **
**                      : LpProtocol2 - The protocol for the second option    **
**                      : LenTypeOfOption - The type of option to be sent     **
**                                                                            **
** InOut parameter      : LpNoOfOptionsTx - This is the index of the array    **
**                          Sd_GaaOptionsRef                                  **
**                      : LpQueueOverflow - boolean indicating overflow       **
**                          of the queue                                      **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : uint8 - This gives the index of the option in the   **
**                          options array                                     **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaOptionsRef              **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0256                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint8 Sd_QueueFillOptionsRefDouble(
    SoAd_SoConIdType LddSoConId1,
    uint8 LucSoCon1Protocol,
    SoAd_SoConIdType LddSoConId2,
    uint8 LucSoCon2Protocol,
    Sd_TypeOfOptionsType LenTypeOfOption,
    uint8 * LpNoOfOptionsTx,
    boolean * LpQueueOverflow)
{
  boolean LblMatch;
  uint16 LusMatchIndex;
  uint16 LusCount;
  boolean LblAddToEnd;
  uint8 LucSoConIndex;

  LusMatchIndex = SD_ZERO;
  LucSoConIndex = SD_ZERO;

  LblMatch = SD_FALSE;
  LblAddToEnd = SD_FALSE;
  /* SWS_SD_00386
     SWS_SD_00626
     SWS_SD_00651a */

  for (LusCount = SD_ZERO; ((LusCount < *LpNoOfOptionsTx) &&
                            (SD_FALSE == LblMatch));
       LusCount++)
  {
    /*polyspace +8 RTE:UNR [Justified:Low] "This condition will be true when configured value
    match the received value." */
    /*polyspace +6 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
    if ((LenTypeOfOption == Sd_GaaOptionsRef[LusCount].enTypeOfOption) &&
        (LddSoConId1 == Sd_GaaOptionsRef[LusCount].ddLocalAddrSoConId) &&
        (LucSoCon1Protocol == Sd_GaaOptionsRef[LusCount].ucProtocol))
    {
      LblMatch = SD_TRUE;
      LusMatchIndex = LusCount;
    }
  }
  /* polyspace +3 RTE:UNR [Justified:Low] "This check will be true when
    Lblmatch is equal to False  */
  if (SD_FALSE == LblMatch)
  {
    LblAddToEnd = SD_TRUE;
  }
  else
  {
    /*polyspace +9 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
    if ((LusMatchIndex < *LpNoOfOptionsTx) &&
        (LenTypeOfOption ==
         Sd_GaaOptionsRef[LusMatchIndex + SD_ONE].enTypeOfOption) &&
        (LddSoConId2 == Sd_GaaOptionsRef[LusMatchIndex + SD_ONE].ddLocalAddrSoConId) &&
        (LucSoCon2Protocol ==
         Sd_GaaOptionsRef[LusMatchIndex + SD_ONE].ucProtocol))
    {
      LucSoConIndex = (uint8)LusMatchIndex;
    }
    else
    {
      LblAddToEnd = SD_TRUE;
    }
  }
  /* polyspace +3 RTE:UNR [Justified:Low] "This check will be true when
    LblAddToEnd is equal to True  */
  if (SD_TRUE == LblAddToEnd)
  {
    /* polyspace +3 RTE:UNR [Justified:Low] "This check will be true when
      LpNoOfOptionsTx is grater than 16  */
    if (*LpNoOfOptionsTx > SD_FIFTEEN)
    {
      *LpQueueOverflow = SD_TRUE;
    }
    else
    {
      Sd_GaaOptionsRef[*LpNoOfOptionsTx].enTypeOfOption = LenTypeOfOption;
      Sd_GaaOptionsRef[*LpNoOfOptionsTx].ddLocalAddrSoConId = LddSoConId1;
      Sd_GaaOptionsRef[*LpNoOfOptionsTx].ucProtocol = LucSoCon1Protocol;
      /*polyspace +4 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being out of bounds." */
      Sd_GaaOptionsRef[*LpNoOfOptionsTx + SD_ONE].enTypeOfOption =
          LenTypeOfOption;
      Sd_GaaOptionsRef[*LpNoOfOptionsTx + SD_ONE].ddLocalAddrSoConId =
          LddSoConId2;
      Sd_GaaOptionsRef[*LpNoOfOptionsTx + SD_ONE].ucProtocol =
          LucSoCon2Protocol;
      LucSoConIndex = *LpNoOfOptionsTx;
      *LpNoOfOptionsTx = *LpNoOfOptionsTx + SD_TWO;
    }
  }
  return (LucSoConIndex);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_QueueGenEntryIndexes                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function generates the Index1, Index2,         **
**                          NoOfOptions1, NoOfOptions2 fields in the entry    **
**                          structure.                                        **
**                        If the config option is present, it is generated    **
**                          first, then the endpoint/multicast option indexes **
**                          are written                                       **
**                        If no config option is present, the endpoint or     **
**                          multicast option is written into the Index1       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LblConfigOptionPresent - Boolean indicating whether **
**                          the config option is present                      **
**                      : LucConfigIndex - This is the index of the config    **
**                          option in the option array, if present            **
**                      : LucSoConIndex - This is the index of the endpoint   **
**                          or multicast option in the option array. It is    **
**                          zero if absent.                                   **
**                      : LucNoOfValidIds - This is the no of valid elements  **
**                          for LucSoConIndex                                 **
**                                                                            **
** InOut parameter      : LpQueueElement - This is a pointer to the queue     **
**                          element in which the indexes have to be updated   **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0258                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static void Sd_QueueGenEntryIndexes(
    boolean LblConfigOptionPresent,
    uint8 LucConfigIndex,
    uint8 LucSoConIndex,
    uint8 LucNoOfValidIds,
    Sd_QueueType * LpQueueElement)
{
  /* SWS_SD_00623
     SWS_SD_00187
   SWS_SD_00188 */
  Sd_Entry1DataType *LpEntry1;
  Sd_Entry2DataType *LpEntry2;
  uint8 LucIndex1ToSend;
  uint8 LucIndex2ToSend;
  uint8 LucNoOfOptions1ToSend;
  uint8 LucNoOfOptions2ToSend;
  /*polyspace +4 RTE:UNR [Justified:Low] "This If condition will be false
  if LblConfigOptionPresent is Set as SD_TRUE" */
  if (SD_TRUE == LblConfigOptionPresent)
  {
    LucIndex1ToSend = LucConfigIndex;
    LucNoOfOptions1ToSend = SD_ONE;
    LucIndex2ToSend = LucSoConIndex;
    LucNoOfOptions2ToSend = LucNoOfValidIds;
  }
  /*polyspace +3 RTE:UNR [Justified:Low] "This Condition shall be True when
LpClientServiceStatic->pUdpSoConGrp is Set other than SD_TRUE" */
  else
  { /*SWS_SD_00626
      SWS_SD_00190 */
    LucIndex1ToSend = LucSoConIndex;
    LucNoOfOptions1ToSend = LucNoOfValidIds;
    LucIndex2ToSend = SD_ZERO;
    LucNoOfOptions2ToSend = SD_ZERO;
  }
  if ((SD_FIND_SERVICE_ENTRY ==
       (LpQueueElement->stEntryData).enTypeOfEntry) ||
      (SD_OFFER_SERVICE_ENTRY ==
       (LpQueueElement->stEntryData).enTypeOfEntry) ||
      (SD_STOP_OFFER_SERVICE_ENTRY ==
       (LpQueueElement->stEntryData).enTypeOfEntry))
  {
    LpEntry1 = &((LpQueueElement->stEntryData).unEntryData.stEntry1);
    LpEntry1->ucIndex1 = LucIndex1ToSend;
    LpEntry1->ucNoOfOptions1 = LucNoOfOptions1ToSend;
    LpEntry1->ucIndex2 = LucIndex2ToSend;
    LpEntry1->ucNoOfOptions2 = LucNoOfOptions2ToSend;
  }
  else
  {
    LpEntry2 = &((LpQueueElement->stEntryData).unEntryData.stEntry2);
    LpEntry2->ucIndex1 = LucIndex1ToSend;
    LpEntry2->ucNoOfOptions1 = LucNoOfOptions1ToSend;
    LpEntry2->ucIndex2 = LucIndex2ToSend;
    LpEntry2->ucNoOfOptions2 = LucNoOfOptions2ToSend;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_TxGetOptionRefFind                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the options for the FIND entry   **
**                        It returns a pointer to pointer to the configutation**
**                          option.                                           **
**                        The return value is always zero as the no of        **
**                          options is counted for TCP and UCP and not  for   **
**                          config option                                     **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to queue element for which **
**                         options references are to be retreived.            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : *LppConfigOption - Pointer to Pointer to            **
**                          Config option                                     **
**                                                                            **
** Return parameter     : uint8 - No of TCP/UDP options returned              **
**                          SD_ZERO in this case                              **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                        Sd_GaaClientServiceStatic                           **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0203                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static uint8 Sd_TxGetOptionRefFind(
    const Sd_QueueType * LpQueueElement,
    const uint8* * LppConfigOption)
{
  /* SWS_SD_00480 */
  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  Sd_InstanceStaticType const *LpInstanceStatic;

  uint8 LucReturnVal;

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[LpQueueElement->ucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LpQueueElement->ucSdInstanceIndex);
#endif

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpClientServiceStatic =
      &Sd_GaaClientServiceStatic[LpQueueElement->ddGenericIndex];
#else
  LpClientServiceStatic =
      ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LpQueueElement->ddGenericIndex);
#endif

  /*polyspace +15 RTE:IDP [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being illegally dereferenced." */

  if (SD_NULL_PTR == LpClientServiceStatic->pConfigOption)

  /*polyspace +15 RTE:UNR [Justified:Low] "Pointers with this Grey flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
  {
    if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
    {
      *LppConfigOption = SD_NULL_PTR;
    }
    else
    {
      *LppConfigOption = LpInstanceStatic->pConfigOption;
    }
  }
  else
  {

    *LppConfigOption = LpClientServiceStatic->pConfigOption;
  }

  LucReturnVal = SD_ZERO;
  return (LucReturnVal);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_TxGetOptionRefOffer                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the options for the OFFER and    **
**                          STOPOFFER entry                                   **
**                        It returns the no of TCP or UDP options configured  **
**                        It orders the outputs so that if only TCP or only   **
**                          UDP is configured, SoConId1 is returned           **
**                        It outputs the Socket Connection ID's and the       **
**                          protocol values for first and second option       **
**                        It also outputs the LpTypeOfOption enum             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to queue element for which **
**                         options references are to be retreived.            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSoConId1 - Pointer to SoCon1 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol1 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId1                         **
**                      : LpSoConId2 - Pointer to SoCon2 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol2 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId2                         **
**                      : *LppConfigOption - Pointer to Pointer to            **
**                          Config option                                     **
**                      : LpTypeOfOption - This gives the type of options     **
**                          to be used.                                       **
**                                                                            **
** Return parameter     : uint8 - No of TCP/UDP options returned              **
**                          SD_ZERO in this case                              **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                        Sd_GaaServerServiceStatic, Sd_GaaSoConId            **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0204                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint8 Sd_TxGetOptionRefOffer(
    const Sd_QueueType * LpQueueElement,
    SoAd_SoConIdType * LpSoConId1,
    uint8 * LpProtocol1,
    SoAd_SoConIdType * LpSoConId2,
    uint8 * LpProtocol2,
    const uint8* * LppConfigOption,
    Sd_TypeOfOptionsType * LpTypeOfOption)
{

  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Sd_InstanceStaticType const *LpInstanceStatic;

  uint8 LucReturnVal;
  /* SWS_SD_00672 */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[LpQueueElement->ucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LpQueueElement->ucSdInstanceIndex);
#endif

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpServerServiceStatic = &Sd_GaaServerServiceStatic[LpQueueElement->ddGenericIndex];
#else
  LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LpQueueElement->ddGenericIndex);
#endif

  /*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being illegally dereferenced." */
  /* polyspace +10 RTE:UNR [Justified:Low] "This check will be true when
                  LpServerServiceStatic->pTcpSoConGrp is not a null ptr " */
  if (SD_NULL_PTR == LpServerServiceStatic->pTcpSoConGrp)

  /* polyspace +4 RTE:UNR [Justified:Low] "This check will be true when
                       LpServerServiceStatic->pTcpSoConGrp is not a null ptr " */
  {

    if (SD_NULL_PTR == LpServerServiceStatic->pUdpSoConGrp)

    {
      LucReturnVal = SD_ZERO;
    }
    else
    {
      LucReturnVal = SD_ONE;

      *LpSoConId1 = Sd_GaaSoConId
          [LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex];

      *LpProtocol1 = SD_PROTOCOL_UDP;
    }
  }
  else
  {

    /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be true
                        when  LpServerServiceStatic is Set as SD_NULL_PTR" */
    /*polyspace +5 RTE:IDP [Justified:Low] "This Condition shall be true
                   when  LpServerServiceStatic is Set as SD_NULL_PTR" */
    if (SD_NULL_PTR == LpServerServiceStatic->pUdpSoConGrp)

    /*polyspace +5 RTE:IDP [Justified:Low] "This Condition shall be true
  when  LpServerServiceStatic is Set as SD_NULL_PTR" */
    /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be true when
                             LpServerServiceStatic is Set as SD_NULL_PTR" */
    {
      LucReturnVal = SD_ONE;

      *LpSoConId1 = Sd_GaaSoConId
          [LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex];

      *LpProtocol1 = SD_PROTOCOL_TCP;
    }
    else
    {
      LucReturnVal = SD_TWO;
      /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being out of bounds." */
      *LpSoConId1 = Sd_GaaSoConId
          [LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex];

      *LpProtocol1 = SD_PROTOCOL_TCP;
      /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
      *LpSoConId2 = Sd_GaaSoConId
          [LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex];

      *LpProtocol2 = SD_PROTOCOL_UDP;
    }
  }
  /* SWS_SD_00210 */
  /*polyspace +11 RTE:UNR [Justified:Low] "This Condition shall be true
                     when  LpInstanceStatic->blDomainIpv4 is Set as SD_FALSE" */
  /*polyspace +10 RTE:IDP [Justified:Low] "This Condition shall be true
                     when  LpInstanceStatic->blDomainIpv4 is Set as SD_FALSE" */
  if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
  {
    *LpTypeOfOption = SD_IPV4_ENDPOINT_OPTION;
  }
  else
  {
    *LpTypeOfOption = SD_IPV6_ENDPOINT_OPTION;
  }

  /* polyspace +7 RTE:UNR [Justified:Low] "This check will be true when
       (LpServerServiceStatic->stServerStaticFlag).blAutoAvaliable)
       is not equal to SD_TRUE " */
  /*polyspace +10 RTE:IDP [Justified:Low] "This Condition shall be True
              when  LpServerServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
  if (SD_NULL_PTR == LpServerServiceStatic->pConfigOption)

  {
    /*polyspace +2 RTE:IDP [Justified:Low] "This Condition shall be True
           when  LpServerServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
    if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
    {
      *LppConfigOption = SD_NULL_PTR;
    }
    /*polyspace +10 RTE:IDP [Justified:Low] "This Condition shall be True
 when  LpServerServiceStatic->pConfigOption is not Set as SD_NULL_PTR" */
    else
    {
      *LppConfigOption = LpInstanceStatic->pConfigOption;
    }
  }
  else
  {

    *LppConfigOption = LpServerServiceStatic->pConfigOption;
  }

  return (LucReturnVal);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_TxGetOptionRefSubscribe                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the options for the SUBSCRIBE    **
**                          and STOPSUBSCRIBE entry                           **
**                        It returns the no of TCP or UDP options configured  **
**                        It orders the outputs so that if only TCP or only   **
**                          UDP is configured, SoConId1 is returned           **
**                        It outputs the Socket Connection ID's and the       **
**                          protocol values for first and second option       **
**                        It also outputs the LpTypeOfOption enum             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to queue element for which **
**                         options references are to be retreived.            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSoConId1 - Pointer to SoCon1 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol1 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId1                         **
**                      : LpSoConId2 - Pointer to SoCon2 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol2 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId2                         **
**                      : *LppConfigOption - Pointer to Pointer to            **
**                          Config option                                     **
**                      : LpTypeOfOption - This gives the type of options     **
**                          to be used.                                       **
**                                                                            **
** Return parameter     : uint8 - No of TCP/UDP options returned              **
**                          SD_ZERO in this case                              **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                          Sd_GaaConsumedEvGrpStatic,                        **
**                          Sd_GaaClientServiceStatic,                        **
**                          Sd_GaaClientService, Sd_GaaSoConId                **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0205                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint8 Sd_TxGetOptionRefSubscribe(
    const Sd_QueueType * LpQueueElement,
    SoAd_SoConIdType * LpSoConId1,
    uint8 * LpProtocol1,
    SoAd_SoConIdType * LpSoConId2,
    uint8 * LpProtocol2,
    const uint8* * LppConfigOption,
    Sd_TypeOfOptionsType * LpTypeOfOption)
{
#if (STD_ON == SD_CLIENT_CONFIGURED)
  Sd_InstanceStaticType const *LpInstanceStatic;
  Sd_ClientServiceStaticType const *LpClientServiceStatic = NULL_PTR;
  Sd_ClientServiceType const *LpClientService;
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
#endif

  uint8 LucReturnVal;
  /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[LpQueueElement->ucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LpQueueElement->ucSdInstanceIndex);
#endif

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpConsumedEvGrpStatic =
      &Sd_GaaConsumedEvGrpStatic[LpQueueElement->ddGenericIndex];
#else
  LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LpQueueElement->ddGenericIndex);
#endif

  /*polyspace +15 RTE:IDP [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being illegally dereferenced." */
  /*polyspace +11 RTE:UNR [Justified:Low] "This Condition shall be false when
   LpConsumedEvGrpStatic->usClientServiceIndex  is Set as SD_NO_OF_CLIENT_SERVICES
   " */
  if (LpConsumedEvGrpStatic->usClientServiceIndex < SD_NO_OF_CLIENT_SERVICES)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic =
        &Sd_GaaClientServiceStatic[LpConsumedEvGrpStatic->usClientServiceIndex];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LpConsumedEvGrpStatic->usClientServiceIndex);
#endif
  }
  LpClientService = &Sd_GaaClientService[LpConsumedEvGrpStatic->usClientServiceIndex];

  /*polyspace +11 RTE:UNR [Justified:Low] "This Condition shall be False when
                  LpClientServiceStatic->pTcpSoConGrp  is  Set as NULL_PTR " */
  /*polyspace +15 RTE:IDP [Justified:Low] "This Condition shall be True when
                  LpServerServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
  if (SD_NULL_PTR == LpClientServiceStatic->pTcpSoConGrp)

  {

    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall
          be false when the blDomainIpv4 is Set to SD_FALSE.*/
    if (SD_NULL_PTR == LpClientServiceStatic->pUdpSoConGrp)

    {
      LucReturnVal = SD_ZERO;
    }
    else
    {
      LucReturnVal = SD_ONE;
      /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag
     are made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
      /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be True when
                      SD_NO_OF_SOCKET_CONNECTIONS is less than SoConIndexUdp  " */
      if (LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        *LpSoConId1 = Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp];
      }
      *LpProtocol1 = SD_PROTOCOL_UDP;
    }
  }
  /*polyspace +8 RTE:UNR [Justified:Low] "This Condition shall be True when
               LpClientServiceStatic->pUdpSoConGrp is Set as SD_NULL_PTR" */
  else
  {

    if (SD_NULL_PTR == LpClientServiceStatic->pUdpSoConGrp)

    {
      LucReturnVal = SD_ONE;
      /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being out of bounds." */
      if (LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        *LpSoConId1 = Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp];
      }

      *LpProtocol1 = SD_PROTOCOL_TCP;
    }
    else
    {
      LucReturnVal = SD_TWO;
      /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
           checks in order to prevent them from being out of bounds." */
      if (LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        *LpSoConId1 = Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp];
      }
      *LpProtocol1 = SD_PROTOCOL_TCP;
      /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being out of bounds." */
      if (LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        *LpSoConId2 = Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp];
      }
      *LpProtocol2 = SD_PROTOCOL_UDP;
    }
  }
  /*polyspace +10 RTE:UNR [Justified:Low] "Pointers with this Grey Flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
  {
    *LpTypeOfOption = SD_IPV4_ENDPOINT_OPTION;
  }

  else
  {
    *LpTypeOfOption = SD_IPV6_ENDPOINT_OPTION;
  }
  if (SD_SERVICE_ID_TYPE_TWO_ENTRY_CHECK == LpClientServiceStatic->usServiceId)
  {
    /* Determine Config option pointer */
    if (SD_NULL_PTR == LpClientServiceStatic->pConfigOption)
    {
      /* If Client option is not present, check for hostname */
      if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
      {
        *LppConfigOption = SD_NULL_PTR;
      }
      else
      {
        *LppConfigOption = LpInstanceStatic->pConfigOption;
      }
    }
    else
    {
      *LppConfigOption = LpClientServiceStatic->pConfigOption;
    }
  }
  else
  {
    *LppConfigOption = SD_NULL_PTR;
  }

  /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be True
when  LpClientServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
  /*polyspace +5 RTE:IDP [Justified:Low] "This Condition shall be True
  when  LpClientServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
  if (SD_NULL_PTR == LpClientServiceStatic->pConfigOption)
  /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be True
  when  LpClientServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
  {
    if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
    {
      *LppConfigOption = SD_NULL_PTR;
    }
    else
    {
      *LppConfigOption = LpInstanceStatic->pConfigOption;
    }
  }
  /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be True
when  LpClientServiceStatic->pConfigOption is Set other than SD_NULL_PTR" */
  else
  {

    *LppConfigOption = LpClientServiceStatic->pConfigOption;
  }

  return (LucReturnVal);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_TxGetOptionRefSubscribeAck                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the options for the SUBSCRIBEACK **
**                          entry                                             **
**                        It returns the no of multicast  options configured  **
**                        It outputs the Socket Connection ID's and the       **
**                          protocol values for multicast option              **
**                        It also outputs the LpTypeOfOption enum             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to queue element for which **
**                         options references are to be retreived.            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSoConId1 - Pointer to SoCon1 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol1 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId1                         **
**                      : *LppConfigOption - Pointer to Pointer to            **
**                          Config option                                     **
**                      : LpTypeOfOption - This gives the type of options     **
**                          to be used.                                       **
**                                                                            **
** Return parameter     : uint8 - No of TCP/UDP options returned              **
**                          SD_ZERO in this case                              **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                        Sd_GaaEvHandlerStatic,                              **
**                        Function(s) invoked : None                          **
**                                                                            **
** Design ID              : SD_SDD_0206                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint8 Sd_TxGetOptionRefSubscribeAck(
    const Sd_QueueType * LpQueueElement,
    SoAd_SoConIdType * LpSoConId1,
    uint8 * LpProtocol1,
    const uint8* * LppConfigOption,
    Sd_TypeOfOptionsType * LpTypeOfOption)
{
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  Sd_InstanceStaticType const *LpInstanceStatic;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;

  uint8 LucReturnVal;
  /* SWS_SD_00480 */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[LpQueueElement->ucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LpQueueElement->ucSdInstanceIndex);
#endif

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LpQueueElement->ddGenericIndex];
#else
  LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + (LpQueueElement->ddGenericIndex));
#endif
  /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
   made sure that they are within their range by having necessary boundary
   checks in order to prevent them from being illegally dereferenced." */
  LpServerServiceStatic = &Sd_GaaServerServiceStatic[(LpEvHandlerStatic->usServerServiceIndex)];
#else
  /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
   made sure that they are within their range by having necessary boundary
   checks in order to prevent them from being illegally dereferenced." */
  LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + (LpEvHandlerStatic->usServerServiceIndex));
#endif
  /* SWS_SD_00659
     SWS_SD_00660  */
  /*polyspace +10 RTE:UNR [Justified:Low] "Pointers with this Grey flag are
   made sure that they are within their range by having necessary boundary
   checks in order to prevent them from being illegally dereferenced." */
  /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (SD_TRUE == ((LpEvHandlerStatic->stEvHandlerStaticFlag).blMulticastEventSoConPresent))
  {
    LucReturnVal = SD_ONE;
    *LpSoConId1 = (LpEvHandlerStatic->ddMulticastEventSoConId);
    *LpProtocol1 = SD_PROTOCOL_UDP;
  }
  /*polyspace +10 RTE:UNR [Justified:Low] "Pointers with this Grey flag are
   made sure that they are within their range by having necessary boundary
   checks in order to prevent them from being illegally dereferenced." */
  else
  {
    LucReturnVal = SD_ZERO;
  }
  /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
  {
    *LpTypeOfOption = SD_IPV4_MULTICAST_OPTION;
  }
  /*polyspace +7 RTE:UNR [Justified:Low] "This Condition shall be false
  when  LpInstanceStatic->blDomainIpv4is Set as SD_FALSE" */
  else
  {
    *LpTypeOfOption = SD_IPV6_MULTICAST_OPTION;
  }

  if (SD_SERVICE_ID_TYPE_TWO_ENTRY_CHECK == LpServerServiceStatic->usServiceId)
  {
    /* Determine Config option pointer */
    if (SD_NULL_PTR == LpEvHandlerStatic->pConfigOption)
    {
      /* If server option is not present, check for hostname */
      if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
      {
        *LppConfigOption = SD_NULL_PTR;
      }
      else
      {
        *LppConfigOption = LpInstanceStatic->pConfigOption;
      }
    }
    else
    {
      *LppConfigOption = LpEvHandlerStatic->pConfigOption;
    }
  }
  else
  {
    *LppConfigOption = SD_NULL_PTR;
  }
  /*polyspace +6 RTE:IDP [Justified:Low] "This Condition shall be True
  when  LpClientServiceStatic->pConfigOption is Set as SD_NULL_PTR" */
  if (SD_NULL_PTR == LpEvHandlerStatic->pConfigOption)
  {
    /*polyspace +7 RTE:UNR [Justified:Low] "This Condition shall be True
    when  LpInstanceStatic->pConfigOption is Set as NULL_PTR" */
    if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
    {
      *LppConfigOption = SD_NULL_PTR;
    }
    else
    {
      *LppConfigOption = LpInstanceStatic->pConfigOption;
    }
  }
  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpEvHandlerStatic is  not equal to SD_NULL_PTR . */
  else
  {
    *LppConfigOption = LpEvHandlerStatic->pConfigOption;
  }

  return (LucReturnVal);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_TxGetOptionRef                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to sent the offer entry     **
**                         It adds the service into the queue                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpQueueElement - Pointer to queue element for which **
**                         options references are to be retreived.            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSoConId1 - Pointer to SoCon1 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol1 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId1                         **
**                      : LpSoConId2 - Pointer to SoCon2 for                  **
**                          SoAd_GetLocalAddr()                               **
**                      : LpProtocol2 - Pointer to the protocol byte          **
**                          (TCP or UDP) for SoConId2                         **
**                      : *LppConfigOption - Pointer to Pointer to            **
**                          Config option                                     **
**                      : LpTypeOfOption - This gives the type of options     **
**                          to be used.                                       **
**                                                                            **
** Return parameter     : uint8 - No Of options valid in output. (0, 1 or 2)  **
**                         This counts the no of TCP or UDP options valid     **
**                         in the frame                                       **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic          **
**                        Function(s) invoked : Sd_TxGetOptionRefFind         **
**                        Sd_TxGetOptionRefOffer,                             **
**                        Sd_TxGetOptionRefSubscribe,                         **
**                        Sd_TxGetOptionRefSubscribeAck                       **
**                                                                            **
** Design ID              : SD_SDD_0202                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint8 Sd_TxGetOptionRef(
    const Sd_QueueType * LpQueueElement,
    SoAd_SoConIdType * LpSoConId1,
    uint8 * LpProtocol1,
    SoAd_SoConIdType * LpSoConId2,
    uint8 * LpProtocol2,
    const uint8* * LppConfigOption,
    Sd_TypeOfOptionsType * LpTypeOfOption)
{
  /*[SWS_SD_00480]*/
  uint8 LucReturnVal;
  Sd_InstanceStaticType const *LpInstanceStatic;
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[LpQueueElement->ucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LpQueueElement->ucSdInstanceIndex);
#endif
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  switch ((LpQueueElement->stEntryData).enTypeOfEntry)
  {
  case SD_FIND_SERVICE_ENTRY:
  {
#if (STD_ON == SD_CLIENT_CONFIGURED)
    LucReturnVal = Sd_TxGetOptionRefFind(LpQueueElement, LppConfigOption);
#else
    LucReturnVal = SD_ZERO;
#endif
    break;
  }
  case SD_OFFER_SERVICE_ENTRY:
  case SD_STOP_OFFER_SERVICE_ENTRY:
  {
#if (STD_ON == SD_SERVER_CONFIGURED)
    LucReturnVal = Sd_TxGetOptionRefOffer(LpQueueElement, LpSoConId1,
                                          LpProtocol1, LpSoConId2, LpProtocol2, LppConfigOption,
                                          LpTypeOfOption);
#else
    LucReturnVal = SD_ZERO;
#endif
    break;
  }
  case SD_SUBSCRIBE_ENTRY:
  case SD_STOP_SUBSCRIBE_ENTRY:
  {
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
    LucReturnVal = Sd_TxGetOptionRefSubscribe(LpQueueElement, LpSoConId1,
                                              LpProtocol1, LpSoConId2, LpProtocol2, LppConfigOption,
                                              LpTypeOfOption);
#else
    LucReturnVal = SD_ZERO;
#endif
    break;
  }
  case SD_SUBSCRIBE_ACK_ENTRY:
  {
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
    LucReturnVal = Sd_TxGetOptionRefSubscribeAck(LpQueueElement, LpSoConId1,
                                                 LpProtocol1, LppConfigOption, LpTypeOfOption);
#else
    LucReturnVal = SD_ZERO;
#endif
    break;
  }
  case SD_SUBSCRIBE_NACK_ENTRY:
  {
    /*polyspace +10 RTE:UNR [Justified:Low] "This Condition shall be True when
    LpInstanceStatic->pConfigOption is Set as NULL_PTR" */
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
    {
      *LppConfigOption = SD_NULL_PTR;
      LucReturnVal = SD_ZERO;
    }
    else
    {
      *LppConfigOption = LpInstanceStatic->pConfigOption;
      LucReturnVal = SD_ZERO;
    }
    break;
  }
  default:
  {
    LucReturnVal = SD_ZERO;
    break;
  }
  }
  return (LucReturnVal);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_TransmitEntry                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function transmits a single entry to the       **
**                          PDU array                                         **
**                        It also converts the entry data to Network          **
**                          byte order.                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEntry - Pointer to Entry to be                    **
**                          transmitted (Sd_EntryType)                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSduDataPtr - Pointer to first byte of entry to    **
**                          be sent                                           **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_HosttonetPtr,              **
**                        Sd_Hosttonet3Ptr, Sd_HosttonetlPtr                  **
**                                                                            **
** Design ID              : SD_SDD_0199                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static void Sd_TransmitEntry(
    uint8 LpSduDataPtr[],
    const Sd_EntryType * LpEntry)
{
  Sd_Entry1DataType const *LpEntry1;
  Sd_Entry2DataType const *LpEntry2;
  uint8 LucNoOfOptions;
  /*SWS_SD_00164
    SWS_SD_00166
  SWS_SD_00168
  SWS_SD_00170
    SWS_SD_00289a
    SWS_SD_00289b */
  /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
   made sure that they are within their range by having necessary boundary
   checks in order to prevent them from being illegally dereferenced." */
  switch (LpEntry->enTypeOfEntry)
  {
  /*SWS_SD_00162*/
  case SD_FIND_SERVICE_ENTRY:
  case SD_OFFER_SERVICE_ENTRY:
  case SD_STOP_OFFER_SERVICE_ENTRY:
  {

    LpEntry1 = &((LpEntry->unEntryData).stEntry1);

    LpSduDataPtr[SD_ZERO] = LpEntry1->ucEntryType;

    LpSduDataPtr[SD_ONE] = LpEntry1->ucIndex1;

    LpSduDataPtr[SD_TWO] = LpEntry1->ucIndex2;

    LucNoOfOptions = ((uint8)((LpEntry1->ucNoOfOptions1) << SD_FOUR) |
                      (LpEntry1->ucNoOfOptions2));
    LpSduDataPtr[SD_THREE] = LucNoOfOptions;

    Sd_HosttonetPtr(&LpSduDataPtr[SD_FOUR], LpEntry1->usServiceId);

    Sd_HosttonetPtr(&LpSduDataPtr[SD_SIX], LpEntry1->usInstanceId);

    LpSduDataPtr[SD_EIGHT] = LpEntry1->ucMajorVersion;

    Sd_Hosttonet3Ptr(&LpSduDataPtr[SD_NINE], LpEntry1->ulTtlsec);

    Sd_HosttonetlPtr(&LpSduDataPtr[SD_TWELVE], LpEntry1->ulMinorVersion);

    break;
  }
  case SD_SUBSCRIBE_ENTRY:
  case SD_STOP_SUBSCRIBE_ENTRY:
  case SD_SUBSCRIBE_ACK_ENTRY:
  case SD_SUBSCRIBE_NACK_ENTRY:
  {
    LpEntry2 = &((LpEntry->unEntryData).stEntry2);

    LpSduDataPtr[SD_ZERO] = LpEntry2->ucEntryType;

    LpSduDataPtr[SD_ONE] = LpEntry2->ucIndex1;

    LpSduDataPtr[SD_TWO] = LpEntry2->ucIndex2;

    LucNoOfOptions = ((uint8)((LpEntry2->ucNoOfOptions1) << SD_FOUR) |
                      (LpEntry2->ucNoOfOptions2));
    LpSduDataPtr[SD_THREE] = LucNoOfOptions;

    Sd_HosttonetPtr(&LpSduDataPtr[SD_FOUR], LpEntry2->usServiceId);

    Sd_HosttonetPtr(&LpSduDataPtr[SD_SIX], LpEntry2->usInstanceId);

    LpSduDataPtr[SD_EIGHT] = LpEntry2->ucMajorVersion;

    Sd_Hosttonet3Ptr(&LpSduDataPtr[SD_NINE], LpEntry2->ulTtlsec);

    LpSduDataPtr[SD_TWELVE] = SD_ZERO;

    LpSduDataPtr[SD_THIRTEEN] = LpEntry2->ucCounter;

    Sd_HosttonetPtr(&LpSduDataPtr[SD_FOURTEEN], LpEntry2->usEventGroupId);

    break;
  }
  default:
  {
    /* Do Nothing */
    break;
  }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_TransmitOption                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function Transmits a single Option to the      **
**                          PDU array                                         **
**                        It also converts the data to Network byte order.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpOptionsRef - Pointer to options to be             **
**                          transmitted (Sd_OptionsRefType)                   **
**                        ucSdInstanceIndex - The Index of the Instance that  **
**                          is to be transmitted (Required for generating     **
**                          Hostname )                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSduDataPtr - Pointer to beginning of entry to     **
**                          be transmitted                                    **
**                                                                            **
**                                                                            **
** Return parameter     : uint16 - Size of this option                        **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic          **
**                        Function(s) invoked : Sd_HosttonetPtr,              **
**                        SoAd_GetLocalAddr, SoAd_GetRemoteAddr,              **
**                        Sd_HosttonetlPtr                                    **
**                                                                            **
** Design ID              : SD_SDD_0200                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static uint16 Sd_TransmitOption(
    uint8 LpSduDataPtr[],
    const Sd_OptionsRefType * LpOptionsRef,
    uint8 ucSdInstanceIndex)
{
  uint16 LusReturnVal;
  TcpIp_SockAddrType LstIpv4Addr;
  TcpIp_SockAddrType LstIpv6Addr;
  uint8 LpNetmaskDummy;
  TcpIp_SockAddrType LstRouterIpv4Dummy;
  TcpIp_SockAddrType LstRouterIpv6Dummy;
  uint16 LusCount;
  uint16 LusCount2;
  uint16 LusHostnameLength;
  uint16 LusConfigOptionLength;
  Sd_InstanceStaticType const *LpInstanceStatic;

  /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[ucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + ucSdInstanceIndex);
#endif
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  switch (LpOptionsRef->enTypeOfOption)
  {
  case SD_CONFIGURATION_OPTION:
  {
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
       the LpOptionsRef is  equal to SD_NULL_PTR . */
    if (SD_NULL_PTR == LpOptionsRef->pConfigOption)
    {
      LusReturnVal = SD_ZERO;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LpOptionsRef->pConfigOption == LpInstanceStatic->pConfigOption)
    {
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[SD_ZERO] = LpInstanceStatic->pConfigOption[SD_ZERO];
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange
      flag are made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[SD_ONE] = LpInstanceStatic->pConfigOption[SD_ONE];
      LpSduDataPtr[SD_TWO] = SD_ONE;
      LpSduDataPtr[SD_THREE] = SD_ZERO;

      LusCount = SD_FOUR;
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      while (SD_ZERO != LpInstanceStatic->pConfigOption[LusCount])
      {
        /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being illegally dereferenced." */
        LpSduDataPtr[LusCount] = LpInstanceStatic->pConfigOption[LusCount];
        LusCount++;
      }
      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[LusCount] = SD_ZERO;
      LusCount++;
      LusReturnVal = LusCount;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    /*polyspace +7 RTE:UNR [Justified:Low] "This Condition shall be True when
     LpInstanceStatic->pConfigOption is Set as NULL_PTR" */
    else if (SD_NULL_PTR == LpInstanceStatic->pConfigOption)
    {
      /*polyspace +6 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[SD_ZERO] = LpOptionsRef->pConfigOption[SD_ZERO];
      LpSduDataPtr[SD_ONE] = LpOptionsRef->pConfigOption[SD_ONE];
      LpSduDataPtr[SD_TWO] = SD_ONE;
      LpSduDataPtr[SD_THREE] = SD_ZERO;

      LusCount = SD_FOUR;
      /*polyspace +6 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      while (SD_ZERO != LpOptionsRef->pConfigOption[LusCount])
      {
        LpSduDataPtr[LusCount] = LpOptionsRef->pConfigOption[LusCount];
        LusCount++;
      }
      /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[LusCount] = SD_ZERO;
      LusCount++;
      LusReturnVal = LusCount;
    }
    else
    {
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange
      flag are made sure that they are within their range by having necessary
      boundary checks in order to prevent them from being illegally dereferenced.
      " */
      LusHostnameLength =
          ((uint16)((uint16)(LpInstanceStatic->pConfigOption[SD_ZERO])
                    << SD_EIGHT)) |
          LpInstanceStatic->pConfigOption[SD_ONE];

      LusConfigOptionLength =
          ((uint16)((uint16)(LpOptionsRef->pConfigOption[SD_ZERO])
                    << SD_EIGHT)) |
          LpOptionsRef->pConfigOption[SD_ONE];

      LusConfigOptionLength = (LusConfigOptionLength +
                               LusHostnameLength) -
                              SD_TWO;

      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[SD_ZERO] = (uint8)(LusConfigOptionLength >> SD_EIGHT);
      LpSduDataPtr[SD_ONE] = (uint8)(LusConfigOptionLength & SD_BYTE_MASK);
      LpSduDataPtr[SD_TWO] = SD_ONE;
      LpSduDataPtr[SD_THREE] = SD_ZERO;

      LusCount = SD_FOUR;
      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      while (SD_ZERO != LpOptionsRef->pConfigOption[LusCount])
      {
        LpSduDataPtr[LusCount] = LpOptionsRef->pConfigOption[LusCount];
        LusCount++;
      }

      LusCount2 = SD_FOUR;
      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag
      are made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      while (SD_ZERO != LpInstanceStatic->pConfigOption[LusCount2])
      {
        /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
        LpSduDataPtr[LusCount] = LpInstanceStatic->pConfigOption[LusCount2];
        LusCount++;
        LusCount2++;
      }
      /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      LpSduDataPtr[LusCount] = SD_ZERO;

      LusReturnVal = LusConfigOptionLength + SD_THREE;
    }
    break;
  }
  /* SWS_SD_00211
   SWS_SD_00670 */
  case SD_IPV4_ENDPOINT_OPTION:
  {
    Sd_HosttonetPtr(&LpSduDataPtr[SD_ZERO], SD_IPV4_OPTION_LENGTH);
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_TWO] = (uint8)SD_OPTION_TYPE_IPV4_ENDPOINT;

    LpSduDataPtr[SD_THREE] = SD_ZERO;

    LstIpv4Addr.domain = TCPIP_AF_INET;
    LstRouterIpv4Dummy.domain = TCPIP_AF_INET;

    (void)SoAd_GetLocalAddr(LpOptionsRef->ddLocalAddrSoConId,
                            &LstIpv4Addr, &LpNetmaskDummy, &LstRouterIpv4Dummy);

    /*redmine #50073*/

    Sd_HtonlArr(&LpSduDataPtr[SD_FOUR],
                &LstIpv4Addr.aaSockAddrInetData[SD_TWO]);
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_EIGHT] = (uint8)SD_ZERO;

    LpSduDataPtr[SD_NINE] = LpOptionsRef->ucProtocol;

    Sd_HtonsArr(&LpSduDataPtr[SD_TEN],
                &LstIpv4Addr.aaSockAddrInetData[SD_ZERO]);
    LusReturnVal = SD_TWELVE;
    break;
  }
  /* SWS_SD_00679 */
  case SD_IPV6_ENDPOINT_OPTION:
  {
    Sd_HosttonetPtr(&LpSduDataPtr[SD_ZERO], SD_IPV6_OPTION_LENGTH);
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_TWO] = (uint8)SD_OPTION_TYPE_IPV6_ENDPOINT;

    LpSduDataPtr[SD_THREE] = (uint8)SD_ZERO;

    LstIpv6Addr.domain = TCPIP_AF_INET6;
    LstRouterIpv6Dummy.domain = TCPIP_AF_INET6;

    (void)SoAd_GetLocalAddr(LpOptionsRef->ddLocalAddrSoConId,
                            &LstIpv6Addr, &LpNetmaskDummy, &LstRouterIpv6Dummy);

    Sd_HtonlArr(&LpSduDataPtr[SD_FOUR],
                &LstIpv6Addr.aaSockAddrInetData[SD_TWO]);
    Sd_HtonlArr(&LpSduDataPtr[SD_EIGHT],
                &LstIpv6Addr.aaSockAddrInetData[SD_SIX]);
    Sd_HtonlArr(&LpSduDataPtr[SD_TWELVE],
                &LstIpv6Addr.aaSockAddrInetData[SD_TEN]);
    Sd_HtonlArr(&LpSduDataPtr[SD_SIXTEEN],
                &LstIpv6Addr.aaSockAddrInetData[SD_FOURTEEN]);
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_TWENTY] = (uint8)SD_ZERO;

    LpSduDataPtr[SD_TWENTY_ONE] = LpOptionsRef->ucProtocol;

    Sd_HtonsArr(&LpSduDataPtr[SD_TWENTY_TWO],
                &LstIpv6Addr.aaSockAddrInetData[SD_ZERO]);

    LusReturnVal = SD_TWENTY_FOUR;
    break;
  }
  /*SWS_SD_00393
  SWS_SD_00394*/
  case SD_IPV4_MULTICAST_OPTION:
  {
    Sd_HosttonetPtr(&LpSduDataPtr[SD_ZERO], SD_IPV4_OPTION_LENGTH);
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_TWO] = (uint8)SD_OPTION_TYPE_IPV4_MULTICAST;

    LpSduDataPtr[SD_THREE] = (uint8)SD_ZERO;

    LstIpv4Addr.domain = TCPIP_AF_INET;

    (void)SoAd_GetRemoteAddr(LpOptionsRef->ddLocalAddrSoConId,
                             &LstIpv4Addr);

    Sd_HtonlArr(&LpSduDataPtr[SD_FOUR],
                &LstIpv4Addr.aaSockAddrInetData[SD_TWO]);

    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_EIGHT] = (uint8)SD_ZERO;

    LpSduDataPtr[SD_NINE] = LpOptionsRef->ucProtocol;

    Sd_HtonsArr(&LpSduDataPtr[SD_TEN],
                &LstIpv4Addr.aaSockAddrInetData[SD_ZERO]);
    LusReturnVal = SD_TWELVE;
    break;
  }
  /*SWS_SD_00399
  SWS_SD_00404
  SWS_SD_00413 */
  case SD_IPV6_MULTICAST_OPTION:
  {
    Sd_HosttonetPtr(&LpSduDataPtr[SD_ZERO], SD_IPV6_OPTION_LENGTH);

    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_TWO] = (uint8)SD_OPTION_TYPE_IPV6_MULTICAST;

    LpSduDataPtr[SD_THREE] = (uint8)SD_ZERO;

    LstIpv6Addr.domain = TCPIP_AF_INET6;

    (void)SoAd_GetRemoteAddr(LpOptionsRef->ddLocalAddrSoConId,
                             &LstIpv6Addr);
    Sd_HtonlArr(&LpSduDataPtr[SD_FOUR],
                &LstIpv6Addr.aaSockAddrInetData[SD_TWO]);
    Sd_HtonlArr(&LpSduDataPtr[SD_EIGHT],
                &LstIpv6Addr.aaSockAddrInetData[SD_SIX]);
    Sd_HtonlArr(&LpSduDataPtr[SD_TWELVE],
                &LstIpv6Addr.aaSockAddrInetData[SD_TEN]);
    Sd_HtonlArr(&LpSduDataPtr[SD_SIXTEEN],
                &LstIpv6Addr.aaSockAddrInetData[SD_FOURTEEN]);

    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpSduDataPtr[SD_TWENTY] = (uint8)SD_ZERO;
    LpSduDataPtr[SD_TWENTY_ONE] = LpOptionsRef->ucProtocol;

    Sd_HtonsArr(&LpSduDataPtr[SD_TWENTY_TWO],
                &LstIpv6Addr.aaSockAddrInetData[SD_ZERO]);

    LusReturnVal = SD_TWENTY_FOUR;
    break;
  }
  default:
  {
    LusReturnVal = SD_ZERO;
    break;
  }
  }
  return (LusReturnVal);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_TxCreatePdu                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function creates the PDU from the queue after  **
**                          combining all the options                         **
**                      : It calls the required functions to create the       **
**                          options and entries for the Sd_frame              **
**                      : This function creates SD headers.                   **
**                      : It converts header bytes to network byte order      **
**                          for transmission.                                 **
**                      : It combines all the SD entries by calling           **
**                          Sd_TransmitEntry                                  **
**                      : It combines all the SD options be calling           **
**                          Sd_TransmitOption                                 **
**                      : It calles the SoAd_IfTransmit() function once the   **
**                          PDU is assembled                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpQueueIndex - Array of indexes of queue            **
**                          elements to use                                   **
**                      : LusNoOfSendQueue - No of Queue Indexes to transmit  **
**                      : LucSdInstanceIndex - The SD instance index of the   **
**                          frame to be transmitted                           **
**                      : LucNoOfOptionsTx - The no of options to be          **
**                          transmitted                                       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                          Sd_GaaInstance, Sd_GaaQueue,                      **
**                          Sd_GaaTxSduData, Sd_GaaOptionsRef                 **
**                        Function(s) invoked : Sd_HosttonetPtr,              **
**                          Sd_GetSessionIdAndFlag, Sd_TransmitEntry,         **
**                          Sd_TransmitOption, SoAd_IfTransmit,               **
**                           SoAd_SetRemoteAddr,                              **
**                          SoAd_GetLocalAddr, Sd_HosttonetlPtr               **
**                                                                            **
** Design ID              : SD_SDD_0201                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"

static void Sd_TxCreatePdu(
    const uint16 LpQueueIndex[],
    uint16 LusNoOfSendQueue,
    uint8 LucSdInstanceIndex,
    uint8 LucNoOfOptionsTx)
{
  Sd_InstanceStaticType const *LpInstanceStatic;
  Sd_InstanceType *LpInstance;
  Sd_QueueType const *LpQueueElement;
  PduLengthType LddPduLength;
  uint8 *LpSduDataPtrTemp;
  Sd_QueueType const *LpQueueElementTx;
  uint8 LucFlag;
  uint32 LulLengthOfEntries;
  uint32 LulLengthOfOptions;
  uint32 LulCurrOptionLength;
  uint32 LulTotalMessageLength;
  PduInfoType LddStPduInfoPtr;
  uint16 LusCount;
  uint16 LusSessionIdTx;
  boolean LblRebootFlagTx;
  uint8 LucSoADTxFlag;
  uint8 LucNetmaskDummy;
  TcpIp_SockAddrType LstSendAddrMulticast;
  TcpIp_SockAddrType LstDefaultRouterDummy;
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpInstanceStatic = &Sd_GaaInstanceStatic[LucSdInstanceIndex];
#else
  LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LucSdInstanceIndex);
#endif

  LpInstance = &Sd_GaaInstance[LucSdInstanceIndex];
  LpQueueElement = &Sd_GaaQueue[LpQueueIndex[SD_ZERO]];
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  LulLengthOfOptions = SD_ZERO;

  LusSessionIdTx = SD_ZERO;
  LblRebootFlagTx = SD_FALSE;

  LpQueueElementTx = LpQueueElement;

  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  Sd_HosttonetPtr(&Sd_GaaTxSduData[SD_ZERO], SD_CLIENT_ID);
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being illegally dereferenced." */
  Sd_GetSessionIdAndFlag(LpInstance, LpInstanceStatic,
                         LpQueueElementTx->blSendUnicast,
                         &LpQueueElementTx->stSendAddr,
                         &LusSessionIdTx, &LblRebootFlagTx);

  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  Sd_HosttonetPtr(&Sd_GaaTxSduData[SD_TWO], LusSessionIdTx);

  Sd_GaaTxSduData[SD_FOUR] = SD_PROTOCOL_VERSION;

  Sd_GaaTxSduData[SD_FIVE] = SD_INTERFACE_VERSION;

  Sd_GaaTxSduData[SD_SIX] = SD_MESSAGE_TYPE;

  Sd_GaaTxSduData[SD_SEVEN] = SD_RETURN_CODE;
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  LucFlag = SD_UNICAST_FLAG_MASK;
  if (SD_TRUE == LblRebootFlagTx)
  {
    LucFlag = SD_UNICAST_REBOOT_FLAG;
  }
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  Sd_GaaTxSduData[SD_EIGHT] = LucFlag;

  Sd_GaaTxSduData[SD_NINE] = SD_ZERO;
  Sd_GaaTxSduData[SD_TEN] = SD_ZERO;
  Sd_GaaTxSduData[SD_ELEVEN] = SD_ZERO;
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();

  /* SWS_SD_00031
     SWS_SD_00039*/
  LulLengthOfEntries = (uint32)LusNoOfSendQueue * SD_SIXTEEN;
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  Sd_HosttonetlPtr(&Sd_GaaTxSduData[SD_TWELVE], LulLengthOfEntries);
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();

  LulTotalMessageLength = SD_SIXTEEN;
  for (LusCount = SD_ZERO; LusCount < LusNoOfSendQueue; LusCount++)
  {
    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
    LpQueueElement = &Sd_GaaQueue[LpQueueIndex[LusCount]];
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
    Sd_TransmitEntry(&Sd_GaaTxSduData[LulTotalMessageLength],
                     &(LpQueueElement->stEntryData));
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
    LulTotalMessageLength = LulTotalMessageLength + SD_SIXTEEN;
  }
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  LpSduDataPtrTemp = &Sd_GaaTxSduData[LulTotalMessageLength];
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  LulTotalMessageLength = LulTotalMessageLength + SD_FOUR;

  for (LusCount = SD_ZERO; LusCount < LucNoOfOptionsTx; LusCount++)
  {
    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
    LulCurrOptionLength = Sd_TransmitOption(
        &Sd_GaaTxSduData[LulTotalMessageLength],
        &Sd_GaaOptionsRef[LusCount], LucSdInstanceIndex);
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
    LulLengthOfOptions = LulLengthOfOptions + LulCurrOptionLength;
    LulTotalMessageLength = LulTotalMessageLength + LulCurrOptionLength;
  }

  Sd_HosttonetlPtr(LpSduDataPtrTemp, LulLengthOfOptions);

  LddPduLength = SD_TWENTY + LulLengthOfEntries + LulLengthOfOptions;

  LddStPduInfoPtr.SduLength = LddPduLength;
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  LddStPduInfoPtr.SduDataPtr = Sd_GaaTxSduData;
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();

  /* SWS_SD_00480 */

  if (SD_TRUE == LpQueueElementTx->blSendUnicast)
  {
    /* Redmine : 50436 */
    /*Redmine 50068*/

    (void)SoAd_SetRemoteAddr(LpInstanceStatic->ddIpAddrSoConId,
                             &LpQueueElementTx->stSendAddr);

    LucSoADTxFlag = SoAd_IfTransmit(LpInstanceStatic->ddTxPduId,
                                    &LddStPduInfoPtr);
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
    Sd_GblSubscribeInQueue = (boolean)SD_FALSE;
#endif
  }
  else
  { /*polyspace +5 RTE:IDP [Justified:Low] "This Condition shall be false
                  when  LpInstanceStatic->blDomainIpv4 is Set as SD_FALSE" */
    /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be false
                    when  LpInstanceStatic->blDomainIpv4 is Set as SD_FALSE" */
    if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
    {
      LstSendAddrMulticast.domain = TCPIP_AF_INET;
      LstDefaultRouterDummy.domain = TCPIP_AF_INET;
    }
#if (STD_ON == SD_IPV6_ENABLED)
    else
    {
      LstSendAddrMulticast.domain = TCPIP_AF_INET6;
      LstDefaultRouterDummy.domain = TCPIP_AF_INET6;
    }
#endif

    (void)SoAd_GetLocalAddr(LpInstanceStatic->ddRxMulticastSoConId,
                            &LstSendAddrMulticast,
                            &LucNetmaskDummy,
                            &LstDefaultRouterDummy);

    /*Redmine 50068*/
    /* SWS_SD_00480 */
    (void)SoAd_SetRemoteAddr(LpInstanceStatic->ddIpAddrSoConId,
                             &LstSendAddrMulticast);

    LucSoADTxFlag = SoAd_IfTransmit(LpInstanceStatic->ddTxPduId,
                                    &LddStPduInfoPtr);
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
    Sd_GblSubscribeInQueue = (boolean)SD_FALSE;
#endif
  }

  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  if (E_NOT_OK == LucSoADTxFlag)
  {
    Sd_GblTxSuccessFLag = SD_FALSE;
    Sd_GucSdInstanceIndex = LucSdInstanceIndex;
    Sd_GddPduInfoPtr.SduLength = LddPduLength;
    Sd_GddPduInfoPtr.SduDataPtr = Sd_GaaTxSduData;
  }
  else
  {
    Sd_GblTxSuccessFLag = SD_TRUE;
  }
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_CombineQueue                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Combines all the elements of the      **
**                          queue that are currently due to transmit.         **
**                        All entries that are directed to a particular       **
**                          communication partner are transmitted in one      **
**                          frame                                             **
**                        If there are transmit requests due to more than one **
**                          communication partner, it is handled in the next  **
**                          main_function call.                               **
**                        (One communication partner here is a unicast        **
**                           Ip address, or a multicast SdInstance.)          **
**                        This function is called once every main function    **
**                          to transmit the queue.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non - Reentrant                                     **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaQueue,Sd_GaaQueueStatus **
**                        Sd_GaaQueueSend                                     **
**                        Function(s) invoked : Sd_QueueCheckforTransmit      **
**                        Sd_TxGetOptionRef, Sd_TxCreatePdu                   **
**                        Sd_QueueGenEntryIndexes,                            **
**                        Sd_QueueFillOptionsRefConfig,                       **
**                        Sd_QueueFillOptionsRefSingle,                       **
**                        Sd_QueueFillOptionsRefDouble,                       **
**                                                                            **
** Design ID              : SD_SDD_0253,SD_SDD_0007                           **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_CombineQueue(void)
{
  uint16 LusCount;
  Sd_QueueType *LpQueueElement;
  boolean LblInitialFrameUnicast;
  uint8 LucInitialSdInstance = SD_ZERO;
  TcpIp_SockAddrType LstInitialSendAddr;
  boolean LblFirstEntry;
  boolean LblTransmitEntry;
  SoAd_SoConIdType LddSoConId1 = {SD_ZERO};
  SoAd_SoConIdType LddSoConId2 = {SD_ZERO};
  uint8 LucSoCon1Protocol = SD_ZERO;
  uint8 LucSoCon2Protocol = SD_ZERO;
  uint8 const *LpElementConfigOption;
  boolean LblConfigOptionPresent;
  boolean LblQueueOverflow;
  Sd_TypeOfOptionsType LenTypeOfOption = {SD_ZERO};
  uint8 LucSoConIndex;
  uint8 LucConfigIndex;
  uint8 LucNoOfValidIds;
  uint8 LucNoOfOptionsTx;
  uint8 LucNoOfQueueSendTx;

  LblFirstEntry = SD_TRUE;
  /* SWS_SD_00481 */
  LusCount = SD_ZERO;
  LucNoOfOptionsTx = SD_ZERO;
  LucNoOfQueueSendTx = SD_ZERO;

#if (SD_QUEUE_SIZE != SD_ONE)
  while (LusCount < SD_QUEUE_SIZE)
#endif
  {
    LblQueueOverflow = FALSE;
    LpQueueElement = &Sd_GaaQueue[LusCount];
    if (SD_QUEUE_FULL == Sd_GaaQueueStatus[LusCount])
    {
      if (LpQueueElement->ulDelayCount > SD_ZERO)
      {
        LpQueueElement->ulDelayCount = LpQueueElement->ulDelayCount - SD_ONE;
      }
      else
      {
        LucSoConIndex = SD_ZERO;

        LblTransmitEntry = Sd_QueueCheckforTransmit(LpQueueElement,
                                                    &LblFirstEntry, &LucInitialSdInstance, &LblInitialFrameUnicast,
                                                    &LstInitialSendAddr);
        /* polyspace +3 RTE:UNR [Justified:Low] "This check will be true when
            LblTransmitEntry is equal to SD_TRUE " */
        if (SD_TRUE == LblTransmitEntry)
        {
          LucNoOfValidIds = Sd_TxGetOptionRef(LpQueueElement, &LddSoConId1,
                                              &LucSoCon1Protocol, &LddSoConId2, &LucSoCon2Protocol,
                                              &LpElementConfigOption, &LenTypeOfOption);
          /*polyspace +10 RTE:NIP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
          LucConfigIndex = Sd_QueueFillOptionsRefConfig(
              LpElementConfigOption, &LucNoOfOptionsTx,
              &LblQueueOverflow, &LblConfigOptionPresent);

          if (SD_ZERO == LucNoOfValidIds)
          {
          }
          /*LogicAnalyser WRN04: Manually Verified*/
          /*polyspace +5 RTE:IDP [Justified:Low] "This Condition shall be True
                                        when  LucNoOfValidIds is Set as SD_ONE" */
          /*polyspace +8 RTE:UNR [Justified:Low] "This Condition shall be True
                                       when  LucNoOfValidIds is Set as SD_ONE" */
          else if (SD_ONE == LucNoOfValidIds)
          {
            LucSoConIndex = Sd_QueueFillOptionsRefSingle(LddSoConId1,
                                                         LucSoCon1Protocol, LenTypeOfOption,
                                                         &LucNoOfOptionsTx, &LblQueueOverflow);
          }
          /*polyspace +4 RTE:UNR [Justified:Low] "This Condition shall be True
                                  when  LucNoOfValidIds is Set other than SD_ONE" */
          else
          {
            LucSoConIndex = Sd_QueueFillOptionsRefDouble(LddSoConId1,
                                                         LucSoCon1Protocol, LddSoConId2,
                                                         LucSoCon2Protocol, LenTypeOfOption,
                                                         &LucNoOfOptionsTx, &LblQueueOverflow);
          }

          Sd_QueueGenEntryIndexes(LblConfigOptionPresent, LucConfigIndex,
                                  LucSoConIndex, LucNoOfValidIds, LpQueueElement);
          /*SWS_SD_00039*/
          /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be false
                                    when  LblQueueOverflow is Set as SD_ZERO" */
          if (SD_TRUE == LblQueueOverflow)
          {
            Sd_TxCreatePdu(Sd_GaaQueueSend, (uint16)LucNoOfQueueSendTx,
                           LucInitialSdInstance, LucNoOfOptionsTx);

            LblFirstEntry = FALSE;
          }
          else
          {
            /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being out of bounds." */
            Sd_GaaQueueSend[LucNoOfQueueSendTx] = LusCount;
#if (SD_QUEUE_SIZE != SD_ONE)
            LucNoOfQueueSendTx++;
#else
            LucNoOfQueueSendTx = SD_ONE;
#endif
            Sd_GaaQueueStatus[LusCount] = SD_QUEUE_EMPTY;
          }
        }
      }
    }
/*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be false
                  when  LblQueueOverflow is Set as SD_ONE" */
#if (SD_QUEUE_SIZE != SD_ONE)
    if (SD_FALSE == LblQueueOverflow)
    {
      LusCount++;
    }
#endif
  }
  if (SD_FALSE == LblFirstEntry)
  {
    Sd_TxCreatePdu(Sd_GaaQueueSend, (uint16)LucNoOfQueueSendTx,
                   LucInitialSdInstance, LucNoOfOptionsTx);
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
