/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Rx.c                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the functions for receive stream           **
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
** 15-Sep-2025  Gourav Purohit      Implementing 24_11 SWS_Sd_00453           **
** 15-Sep-2025  Gourav Purohit      Initial Release.                          **
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
/** At section SD_Rx_c_REF_1
* Violates MISRA 2012 Advisory Rule 2.2, This statement has no side effects.
* This statement is required for polyspace.
* Justification: For the unused variables or variables which are set but not
* used for specific configuration compiler shows warning. QAC shows dead code
* for the steps which are implemented to avoid such compiler warnings.

* #section SD_Rx_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* All the #include statements in a particular code file should be grouped
* together near the head of the file. The rule states that the only items which
* may precede a #include in a file are other preprocessor directives or comments
* Justification: As per RS_BSW_00437 in AUTOSAR_SRS_BSWGeneral document Memory
* mapping is provided as start and stop memory sections. This is approved
* by AUTOSAR.

* #section SD_Rx_c_REF_3
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
* violates #ref SD_Rx_c_REF_1 Violates MISRA 2012 Required Rule 20.1
*  As per KPIT coding guidelines, macro name should start from module name
* (upper case) and hence this violation is suppressed as it does not impact the module funtionality
*
* #violates #ref SD_Rx_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)
* PRQA S 0857 EOF
* Part of  Common Deviation

* violates #ref SD_Rx_c_REF_3 Violates MISRA 2012 Dir-1.1
* PRQA S 0380 EOF
* Part of  Common Deviation
*
* #Violates #ref SD_Rx_REF_7, DCL00 Msg(qac-10.1.0-3227)
* PRQA S 3227 EOF
* *The message can be suppressed in case of AUTOSAR provided Standard API input arguments:
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
*
* #Violates #ref SD_Rx_c_REF_6,INT02 Msg(qac-10.1.0-2100)
*PRQA S 2100 EOF
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Rx_c_REF_7,INT02 Msg(qac-10.1.0-2101)
*PRQA S 2101 EOF
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
*
*
* #Violates #ref SD_Rx_c_REF_8,INT02 Msg(qac-10.1.0-2120)
*PRQA S 2120 EOF
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Rx_c_REF_9,INT02 Msg(qac-10.1.0-1251)
*PRQA S 1251 EOF
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
*
* #Violates #ref SD_Rx_c_REF_9,PRE04 Msg(certccm-2.1.0-5001)
*PRQA S 5001 EOF
*Deviation is only approved for
*the file names derived through AUTOSAR Specifications
* and KPIT Coding Guidelines as they do not cause any issue.
* #Violates #ref SD_Rx_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)
* PRQA S 5002 EOF
*Deviation is only approved for
* the file names derived through AUTOSAR Specifications and KPIT Coding
* Guidelines as they do not cause any issue.
*
* #Violates #ref SD_Rx_c_REF_9,PRE08 Msg(certccm-2.1.0-3200)
*PRQA S 3200 EOF
*Deviation is only approved for  the file names derived through
* AUTOSAR Specifications and KPIT Coding Guidelines as they do not cause any issue.
*
* #Violates #ref SD_Rx_c_REF_9,DCL00 Msg(qac-10.1.0-3204)
*PRQA S 3204 EOF
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
*#Violates #ref SD_Rx_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)
*PRQA S 4810 EOF
* Common Deviation
* #Violates #ref SD_Rx_c_REF_9,DCL07 Msg(qac-10.1.0-3450)
* PRQA S 553,2017,3219 EOF
* Deviation:77966
* #Violates #ref SD_Rx_REF_7,Rule-10.3 Msg(qac-10.1.0-1297)
* PRQA S 1297 EOF
* Deviation:77966
* #Violates #ref SD_Rx_c_REF_4,MSC01 Msg(qac-10.1.0-2000)
*PRQA S 2000 EOF
* Deviation:77966
* #Violates #ref SD_Rx_REF_7, Rule-17.7 Msg(qac-10.1.0-3200)
*PRQA S 2017,3198,3408,3447 EOF
* Deviation:77966
** #Violates #ref SD_Tx_c_REF_5,INT30 Msg(qac-10.1.0-3383)
*PRQA S 3383 EOF
*Deviation:77966
* #Violates #ref SD_Tx_c_REF_5,INT30 Msg(qac-10.1.0-3384)
*PRQA S 3384 EOF
* Deviation:77966
*/
/* PRQA S 5087 EOF */
/* violates #ref SD_Rx_c_REF_1 Violates MISRA 2012 Required Rule 20.1 */

/*#violates #ref SD_Rx_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)*/
/*PRQA S 0857 EOF*/

/* violates #ref SD_Rx_c_REF_3 Violates MISRA 2012 Dir-1.1 */
/* PRQA S 0380 EOF */

/* #Violates #ref SD_Rx_REF_7, DCL00 Msg(qac-10.1.0-3227) */
/* PRQA S 3227 EOF */

/* #Violates #ref SD_Tx_c_REF_5,INT30 Msg(qac-10.1.0-3383) */
/*PRQA S 3383 EOF*/

/* #Violates #ref SD_Tx_c_REF_5,INT30 Msg(qac-10.1.0-3384) */
/*PRQA S 3384 EOF*/

/* #Violates #ref SD_Rx_REF_7, Rule-17.7 Msg(qac-10.1.0-3200) */
/*PRQA S 2017,3198,3408,3447 EOF */

/* #Violates #ref SD_Rx_c_REF_4,MSC01 Msg(qac-10.1.0-2000) */
/*PRQA S 2000 EOF*/

/* #Violates #ref SD_Rx_c_REF_6,INT02 Msg(qac-10.1.0-2100) */
/*PRQA S 2100 EOF*/

/* #Violates #ref SD_Rx_c_REF_7,INT02 Msg(qac-10.1.0-2101) */
/*PRQA S 2101 EOF*/

/* #Violates #ref SD_Rx_REF_7,Rule-10.3 Msg(qac-10.1.0-1297) */
/*PRQA S 1297 EOF*/

/* #Violates #ref SD_Rx_c_REF_8,INT02 Msg(qac-10.1.0-2120) */
/*PRQA S 2120 EOF*/

/* #Violates #ref SD_Rx_c_REF_9,INT02 Msg(qac-10.1.0-1251) */
/*PRQA S 1251 EOF*/

/* #Violates #ref SD_Rx_c_REF_9,DCL07 Msg(qac-10.1.0-3450) */
/*PRQA S 553,2017,3219 EOF*/

/* #Violates #ref SD_Rx_c_REF_9,PRE04 Msg(certccm-2.1.0-5001) */
/*PRQA S 5001 EOF*/

/* #Violates #ref SD_Rx_c_REF_9,PRE08 Msg(certccm-2.1.0-5002) */
/*PRQA S 5002 EOF*/

/* #Violates #ref SD_Rx_c_REF_9,PRE08 Msg(certccm-2.1.0-3200) */
/*PRQA S 3200 EOF */

/* #Violates #ref SD_Rx_c_REF_9,DCL00 Msg(qac-10.1.0-3204)  */
/*PRQA S 3204 EOF */

/* #Violates #ref SD_Rx_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
/*PRQA S 4810 EOF */
/* #Violates #ref SD_Rx_c_REF_9,M3CM-3,03_EXP:Rule-18.4,EXP08 Msg(qac-10.1.0-0488) */
/*PRQA S 0488 EOF*/
/********************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Sd.h"
#include "Sd_IntTypes.h"
#include "Sd_Internal.h"
#include "BswM_Sd.h"
#include "Dem.h"
#include "SchM_Sd.h"
#include "SoAd.h"

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
**                      	Function Definitions                                  **
*******************************************************************************/
/*Design ID : SD_SDD_0338 */

/*******************************************************************************
** Function Name        : Sd_RxCheckHeader                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks the header fields of an SD     **
**                        message                                             **
**                                                                            **
**                        It raises error message if the field is not         **
**                          received properly                                 **
**                        It checks for SessionId and generates indication    **
**                          for Reboot                                        **
**                        It checks the length of the PDU message whether it  **
**                          is enough to receive the header, and also         **
**                          whether it is equal to size of header +           **
**                          size of entries + size of options.                **
**                        It converts the header bytes of the  PDU from       **
**                          network byte order to CPU byte order.             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpSduDataPtr - pointer to first byte of input PDU   **
**                      : LusSduLength - Length of the input PDU              **
**                      : LpInstance - pointer to instance of Sd              **
**                      : LblUnicast - This indicates whether the frame was   **
**                           received by unicast or multicast                 **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSessionId - This is a pointer to the session ID   **
**                          received in the frame                             **
**                      : LpRebootFlag - This is set SD_TRUE if reboot flag   **
**                          is received in the frame as '1' else SD_FALSE     **
**                                                                            **
** Return parameter     : E_OK - if header is decoded properly                **
**                      : E_NOT_OK - if header has any error                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID              : SD_SDD_0233                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxCheckHeader(
    const uint8 LpSduDataPtr[],
    const PduLengthType LusSduLength,
    uint16 * LpSessionId,
    boolean * LpRebootFlag)
{
  Std_ReturnType LddReturnValue;
  uint16 LusClientId;
  uint8 LucProtocolVer;
  uint8 LucInterfaceVer;
  uint8 LucMessageType;
  uint8 LucReturnCode;
  uint8 LucFlags;
  uint32 LulLengthofEntry;
  uint32 LulLengthOfOptions;
  /*SWS_SD_00708a
    SWS_SD_00484
  SWS_SD_00485*/
  if (LusSduLength < (uint32)SD_SIXTEEN)
  {
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* Generate Header Fields */
    LusClientId = Sd_NettohostPtr(&LpSduDataPtr[SD_ZERO]);
    *LpSessionId = Sd_NettohostPtr(&LpSduDataPtr[SD_TWO]);
    LucProtocolVer = LpSduDataPtr[SD_FOUR];
    LucInterfaceVer = LpSduDataPtr[SD_FIVE];
    LucMessageType = LpSduDataPtr[SD_SIX];
    LucReturnCode = LpSduDataPtr[SD_SEVEN];
    LucFlags = LpSduDataPtr[SD_EIGHT];

    LulLengthofEntry = Sd_NettohostlPtr(&LpSduDataPtr[SD_TWELVE]);

    if (SD_CLIENT_ID != LusClientId)
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_PROTOCOL_VERSION != LucProtocolVer)
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_INTERFACE_VERSION != LucInterfaceVer)
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_MESSAGE_TYPE != LucMessageType)
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_RETURN_CODE != LucReturnCode)
    {
      LddReturnValue = E_NOT_OK;
    }
    /* SWS_SD_00152 */
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_UNICAST_FLAG_MASK != (LucFlags & SD_UNICAST_FLAG_MASK))
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if ((uint32)SD_ZERO != (uint32)(LulLengthofEntry % (uint32)SD_SIXTEEN))
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LusSduLength < ((PduLengthType)LulLengthofEntry + (uint32)SD_SIXTEEN))
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      LulLengthOfOptions = Sd_NettohostlPtr(
          &LpSduDataPtr[LulLengthofEntry + (uint32)SD_SIXTEEN]);

      if (LusSduLength != ((PduLengthType)LulLengthofEntry +
                           (PduLengthType)LulLengthOfOptions + (uint32)SD_TWENTY))
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        LddReturnValue = E_OK;
        if (SD_REBOOT_FLAG_MASK == (LucFlags & SD_REBOOT_FLAG_MASK))
        {
          *LpRebootFlag = (boolean)SD_TRUE;
        }
        else
        {
          *LpRebootFlag = (boolean)SD_FALSE;
        }
      }
    }
  }

  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
/*******************************************************************************
** Function Name        : Sd_FillTypeOfEntry                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function fills the enTypeOfEntry enum in the   **
**                          entry structure.It fills this based on the input  **
**                          type field in the entry and the ttl received      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LucEntryType - Thus is the type field received in   **
**                          the entry                                         **
**                      : LulTtlSec - This is the ttl in sec received in the  **
**                          entry                                             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpEntry - This is the pointer to the entry struct   **
**                          in which the enTypeOfEntry field is to be filled  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - No error in type field      **
**                          E_NOT_OK - Type field is not in range             **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID              : SD_SDD_0218                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_FillTypeOfEntry(
    const uint8 LucEntryType,
    const uint32 LulTtlSec,
    Sd_EntryType * LpEntry)
{
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;

  if (LulTtlSec > (uint32)SD_ZERO)
  {
    if (SD_ENTRY_TYPE_FIND == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_FIND_SERVICE_ENTRY;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_ENTRY_TYPE_OFFER == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_OFFER_SERVICE_ENTRY;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_ENTRY_TYPE_SUBSCRIBE == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_SUBSCRIBE_ENTRY;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_ENTRY_TYPE_SUBSCRIBE_ACK == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_SUBSCRIBE_ACK_ENTRY;
    }
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
      LddReturnValue is E_OK " */
    else
    {
      LddReturnValue = E_NOT_OK;
    }
  }
  else
  {

    if (SD_ENTRY_TYPE_STOP_OFFER == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_STOP_OFFER_SERVICE_ENTRY;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_ENTRY_TYPE_STOP_SUBSCRIBE == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_STOP_SUBSCRIBE_ENTRY;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_ENTRY_TYPE_SUBSCRIBE_NACK == LucEntryType)
    {
      LpEntry->enTypeOfEntry = SD_SUBSCRIBE_NACK_ENTRY;
    }
    else
    {
      LddReturnValue = E_NOT_OK;
    }
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
**                      	Function Definitions                          **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_CheckIndexInRange(
    uint8 LucIndex1,
    uint8 LucNoOfOptions1,
    uint8 LucIndex2,
    uint8 LucNoOfOptions2,
    uint8 LucTotalNoOfOptions)
{
  /*SWS_SD_00708b*/
  Std_ReturnType LddReturnValue;

  if ((LucNoOfOptions1 + LucIndex1) > LucTotalNoOfOptions)
  {
    LddReturnValue = E_NOT_OK;
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((LucNoOfOptions2 + LucIndex2) > LucTotalNoOfOptions)
  {
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    LddReturnValue = E_OK;
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_RxGetEntry                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to decode the entry from    **
**                        the incoming data stream                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpPduDataPtr - pointer to first byte of entry       **
**                      : LpEntry - Pointer to entry                          **
**                      : LucNoOfOptions - This gives the total no of options **
**                          received in the SD frame                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK - if all types are read OK,                    **
**                        E_NOT_OK if any error occured                       **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_NettohostPtr,              **
**                          Sd_Nettohost3Ptr, Sd_NettohostlPtr,               **
**                          Sd_CheckIndexInRange, Sd_FillTypeOfEntry          **
**                                                                            **
** Design ID              : SD_SDD_0235                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxGetEntry(
    const uint8 LpPduDataPtr[],
    Sd_EntryType * LpEntry,
    uint8 LucNoOfOptions)
{
  uint8 LucEntryType;
  uint32 LulTtlSec;
  Std_ReturnType LddReturnValue;
  boolean LblEntryType1;
  uint8 LucData;

  LucEntryType = LpPduDataPtr[SD_ZERO];
  LddReturnValue = E_OK;

  if ((SD_ENTRY_TYPE_FIND == LucEntryType) ||
      (SD_ENTRY_TYPE_OFFER == LucEntryType))
  {
    LblEntryType1 = (boolean)SD_TRUE;
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((SD_ENTRY_TYPE_SUBSCRIBE == LucEntryType) ||
           (SD_ENTRY_TYPE_SUBSCRIBE_ACK == LucEntryType))
  {
    LblEntryType1 = (boolean)SD_FALSE;
  }
  else
  {
    LblEntryType1 = (boolean)SD_FALSE;
    LddReturnValue = E_NOT_OK;
  }
  if (E_OK == LddReturnValue)
  { /*SWS_SD_00624
      SWS_SD_00627*/
    if (LblEntryType1)
    {
      (LpEntry->unEntryData).stEntry1.ucEntryType = LucEntryType;
      (LpEntry->unEntryData).stEntry1.ucIndex1 = LpPduDataPtr[SD_ONE];
      (LpEntry->unEntryData).stEntry1.ucIndex2 = LpPduDataPtr[SD_TWO];

      LucData = LpPduDataPtr[SD_THREE];

      (LpEntry->unEntryData).stEntry1.ucNoOfOptions1 =
          ((uint8)(LucData & (uint8)SD_HIGH_NIBBLE_MASK)) >> SD_FOUR;
      (LpEntry->unEntryData).stEntry1.ucNoOfOptions2 =
          (LucData & (uint8)SD_LOW_NIBBLE_MASK);
      (LpEntry->unEntryData).stEntry1.usServiceId =
          Sd_NettohostPtr(&LpPduDataPtr[SD_FOUR]);
      (LpEntry->unEntryData).stEntry1.usInstanceId =
          Sd_NettohostPtr(&LpPduDataPtr[SD_SIX]);
      (LpEntry->unEntryData).stEntry1.ucMajorVersion = LpPduDataPtr[SD_EIGHT];
      (LpEntry->unEntryData).stEntry1.ulTtlsec =
          Sd_Nettohost3Ptr(&LpPduDataPtr[SD_NINE]);

      LulTtlSec = (LpEntry->unEntryData).stEntry1.ulTtlsec;

      (LpEntry->unEntryData).stEntry1.ulMinorVersion =
          Sd_NettohostlPtr(&LpPduDataPtr[SD_TWELVE]);

      if (SD_ZERO == (LpEntry->unEntryData).stEntry1.ucNoOfOptions1)
      {
        (LpEntry->unEntryData).stEntry1.ucIndex1 = SD_ZERO;
      }

      if (SD_ZERO == (LpEntry->unEntryData).stEntry1.ucNoOfOptions2)
      {
        (LpEntry->unEntryData).stEntry1.ucIndex2 = SD_ZERO;
      }

      LddReturnValue = Sd_CheckIndexInRange(
          (LpEntry->unEntryData).stEntry1.ucIndex1,
          (LpEntry->unEntryData).stEntry1.ucNoOfOptions1,
          (LpEntry->unEntryData).stEntry1.ucIndex2,
          (LpEntry->unEntryData).stEntry1.ucNoOfOptions2,
          LucNoOfOptions);
    }
    else
    {
      (LpEntry->unEntryData).stEntry2.ucEntryType = LucEntryType;
      (LpEntry->unEntryData).stEntry2.ucIndex1 = LpPduDataPtr[SD_ONE];
      (LpEntry->unEntryData).stEntry2.ucIndex2 = LpPduDataPtr[SD_TWO];

      LucData = LpPduDataPtr[SD_THREE];

      (LpEntry->unEntryData).stEntry2.ucNoOfOptions1 =
          (LucData & (uint8)SD_HIGH_NIBBLE_MASK) >> (uint8)SD_FOUR;
      (LpEntry->unEntryData).stEntry2.ucNoOfOptions2 =
          (LucData & (uint8)SD_LOW_NIBBLE_MASK);
      (LpEntry->unEntryData).stEntry2.usServiceId =
          Sd_NettohostPtr(&LpPduDataPtr[SD_FOUR]);
      (LpEntry->unEntryData).stEntry2.usInstanceId =
          Sd_NettohostPtr(&LpPduDataPtr[SD_SIX]);
      (LpEntry->unEntryData).stEntry2.ucMajorVersion = LpPduDataPtr[SD_EIGHT];
      (LpEntry->unEntryData).stEntry2.ulTtlsec =
          Sd_Nettohost3Ptr(&LpPduDataPtr[SD_NINE]);
      LulTtlSec = (LpEntry->unEntryData).stEntry2.ulTtlsec;
      (LpEntry->unEntryData).stEntry2.usReserved = LpPduDataPtr[SD_TWELVE];
      (LpEntry->unEntryData).stEntry2.ucCounter = (LpPduDataPtr[SD_THIRTEEN] &
                                                   SD_COUNTER_MASK);
      (LpEntry->unEntryData).stEntry2.usEventGroupId =
          Sd_NettohostPtr(&LpPduDataPtr[SD_FOURTEEN]);
      if (SD_ZERO == (LpEntry->unEntryData).stEntry2.ucNoOfOptions1)
      {
        (LpEntry->unEntryData).stEntry2.ucIndex1 = SD_ZERO;
      }

      if (SD_ZERO == (LpEntry->unEntryData).stEntry2.ucNoOfOptions2)
      {
        (LpEntry->unEntryData).stEntry2.ucIndex2 = SD_ZERO;
      }

      LddReturnValue = Sd_CheckIndexInRange(
          (LpEntry->unEntryData).stEntry2.ucIndex1,
          (LpEntry->unEntryData).stEntry2.ucNoOfOptions1,
          (LpEntry->unEntryData).stEntry2.ucIndex2,
          (LpEntry->unEntryData).stEntry2.ucNoOfOptions2,
          LucNoOfOptions);
    }

    if (E_OK == LddReturnValue)
    {
      LddReturnValue = Sd_FillTypeOfEntry(LucEntryType, LulTtlSec, LpEntry);
    }
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetOptionConfig                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the option for the Configuration **
**                          option                                            **
**                        If the otherserv key is present in the input stream **
**                          it is stored in the aaOtherServ array of the      **
**                          options union                                     **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LusOptionLength - Length of this individual option  **
**                      :   decoded from the input frame                      **
**                      : LpOptionsPtr - Pointer to Options starting point,   **
**                          after length of options                           **
**                                                                            **
** InOut parameter      : LpOptPtrIndex - Current index of the options        **
**                          pointer array above                               **
**                      : LpRxOptionsData - Pointer to base address of        **
**                          options array                                     **
**                      : LpNoOfOptions - Current no of the options in the    **
**                          options array                                     **
**                      : LpMalformedOption - Indicating whether the previous **
**                          option is malformed and output indicates if       **
**                          current is malformed                              **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_MatchString                **
** Design ID              : SD_SDD_0220                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetOptionConfig(
    uint16 LusOptionLength,
    const uint8 LpOptionsPtr[],
    uint16 * LpOptPtrIndex,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions,
    boolean * LpMalformedOption)
{
  uint8 LucNoOfChar;
  Std_ReturnType LddMatchReturn;
  uint16 LusOtherServIndex;
  uint16 LusCount;

  const uint8 LaaString[SD_ELEVEN] = {"otherserv="};

  LusOtherServIndex = SD_ZERO;
  LddMatchReturn = Sd_MatchString(&LpOptionsPtr[*LpOptPtrIndex],
                                  &LaaString[SD_ZERO], &LusOtherServIndex);
  /*SWS_SD_00205
    SWS_SD_00206
    SWS_SD_00665
    SWS_SD_00664 */
  if (E_NOT_OK == LddMatchReturn)
  {
    /* Set the first byte to '\0'*/
    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).aaOtherServ[SD_ZERO] = SD_ZERO;
  }
  else
  {
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LucNoOfChar = LpOptionsPtr
        [(*LpOptPtrIndex + LusOtherServIndex) - SD_ONE];

    LusCount = SD_ZERO;
    if (LucNoOfChar < SD_TEN)
    {
      *LpMalformedOption = (boolean)SD_TRUE;
    }
    else
    {
      LucNoOfChar = LucNoOfChar - SD_TEN;

      while ((LusCount < LucNoOfChar) &&
             (LusCount < (SD_OTHERSERV_SIZE - SD_ONE)))
      {
        /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
        (LpRxOptionsData[*LpNoOfOptions].unOptionsData).aaOtherServ[LusCount] =
            LpOptionsPtr[*LpOptPtrIndex + LusOtherServIndex + SD_TEN + LusCount];
        LusCount++;
      }
    }

    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).aaOtherServ[LusCount] =
        SD_ZERO;
  }

  *LpNoOfOptions = *LpNoOfOptions + SD_ONE;

  *LpOptPtrIndex = (*LpOptPtrIndex + LusOptionLength) - SD_ONE;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetOptionIpV4                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the option for the IPV4 option   **
**                          types.                                            **
**                        All the fields from the input stream are converted  **
**                          into network byte order and stored into the       **
**                          structure                                         **
**                        It checks if the domain is the IPv4 and returns a   **
**                          malformed error otherwise.                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LusOptionLength - Length of this individual option  **
**                      :   decoded from the input frame                      **
**                      : LenTypeOfOption - This is the type of option to be  **
**                          filled in the enTypeOfOption field                **
**                      : LpOptionsPtr - Pointer to Options starting point,   **
**                          after length of options                           **
**                                                                            **
** InOut parameter      : LpOptPtrIndex - Current index of the options        **
**                          pointer array above                               **
**                      : LpRxOptionsData - Pointer to base address of        **
**                          options array                                     **
**                      : LpNoOfOptions - Current no of the options in the    **
**                          options array                                     **
**                      : LpMalformedOption - Indicating whether the previous **
**                          option is malformed and output indicates if       **
**                          current is malformed                              **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_NettohostlPtr,             **
**                                              Sd_NettohostPtr               **
** Design ID              : SD_SDD_0221   [SWS_SD_00654]  [SWS_SD_00675]      **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetOptionIpV4(
    const Sd_InstanceStaticType * LpInstanceStatic,
    uint16 LusOptionLength,
    Sd_TypeOfOptionsType LenTypeOfOption,
    const uint8 LpOptionsPtr[],
    uint16 * LpOptPtrIndex,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions,
    boolean * LpMalformedOption)
{
  if (LusOptionLength != SD_IPV4_OPTION_LENGTH)
  {
    *LpMalformedOption = (boolean)SD_TRUE;
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be true when
  the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (!LpInstanceStatic->blDomainIpv4)
  {
    *LpMalformedOption = (boolean)SD_TRUE;
  }
  else
  {

    LpRxOptionsData[*LpNoOfOptions].enTypeOfOption = LenTypeOfOption;
    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv4.ulIpAddr =
        Sd_NettohostlPtr(&LpOptionsPtr[*LpOptPtrIndex]);
    *LpOptPtrIndex = *LpOptPtrIndex + SD_FOUR;
    *LpOptPtrIndex = *LpOptPtrIndex + SD_ONE; /* Reserved Field */
                                              /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
                                                made sure that they are within their range by having necessary boundary
                                                checks in order to prevent them from being illegally dereferenced." */
    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv4.ucProtocol =
        LpOptionsPtr[*LpOptPtrIndex];
    *LpOptPtrIndex = *LpOptPtrIndex + SD_ONE;
    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv4.usPortNo =
        Sd_NettohostPtr(&LpOptionsPtr[*LpOptPtrIndex]);
    *LpOptPtrIndex = *LpOptPtrIndex + SD_TWO;

    *LpNoOfOptions = *LpNoOfOptions + SD_ONE;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetOptionIpV6                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the option for the IPV6 option   **
**                          types.                                            **
**                        All the fields from the input stream are converted  **
**                          into network byte order and stored into the       **
**                          structure                                         **
**                        It checks if the domain is the IPv6 and returns a   **
**                          malformed error otherwise.                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LusOptionLength - Length of this individual option  **
**                      :   decoded from the input frame                      **
**                      : LenTypeOfOption - This is the type of option to be  **
**                          filled in the enTypeOfOption field                **
**                      : LpOptionsPtr - Pointer to Options starting point,   **
**                          after length of options                           **
**                                                                            **
** InOut parameter      : LpOptPtrIndex - Current index of the options        **
**                          pointer array above                               **
**                      : LpRxOptionsData - Pointer to base address of        **
**                          options array                                     **
**                      : LpNoOfOptions - Current no of the options in the    **
**                          options array                                     **
**                      : LpMalformedOption - Indicating whether the previous **
**                          option is malformed and output indicates if       **
**                          current is malformed                              **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_NettohostlPtr,             **
**                                              Sd_NettohostPtr               **
** Design ID              : SD_SDD_0220                                       **
*******************************************************************************/
#if (SD_IPV6_ENABLED == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetOptionIpV6(
    const Sd_InstanceStaticType * LpInstanceStatic,
    uint16 LusOptionLength,
    Sd_TypeOfOptionsType LenTypeOfOption,
    const uint8 LpOptionsPtr[],
    uint16 * LpOptPtrIndex,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions,
    boolean * LpMalformedOption)
{
  /*SWS_SD_00656
    SWS_SD_00218
  SWS_SD_00684 */
  uint16 LusCount;
  uint8 LucNoOfOptions;

  LucNoOfOptions = *LpNoOfOptions;

  if (LusOptionLength != SD_IPV6_OPTION_LENGTH)
  {
    *LpMalformedOption = (boolean)SD_TRUE;
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (LpInstanceStatic->blDomainIpv4)
  {
    *LpMalformedOption = (boolean)SD_TRUE;
  }
  else
  {
    LpRxOptionsData[*LpNoOfOptions].enTypeOfOption = LenTypeOfOption;

    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv6.pIpAddr = &Sd_GaaIpAddr[LucNoOfOptions * SD_FOUR];

    for (LusCount = SD_ZERO; LusCount < SD_FOUR; LusCount++)
    {
      (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv6.pIpAddr[LusCount] =
          Sd_NettohostlPtr(&LpOptionsPtr[*LpOptPtrIndex]);
      *LpOptPtrIndex = *LpOptPtrIndex + SD_FOUR;
    }

    *LpOptPtrIndex = *LpOptPtrIndex + SD_ONE; /* Reserved Field */
                                              /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
                                                made sure that they are within their range by having necessary boundary
                                                checks in order to prevent them from being illegally dereferenced." */
    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv6.ucProtocol =
        LpOptionsPtr[*LpOptPtrIndex];
    *LpOptPtrIndex = *LpOptPtrIndex + SD_ONE;
    (LpRxOptionsData[*LpNoOfOptions].unOptionsData).stOptionsIpv6.usPortNo =
        Sd_NettohostPtr(&LpOptionsPtr[*LpOptPtrIndex]);
    *LpOptPtrIndex = *LpOptPtrIndex + SD_TWO;

    *LpNoOfOptions = *LpNoOfOptions + SD_ONE;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_RxGetAllOptions                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function decodes the options in the PDU        **
**                      : It converts the options from network byte order to  **
**                          CPU byte order                                    **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - This is the static Instance      **
**                           pointer for this  PDU. (to check domain)         **
**                      : LpOptionsPtr - Pointer to Options starting point,   **
**                           after length of options                          **
**                      : LulLengthOfOptions - The length of the options      **
**                           array                                            **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpRxOptionsData - This is an array in which all     **
**                          the options are stored                            **
**                          Maximum 16 options can be accessed and stored.    **
**                      : LpNoOfOptions - The no of options found             **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - No error found in the       **
**                          options                                           **
**                        E_NOT_OK - error found when decoding options        **
**                          i.e. Malformed frame                              **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_GetOptionConfig,           **
**                          Sd_GetOptionIpV4, Sd_GetOptionIpV6,               **
**                          Sd_NettohostPtr, Dem_SetEventStatus,              **
**                          Dem_ReportErrorStatus                             **
** Design ID              : SD_SDD_0234  SWS_SD_00693                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxGetAllOptions(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const uint8 LpOptionsPtr[],
    uint32 LulLengthOfOptions,
    Sd_OptionsDataType LpRxOptionsData[],
    uint8 * LpNoOfOptions)
{
  uint32 LulCurrLength;
  boolean LblMalformedOption;
  Std_ReturnType LddReturnValue;

  uint16 LusOptionLength;
  uint8 LucOptionsType;
  uint16 LusOptPtrIndex;

  LulCurrLength = LulLengthOfOptions;
  *LpNoOfOptions = SD_ZERO;
  LblMalformedOption = (boolean)SD_FALSE;
  /* SD_SRS_584
     SWS_SD_00483
   SWS_SD_00477a */
  LusOptPtrIndex = SD_ZERO;

  while (LulCurrLength > (uint32)SD_ZERO)
  {
    LusOptionLength = Sd_NettohostPtr(&LpOptionsPtr[LusOptPtrIndex]);
    LusOptPtrIndex = LusOptPtrIndex + SD_TWO;
    /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    LucOptionsType = LpOptionsPtr[LusOptPtrIndex];
    LusOptPtrIndex = LusOptPtrIndex + SD_ONE;
    LusOptPtrIndex = LusOptPtrIndex + SD_ONE;

    if (((uint32)LusOptionLength + (uint32)SD_THREE) > LulCurrLength)
    {
      LulCurrLength = SD_ZERO;
      LblMalformedOption = (boolean)SD_TRUE;
    }
    else
    {

      LulCurrLength = LulCurrLength - ((uint32)LusOptionLength + (uint32)SD_THREE);
      /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      LpRxOptionsData[*LpNoOfOptions].enTypeOfOption = SD_CONFIGURATION_OPTION;

      if (SD_OPTION_TYPE_CONFIG == LucOptionsType)
      {
        Sd_GetOptionConfig(LusOptionLength, LpOptionsPtr,
                           &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_OPTION_TYPE_IPV4_ENDPOINT == LucOptionsType)
      {
        Sd_GetOptionIpV4(LpInstanceStatic, LusOptionLength,
                         (Sd_TypeOfOptionsType)SD_IPV4_ENDPOINT_OPTION, LpOptionsPtr,
                         &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_OPTION_TYPE_IPV4_MULTICAST == LucOptionsType)
      {
        Sd_GetOptionIpV4(LpInstanceStatic, LusOptionLength,
                         (Sd_TypeOfOptionsType)SD_IPV4_MULTICAST_OPTION, LpOptionsPtr,
                         &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_OPTION_TYPE_IPV4_SD_ENDPOINT == LucOptionsType)
      {
        Sd_GetOptionIpV4(LpInstanceStatic, LusOptionLength,
                         (Sd_TypeOfOptionsType)SD_IPV4_SD_ENDPOINT_OPTION, LpOptionsPtr,
                         &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
#if (SD_IPV6_ENABLED == STD_ON)
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_OPTION_TYPE_IPV6_ENDPOINT == LucOptionsType)
      {
        Sd_GetOptionIpV6(LpInstanceStatic, LusOptionLength,
                         (Sd_TypeOfOptionsType)SD_IPV6_ENDPOINT_OPTION, LpOptionsPtr,
                         &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_OPTION_TYPE_IPV6_MULTICAST == LucOptionsType)
      {
        Sd_GetOptionIpV6(LpInstanceStatic, LusOptionLength,
                         (Sd_TypeOfOptionsType)SD_IPV6_MULTICAST_OPTION, LpOptionsPtr,
                         &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_OPTION_TYPE_IPV6_SD_ENDPOINT == LucOptionsType)
      {
        Sd_GetOptionIpV6(LpInstanceStatic, LusOptionLength,
                         (Sd_TypeOfOptionsType)SD_IPV6_SD_ENDPOINT_OPTION, LpOptionsPtr,
                         &LusOptPtrIndex, LpRxOptionsData, LpNoOfOptions, &LblMalformedOption);
      }
#endif

      else
      { /*SWS_SD_00661
          SWS_SD_00662*/

        *LpNoOfOptions = *LpNoOfOptions + SD_ONE;

        LusOptPtrIndex = (LusOptPtrIndex + LusOptionLength) - SD_ONE;
      }
    }
    /* SWS_SD_00663 */
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    LpNoOfOptions is greater than SD_SIXTEEN" */
    if (*LpNoOfOptions > SD_SIXTEEN)
    {
      LulCurrLength = SD_ZERO;
      LblMalformedOption = (boolean)SD_TRUE;
    }
  }
  /* SWS_SD_00710 */
  LddReturnValue = E_OK;
  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    LblMalformedOption is SD_TRUE" */
  if (LblMalformedOption)
  {
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
    LddReturnValue = E_NOT_OK;
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_RxGetRemoteAddr                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function gets the remote address for the SD    **
**                          frame.                                            **
**                        If the SD endpoint option is detected, the remote   **
**                          address is taken from that option,                **
**                        Otherwise, the function SoAd_GetRemoteAddr is called**
**                          to determine the remote addr                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to instance structure    **
**                          for this SD frame.                                **
**                      : LpRxOptionsData - This is the pointer to the array  **
**                          of options for this frame.                        **
**                      : LucNoOfOptions - This is the number of options in   **
**                          this SD frame.                                    **
**                      : LblUnicast - This indicates whether the SD frame is **
**                          received via unicast or multicast                 **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Return parameter     : LpRemoteAddr - This is the pointer to the remote    **
**                          address for this frame                            **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GddIpv4Wildcard            **
**                          Sd_GddIpv6Wildcard                                **
**                                                                            **
**                        Function(s) invoked : Dem_SetEventStatus,           **
**                          SoAd_GetRemoteAddr, SoAd_SetRemoteAddr,           **
**                          Dem_ReportErrorStatus                             **
**                                                                            **
** Design ID              : SD_SDD_0236                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RxGetRemoteAddr(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_OptionsDataType * LpRxOptionsData,
    uint8 LucNoOfOptions,
    boolean LblUnicast,
    TcpIp_SockAddrType * LpRemoteAddr)
{
  boolean LblMalformedOption;
  Std_ReturnType LddReturnValue;
  SoAd_SoConIdType LddSoConId;

  TcpIp_SockAddrType *LpRemoteAddrIp;

  /* SWS_SD_00482  */

  LddSoConId = LpInstanceStatic->ddRxMulticastSoConId;
  if (LblUnicast)
  {
    LddSoConId = LpInstanceStatic->ddRxUnicastSoConId;
  }

  LpRemoteAddrIp = LpRemoteAddr;
  LblMalformedOption = (boolean)SD_FALSE;

  if ((LucNoOfOptions >= SD_ONE) &&
      (LpRxOptionsData->enTypeOfOption == SD_IPV4_SD_ENDPOINT_OPTION) &&
      (LpInstanceStatic->blDomainIpv4))
  {
    Sd_Ipv4LoadData(LpRxOptionsData, LpRemoteAddrIp);

    (void)SoAd_SetRemoteAddr(LddSoConId, &Sd_GddIpv4Wildcard);
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((LucNoOfOptions >= SD_ONE) &&
           (LpRxOptionsData->enTypeOfOption == SD_IPV6_SD_ENDPOINT_OPTION) &&
           (LpInstanceStatic->blDomainIpv4))
  {
    LblMalformedOption = (boolean)SD_TRUE;
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
  the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (LpInstanceStatic->blDomainIpv4)
  {
    LpRemoteAddr->domain = TCPIP_AF_INET;

    (void)SoAd_GetRemoteAddr(LddSoConId, LpRemoteAddr);

    (void)SoAd_ReleaseRemoteAddr(LddSoConId);
  }
#if (STD_ON == SD_IPV6_ENABLED)
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((LucNoOfOptions >= SD_ONE) &&
           (LpRxOptionsData->enTypeOfOption == SD_IPV6_SD_ENDPOINT_OPTION) &&
           (!LpInstanceStatic->blDomainIpv4))
  {
    Sd_Ipv6LoadData(LpRxOptionsData, LpRemoteAddrIp);

    (void)SoAd_ReleaseRemoteAddr(LddSoConId);
  }
  /* SWS_SD_00673 */
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((LucNoOfOptions >= SD_ONE) &&
           (LpRxOptionsData->enTypeOfOption == SD_IPV4_SD_ENDPOINT_OPTION) &&
           (!LpInstanceStatic->blDomainIpv4))
  {
    LblMalformedOption = (boolean)SD_TRUE;
  }
  else
  {
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
      LpInstanceStatic is False" */
    if (!LpInstanceStatic->blDomainIpv4)
    {
      LpRemoteAddr->domain = TCPIP_AF_INET6;

      (void)SoAd_GetRemoteAddr(LddSoConId, LpRemoteAddr);

      (void)SoAd_ReleaseRemoteAddr(LddSoConId);
    }
  }
#else
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
  else
  {
    /*Do Nothing */
  }
#endif
  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
   LblMalformedOption is SD_TRUE." */
  if (LblMalformedOption)
  {
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
  }

  LddReturnValue = E_OK;
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_MatchOtherServSingle                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function takes a single option, checks if it   **
**                          is a configuration option and if so, matches it   **
**                          against the otherserv string configured.          **
**                        It returns true if match is found else false.       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpCurrOption - The is the pointer to the option to  **
**                          be matched.                                       **
**                      : LusOtherServIndex - This is the offset of the       **
**                          Otherserv key within the above array              **
**                      : LusOtherServLength - This is the length of the      **
**                          OtherServ key that is configured for that service **
**                                                                            **
** InOut parameter      : LpOtherServMatch - This is the pointer to the       **
**                          otherserv match. If already matched, it does not  **
**                          check again.                                      **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID              : SD_SDD_0223                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_MatchOtherServSingle(
    const Sd_OptionsDataType * LpCurrOption,
    const uint8 LpOtherServStatic[],
    uint16 LusOtherServIndex,
    uint16 LusOtherServLength,
    boolean * LpOtherServMatch)
{
  uint8 LusDataIndex;
  boolean LblBreak;
  uint8 LucCount2;

  /* SWS_SD_00293c
     SWS_SD_00293d */
  /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (SD_CONFIGURATION_OPTION == LpCurrOption->enTypeOfOption)
  {

    if (!*LpOtherServMatch)
    {
      LusDataIndex = SD_ZERO;
      LblBreak = (boolean)SD_FALSE;
      *LpOtherServMatch = (boolean)SD_TRUE;
      for (LucCount2 = SD_ZERO; (LucCount2 < LusOtherServLength) &&
                                (!LblBreak);
           LucCount2++)
      {
        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
            made sure that they are within their range by having necessary boundary
            checks in order to prevent them from being out of bounds." */
        /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
        if (LpCurrOption->unOptionsData.aaOtherServ[LusDataIndex] !=
            LpOtherServStatic[LusOtherServIndex + LusDataIndex])
        {
          *LpOtherServMatch = (boolean)SD_FALSE;
          LblBreak = (boolean)SD_TRUE;
        }

        LusDataIndex = LusDataIndex + SD_ONE;
      }
      if (!LblBreak)
      {
        /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being out of bounds." */
        if (LpCurrOption->unOptionsData.aaOtherServ[LusDataIndex] != SD_ZERO)
        {
          *LpOtherServMatch = (boolean)SD_FALSE;
        }
        else
        {
          *LpOtherServMatch = (boolean)SD_TRUE;
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_MatchOtherServ                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called if the serviceID configured **
**                        is 0xFFFE. It checks for a match of the otherserv   **
**                        string received vs the otherserv string configured  **
**                        It returns true if match is found else false.       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpOtherServStatic - This is the pointer to the      **
**                          configuration option for that service             **
**                      : LusOtherServIndex - This is the offset of the       **
**                          Otherserv key within the above array              **
**                      : LusOtherServLength - This is the length of the      **
**                          OtherServ key that is configured for that service **
**                      : LpEntry - This is the pointer to the entry          **
**                      : LpOptionsData - This is the pointer to the first    **
**                          location of the options array                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : boolean - SD_TRUE - if otherserv is matched         **
**                         SD_FALSE - if otherserv is not matched             **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_MatchOtherServSingle       **
**                                                                            **
** Design ID              : SD_SDD_0222                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchOtherServ(
    const uint8 LpOtherServStatic[],
    uint16 LusOtherServIndex,
    uint16 LusOtherServLength,
    const Sd_EntryType * LpEntry,
    const Sd_OptionsDataType * LpOptionsData)
{
  boolean LblOtherServMatch;
  uint8 LucIndex1;
  uint8 LucNoOfOptions1;
  uint8 LucIndex2;
  uint8 LucNoOfOptions2;
  uint8 LucCount;
  const Sd_OptionsDataType *LpCurrOption;

  if (SD_ZERO == LusOtherServLength)
  {
    LblOtherServMatch = (boolean)SD_FALSE;
  }
  else
  {
    LblOtherServMatch = (boolean)SD_FALSE;

    if ((SD_FIND_SERVICE_ENTRY == LpEntry->enTypeOfEntry) ||
        (SD_OFFER_SERVICE_ENTRY == LpEntry->enTypeOfEntry) ||
        (SD_STOP_OFFER_SERVICE_ENTRY == LpEntry->enTypeOfEntry))
    {

      LucIndex1 = LpEntry->unEntryData.stEntry1.ucIndex1;
      LucNoOfOptions1 = LpEntry->unEntryData.stEntry1.ucNoOfOptions1;
      LucIndex2 = LpEntry->unEntryData.stEntry1.ucIndex2;
      LucNoOfOptions2 = LpEntry->unEntryData.stEntry1.ucNoOfOptions2;
    }
    else
    {

      LucIndex1 = LpEntry->unEntryData.stEntry2.ucIndex1;
      LucNoOfOptions1 = LpEntry->unEntryData.stEntry2.ucNoOfOptions1;
      LucIndex2 = LpEntry->unEntryData.stEntry2.ucIndex2;
      LucNoOfOptions2 = LpEntry->unEntryData.stEntry2.ucNoOfOptions2;
    }

    for (LucCount = LucIndex1; LucCount < (LucIndex1 + LucNoOfOptions1);
         LucCount++)
    {
      LpCurrOption = &LpOptionsData[LucCount];

      Sd_MatchOtherServSingle(LpCurrOption, LpOtherServStatic,
                              LusOtherServIndex, LusOtherServLength, &LblOtherServMatch);
    }

    for (LucCount = LucIndex2; LucCount < (LucIndex2 + LucNoOfOptions2);
         LucCount++)
    {
      LpCurrOption = &LpOptionsData[LucCount];

      Sd_MatchOtherServSingle(LpCurrOption, LpOtherServStatic,
                              LusOtherServIndex, LusOtherServLength, &LblOtherServMatch);
    }
  }
  return (LblOtherServMatch);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_MatchService                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks for a match in service.        **
**                        If the Service ID received and configured is 0xFFFE **
**                          it calls the Sd_MatchOtherServ function to check  **
**                          the match for otherserv.                          **
**                        Else, it returns true if the service ID's are equal **
**                        and false if they are not  equal.                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LusServiceIdRecd - The service ID received in the   **
**                         input frame.                                       **
**                      : LusServiceIdStatic - The Service ID configured for  **
**                         that service.                                      **
**                      : LpOtherServStatic - This is the pointer to the      **
**                          first byte of the OtherServ key that is           **
**                          configured for that service                       **
**                      : LusOtherServLength - This is the length of the      **
**                          OtherServ key that is configured for that service **
**                      : LpEntry - This is the pointer to the entry          **
**                      : LpOptionsData - This is the pointer to the first    **
**                          location of the options array                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : boolean - SD_TRUE - service is matched              **
**                          SD_FALSE - service is not matched                 **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_MatchOtherServ             **
**                                                                            **
** Design ID              : SD_SDD_0224                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchService(
    uint16 LusServiceIdRecd,
    uint16 LusServiceIdStatic,
    const uint8 * LpOtherServStatic,
    uint16 LusOtherServIndex,
    uint16 LusOtherServLength,
    const Sd_EntryType * LpEntry,
    const Sd_OptionsDataType * LpOptionsData)
{
  boolean LblServiceMatch;

  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be false when
  the LusServiceIdRecd ,LusServiceIdStatic  is of
                      SD_SERVICE_ID_OTHERSERV ,SD_SERVICE_ID_OTHERSERV Type .*/
  /*LogicAnalyser WRN04: Manually Verified*/
  if ((SD_SERVICE_ID_OTHERSERV == LusServiceIdRecd) &&
      (SD_SERVICE_ID_OTHERSERV == LusServiceIdStatic))
  {

    LblServiceMatch = Sd_MatchOtherServ(LpOtherServStatic, LusOtherServIndex,
                                        LusOtherServLength, LpEntry, LpOptionsData);
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (LusServiceIdStatic == LusServiceIdRecd)
  {
    LblServiceMatch = (boolean)SD_TRUE;
  }
  else
  {
    LblServiceMatch = (boolean)SD_FALSE;
  }
  return (LblServiceMatch);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_FindRecd                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when find entry is received **
**                      : at the server                                       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Instance structure    **
**                      : LpEntryData - Base pointer of array of entries      **
**                      : LpRemoteAddr - Remote Address of this frame         **
**                      : LpRxOtherserv - The Otherserv string, for matching  **
**                           the service ID.                                  **
**                           SD_NULL if absent.                               **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic     **
**                          Sd_GaaServerService                               **
**                                                                            **
**                        Function(s) invoked : Sd_MatchService,              **
**                          Sd_Rand, Sd_SendOffer                             **
**                                                                            **
** Design ID              : SD_SDD_0219,SD_SDD_0334                           **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_FindRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_OptionsDataType * LpOptionsData)
{
  Std_ReturnType LddReturnValue;
  uint16 LusBaseIndex;
  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint32 LulMinorVersion;

  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Sd_ServerServiceType const *LpServerService;
  Sd_ServerTimerStaticType const *LpServerTimer;

  boolean LblServiceMatch;
  uint32 LulDelay;
  uint16 LusCount;

  LddReturnValue = E_NOT_OK;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
  LusServiceId = (LpEntryData->unEntryData).stEntry1.usServiceId;
  LusInstanceId = (LpEntryData->unEntryData).stEntry1.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry1.ucMajorVersion;
  LulMinorVersion = (LpEntryData->unEntryData).stEntry1.ulMinorVersion;
  LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;

  /*SWS_SD_00486a
    SWS_SD_00332a
    SWS_SD_00332b */
  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                            LpInstanceStatic->usNoOfServerServices);
       LusCount++)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];
#else
    LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount);
#endif
    if (SD_SERVICE_ID_ALL_MATCH == LusServiceId)
    {
      LblServiceMatch = (boolean)SD_TRUE;
    }
    else
    {

      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      LblServiceMatch = Sd_MatchService(
          LusServiceId, LpServerServiceStatic->usServiceId,
          LpServerServiceStatic->pConfigOption,
          LpServerServiceStatic->usOtherServKeyIndex,
          LpServerServiceStatic->usOtherServKeyLength,
          LpEntryData, LpOptionsData);
    }

    if (LblServiceMatch)
    {

      if ((SD_INSTANCE_ID_ALL_MATCH == LusInstanceId) ||

          /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
            made sure that they are within their range by having necessary boundary
            checks in order to prevent them from being illegally dereferenced." */
          (LusInstanceId == LpServerServiceStatic->usInstanceId))

      {

        if ((SD_MAJOR_VERSION_ALL_MATCH == LucMajorVersion) ||

            /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
            (LucMajorVersion == LpServerServiceStatic->ucMajorVersion))

        {

          if (((uint32)SD_MINOR_VERSION_ALL_MATCH == LulMinorVersion) ||

              /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
              (LulMinorVersion == LpServerServiceStatic->ulMinorVersion))

          {

            LddReturnValue = E_OK;
            LpServerService = &Sd_GaaServerService[LusCount];
            /* SWS_SD_00319
         SWS_SD_00343a*/
            /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
            if ((SD_SERVER_REPETITION == LpServerService->enServerPhase) ||
                (SD_SERVER_MAIN == LpServerService->enServerPhase))
            {

              LpServerTimer = LpServerServiceStatic->pServerTimer;
              LulDelay = Sd_Rand(
                  (uint32)LpServerTimer->ulRequestResponseMinDelay,
                  (uint32)LpServerTimer->ulRequestResponseMaxDelay);

              Sd_SendOffer(LpServerServiceStatic, LpRemoteAddr,
                           LulDelay, (boolean)SD_TRUE);
            }
          }
        }
      }
    }
  }

  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_SubscribeRecdActions                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions when the         **
**                         subscribe entry is received in MAIN and            **
**                         REPETITION phases                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - pointer to Instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to static Server    **
**                          structure                                         **
**                      : LpEvHandler - Pointer to Event Handler structure    **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                          structure                                         **
**                      : LpRemoteAddr - Pointer to the remote address of the **
**                          input frame                                       **
**                      : LpEntryData - Pointer to the entry received         **
**                      : LpOptionsData - Pointer to the first option         **
**                          received                                          **
**                      : LucNoOfOptions - The number of options received     **
**                          in the input frame                                **
**                      : LucCounter - The Counter valus received in the      **
**                          subscribe entry                                   **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandlerSubGrp         **
**                                                                            **
**                        Function(s) invoked : Dem_SetEventStatus,           **
**                          BswM_Sd_EventHandlerCurrentState,                 **
**                          Sd_GetIpAddrFromOptions,                          **
**                          Sd_CheckSubnet, Sd_GetEvHandlerSubGrpIndex,       **
**                          Sd_AddClientToFanout, Sd_SendSubscribeAck,        **
**                          Dem_ReportErrorStatus                             **
**                                                                            **
** Design ID              : SD_SDD_0246,SD_SDD_0015                           **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_SubscribeRecdActions(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    uint8 LucCounter,
    uint8 LucReturnCode_ACL)
{
  Std_ReturnType LddReturnValue;

  TcpIp_SockAddrType LstIpAddrTcp;
  TcpIp_SockAddrType LstIpAddrUdp;
  uint8 LucReturnCode;
  Std_ReturnType LddSubnetRet;
  uint8 LucSubGrpReturnCode;
  Sd_ServicesType LddEvHandlerSubGrpIndex;
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp;

  /* SWS_SD_00333
     SWS_SD_00333b
     SWS_SD_00333c
   SWS_SD_00333d
   SWS_SD_00344
   SWS_SD_00334b
     SWS_SD_00334c*/

  LddReturnValue = E_OK;

  /* SWS_SD_00797: Check ACL policy for incoming subscribe request */
#if (STD_ON == SD_ENABLE_ACL_POLICY_CHECK)
  if (SD_TRUE == Sd_GaaAclPolicyFlag)
  {
    /* LucReturnCode_ACL encoding:
     * SD_ZERO  = No authorized endpoint found (ACL check failed)
     * SD_ONE   = UDP endpoint authorized
     * SD_TWO   = TCP endpoint authorized
     * SD_THREE = Both TCP and UDP authorized */
    if (SD_ZERO == LucReturnCode_ACL)
    {
      /* Remote subscriber not in AllowedConsumers list - Reject */
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
      (void)IdsM_SetSecurityEvent(SD_SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION);
#endif
      LddReturnValue = E_NOT_OK;
      return LddReturnValue;
    }
  }
#endif

  LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[SD_ZERO];
  LucReturnCode = Sd_GetIpAddrFromOptions(LpEntryData, LpOptionsData,
                                          LucTotalNoOfOptions, &LstIpAddrTcp, &LstIpAddrUdp);

  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     LddSubnetRet is not SD_OPTIONS_MALFORMED_MASK." */
  if (SD_OPTIONS_MALFORMED_MASK == (LucReturnCode & SD_OPTIONS_MALFORMED_MASK))
  {
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    /* SWS_SD_00688 */
    LddSubnetRet = Sd_CheckSubnet(LpInstance, LpInstanceStatic,
                                  &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode);
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    LddSubnetRet is not E_OK." */
    if (E_OK != LddSubnetRet)
    {
      SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
        LpServerServiceStatic is not SD_NULL_PTR." */

      /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pTcpSoConGrp is not equal to SD_NULL_PTR. */
      if ((LucReturnCode == SD_ONE) || (LucReturnCode == SD_THREE))
      {
        if ((SD_NULL_PTR != LpServerServiceStatic->pTcpSoConGrp) &&
            (SD_TCP_OPTIONS_MASK != (LucReturnCode & SD_TCP_OPTIONS_MASK)))
        {
          LddReturnValue = E_NOT_OK;
          SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
        }
      }

      /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
        LpServerServiceStatic is not SD_NULL_PTR." */

      /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
      pUdpSoConGrp is not equal to SD_NULL_PTR. */
      if ((LucReturnCode == SD_TWO) || (LucReturnCode == SD_THREE))
      {
        if ((SD_NULL_PTR != LpServerServiceStatic->pUdpSoConGrp) &&
            (SD_UDP_OPTIONS_MASK != (LucReturnCode & SD_UDP_OPTIONS_MASK)))
        {
          LddReturnValue = E_NOT_OK;
          SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
        }
      }
      if (LucReturnCode == SD_ZERO)
      {
        LddReturnValue = E_NOT_OK;
        SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
      }
    }
  }

  if (E_OK == LddReturnValue)
  {

    LucSubGrpReturnCode = Sd_GetEvHandlerSubGrpIndex(LpEvHandlerStatic,
                                                     LpRemoteAddr, LucCounter, &LddEvHandlerSubGrpIndex);

    if (SD_NOT_MATCHED_AND_NOT_FREE == LucSubGrpReturnCode)
    {

      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_NOT_MATCHED_AND_FREE == LucSubGrpReturnCode)
    {

      LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LddEvHandlerSubGrpIndex];
      LddReturnValue = Sd_AddClientToFanout(LpEvHandler, LpEvHandlerStatic,
                                            LpEvHandlerSubGrp, &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode, LucReturnCode_ACL, 
                                            LpEntryData, LpRemoteAddr);
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (SD_MATCHED_AND_EXISTING == LucSubGrpReturnCode)
    {

      LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LddEvHandlerSubGrpIndex];
      LddReturnValue = Sd_AddClientToFanout(LpEvHandler, LpEvHandlerStatic,
                                            LpEvHandlerSubGrp, &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode, LucReturnCode_ACL,
                                            LpEntryData, LpRemoteAddr);
    }
    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
      LddReturnValue is not E_OK." */
    else
    {
      LddReturnValue = E_NOT_OK;
    }
  }

  if (E_OK == LddReturnValue)
  {

    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
    if (LpEvHandler->enEvHandlerCurrState != SD_EVENT_HANDLER_REQUESTED)
    {
      LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_REQUESTED;
      /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being out of bounds." */
      Sd_GaaBswMEvNotifiFlag[LpEvHandlerStatic->usHandleId] = (boolean)SD_TRUE;
    }

    LpEvHandlerSubGrp->ulEvSubGrpTtlCount =
        ((LpEntryData->unEntryData).stEntry2.ulTtlsec) * (uint32)SD_SEC_TO_COUNT;
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SubscribeRecd                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the subscribe entry is **
**                      : received at the server                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Instance structure    **
**                      : LpEntryData - Base pointer of array of entries      **
**                      : LpRemoteAddr - Remote Address of this frame         **
**                      : LpOptionsData - Base pointer of the array of options**
**                      : LucTotalNoOfOptions - The number of options for     **
**                          this SD frame                                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic,    **
**                          Sd_GaaServerService, Sd_GaaEvHandlerStatic        **
**                          Sd_GaaEvHandler                                   **
**                                                                            **
**                        Function(s) invoked : Sd_MatchService,              **
**                          Sd_SubscribeRecdActions, Sd_SendSubscribeNack,    **
**                                                                            **
** Design ID              : SD_SDD_0245                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
Std_ReturnType Sd_SubscribeRecd(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    uint8 LucReturnCode)
#else
Std_ReturnType Sd_SubscribeRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr)

#endif

{
  Std_ReturnType LddReturnValue;
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint8 LucCounter;
  uint16 LusEventGroupId;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint16 LusCount2;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Sd_ServerServiceType const *LpServerService;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  Sd_EvHandlerType *LpEvHandler;
  uint16 LusBaseEventIndex;
  boolean LblServiceMatch;
#endif

  LddReturnValue = E_NOT_OK;

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  LusServiceId = (LpEntryData->unEntryData).stEntry2.usServiceId;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
  LusInstanceId = (LpEntryData->unEntryData).stEntry2.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry2.ucMajorVersion;
  LucCounter = (LpEntryData->unEntryData).stEntry2.ucCounter;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusEventGroupId = (LpEntryData->unEntryData).stEntry2.usEventGroupId;
  LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                            (LpInstanceStatic->usNoOfServerServices));
       LusCount++)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];
#else
    LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount);
#endif
    /*SWS_SD_00430
    SWS_SD_00431
    SWS_SD_00430e*/

    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being illegally dereferenced." */
    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpServerServiceStatic->usServiceId, LpServerServiceStatic->pConfigOption,
                                      LpServerServiceStatic->usOtherServKeyIndex,
                                      LpServerServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);

    if (LblServiceMatch)
    {

      if (LusInstanceId == LpServerServiceStatic->usInstanceId)

      {

        if (LucMajorVersion == LpServerServiceStatic->ucMajorVersion)

        {
          LpServerService = &Sd_GaaServerService[LusCount];

          LusBaseEventIndex = LpServerServiceStatic->usBaseEvHandlerIndex;

          for (LusCount2 = LusBaseEventIndex; LusCount2 < (LusBaseEventIndex +
                                                           LpServerServiceStatic->usNoOfEvHandlers);
               LusCount2++)

          {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
            LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount2];
#else
            LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount2);
#endif
            /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
            if ((SD_EVENT_GROUP_ID_ALL_MATCH == LusEventGroupId) ||
                (LusEventGroupId == LpEvHandlerStatic->usEventGroupId))
            {

              LpEvHandler = &Sd_GaaEvHandler[LusCount2];
              /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
              if ((LpServerService->enServerPhase == SD_SERVER_DOWN) ||
                  (LpServerService->enServerPhase == SD_SERVER_INITIAL_WAIT))
              {
              }
              else
              /*SWS_SD_00698a
            SWS_SD_00430f */
              {

                LddReturnValue = Sd_SubscribeRecdActions(LpInstance,
                                                         LpInstanceStatic, LpServerServiceStatic, LpEvHandler,
                                                         LpEvHandlerStatic, LpRemoteAddr, LpEntryData, LpOptionsData,
                                                         LucTotalNoOfOptions, LucCounter, LucReturnCode);
              }
            }
          }
        }
      }
    }
  }
  /* SWS_SD_00430b
     SWS_SD_00430c
   SWS_SD_00430d
   SWS_SD_00759
   SWS_SD_00760b , SRS 2718 */
  if (E_OK != LddReturnValue)
  {
    Sd_SendSubscribeNack(LpInstanceStatic, LpEntryData, LpRemoteAddr, SD_ZERO);

    SD_UNUSED(LpOptionsData);
    SD_UNUSED(LucTotalNoOfOptions);
    SD_UNUSED(LpInstance);
  }
#else

  Sd_SendSubscribeNack(LpInstanceStatic, LpEntryData, LpRemoteAddr, SD_ZERO);

#endif
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
/*******************************************************************************
** Function Name        : Sd_StopSubscribeRecd                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the Stop Subscribe     **
**                      :   entry is received on the server side              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Instance structure    **
**                      : LpEntryData - Base pointer of array of entries      **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Preconditions        : Sd_Init has been called                             **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic,    **
**                          Sd_GaaServerService, Sd_GaaEvHandlerStatic        **
**                          Sd_GaaEvHandler, Sd_GaaEvHandlerSubGrp            **
**                                                                            **
**                        Function(s) invoked : Sd_MatchService,              **
**                          Sd_GetEvHandlerSubGrpIndex,                       **
**                          Sd_RemoveClientFromFanout,                        **
**                          BswM_Sd_EventHandlerCurrentState                  **
**                                                                            **
** Design ID              : SD_SDD_0240                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_StopSubscribeRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const Sd_OptionsDataType * LpOptionsData)
{
  Std_ReturnType LddReturnValue;

  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint8 LucCounter;
  uint16 LusEventGroupId;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint16 LusCount2;

  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Sd_ServerServiceType const *LpServerService;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  Sd_EvHandlerType *LpEvHandler;
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp;

  uint16 LusBaseEventIndex;
  Sd_ServicesType LddEvHandlerSubGrpIndex;
  uint8 LucSubGrpReturnCode;
  boolean LblServiceMatch;

  LddReturnValue = E_NOT_OK;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
  LusServiceId = (LpEntryData->unEntryData).stEntry2.usServiceId;
  LusInstanceId = (LpEntryData->unEntryData).stEntry2.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry2.ucMajorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LucCounter = (LpEntryData->unEntryData).stEntry2.ucCounter;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusEventGroupId = (LpEntryData->unEntryData).stEntry2.usEventGroupId;
  LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                            LpInstanceStatic->usNoOfServerServices);
       LusCount++)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];
#else
    LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount);
#endif
    /*SWS_SD_00427 ,SWS_SD_00694*/
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpServerServiceStatic->usServiceId, LpServerServiceStatic->pConfigOption,
                                      LpServerServiceStatic->usOtherServKeyIndex,
                                      LpServerServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);

    /* SWS_SD_00490 */

    if ((LblServiceMatch) &&
        (LusInstanceId == LpServerServiceStatic->usInstanceId) &&
        (LucMajorVersion == LpServerServiceStatic->ucMajorVersion))

    {
      LpServerService = &Sd_GaaServerService[LusCount];

      LusBaseEventIndex = LpServerServiceStatic->usBaseEvHandlerIndex;

      for (LusCount2 = LusBaseEventIndex; LusCount2 < (LusBaseEventIndex +
                                                       LpServerServiceStatic->usNoOfEvHandlers);
           LusCount2++)

      {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount2];
#else
        LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount2);
#endif
        /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orangeflagare
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
        if ((SD_EVENT_GROUP_ID_ALL_MATCH == LusEventGroupId) ||
            (LusEventGroupId == LpEvHandlerStatic->usEventGroupId))
        {

          LpEvHandler = &Sd_GaaEvHandler[LusCount2];
          LddReturnValue = E_OK;
          /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orangeflagare
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being illegally dereferenced." */
          if ((LpServerService->enServerPhase == SD_SERVER_DOWN) ||
              (LpServerService->enServerPhase == SD_SERVER_INITIAL_WAIT))
          {
          }
          else
          {

            LucSubGrpReturnCode = Sd_GetEvHandlerSubGrpIndex(LpEvHandlerStatic,
                                                             LpRemoteAddr, LucCounter, &LddEvHandlerSubGrpIndex);
            if (SD_MATCHED_AND_EXISTING == LucSubGrpReturnCode)
            {

              LpEvHandlerSubGrp =
                  &Sd_GaaEvHandlerSubGrp[LddEvHandlerSubGrpIndex];

              LpEvHandlerSubGrp->ulEvSubGrpTtlCount = SD_ZERO;
              Sd_RemoveClientFromFanout(LpEvHandler, LpEvHandlerStatic,
                                        LpEvHandlerSubGrp);
              /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orangeflagare
                made sure that they are within their range by having necessary boundary
                checks in order to prevent them from being illegally dereferenced." */
              if ((SD_ZERO == LpEvHandler->ucNoOfSubGrpsTcp) &&
                  (SD_ZERO == LpEvHandler->ucNoOfSubGrpsUdp))
              {
                LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;
                BswM_Sd_EventHandlerCurrentState(LpEvHandlerStatic->usHandleId,
                                                 LpEvHandler->enEvHandlerCurrState);
              }
            }
            else
            {
            }
          }
        }
      }
    }
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_OfferRecdCheckOptions                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks whether the TCP options is     **
**                          received if TCP option is configured and          **
**                          similarly for UDP option.                         **
**                        If not received a DEM error of malformed messsage   **
**                          is generated                                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                          structure                                         **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Options are OK.             **
**                         E_NOT_OK - Some error as per description above.    **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                                                                            **
**                        Function(s) invoked : Dem_SetEventStatus            **
**                        Dem_ReportErrorStatus                               **
** Design ID              : SD_SDD_0228                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_OfferRecdCheckOptions(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const uint8 LucOptionsCode)
{
  Std_ReturnType LddReturnValue;

  LddReturnValue = E_OK;

  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
     LpClientServiceStatic is not equal to SD_NULL_PTR */

  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
   pTcpSoConGrp is not equal to SD_NULL_PTR. */
  if ((SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp) &&
      (SD_TCP_OPTIONS_MASK != (LucOptionsCode & SD_TCP_OPTIONS_MASK)))

  {
    LddReturnValue = E_NOT_OK;
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
   LpClientServiceStatic is not equal to SD_NULL_PTR */

  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
   pUdpSoConGrp is not equal to SD_NULL_PTR. */
  if ((SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp) &&
      (SD_UDP_OPTIONS_MASK != (LucOptionsCode & SD_UDP_OPTIONS_MASK)))

  {
    LddReturnValue = E_NOT_OK;
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_OfferRecdDown                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called if Offer is matched in the  **
**                          DOWN state.                                       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client structure       **
**                      : LpClientServiceStatic - Pointer to static client    **
**                          structure                                         **
**                      : LpIpAddrTcp - Pointer to the addr of TCP option     **
**                      : LpIpAddrUdp - Pointer to the addr of UDP option     **
**                      : LulTtlSec - The TTL value received in the offer     **
**                          entry                                             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                                                                            **
**                        Function(s) invoked : Sd_CopyIpAddr                 **
**                                                                            **
** Design ID              : SD_SDD_0229                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdDown(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint32 LulTtlSec)
{
  /* SWS_SD_00463
     SWS_SD_00463b
   SWS_SD_00463c */
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be False when
     pTcpSoConGrp is not equal to SD_NULL_PTR. */

  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be False when
     pTcpSoConGrp is equal to SD_NULL_PTR. */
  if (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp)

  {
    Sd_CopyIpAddr(&LpClientService->stOfferEndpointAddrTcp, LpIpAddrTcp);
  }

  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
   pUdpSoConGrp is not equal to SD_NULL_PTR. */
  if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)

  {
    Sd_CopyIpAddr(&LpClientService->stOfferEndpointAddrUdp, LpIpAddrUdp);
  }
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be false when
    the LulTtlSec is not equal to the value of LulTtlSec  .*/
  if (SD_TTL_SEC_MAX == LulTtlSec)
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = (uint8)SD_TRUE;
    LpClientService->ulOfferTtlCount = SD_TTL_COUNT_MAX;
  }
  else
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = (uint8)SD_FALSE;
    LpClientService->ulOfferTtlCount = LulTtlSec * (uint32)SD_SEC_TO_COUNT;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_OfferRecdInitialWait                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called if Offer is matched in the  **
**                          INITIAL WAIT phase.                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client structure       **
**                      : LpClientServiceStatic - Pointer to static client    **
**                          structure                                         **
**                      : LpIpAddrTcp - Pointer to the addr of TCP option     **
**                      : LpIpAddrUdp - Pointer to the addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                          Sd_GetIpAddrFromOptions)                          **
**                      : LpRemoteAddr - Pointer to remote address of input   **
**                          frame                                             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrpStatic     **
**                          Sd_GaaConsumedEvGrp                               **
**                                                                            **
**                        Function(s) invoked : Sd_ClientSetUpTcpUdpConnection**
**                          Sd_ClientFanIn, Sd_SendSubscribe, Sd_Rand         **
**                          BswM_Sd_ClientServiceCurrentState,                **
**                                                                            **
** Design ID              : SD_SDD_0230                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdInitialWait(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint32 LulTtlSec,
    boolean LblUnicast,
    uint8 LucReturnCode_ACL)
{
  Std_ReturnType LddReturnValue;
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic;
  Sd_ConsumedEvGrpType * LpConsumedEvGrp;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint32 LulDelay;
#endif

  /* SWS_SD_00352
     SWS_SD_00604
   SWS_SD_00352g*/
  LpClientService->ulClientDelayCount = SD_ZERO;

  if (SD_TTL_SEC_MAX == LulTtlSec)
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = SD_TRUE;
    LpClientService->ulOfferTtlCount = SD_TTL_COUNT_MAX;
  }
  else
  {

    (LpClientService->stClientFlag).blOfferMaxTtl = SD_FALSE;
    LpClientService->ulOfferTtlCount = LulTtlSec * (uint32)SD_SEC_TO_COUNT;
  }

  LpClientService->enClientCurrState = SD_CLIENT_SERVICE_AVAILABLE;
  /* SWS_SD_00352c */

  BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                                    LpClientService->enClientCurrState);

  LddReturnValue = Sd_ClientSetUpTcpUdpConnection(LpClientService,
                                                  LpClientServiceStatic, LpIpAddrTcp, LpIpAddrUdp, LucOptionsCode, LucReturnCode_ACL);

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)

  if (E_OK == LddReturnValue)
  {

    LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                              LpClientServiceStatic->usNoOfConEventGrp);
         LusCount++)

    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
      LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif
      LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];

      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      if (SD_CONSUMED_EVENTGROUP_REQUESTED ==
          LpConsumedEvGrp->enConEvGrpSetState)
      {

        Sd_ClientFanIn(LpClientService, LpConsumedEvGrp, LpConsumedEvGrpStatic,
                       LucReturnCode_ACL);

        if (LblUnicast)
        {
          Sd_SendSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, SD_ZERO);
          (LpConsumedEvGrp->stConsumedEvGrpFlag).blUnicastOfferRecd = SD_TRUE;
        }
        else
        {
          /* SWS_SD_00491b */
          LulDelay = Sd_Rand((uint32)
                                 LpConsumedEvGrpStatic->pClientTimer->ulRequestResponseMinDelay,
                             (uint32)LpConsumedEvGrpStatic->pClientTimer->ulRequestResponseMaxDelay);

          Sd_SendSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, LulDelay);
          (LpConsumedEvGrp->stConsumedEvGrpFlag).blUnicastOfferRecd = SD_FALSE;
        }
        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeSent = SD_TRUE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeAckRecd = SD_FALSE;
      }
    }
  }
#endif

  LpClientService->enClientPhase = SD_CLIENT_MAIN;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_OfferRecdRepetition                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called if Offer is matched in the  **
**                          REPETITION phase.                                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client structure       **
**                      : LpClientServiceStatic - Pointer to static client    **
**                          structure                                         **
**                      : LpIpAddrTcp - Pointer to the addr of TCP option     **
**                      : LpIpAddrUdp - Pointer to the addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                          Sd_GetIpAddrFromOptions)                          **
**                      : LpRemoteAddr - Pointer to remote address of input   **
**                          frame                                             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrpStatic     **
**                          Sd_GaaConsumedEvGrp                               **
**                                                                            **
**                        Function(s) invoked : Sd_ClientFanIn,               **
**                          Sd_ClientSetUpTcpUdpConnection,                   **
**                          Sd_SendSubscribe,Sd_Rand,                         **
**                          BswM_Sd_ClientServiceCurrentState,                **
**                                                                            **
** Design ID              : SD_SDD_0232                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_OfferRecdRepetition(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    uint32 LulTtlSec,
    uint8 LucReturnCode_ACL)
{
  Std_ReturnType LddReturnValue;
  /* SWS_SD_00365
     SWS_SD_00604
   SWS_SD_00365a
   SWS_SD_00365c*/

  LpClientService->ulClientDelayCount = SD_ZERO;
  /*SWS_SD_00365b
    SWS_SD_00365d
  SWS_SD_00365e
  SWS_SD_00365f */
  if (SD_TTL_SEC_MAX == LulTtlSec)
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = SD_TRUE;
    LpClientService->ulOfferTtlCount = SD_TTL_COUNT_MAX;
  }
  else
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = SD_FALSE;
    LpClientService->ulOfferTtlCount = LulTtlSec * (uint32)SD_SEC_TO_COUNT;
  }

  if (SD_CLIENT_SERVICE_DOWN == LpClientService->enClientCurrState)
  {
    LpClientService->enClientCurrState = SD_CLIENT_SERVICE_AVAILABLE;

    BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                                      LpClientService->enClientCurrState);
  }

  LddReturnValue = Sd_ClientSetUpTcpUdpConnection(LpClientService,
                                                  LpClientServiceStatic, LpIpAddrTcp, LpIpAddrUdp, LucOptionsCode, LucReturnCode_ACL);

  if (E_OK == LddReturnValue)
  {
    LpClientService->enClientPhase = SD_CLIENT_MAIN;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_OfferRecdMain                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called if Offer is matched in the  **
**                          MAIN phase                                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client structure       **
**                      : LpClientServiceStatic - Pointer to static client    **
**                          structure                                         **
**                      : LpIpAddrTcp - Pointer to the addr of TCP option     **
**                      : LpIpAddrUdp - Pointer to the addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                          Sd_GetIpAddrFromOptions)                          **
**                      : LpRemoteAddr - Pointer to remote address of input   **
**                          frame                                             **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrpStatic,    **
**                          Sd_GaaConsumedEvGrp                               **
**                                                                            **
**                        Function(s) invoked : Sd_ClientFanIn,               **
**                          Sd_ClientSetUpTcpUdpConnection, Sd_Rand,          **
**                          Sd_SendStopSubscribe, Sd_SendSubscribe,           **
**                          BswM_Sd_ClientServiceCurrentState                 **
**                                                                            **
** Design ID              : SD_SDD_0231                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_OfferRecdMain(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint32 LulTtlSec,
    boolean LblUnicast,
    uint8 LucReturnCode_ACL)
{
  Std_ReturnType LddReturnValue;

  boolean LblSoConOnline = (boolean)SD_FALSE;

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
  Sd_ConsumedEvGrpType *LpConsumedEvGrp;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint32 LulDelay;
#if (SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE == STD_ON)
  Sd_ClientTimerStaticType const *Lpclientsubscriptiondelaytimer;
  uint32 Delay_Value;
  LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[SD_ZERO];
  LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[SD_ZERO];
#endif
#endif

  /* SWS_SD_00376 removed from SWS */
  /* SWS_SD_00721a, SD_SRS_2063, SDD_0231, SD_ETC_110 */
  if (SD_TTL_SEC_MAX == LulTtlSec)
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = SD_TRUE;
    LpClientService->ulOfferTtlCount = SD_TTL_COUNT_MAX;
  }
  else
  {
    (LpClientService->stClientFlag).blOfferMaxTtl = SD_FALSE;
    LpClientService->ulOfferTtlCount = LulTtlSec * (uint32)SD_SEC_TO_COUNT;
  }
  /* polyspace +7 RTE:UNR [Justified:Low]  LpClientService->enClientCurrState
    is false when enClientCurrState
  is when enClientCurrState is SD_CLIENT_SERVICE_AVAILABLE*/

/* SWS_SD_00721b */
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)

  LddReturnValue = Sd_ClientSetUpTcpUdpConnection(LpClientService,
                                                  LpClientServiceStatic, LpIpAddrTcp, LpIpAddrUdp, LucOptionsCode, LucReturnCode_ACL);

  LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;

  /* SWS_SD_00721d, SWS_SD_00721e */
  if ((SD_TRUE == ((LpClientService->stClientFlag).blOfferAvailable)) &&
      (SD_FALSE == (LpClientService->stClientFlag).blOfferTtlExpired))
  {
    LblSoConOnline = Sd_OfferNtExpire(LpClientService, LpClientServiceStatic,
                                      LblSoConOnline);
  }

  /*SWS_SD_00701*/
  /* SD_SRS_2068 */
  if ((E_OK == LddReturnValue) || (LblSoConOnline))
  {

    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                              LpClientServiceStatic->usNoOfConEventGrp);
         LusCount++)

    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
      LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif
      LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];

      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being illegally dereferenced." */
      if (SD_CONSUMED_EVENTGROUP_REQUESTED ==
          LpConsumedEvGrp->enConEvGrpSetState)
      {
        Sd_ClientFanIn(LpClientService, LpConsumedEvGrp, LpConsumedEvGrpStatic,
                       LucReturnCode_ACL);

        if (LblUnicast)
        {

          LulDelay = SD_ZERO;
        }
        else
        {
          /* SWS_SD_00491a */
          LulDelay = Sd_Rand((uint32)LpConsumedEvGrpStatic->pClientTimer->ulRequestResponseMinDelay,
                             (uint32)LpConsumedEvGrpStatic->pClientTimer->ulRequestResponseMaxDelay);
        }
        /* SWS_SD_00721f, SD_SRS_2714, SD_SDD_0231, SD_ETC_1245 ,
           SWS_SD_00721g, SD_SRS_2715, SD_SDD_0231, SD_ETC_1246  */
        if ((SD_FALSE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blUnicastOfferRecd) &&
            (SD_TRUE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeSent) &&
            (SD_FALSE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeAckRecd) &&
            (!LblUnicast))
        {
          Sd_SendStopSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, LulDelay);

          Sd_SendSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, LulDelay);
          /* Configure Timer*/
        }
        else
        {
          Sd_SendSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, LulDelay);
        }

        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeSent = SD_TRUE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeAckRecd = SD_FALSE;

        if (LblUnicast)
        {
          (LpConsumedEvGrp->stConsumedEvGrpFlag).blUnicastOfferRecd = SD_TRUE;
        }
        else
        {
          (LpConsumedEvGrp->stConsumedEvGrpFlag).blUnicastOfferRecd = SD_FALSE;
        }
      }
    }

    /* SWS_SD_00735b*/
    /* polyspace +7 RTE:UNR [Justified:Low]SD_SUBSCRIBE_EVENTGROUP_RETRY
       _ENABLE  is false when SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE
       is when STD_OFF is SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE*/
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
    /* polyspace +6 RTE:UNR [Justified:Low]  LpClientService->
       enClientCurrState is false when enClientCurrState
       is when enClientCurrState is SD_CLIENT_SERVICE_AVAILABLE*/
    Sd_GblSubscribeInQueue = (boolean)SD_TRUE;

    Delay_Value =
        (uint32)((uint32)((LpConsumedEvGrpStatic->pClientTimer)->ulSubscribeEventgroupRetryDelay) * ((uint32)(LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax));
    /*SWS_SD_00736a*/
    /*SWS_SD_00736b*/
    /* SWS_SD_00721h, SD_SRS_2716, SDD_0231, SD_ETC_1229 */
    if (Delay_Value <= (LulTtlSec * (uint32)SD_SEC_TO_MS))
    {
      /* SWS_SD_00735a*/
      /* polyspace +6 RTE:UNR [Justified:Low]  LpClientService->
      enClientCurrState is false when enClientCurrState
      is when enClientCurrState is SD_CLIENT_SERVICE_AVAILABLE*/
      if (SD_ZERO < (LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax)
      {
        if ((uint32)SD_ZERO == LpClientService->ulClientRetrySubDelayCount)
        {
          Lpclientsubscriptiondelaytimer = LpConsumedEvGrpStatic->pClientTimer;
          LpClientService->ulClientRetrySubDelayCount =
              Lpclientsubscriptiondelaytimer->ulSubscribeEventgroupRetryDelay;
        }
        LpConsumedEvGrp->ulConEvGrpRetryCount = SD_ONE;
      }
    }
#endif
  }
#endif
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_OfferRecd                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the Offer entry is     **
**                      : received.                                           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic- Pointer to Instance Static        **
**                      :     structure                                       **
**                      : LpEntryData - Pointer to Entry Data structure       **
**                      : LpOptionsData - Base pointer of the array of options**
**                      : LucTotalNoOfOptions - The number of options for     **
**                          this SD frame                                     **
**                      : LpRemoteAddr - Pointer to the remote addr that the  **
**                      :       message is received on                        **
**                      : LblUnicast - This flag is SD_TRUE if the message is **
**                      :    received via unicast, else false. It is required **
**                      :    to set the delay                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : StdReturnValue - E_OK - The entry has matched       **
**                               - E_NOT_OK - The entry has not matched       **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init should be called                            **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientServiceStatic,    **
**                          Sd_GaaClientService                               **
**                                                                            **
**                        Function(s) invoked : Dem_SetEventStatus,           **
**                          Sd_MatchService, Sd_GetIpAddrFromOptions,         **
**                          Sd_CheckSubnet, Sd_OfferRecdCheckOptions,         **
**                          Sd_CopyIpAddr, Sd_OfferRecdDown,                  **
**                          Sd_OfferRecdInitialWait, Sd_OfferRecdRepetition   **
**                          Sd_OfferRecdMain, Dem_ReportErrorStatus           **
**                                                                            **
** Design ID              : SD_SDD_0227                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_OfferRecd(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr,
    boolean LblUnicast,
    uint8 LucReturnCode_ACL)
{
  Std_ReturnType LddReturnValue;

  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint32 LulMinorVersion;
  uint32 LulTtlSec;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint8 LucReturnCode;
  Std_ReturnType LddSubnetRet;
  boolean LblServiceMatch;

  TcpIp_SockAddrType LstIpAddrTcp;
  TcpIp_SockAddrType LstIpAddrUdp;

  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  Sd_ClientServiceType *LpClientService;

  LddReturnValue = E_NOT_OK;

  /* SWS_SD_00797: Check ACL policy for incoming offer - do not subscribe to unauthorized provider */
#if (STD_ON == SD_ENABLE_ACL_POLICY_CHECK)
  if (SD_TRUE == Sd_GaaAclPolicyFlag)
  {
    if (SD_ZERO == LucReturnCode_ACL)
    {
      /* Remote provider not in AllowedProviders list - Do not send Subscribe */
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
      (void)IdsM_SetSecurityEvent(SD_SEV_SOME_IP_ACL_CHECK_FAILED_OFFER);
#endif
      return LddReturnValue;
    }
  }
#endif

  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
   made sure that they are initialized with proper Value " */
  LusServiceId = (LpEntryData->unEntryData).stEntry1.usServiceId;
  LusInstanceId = (LpEntryData->unEntryData).stEntry1.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry1.ucMajorVersion;
  LulMinorVersion = (LpEntryData->unEntryData).stEntry1.ulMinorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
  made sure that they are initialized with proper Value " */
  LulTtlSec = (LpEntryData->unEntryData).stEntry1.ulTtlsec;
  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;

  /* SWS_SD_00487a  */
  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                            LpInstanceStatic->usNoOfClientServices);
       LusCount++)
  {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount);
#endif

    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpClientServiceStatic->usServiceId, LpClientServiceStatic->pConfigOption,
                                      LpClientServiceStatic->usOtherServKeyIndex,
                                      LpClientServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);

    /* SWS_SD_00488
       SWS_SD_00489*/

    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
    if ((LblServiceMatch) &&
        (LusInstanceId == LpClientServiceStatic->usInstanceId) &&
        (LucMajorVersion == LpClientServiceStatic->ucMajorVersion) &&
        (((uint32)SD_MINOR_VERSION_ALL_MATCH ==
          LpClientServiceStatic->ulMinorVersion) ||
         (LulMinorVersion == LpClientServiceStatic->ulMinorVersion)) &&
        (LpClientServiceStatic->EndrivenBehaviour ==
         SD_EXACT_OR_ANY_MINOR_VERSION))

    {
      LpClientService = &Sd_GaaClientService[LusCount];
      LucReturnCode = Sd_GetIpAddrFromOptions(LpEntryData, LpOptionsData,
                                              LucTotalNoOfOptions, &LstIpAddrTcp, &LstIpAddrUdp);
      /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
      LucReturnCode is equal to SD_OPTIONS_MALFORMED_MASK */
      if ((LucReturnCode & SD_OPTIONS_MALFORMED_MASK) ==
          SD_OPTIONS_MALFORMED_MASK)
      {
        SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /*  SWS_SD_00688  */
        LddSubnetRet = Sd_CheckSubnet(LpInstance, LpInstanceStatic,
                                      &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode);
        /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
        LddSubnetRet is not equal to E_OK */
        if (E_OK != LddSubnetRet)
        {
          SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
          LddReturnValue = E_NOT_OK;
        }
        else
        {

          LddReturnValue = Sd_OfferRecdCheckOptions(LpInstanceStatic,
                                                    LpClientServiceStatic, LucReturnCode);
        }
      }
      /* SWS_SD_00352 */
      if (E_OK == LddReturnValue)
      {
        /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
        (LpClientService->stClientFlag).blOfferAvailable = SD_TRUE;
        Sd_CopyIpAddr(&LpClientService->stOfferRemoteAddr, LpRemoteAddr);

        if (SD_CLIENT_DOWN == LpClientService->enClientPhase)
        {

          Sd_OfferRecdDown(LpClientService, LpClientServiceStatic,
                           &LstIpAddrTcp, &LstIpAddrUdp, LulTtlSec);
        }
        /*LogicAnalyser WRN04: Manually Verified*/
        else if (SD_CLIENT_INITIAL_WAIT == LpClientService->enClientPhase)
        {

          Sd_OfferRecdInitialWait(LpClientService, LpClientServiceStatic,
                                  &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode, LpRemoteAddr,
                                  LulTtlSec, LblUnicast, LucReturnCode_ACL);
        }
        /*LogicAnalyser WRN04: Manually Verified*/
        else if ((SD_CLIENT_REPETITION == LpClientService->enClientPhase) &&
                 (SD_CLIENT_SERVICE_REQUESTED == LpClientService->enClientSetState))
        {

          Sd_OfferRecdRepetition(LpClientService, LpClientServiceStatic,
                                 &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode, LulTtlSec, LucReturnCode_ACL);
        }
        else
        {
          /*Do notthing*/
        }
        /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
           the client is in SD_CLIENT_MAIN phase */
        if (SD_CLIENT_MAIN == LpClientService->enClientPhase)
        {

          Sd_OfferRecdMain(LpClientService, LpClientServiceStatic,
                           &LstIpAddrTcp, &LstIpAddrUdp, LucReturnCode, LpRemoteAddr,
                           LulTtlSec, LblUnicast, LucReturnCode_ACL);
        }
      }
    }
  }

  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_MulticastMatchSoConGroup                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function loops over all the socket connection  **
**                          groups configured for the consumed event group    **
**                        It matches the local address of the group with the  **
**                          IP address received in the multicast option       **
**                        If Wildcard match is detected, it sets up the       **
**                          connection using the function                     **
**                          SoAd_RequestIpAddrAssignment                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpConsumedEvGrp - Pointer to Consumed Event Group   **
**                          structure                                         **
**                      : LpConsumedEvGrpStatic - Pointer to static Consumed  **
**                          Event Group structure                             **
**                      : LpIpAddrUdp - The IP address received in the        **
**                          Multicast endpoint option of the Subscribe Ack    **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSoConGrpIndex - Pointer to the index of the       **
**                          socket connection group that has been matched.    **
**                        Valid if return is E_OK.                            **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Match received, either      **
**                          wildcard or normal                                **
**                        E_NOT_OK - No match received                        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConGroupStatic,       **
**                          Sd_GaaMulticastSoConGrpIndex, Sd_GaaSoConId       **
**                          Sd_GaaSoConGroup                                  **
**                                                                            **
**                        Function(s) invoked : SoAd_GetLocalAddr,            **
**                          Sd_MatchIpAddr, Sd_MatchIpWildcard,               **
**                          Dem_SetEventStatus, Dem_ReportErrorStatus         **
**                          SoAd_RequestIpAddrAssignment                      **
**                                                                            **
** Design ID              : SD_SDD_0225                                       **
*******************************************************************************/
#if ((STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) && \
     (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_MulticastMatchSoConGroup(
    const Sd_InstanceStaticType * LpInstanceStatic,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    SoAd_SoConIdType * LpSoConGrpIndex)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  Sd_SoConGroupType *LpSoConGrp;
  Sd_SoConGroupStaticType const *LpSoConGrpStatic;
  SoAd_SoConIdType LddSoConIndex;
  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  uint16 LusMatchIndex = SD_ZERO;
  uint16 LusWildcardMatchIndex = SD_ZERO;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint8 LucNetmask = SD_ZERO;

  TcpIp_SockAddrType LddIpAddrLocal;
  TcpIp_SockAddrType LddDefaultRouter;

  /*  SWS_SD_00704
      SWS_SD_00704b  */

  /* SWS_SD_00377a , SD_SRS_825, SD_SDD_0225, SD_ETC_117 */
  LusBaseIndex = LpConsumedEvGrpStatic->ddBaseMulticastSoConGrpIndex;
  LblMatchRecd = (boolean)SD_FALSE;
  LblWildcardMatch = (boolean)SD_FALSE;

  for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex +
                                             LpConsumedEvGrpStatic->ddNoOfMulticastSoConGrp)) &&
                                (!LblMatchRecd);
       LusCount++)
  {
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag
          are made sure that they are within their range by having necessary
          boundary checks in order to prevent them from being out of bounds." */
    LpSoConGrpStatic =
        &Sd_GaaSoConGroupStatic[Sd_GaaMulticastSoConGrpIndex[LusCount]];
    /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be false when
      the LpInstanceStatic->blDomainIpv4 is set to False.*/
    if (!LpInstanceStatic->blDomainIpv4)
    {
      LddIpAddrLocal.domain = TCPIP_AF_INET;
      LddDefaultRouter.domain = TCPIP_AF_INET;
    }
    else
    {
      LddIpAddrLocal.domain = TCPIP_AF_INET6;
      LddDefaultRouter.domain = TCPIP_AF_INET6;
    }

    (void)SoAd_GetLocalAddr(
        Sd_GaaSoConId[LpSoConGrpStatic->usBaseSocketConIndex],
        &LddIpAddrLocal, &LucNetmask, &LddDefaultRouter);

    LblMatchRecd = Sd_MatchIpAddr(&LddIpAddrLocal, LpIpAddrUdp);
    LusMatchIndex = LusCount;
    /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
        LblWildcardMatch & LblMatchRecd is equal to SD_FALSE */
    if (!LblWildcardMatch)
    {
      LblWildcardMatch = Sd_MatchIpWildcard(&LddIpAddrLocal);
      LusWildcardMatchIndex = LusCount;
    }
  }

  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
   LblWildcardMatch & LblMatchRecd is equal to SD_FALSE */
  if ((!LblMatchRecd) && (!LblWildcardMatch))
  {
    SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
    LddReturnValue = E_NOT_OK;
  }
  /*LogicAnalyser WRN04: Manually Verified*/

  else if ((!LblMatchRecd) && (LblWildcardMatch))
  {
    LddSoConIndex = Sd_GaaMulticastSoConGrpIndex[LusWildcardMatchIndex];
    LpSoConGrp = &Sd_GaaSoConGroup[LddSoConIndex];
    LpSoConGrpStatic = &Sd_GaaSoConGroupStatic[LddSoConIndex];

    /*Design ID : SD_SDD_0080*/
    (void)SoAd_RequestIpAddrAssignment(
        Sd_GaaSoConId[LpSoConGrpStatic->usBaseSocketConIndex],
        (TcpIp_IpAddrAssignmentType)TCPIP_IPADDR_ASSIGNMENT_STATIC,
        LpIpAddrUdp, LucNetmask, &LddDefaultRouter);

    LpConsumedEvGrp->ddSoConGrpIndexMulticast = LddSoConIndex;

    LpSoConGrp->usNoOfSubConEvGrp = LpSoConGrp->usNoOfSubConEvGrp + SD_ONE;

    LpSoConGrp->blWildcardConEvGrp = (boolean)SD_TRUE;

    *LpSoConGrpIndex = LddSoConIndex;
    LddReturnValue = E_OK;
  }
  else
  {
    LddSoConIndex = Sd_GaaMulticastSoConGrpIndex[LusMatchIndex];
    LpSoConGrp = &Sd_GaaSoConGroup[LddSoConIndex];

    LpConsumedEvGrp->ddSoConGrpIndexMulticast = LddSoConIndex;

    LpSoConGrp->usNoOfSubConEvGrp = LpSoConGrp->usNoOfSubConEvGrp + SD_ONE;

    *LpSoConGrpIndex = LddSoConIndex;
    LddReturnValue = E_OK;
  }
  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_MulticastMatchSocket                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function matches the socket connection of the  **
**                          group identified previously.                      **
**                        It Checks the IP address received in the offer for  **
**                          a match against the remote address of the socket  **
**                          connection.                                       **
**                        It checks for wildcard match also. If a wildcard    **
**                          match is detected it sets up the connection by    **
**                          calling the function SoAd_SetUniqueRemoteAddr     **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpClientService - pointer to client structure       **
**                      : LpSoConGrpStatic - Pointer to socket connection     **
**                          static structure which is matched previously      **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSoConId - Pointer to socket connection Id which   **
**                          is matched                                        **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - match is found, wildcard or **
**                          normal                                            **
**                      : E_NOT_OK - No match                                 **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId                 **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard, SoAd_GetRemoteAddr,           **
**                          SoAd_SetRemoteAddr, Dem_SetEventStatus            **
**                          Dem_ReportErrorStatus                             **
** Design ID              : SD_SDD_0226                                       **
*******************************************************************************/
#if ((STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) && \
     (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_MulticastMatchSocket(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ClientServiceType * LpClientService,
    const Sd_SoConGroupStaticType * LpSoConGrpStatic,
    SoAd_SoConIdType * LpSoConId)
{
  Std_ReturnType LddReturnValue;

/* SD_SDD_0226, SD_SRS_826, SWS_SD_00377b, SD_ETC_1231, SD_ETC_1232 */
#if (SD_SET_REM_ADDR_OF_CLIENT_RX_MULTICAST_SO_CON == STD_ON)

  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  uint16 LusMatchIndex = SD_ZERO;
  uint16 LusWildcardMatchIndex = SD_ZERO;
  uint16 LusCount = SD_ZERO;
  uint16 LusBaseIndex = SD_ZERO;

  SoAd_SoConIdType LddAssignedSoConId;
  TcpIp_SockAddrType LstIpAddrRemote;
  TcpIp_SockAddrType LstOfferIpAddr;

  /* SWS_SD_00704 */
  LusBaseIndex = LpSoConGrpStatic->usBaseSocketConIndex;
  LblMatchRecd = (boolean)SD_FALSE;
  LblWildcardMatch = (boolean)SD_FALSE;
#else
  LddReturnValue = E_OK;
#endif

#if (SD_SET_REM_ADDR_OF_CLIENT_RX_MULTICAST_SO_CON == STD_ON)
  for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex +
                                             LpSoConGrpStatic->usNoOfSockets)) &&
                                (!LblMatchRecd);
       LusCount++)
  {
    /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     blDomainIpv4 is not equal to SD_TRUE. */
    if (LpInstanceStatic->blDomainIpv4)
    {
      LstIpAddrRemote.domain = TCPIP_AF_INET;
      LstOfferIpAddr.domain = TCPIP_AF_INET;
    }
    else
    {
      LstIpAddrRemote.domain = TCPIP_AF_INET6;
      LstOfferIpAddr.domain = TCPIP_AF_INET6;
    }

    (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddrRemote);
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
    if (LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
    {
      (void)SoAd_GetRemoteAddr(
          Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp],
          &LstOfferIpAddr);
    }
    LblMatchRecd = Sd_MatchIpAddr(&LstIpAddrRemote, &LstOfferIpAddr);
    LusMatchIndex = LusCount;
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
    LblWildcardMatch is equal to SD_FALSE */
    if (!LblWildcardMatch)
    {
      LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddrRemote);
      LusWildcardMatchIndex = LusCount;
    }
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
  LblMatchRecd & LblWildcardMatch is equal to SD_FALSE */
  if ((!LblMatchRecd) && (!LblWildcardMatch))
  {
    LddReturnValue = E_NOT_OK;
    SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((!LblMatchRecd) && (LblWildcardMatch))
  {
    LddReturnValue = E_OK;
    *LpSoConId = Sd_GaaSoConId[LusWildcardMatchIndex];
    (void)SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LusWildcardMatchIndex],
                                   &LstOfferIpAddr, &LddAssignedSoConId);
    if (LddAssignedSoConId == Sd_GaaSoConId[LusWildcardMatchIndex])
    {
      Sd_GaaSoCon[LusWildcardMatchIndex].stSoConFlag.blWildcardSocketClient = SD_TRUE;
      Sd_GaaSoCon[LusWildcardMatchIndex].usNoOfSubClients =
          Sd_GaaSoCon[LusWildcardMatchIndex].usNoOfSubClients + SD_ONE;
    }
  }
  else
  {
    LddReturnValue = E_OK;
    *LpSoConId = Sd_GaaSoConId[LusMatchIndex];
  }
#else
  if (LpClientService != SD_NULL_PTR)
  {
    LddReturnValue = Sd_MulticastMatchSocket_Rem_Addr_Off(LpInstanceStatic,
                                                          LpSoConGrpStatic, LpSoConId);
  }

#endif
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SubscribeAckRecdActions                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions on receiving a   **
**                          matched subscribe ack entry                       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client structure       **
**                      : LpConsumedEvGrp - Pointer to Consumed Event Group   **
**                          structure                                         **
**                      : LpConsumedEvGrpStatic - Pointer to static Consumed  **
**                          event group structure                             **
**                      : LpEntryData - Base pointer of array of entries      **
**                      : LpOptionsData - Base pointer of the array of options**
**                      : LucTotalNoOfOptions - The number of options for     **
**                          this SD frame                                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrpStatic     **
**                          Sd_GaaConsumedEvGrp                               **
**                                                                            **
**                        Function(s) invoked : Sd_ClientFanIn                **
**                          Sd_ClientSetUpTcpUdpConnection, Sd_Rand,          **
**                          Sd_MulticastMatchSoConGroup,                      **
**                           Sd_MulticastMatchSocket                          **
**                          Sd_SendStopSubscribe, Sd_SendSubscribe,           **
**                          BswM_Sd_ClientServiceCurrentState                 **
**                                                                            **
** Design ID              : SD_SDD_0242,SD_SDD_0336                           **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SubscribeAckRecdActions(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_ClientServiceType * LpClientService,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions)
{
  Std_ReturnType LddReturnValue;
  uint8 LucReturnCode;
  Std_ReturnType LddSubnetRet;

#if (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED)
  Sd_SoConGroupStaticType const *LpSoConGrpStatic;
  SoAd_SoConIdType LddSoConId;
  SoAd_SoConIdType LddSoConGrpIndex;
#endif

  TcpIp_SockAddrType LstIpAddrUdp;

  /* SWS_SD_00704
     SWS_SD_00695
   SWS_SD_00705 */
  LddReturnValue = E_OK;

  /*SWS_SD_00429
    SWS_SD_00429b */
  LucReturnCode = Sd_GetIpAddrFromMulticastOption(LpEntryData, LpOptionsData,
                                                  LucTotalNoOfOptions, &LstIpAddrUdp);

  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
   multicast shall reference an IPv4 Multicast Option and/or and IPv6 Multicast Option.
   Module Test Case Reference SD_ETC_398, SWS ID SWS_SD_00429" */
  if (SD_OPTIONS_MALFORMED_MASK == (LucReturnCode & SD_OPTIONS_MALFORMED_MASK))
  {
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
    LddReturnValue = E_NOT_OK;
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
  multicast shall reference an IPv4 Multicast Option and/or and IPv6 Multicast Option.
  Module Test Case Reference SD_ETC_398, SWS ID SWS_SD_00429b" */
  else if ((SD_ZERO != LpConsumedEvGrpStatic->ddNoOfMulticastSoConGrp) &&
           (SD_UDP_OPTIONS_MASK != (LucReturnCode & SD_UDP_OPTIONS_MASK)))
  {
    SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
    LddReturnValue = E_NOT_OK;
  }
  else
  {

    LddSubnetRet = Sd_CheckSubnet(LpInstance, LpInstanceStatic,
                                  SD_NULL_PTR, &LstIpAddrUdp, LucReturnCode);

    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
       LddSubnetRet is not equal to E_OK. */
    if (E_OK != LddSubnetRet)
    {
      SD_REPORT_DEM_MALFORMED(LpInstanceStatic);
      LddReturnValue = E_NOT_OK;
    }
  }

#if (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED)

  if ((SD_ZERO != LpConsumedEvGrpStatic->ddNoOfMulticastSoConGrp) &&
      (SD_UDP_OPTIONS_MASK == (LucReturnCode & SD_UDP_OPTIONS_MASK)) &&
      (E_OK == LddReturnValue))
  {
    /* SWS_SD_00377a  */
    LddReturnValue = Sd_MulticastMatchSoConGroup(LpInstanceStatic,
                                                 LpConsumedEvGrp, LpConsumedEvGrpStatic,
                                                 &LstIpAddrUdp, &LddSoConGrpIndex);

    /*  SWS_SD_00704  */
    if (E_OK == LddReturnValue)
    {
      LpSoConGrpStatic = &Sd_GaaSoConGroupStatic[LddSoConGrpIndex];
      /*SWS_SD_00377b, SWS_SD_00377c */
      LddReturnValue = Sd_MulticastMatchSocket(LpInstanceStatic,
                                               LpClientService, LpSoConGrpStatic, &LddSoConId);

      if (E_OK == LddReturnValue)
      {
        /* SWS_SD_00377d, SD_SDD_0242, SD_SRS_829, SD_ETC_1233
           SWS_SD_00377e, SD_SDD_0242, SD_SRS_2070, SD_ETC_123 */

        /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
        blMulticastActivationRoGrpIdPresent is not equal to SD_TRUE. */
        /* TODO : Previous check SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).
                 blUdpActivationRoGrpIdPresent) */
        if ((SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).blMulticastActivationRoGrpIdPresent) &&
            (SD_FALSE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blMulticastRoutingEnabled))
        {
          (void)SoAd_EnableSpecificRouting(
              LpConsumedEvGrpStatic->ddMulticastActivationRoGrpId,
              LddSoConId);
          (LpConsumedEvGrp->stConsumedEvGrpFlag).blMulticastRoutingEnabled = SD_TRUE;
          LpConsumedEvGrp->ddSoConIdMulticast = LddSoConId;
        }
      }
    }
  }

#endif

  /*  SWS_SD_00377f, SD_SDD_0242, SD_SRS_2071, SD_ETC_119
      SWS_SD_00377g, SD_SDD_0242, SD_SRS_2072, SD_ETC_120 */
  if (E_OK == LddReturnValue)
  {
    LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_AVAILABLE;
    BswM_Sd_ConsumedEventGroupCurrentState(LpConsumedEvGrpStatic->usHandleId,
                                           LpConsumedEvGrp->enConEvGrpCurrState);

    LpConsumedEvGrp->ulConEvGrpTtlCount =
        (LpEntryData->unEntryData).stEntry2.ulTtlsec *
        (uint32)SD_SEC_TO_COUNT;
  }
  /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.7*/
  /*PRQA S 3112 2 */
  SD_UNUSED(LpClientService);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SubscribeAckRecd                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the Subscribe Ack      **
**                      : entry is received.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Instance structure    **
**                      : LpEntryData - Base pointer of array of entries      **
**                      : LpOptionsData - Base pointer of the array of options**
**                      : LucTotalNoOfOptions - The number of options for     **
**                          this SD frame                                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientServiceStatic,    **
**                          Sd_GaaClientService, Sd_GaaConsumedEvGrpStatic,   **
**                          Sd_GaaConsumedEvGrp                               **
**                                                                            **
**                        Function(s) invoked : Sd_MatchService               **
**                          Sd_SubscribeAckRecdActions                        **
**                                                                            **
** Design ID              : SD_SDD_0241                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_SubscribeAckRecd(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions)
{
  Std_ReturnType LddReturnValue;
  uint16 LusBaseIndex;
  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint8 LucCounter;
  uint16 LusEventGroupId;
  boolean LblServiceMatch;
  boolean LblMatchRecd;
  uint16 LusCount;
  uint16 LusCount2;
  uint16 LusBaseIndex2;

  const Sd_ClientServiceStaticType * LpClientServiceStatic;
  const Sd_ClientServiceType * LpClientService;
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic;
  Sd_ConsumedEvGrpType * LpConsumedEvGrp;

  LddReturnValue = E_NOT_OK;
  LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[0];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[0];
#else
  LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + 0);
#endif
  LpClientService = &Sd_GaaClientService[0];

  LusServiceId = (LpEntryData->unEntryData).stEntry2.usServiceId;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
  LusInstanceId = (LpEntryData->unEntryData).stEntry2.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry2.ucMajorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
  LucCounter = (LpEntryData->unEntryData).stEntry2.ucCounter;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
  LusEventGroupId = (LpEntryData->unEntryData).stEntry2.usEventGroupId;
  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;
  LblMatchRecd = (boolean)SD_FALSE;
  /*  SWS_SD_00490
      SWS_SD_00304b
    SWS_SD_00693b  */
  for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex +
                                             LpInstanceStatic->usNoOfClientServices)) &&
                                (!LblMatchRecd);
       LusCount++)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount);
#endif
    LpClientService = &Sd_GaaClientService[LusCount];
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpClientServiceStatic->usServiceId, LpClientServiceStatic->pConfigOption,
                                      LpClientServiceStatic->usOtherServKeyIndex,
                                      LpClientServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);

    if ((LblServiceMatch) &&
        (LusInstanceId == LpClientServiceStatic->usInstanceId) &&
        (LucMajorVersion == LpClientServiceStatic->ucMajorVersion))

    {

      LusBaseIndex2 = LpClientServiceStatic->usBaseConEventGrp;
      for (LusCount2 = LusBaseIndex2; (LusCount2 < (LusBaseIndex2 +
                                                    LpClientServiceStatic->usNoOfConEventGrp)) &&
                                      (!LblMatchRecd);
           LusCount2++)

      {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
        LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif
        LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount2];

        if ((LusEventGroupId == LpConsumedEvGrpStatic->usEventGroupId) &&
            (LucCounter == LpConsumedEvGrpStatic->ucCounter))
        {
          LddReturnValue = E_OK;
          LblMatchRecd = (boolean)SD_TRUE;
        }
      }
    }
  }
  /* SWS_SD_00490  */
  if (LblMatchRecd)
  {
    /* Redmine : 50436 */
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
    LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeSent = SD_TRUE;
    LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeAckRecd = SD_TRUE;
  }
  if ((LblMatchRecd) &&
      (LpConsumedEvGrp->enConEvGrpCurrState !=
       SD_CONSUMED_EVENTGROUP_AVAILABLE))
  {
    Sd_SubscribeAckRecdActions(LpInstance, LpInstanceStatic,
                               LpClientService, LpConsumedEvGrp, LpConsumedEvGrpStatic,
                               LpEntryData, LpOptionsData, LucTotalNoOfOptions);
  }

  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_StopOfferRecd                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the stop offer service **
**                      : is received                                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Instance structure    **
**                      : LpEntryData - Base pointer of array of entries      **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientServiceStatic     **
**                          Sd_GaaClientServiceStatic                         **
**                                                                            **
**                        Function(s) invoked : Sd_MatchService               **
**                          Sd_StopOfferRecdActions                           **
**                                                                            **
** Design ID              : SD_SDD_0238                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_StopOfferRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData)
{
  Std_ReturnType LddReturnValue;

  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint32 LulMinorVersion;
  uint16 LusBaseIndex;
  uint16 LusCount;
  boolean LblServiceMatch;

  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  Sd_ClientServiceType *LpClientService;

  LddReturnValue = E_NOT_OK;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
  LusServiceId = (LpEntryData->unEntryData).stEntry1.usServiceId;
  LusInstanceId = (LpEntryData->unEntryData).stEntry1.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry1.ucMajorVersion;
  LulMinorVersion = (LpEntryData->unEntryData).stEntry1.ulMinorVersion;
  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                            LpInstanceStatic->usNoOfClientServices);
       LusCount++)
  {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount);
#endif

    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpClientServiceStatic->usServiceId, LpClientServiceStatic->pConfigOption,
                                      LpClientServiceStatic->usOtherServKeyIndex,
                                      LpClientServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);

    /*  SWS_SD_00424  */

    if ((LblServiceMatch) &&
        (LusInstanceId == LpClientServiceStatic->usInstanceId) &&
        (LucMajorVersion == LpClientServiceStatic->ucMajorVersion) &&
        (((uint32)SD_MINOR_VERSION_ALL_MATCH ==
          LpClientServiceStatic->ulMinorVersion) ||
         (LulMinorVersion == LpClientServiceStatic->ulMinorVersion)))

    {
      LddReturnValue = E_OK;
      LpClientService = &Sd_GaaClientService[LusCount];
      /*polyspace +6 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      if ((SD_CLIENT_REPETITION == LpClientService->enClientPhase) &&
          (SD_CLIENT_SERVICE_REQUESTED == LpClientService->enClientSetState))
      {
        LpClientService->ulClientDelayCount = SD_ZERO;
        LpClientService->enClientPhase = SD_CLIENT_MAIN;
      }

      else
      {

        Sd_StopOfferRecdActions(LpClientService,
                                LpClientServiceStatic);
      }
    }
  }

  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SubscribeNackRecdActions                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions on receiving a   **
**                          Subscribe Nack entry                              **
**                        It also checks if a Subscribe Ack is received in    **
**                          the currrent frame before performing the actions. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientServiceStatic - Pointer to static Client    **
**                          structure                                         **
**                      : LpBaseEntriesSduPtr - This is the pointer to the    **
**                           first byte of first entry in the SD frame        **
**                      : LucNoOfEntries - The no of entries in the frame     **
**                      : LucNoOfOptions - The no of options in the frame     **
**                      : LusServiceId - The service ID received in the       **
**                          subscribe nack entry                              **
**                      : LusInstanceId - The instance ID received in the     **
**                          subscribe nack entry                              **
**                      : LucMajorVersion - The major version received in the **
**                          subscribe nack entry                              **
**                      : LucCounter - The counter received in the            **
**                          subscribe nack entry                              **
**                      : LusEventGroupId -The Event Group ID received in the **
**                          subscribe nack entry                              **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoCon, Sd_GaaSoConId    **
**                                                                            **
**                        Function(s) invoked : Sd_RxGetEntry,                **
**                          SoAd_CloseSoCon, SoAd_OpenSoCon,                  **
**                                                                            **
** Design ID              : SD_SDD_0244                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_SubscribeNackRecdActions(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const uint8 LpBaseEntriesSduPtr[],
    uint8 LucNoOfEntries,
    uint8 LucNoOfOptions,
    uint16 LusServiceId,
    uint16 LusInstanceId,
    uint8 LucMajorVersion,
    uint8 LucCounter,
    uint16 LusEventGroupId)
{
  uint16 LusCount;
  boolean LblSubscribeAckRecd;
  uint8 LusCurrEntryIndex;
  Std_ReturnType LddEntryReturn;
  Sd_EntryType LstAckEntry = {SD_ZERO};
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  uint16 LusServiceIdAck;
  uint16 LusInstanceIdAck;
  uint8 LucMajorVersionAck;
  uint8 LucCounterAck;
  uint16 LusEventGroupIdAck;
  Std_ReturnType LddConnectionReturnValue;
  Sd_InstanceStaticType const *LpInstanceStatic;
  TcpIp_SockAddrType LstIpAddr;
  boolean LblMatchRecd;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)

  LpInstanceStatic =
      &Sd_GaaInstanceStatic[LpClientServiceStatic->ucSdInstanceIndex];
#else
  LpInstanceStatic =
      ((Sd_GpConfigPtr->pInstanceStatic) + LpClientServiceStatic->ucSdInstanceIndex);
#endif
  (void)SD_MEMSET(&LstIpAddr, (sint32)SD_ZERO, sizeof(TcpIp_SockAddrType));
  /* Initializing with TCPIP_E_OK as action to be taken if not TCPIP_E_OK */
  LddConnectionReturnValue = (uint8)TCPIP_E_OK;

  /*  SD_SDD_0244
      SWS_SD_00465
      SWS_SD_00693c
    SWS_SD_00693b  */
  LblSubscribeAckRecd = (boolean)SD_FALSE;
  LusCurrEntryIndex = SD_ZERO;
  for (LusCount = SD_ZERO; LusCount < LucNoOfEntries; LusCount++)
  {
    if (SD_ENTRY_TYPE_SUBSCRIBE_NACK == LpBaseEntriesSduPtr[LusCurrEntryIndex])
    {
      LddEntryReturn = Sd_RxGetEntry(&LpBaseEntriesSduPtr[LusCurrEntryIndex],
                                     &LstAckEntry, LucNoOfOptions);
      if (E_OK == LddEntryReturn)
      {
        LusServiceIdAck = LstAckEntry.unEntryData.stEntry2.usServiceId;
        LusInstanceIdAck = LstAckEntry.unEntryData.stEntry2.usInstanceId;
        LucMajorVersionAck = LstAckEntry.unEntryData.stEntry2.ucMajorVersion;
        LucCounterAck = LstAckEntry.unEntryData.stEntry2.ucCounter;
        LusEventGroupIdAck = LstAckEntry.unEntryData.stEntry2.usEventGroupId;

        if ((LusServiceId == LusServiceIdAck) &&
            (LusInstanceId == LusInstanceIdAck) &&
            (LucMajorVersion == LucMajorVersionAck) &&
            (LucCounter == LucCounterAck) &&
            (LusEventGroupId == LusEventGroupIdAck))
        {
          LblSubscribeAckRecd = (boolean)SD_TRUE;
        }
      }
    }
    LusCurrEntryIndex = LusCurrEntryIndex + SD_SIXTEEN;
  }
  /*SRS : 831,832
    ETC_122, 123
    SWS_SD_00465a
    SWS_SD_00465b
    SWS_SD_00465c */
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
   LblSubscribeAckRecd is not equal to SD_TRUE.
   Module Test Case Reference SD_ETC_122, SWS ID SWS_SD_00465" */
  if (LblSubscribeAckRecd)
  {
    /* SWS_SD_00465a, SD_SRS_830, SD_SDD_0244, SD_ETC_121 */
    SD_E_SUBSCR_NACK_RECV(LpInstanceStatic);

    /* polyspace +6 RTE:UNR [Justified:Low] "This If condition will be false
    if pTcpSoConGrp is Set as SD_NULL_PTR" */
    if (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp)

    {

      LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
      LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;

      for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
           LusCount++)
      {
        /* SWS_SD_00465b, SD_SRS_831, SD_SDD_0244, SD_ETC_122, SD_ETC_1235 */
        /* SWS_SD_00465c, SD_SRS_832, SD_SDD_0244, SD_ETC_123, SD_ETC_1234 */
        /* To check if SoAd_IsConnectionReady() returned a different value
        than TCPIP_E_OK */
        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being out of bounds." */
        (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddr);
        LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpRemoteAddr);
        if (LblMatchRecd)
        {
          LddConnectionReturnValue =
              (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LusCount],
                                             &LstIpAddr));
        }
        if ((SD_TRUE == Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened) ||
            (LddConnectionReturnValue != (uint8)TCPIP_E_OK))
        {
          (void)SoAd_CloseSoCon(Sd_GaaSoConId[LusCount], (boolean)SD_TRUE);
          (void)SoAd_OpenSoCon(Sd_GaaSoConId[LusCount]);
        }
      }
    }

    /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
      pUdpSoConGrp is not equal to SD_NULL_PTR. */
    if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)

    {

      LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
      LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;

      for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
           LusCount++)
      {
        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */

        /* SWS: 00465b 00465c, SRS : 831,832, ETC_FT : 1234, 1235 */
        /* To check if SoAd_IsConnectionReady() returned a different value
        than TCPIP_E_OK */
        (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddr);
        LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpRemoteAddr);
        if (LblMatchRecd)
        {
          LddConnectionReturnValue =
              (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LusCount],
                                             &LstIpAddr));
        }
        if ((SD_TRUE == Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened) ||
            (LddConnectionReturnValue != (uint8)TCPIP_E_OK))
        {
          (void)SoAd_CloseSoCon(Sd_GaaSoConId[LusCount], (boolean)SD_TRUE);
          (void)SoAd_OpenSoCon(Sd_GaaSoConId[LusCount]);
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SubscribeNackRecd                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the Subscribe Nack is  **
**                      :    received                                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Instance structure    **
**                      : LpEntryData - Base pointer of array of entries      **
**                      : LpBaseEntriesSduPtr - This is the pointer to the    **
**                           first byte of first entry in the SD frame        **
**                      : LucNoOfEntries - This is the no of entries detected **
**                           for this frame.                                  **
**                      : LpOptionsData - Base pointer of the array of options**
**                      : LucNoOfOptions - The number of options in the input **
**                                                                            **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK if Match detected                              **
**                      : E_NOT_OK if match not detected.                     **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientServiceStatic     **
**                          Sd_GaaConsumedEvGrpStatic                         **
**                                                                            **
**                        Function(s) invoked : Sd_MatchService               **
**                          Sd_SubscribeNackRecdActions                       **
**                                                                            **
** Design ID              : SD_SDD_0243                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_SubscribeNackRecd(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const uint8 LpBaseEntriesSduPtr[],
    uint8 LucNoOfEntries,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr)
{
  Std_ReturnType LddReturnValue;
  uint16 LusBaseIndex;
  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint8 LucCounter;
  uint16 LusEventGroupId;
  boolean LblMatchRecd;
  uint16 LusCount;
  const Sd_ClientServiceStaticType * LpClientServiceStatic;
  boolean LblServiceMatch;
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
  uint16 LusBaseIndex2;
  uint16 LusCount2;
#endif

  Sd_ConsumedEvGrpType * LpConsumedEvGrp;
  LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[SD_ZERO];

  LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpClientServiceStatic = &Sd_GaaClientServiceStatic[0];
#else
  LpClientServiceStatic =
      ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + (Sd_GpConfigPtr->pSd_GaaClientHandleMapArray[0]));
#endif

  /*SWS_SD_00430*/
  LusServiceId = (LpEntryData->unEntryData).stEntry2.usServiceId;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusInstanceId = (LpEntryData->unEntryData).stEntry2.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry2.ucMajorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LucCounter = (LpEntryData->unEntryData).stEntry2.ucCounter;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusEventGroupId = (LpEntryData->unEntryData).stEntry2.usEventGroupId;

  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;

  LblMatchRecd = (boolean)SD_FALSE;

  for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex +
                                             LpInstanceStatic->usNoOfClientServices)) &&
                                (!LblMatchRecd);
       LusCount++)
  {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount);
#endif
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpClientServiceStatic->usServiceId, LpClientServiceStatic->pConfigOption,
                                      LpClientServiceStatic->usOtherServKeyIndex,
                                      LpClientServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);

    if ((LblServiceMatch) &&
        (LusInstanceId == LpClientServiceStatic->usInstanceId) &&
        (LucMajorVersion == LpClientServiceStatic->ucMajorVersion))
    {
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
      LusBaseIndex2 = LpClientServiceStatic->usBaseConEventGrp;
      for (LusCount2 = LusBaseIndex2; (LusCount2 < (LusBaseIndex2 +
                                                    LpClientServiceStatic->usNoOfConEventGrp)) &&
                                      (!LblMatchRecd);
           LusCount2++)
      {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount2];
#else
        LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount2);
#endif
        LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount2];
        /* SWS_SD_00692  */
        if ((LusEventGroupId == LpConsumedEvGrpStatic->usEventGroupId) &&
            (LucCounter == LpConsumedEvGrpStatic->ucCounter))
        {
          LddReturnValue = E_OK;
          LblMatchRecd = (boolean)SD_TRUE;
        }
      }
#endif
    }
  }
  if (LblMatchRecd)
  {
    /*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +5 RTE:NIP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    (LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeNAckRecd = SD_TRUE;

    Sd_SubscribeNackRecdActions(LpClientServiceStatic, LpRemoteAddr,
                                LpBaseEntriesSduPtr, LucNoOfEntries, LucNoOfOptions,
                                LusServiceId, LusInstanceId, LucMajorVersion, LucCounter,
                                LusEventGroupId);
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_StopOfferRecdActions                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to perform the actions when **
**                      : Stop offer is received                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - This is the pointer to the       **
**                          instance static structure                         **
**                      : LpClientService - This is the pointer to the client **
**                          service structure                                 **
**                      : LpClientServiceStatic - This is the pointer to the  **
**                          client service static structure                   **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp           **
**                          Sd_GaaConsumedEvGrpStatic                         **
**                                                                            **
**                        Function(s) invoked : Sd_ClientInactive,            **
**                          Sd_ConsumedEvGrpRelease,                          **
**                          BswM_Sd_ClientServiceCurrentState,                **
**                          BswM_Sd_ConsumedEventGroupCurrentState,           **
**                                                                            **
** Design ID              : SD_SDD_0239                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_StopOfferRecdActions(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  Sd_ConsumedEvGrpType *LpConsumedEvGrp;
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
#endif
  uint16 LusNoOfElements;
  uint16 LusBaseIndex;
  uint16 LusCount;

  /* SWS_SD_00481b
     SWS_SD_00463
     SWS_SD_00463c
     SWS_SD_00422 */
  (LpClientService->stClientFlag).blOfferAvailable = SD_FALSE;
  (LpClientService->stClientFlag).blOfferMaxTtl = SD_FALSE;
  Sd_ClientInactive(LpClientService);
  LpClientService->ulClientDelayCount = SD_ZERO;
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
  LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[SD_ZERO];
  LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[SD_ZERO];
#endif

  /*  SWS_SD_00367
       SWS_SD_00367b
      SWS_SD_00367c
     SWS_SD_00367d
       SWS_SD_00367e */
  /*7.3.6 Flags field update*/

  if (LpClientServiceStatic->pTcpSoConGrp != SD_NULL_PTR)
  {

    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
         LusCount++)
    {
      /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag
        are made sure that they are within their range by having necessary
        boundary checks in order to prevent them from being out of bounds." */
      if (SD_TRUE == Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened)
      {
        (void)SoAd_CloseSoCon(Sd_GaaSoConId[LusCount], (boolean)SD_TRUE);
      }
    }
  }

  if (SD_CLIENT_SERVICE_AVAILABLE == LpClientService->enClientCurrState)
  {
    LpClientService->enClientCurrState = SD_CLIENT_SERVICE_DOWN;

    BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                                      LpClientService->enClientCurrState);
  }

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)

  LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;
  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                            LpClientServiceStatic->usNoOfConEventGrp);
       LusCount++)

  {
    LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
    LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif

    /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LpConsumedEvGrp->ulConEvGrpTtlCount = SD_ZERO;

    if (SD_CONSUMED_EVENTGROUP_AVAILABLE ==
        LpConsumedEvGrp->enConEvGrpCurrState)
    {
      LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_DOWN;
      BswM_Sd_ConsumedEventGroupCurrentState(LpConsumedEvGrpStatic->usHandleId, LpConsumedEvGrp->enConEvGrpCurrState);
      Sd_ConsumedEvGrpRelease(LpConsumedEvGrp, LpConsumedEvGrpStatic);
    }
  }

/* SWS 00367d */
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
  /* polyspace +6 RTE:UNR [Justified:Low]  LpClientService->
  enClientCurrState is false when enClientCurrState
  is when enClientCurrState is SD_CLIENT_SERVICE_AVAILABLE*/
  if (SD_ZERO < (LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax)
  {
    LpClientService->ulClientRetrySubDelayCount = SD_ZERO;
    LpConsumedEvGrp->ulConEvGrpRetryCount = SD_ZERO;
  }
#endif
#endif
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
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
