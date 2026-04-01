/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Internal.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the internal and helper functions          **
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
/** At section SD_Internal_c_REF_1
* Violates MISRA 2012 Advisory Rule 2.2, This statement has no side effects.
* This statement is required for polyspace.
* Justification: For the unused variables or variables which are set but not
* used for specific configuration compiler shows warning. QAC shows dead code
* for the steps which are implemented to avoid such compiler warnings.

* #section SD_Internal_C_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* All the #include statements in a particular code file should be grouped
* together near the head of the file. The rule states that the only items which
* may precede a #include in a file are other preprocessor directives or comments
* Justification: As per RS_BSW_00437 in AUTOSAR_SRS_BSWGeneral document Memory
* mapping is provided as start and stop memory sections. This is approved
* by AUTOSAR.

* #section SD_Internal_C_REF_3
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
* violates #ref SD_INTERNAL_C_REF_1 Violates MISRA 2012 Required Rule 20.1
* As per KPIT coding guidelines, macro name should start from module name
*  (upper case) and hence this violation is suppressed as it does not impact the module funtionality
*#violates #ref SD_Internal_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)
*PRQA S 0857 EOF
*
* violates #ref SD_Internal_c_REF_3 Violates MISRA 2012 Dir-1.1
* PRQA S 0380 EOF
* Part of  Common Deviation
*
* #Violates #ref SD_Internal_c_REF_7, DCL00 Msg(qac-10.1.0-3227)
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
* #Violates #ref SD_Internal_c_REF_6,INT02 Msg(qac-10.1.0-2100)
*PRQA S 2100 EOF
*This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Internal_c_REF_7,INT02 Msg(qac-10.1.0-2101)
*PRQA S 2101 EOF
*This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Internal_c_REF_8,INT02 Msg(qac-10.1.0-2120)
*PRQA S 2120 EOF
*This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Internal_c_REF_9,INT02 Msg(qac-10.1.0-1251)
*PRQA S 1251 EOF
*This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Internal_c_REF_9,PRE04 Msg(certccm-2.1.0-5001)
* PRQA S 5001 EOF
* Deviation is only approved for  the file names derived through AUTOSAR
* Specifications and KPIT Coding Guidelines as they do not cause any issue.
* #Violates #ref SD_Internal_c_REF_9,INT02 Msg(qac-10.1.0-1290)
* PRQA S 1-9999 EOF
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
* #Violates #ref SD_Internal_c_REF_9INT02 Msg(qac-10.1.0-1290)
* PRQA S 1290 EOF
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
*
* #Violates #ref SD_Internal_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)
* PRQA S 5002 EOF
* Deviation is only approved for  the file names derived through AUTOSAR
* Specifications and KPIT Coding Guidelines as they do not cause any issue.
* #Violates #ref SD_Internal_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)
* PRQA S 0-9999 EOF
* Deviation is only approved for  the file names derived through AUTOSAR
* Specifications and KPIT Coding Guidelines as they do not cause any issue.
*
* #Violates #ref SD_Internal_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)
PRQA S 4810 EOF
*Common Deviation
* #Violates #ref SD_Internal_c_REF_9,Dir-4.4 Msg(qac-10.1.0-2053)
* PRQA S 2052,2053 EOF
* Deviation:77966
*  #Violates #ref SD_Internal_c_REF_9 Dir-4.4 Msg(qac-10.1.0-2053)
*PRQA S 2053 EOF
* Deviation:77966
* #Violates #ref SD_Internal_c_REF_9,DCL07 Msg(qac-10.1.0-3450)
*PRQA S 553,2017,3219 EOF
* Deviation:77966
* #Violates #ref SD_Internal_c_REF_4,INT30 Msg(qac-10.1.0-3383)
*PRQA S 3383 EOF
*Deviation:77966
* #Violates #ref SD_Internal_c_REF_5,INT30 Msg(qac-10.1.0-3384)
*PRQA S 3384 EOF
*Deviation:77966
* #Violates #ref SD_Internal_c_REF_4,MSC01 Msg(qac-10.1.0-2000)
*PRQA S 2000 EOF
*Deviation:77966
* #Violates #ref SD_Internal_c_REF_4,MSC01 Msg(qac-10.1.0-2004)
*PRQA S 2004 EOF
*Deviation:77966
**/

/* PRQA S 5087 EOF */
/* violates #ref SD_INTERNAL_C_REF_1 Violates MISRA 2012 Required Rule 20.1 */

/*#violates #ref SD_Internal_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)*/
/*PRQA S 0857 EOF*/

/* violates #ref SD_Internal_c_REF_3 Violates MISRA 2012 Dir-1.1 */
/* PRQA S 0380 EOF */

/* #Violates #ref SD_Internal_c_REF_7, DCL00 Msg(qac-10.1.0-3227) */
/* PRQA S 3227 EOF */

/* #Violates #ref SD_Internal_c_REF_4,INT30 Msg(qac-10.1.0-3383) */
/*PRQA S 3383 EOF*/

/* #Violates #ref SD_Internal_c_REF_5,INT30 Msg(qac-10.1.0-3384) */
/*PRQA S 3384 EOF*/

/* #Violates #ref SD_Internal_c_REF_4,MSC01 Msg(qac-10.1.0-2000) */
/*PRQA S 2000 EOF*/

/* #Violates #ref SD_Internal_c_REF_4,MSC01 Msg(qac-10.1.0-2004) */
/*PRQA S 2004 EOF*/

/* #Violates #ref SD_Internal_c_REF_6,INT02 Msg(qac-10.1.0-2100) */
/*PRQA S 2100 EOF*/

/* #Violates #ref SD_Internal_c_REF_7,INT02 Msg(qac-10.1.0-2101) */
/*PRQA S 2101 EOF*/

/* #Violates #ref SD_Internal_c_REF_8,INT02 Msg(qac-10.1.0-2120) */
/*PRQA S 2120 EOF*/

/* #Violates #ref SD_Internal_c_REF_9,INT02 Msg(qac-10.1.0-1251) */
/*PRQA S 1251 EOF*/

/* #Violates #ref SD_Internal_c_REF_9,DCL07 Msg(qac-10.1.0-3450) */
/*PRQA S 553,2017,3219 EOF*/

/* #Violates #ref SD_Internal_c_REF_9,PRE04 Msg(certccm-2.1.0-5001) */
/*PRQA S 5001 EOF*/

/* #Violates #ref SD_Internal_c_REF_9,INT02 Msg(qac-10.1.0-1290) */
/*PRQA S 1-9999 EOF*/

/* #Violates #ref SD_Internal_c_REF_9INT02 Msg(qac-10.1.0-1290) */
/*PRQA S 1290 EOF*/

/* #Violates #ref SD_Internal_c_REF_9 Dir-4.4 Msg(qac-10.1.0-2053) */
/*PRQA S 2053 EOF*/

/* #Violates #ref SD_Internal_c_REF_9,PRE08 Msg(certccm-2.1.0-5002) */
/*PRQA S 5002 EOF*/
/* #Violates #ref SD_Internal_c_REF_9,PRE08 Msg(certccm-2.1.0-5002) */
/* PRQA S 0-9999 EOF */
/* #Violates #ref SD_Internal_c_REF_9,Dir-4.4 Msg(qac-10.1.0-2053) */
/* PRQA S 2052,2053 EOF */
/* #Violates #ref SD_Internal_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
/*PRQA S 4810 EOF */
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
#include "NvM.h"
#if (STD_ON == SD_ENABLE_SECURITY_EVENT_REPORTING)
#include "IdsM.h"
#endif
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
** Function Name        : Sd_MatchString                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks if the match string is present **
**                        in the source string inputs                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpSource - Pointer to Source string                 **
**                                                                            **
**                      : LpMatch - Pointer to string to be matched           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : E_OK - Match found                                  **
**                        E_NOT_OK - Match not found                          **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0320, SD_SDD_0087,SD_SDD_0045                **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_MatchString(
    const uint8 * LpSource,
    const uint8 * LpMatch,
    uint16 * LpIndex)
{ /* SWS_SD_00293*/
  Std_ReturnType LddReturnValue;

  boolean LblOuterBreak;
  boolean LblBreak;
  uint16 LusSourceIndex;
  uint16 LusSourceIndexInt;
  uint16 LusMatchIndexInt;

  LddReturnValue = E_NOT_OK;
  LblOuterBreak = FALSE;
  LusSourceIndex = SD_ZERO;
  /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
  made sure that they are within their range by having necessary boundary
  checks in order to prevent them from being illegally dereferenced." */
  while ((SD_FALSE == LblOuterBreak) && (LpSource[LusSourceIndex] != SD_ZERO))
  {
    LusSourceIndexInt = LusSourceIndex;
    LusMatchIndexInt = SD_ZERO;

    LblBreak = FALSE;
    /*polyspace +7 RTE:IDP [Justified:Low] "LpMatch point to only
     index 0. hence it will not exceed beyond its boundary. LpMatch,
     has config for only 1 trcv. so its within bounds" */
    while ((SD_FALSE == LblBreak) && (LpMatch[LusMatchIndexInt] != SD_ZERO))
    {
      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      if (LpSource[LusSourceIndexInt] != LpMatch[LusMatchIndexInt])
      {
        LblBreak = SD_TRUE;
      }
      LusSourceIndexInt = LusSourceIndexInt + SD_ONE;
      LusMatchIndexInt = LusMatchIndexInt + SD_ONE;
    }

    if (SD_FALSE == LblBreak)
    {
      *LpIndex = LusSourceIndex;
      LddReturnValue = E_OK;
      LblOuterBreak = SD_TRUE;
    }

    LusSourceIndex = LusSourceIndex + SD_ONE;
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetIpAddrFromV4Option                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the IPV4 addr from a       **
**                        single IPv4 option.                                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpCurrOption - Pointer to the current option to be  **
**                          considered                                        **
**                                                                            **
** InOut parameter      : LpPrevTcpOptionFound - Pointer indicating if TCP    **
**                          option was found previously                       **
**                      : LpPrevUdpOptionFound - Pointer indicating if UDP    **
**                          option was found previously                       **
**                      : LpReturnValue - This is the running return value    **
**                          for the loop. It is made E_NOT_OK in case of error**
**                          and is left unchanged otherwise                   **
**                      : LpMalformedOption - This is the running malformed   **
**                          option boolean for the loop. It is made SD_TRUE,  **
**                          if a malformed option is detected                 **
**                                                                            **
** Output Parameters    : LpIpAddrTcp - The Ipaddr of the TCP option,         **
**                      : LpIpAddrUdp - The Ipaddr of the UDP option,         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0306,SD_SDD_0330,                            **
                          SD_SDD_0115,SD_SDD_0348,SD_SDD_0347,                **
                          SD_SDD_0349,SD_SDD_0158,SD_SDD_0159,                **
                          ,SD_SDD_0444, SD_SDD_0446                **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static void Sd_GetIpAddrFromV4Option(
    const Sd_OptionsDataType * LpCurrOption,
    boolean * LpPrevTcpOptionFound,
    boolean * LpPrevUdpOptionFound,
    Std_ReturnType * LpReturnValue,
    boolean * LpMalformedOption,
    TcpIp_SockAddrType * LpIpAddrTcp,
    TcpIp_SockAddrType * LpIpAddrUdp)
{
  uint8 LucProtocol;

  TcpIp_SockAddrType * LpIpAddrTcpInt;
  TcpIp_SockAddrType * LpIpAddrUdpInt;

  LpIpAddrTcpInt = LpIpAddrTcp;
  LpIpAddrUdpInt = LpIpAddrUdp;
  /*[SWS_SD_00653]*/
  /*  Design ID   : SD_SDD_0115,SD_SDD_0348,SD_SDD_0347,SD_SDD_0349,SD_SDD_0158,SD_SDD_0159,SD_SDD_0444, SD_SDD_0446 */
  LucProtocol = (LpCurrOption->unOptionsData).stOptionsIpv4.ucProtocol;
  if (SD_PROTOCOL_TCP == LucProtocol)
  {
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    the LpPrevTcpOptionFound value is SD_FALSE .
    Unit Test Case Reference SD_UTP_0156, SWS ID SD_SRS_765" */
    if (SD_FALSE == *LpPrevTcpOptionFound)
    {
      *LpPrevTcpOptionFound = SD_TRUE;

      Sd_Ipv4LoadData(LpCurrOption, LpIpAddrTcpInt);
    }
    else
    {
      *LpReturnValue = E_NOT_OK;
      *LpMalformedOption = SD_TRUE;
    }
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (SD_PROTOCOL_UDP == LucProtocol)
  {
    if (SD_FALSE == *LpPrevUdpOptionFound)
    {
      *LpPrevUdpOptionFound = SD_TRUE;

      Sd_Ipv4LoadData(LpCurrOption, LpIpAddrUdpInt);
    }
    else
    {

      *LpReturnValue = E_NOT_OK;
      *LpMalformedOption = SD_TRUE;
    }
  }
  else
  {
    *LpReturnValue = E_NOT_OK;
    *LpMalformedOption = SD_TRUE;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
/*******************************************************************************
** Function Name        : Sd_GetIpAddrFromV6Option                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the IPV6 addr from a       **
**                        single IPv6 option.                                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpCurrOption - Pointer to the current option to be  **
**                          considered                                        **
**                                                                            **
** InOut parameter      : LpPrevTcpOptionFound - Pointer indicating if TCP    **
**                          option was found previously                       **
**                      : LpPrevUdpOptionFound - Pointer indicating if UDP    **
**                          option was found previously                       **
**                      : LpReturnValue - This is the running return value    **
**                          for the loop. It is made E_NOT_OK in case of error**
**                          and is left unchanged otherwise                   **
**                      : LpMalformedOption - This is the running malformed   **
**                          option boolean for the loop. It is made SD_TRUE,  **
**                          if a malformed option is detected                 **
**                                                                            **
** Output Parameters    : LpIpAddrTcp - The Ipaddr of the TCP option,         **
**                      : LpIpAddrUdp - The Ipaddr of the UDP option,         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0307,SD_SDD_0360,SD_SDD_0362,                **
                          SD_SDD_0120,SD_SDD_0364,SD_SDD_0122,                **
                          SD_SDD_0363,SD_SDD_0121,SD_SDD_0124,                **
                          SD_SDD_0365, SD_SDD_0123,SD_SDD_0367,               **
                          SD_SDD_0125                                         **
*******************************************************************************/
#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static void Sd_GetIpAddrFromV6Option(
    const Sd_OptionsDataType * LpCurrOption,
    boolean * LpPrevTcpOptionFound,
    boolean * LpPrevUdpOptionFound,
    Std_ReturnType * LpReturnValue,
    boolean * LpMalformedOption,
    TcpIp_SockAddrType * LpIpAddrTcp,
    TcpIp_SockAddrType * LpIpAddrUdp)
{
  uint8 LucProtocol;

  TcpIp_SockAddrType * LpIpAddrTcpInt;
  TcpIp_SockAddrType * LpIpAddrUdpInt;

  LpIpAddrTcpInt = LpIpAddrTcp;
  LpIpAddrUdpInt = LpIpAddrUdp;

  LucProtocol = (LpCurrOption->unOptionsData).stOptionsIpv6.ucProtocol;
  if (SD_PROTOCOL_TCP == LucProtocol)
  {
    if (SD_FALSE == *LpPrevTcpOptionFound)
    {
      *LpPrevTcpOptionFound = SD_TRUE;

      Sd_Ipv6LoadData(LpCurrOption, LpIpAddrTcpInt);
    }
    else
    {
      *LpReturnValue = E_NOT_OK;
      *LpMalformedOption = SD_TRUE;
    }
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (SD_PROTOCOL_UDP == LucProtocol)
  {
    if (SD_FALSE == *LpPrevUdpOptionFound)
    {
      *LpPrevUdpOptionFound = SD_TRUE;

      Sd_Ipv6LoadData(LpCurrOption, LpIpAddrUdpInt);
    }
    else
    {
      *LpReturnValue = E_NOT_OK;
      *LpMalformedOption = SD_TRUE;
    }
  }
  else
  {
    *LpReturnValue = E_NOT_OK;
    *LpMalformedOption = SD_TRUE;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_GetIpAddrFromOptions                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the IP addr from the       **
**                        options. It operates on the OfferService and        **
**                        on client side                                      **
**                        and subscribeeventgroup entry on the server         **
**                        side                                                **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEntryData - Pointer to the Entry Structure        **
**                      : LpOptionsData - Pointer to the Options Array        **
**                      :       holding upto 16 options                       **
**                      : LucTotalNoOfOptions - The no of options in the      **
**                              options array                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpIpAddrTcp - The Ipaddr of the TCP option,         **
**                      : LpIpAddrUdp - The Ipaddr of the UDP option,         **
**                                                                            **
** Return parameter     : SD_OPTIONS_NOT_FOUND - (0x00) This is set if no     **
**                          options are found or mismatching options are      **
**                          found                                             **
**                        SD_TCP_OPTIONS_MASK - (0x01) - This bit is set if   **
**                          TCP options are found                             **
**                        SD_UDP_OPTIONS_MASK - (0x02) - This bit is set if   **
**                          UDP options are found                             **
**                        SD_OPTIONS_MALFORMED_MASK(0x04) - This bit is set if**
**                          Malformed message is detected and DEM error       **
**                          should be invoked in calling function             **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_GetIpAddrFromV4Option      **
**                          Sd_GetIpAddrFromV6Option                          **
**                                                                            **
** Design ID            : SD_SDD_0305                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_GetIpAddrFromOptions(
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    TcpIp_SockAddrType * LpIpAddrTcp,
    TcpIp_SockAddrType * LpIpAddrUdp)
{
  Std_ReturnType LddReturnValue;
  uint8 LucIndex1 = SD_ZERO;
  uint8 LucIndex2 = SD_ZERO;
  uint16 LusCount;
  uint8 LucNoOfOptions1 = SD_ZERO;
  uint8 LucNoOfOptions2 = SD_ZERO;
  uint8 LucReturnCode;
  const Sd_Entry1DataType * LpEntry1;
  const Sd_Entry2DataType * LpEntry2;
  const Sd_OptionsDataType * LpCurrOption;

  boolean LblTcpOptionFound;
  boolean LblUdpOptionFound;
  boolean LblMalformedOption;

  LucReturnCode = SD_OPTIONS_NOT_FOUND;
  LblTcpOptionFound = SD_FALSE;
  LblUdpOptionFound = SD_FALSE;
  LblMalformedOption = SD_FALSE;
  /*[SWS_SD_00655] */
  /* polyspace +4 RTE:UNR [Justified:Low]
    "This check will be false when SD_OFFER_SERVICE_ENTRY
   is not equal to entry type " */
  if (SD_OFFER_SERVICE_ENTRY == LpEntryData->enTypeOfEntry)
  {
    LpEntry1 = &(LpEntryData->unEntryData).stEntry1;
    LucIndex1 = LpEntry1->ucIndex1;
    LucNoOfOptions1 = LpEntry1->ucNoOfOptions1;
    LucIndex2 = LpEntry1->ucIndex2;
    LucNoOfOptions2 = LpEntry1->ucNoOfOptions2;
    LddReturnValue = E_OK;
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  /* polyspace +4 RTE:UNR [Justified:Low]
     "This check will be false when SD_OFFER_SERVICE_ENTRY
    is not equal to entry type " */
  else if (SD_SUBSCRIBE_ENTRY == LpEntryData->enTypeOfEntry)
  {
    LpEntry2 = &(LpEntryData->unEntryData).stEntry2;
    LucIndex1 = LpEntry2->ucIndex1;
    LucNoOfOptions1 = LpEntry2->ucNoOfOptions1;
    LucIndex2 = LpEntry2->ucIndex2;
    LucNoOfOptions2 = LpEntry2->ucNoOfOptions2;
    LddReturnValue = E_OK;
  }
  /* polyspace +5 RTE:UNR [Justified:Low]
    "This check will be true when SD_SUBSCRIBE_ENTRY
  is not equal to entry type " */
  else
  {
    LddReturnValue = E_NOT_OK;
  }

  /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
  the LddReturnValue is  equal to E_OK . */
  if (E_OK == LddReturnValue)
  {
    if (((LucIndex1 + LucNoOfOptions1) > LucTotalNoOfOptions) ||
        ((LucIndex2 + LucNoOfOptions2) > LucTotalNoOfOptions))
    {
      LddReturnValue = E_NOT_OK;
      LblMalformedOption = SD_TRUE;
    }

    for (LusCount = LucIndex1; LusCount < ((uint16)LucIndex1 + LucNoOfOptions1);
         LusCount++)
    {
      LpCurrOption = &LpOptionsData[LusCount];
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
      if (SD_IPV4_ENDPOINT_OPTION == LpCurrOption->enTypeOfOption)
      {

        Sd_GetIpAddrFromV4Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 LpIpAddrTcp, LpIpAddrUdp);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_IPV6_ENDPOINT_OPTION == LpCurrOption->enTypeOfOption)
      {
#if (STD_ON == SD_IPV6_ENABLED)

        Sd_GetIpAddrFromV6Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 LpIpAddrTcp, LpIpAddrUdp);
#else

        LddReturnValue = E_NOT_OK;
        LblMalformedOption = SD_TRUE;
#endif
      }

      else
      {
        /*Do Nothing */
      }
    }

    for (LusCount = LucIndex2; LusCount < ((uint16)LucIndex2 + LucNoOfOptions2);
         LusCount++)
    {
      LpCurrOption = &LpOptionsData[LusCount];
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      if (SD_IPV4_ENDPOINT_OPTION == LpCurrOption->enTypeOfOption)
      {

        Sd_GetIpAddrFromV4Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 LpIpAddrTcp, LpIpAddrUdp);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_IPV6_ENDPOINT_OPTION == LpCurrOption->enTypeOfOption)
      {
#if (STD_ON == SD_IPV6_ENABLED)
        Sd_GetIpAddrFromV6Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 LpIpAddrTcp, LpIpAddrUdp);
#else

        LddReturnValue = E_NOT_OK;
        LblMalformedOption = SD_TRUE;
#endif
      }
      else
      {
        /*Do Nothing */
      }
    }

    if (SD_TRUE == LblMalformedOption)
    {
      LucReturnCode = SD_OPTIONS_MALFORMED_MASK;
    }
    if (E_OK == LddReturnValue)
    {
      if (SD_TRUE == LblTcpOptionFound)
      {
        LucReturnCode = LucReturnCode | (SD_TCP_OPTIONS_MASK);
      }

      if (SD_TRUE == LblUdpOptionFound)
      {
        LucReturnCode = LucReturnCode | (SD_UDP_OPTIONS_MASK);
      }
    }
  }
  return (LucReturnCode);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetIpAddrFromMulticastOption                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the IP addr from the       **
**                        multicast options. It operates on the Subscribe     **
**                        Eventgroup Ack Recd on client side                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEntryData - Pointer to the Entry Structure        **
**                      : LpOptionsData - Pointer to the Options Array        **
**                      :       holding upto 16 options                       **
**                      : LucTotalNoOfOptions - The no of options in the      **
**                        options array                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpIpAddrUdp - The Ipaddr of the UDP option,         **
**                                                                            **
** Return parameter     : SD_OPTIONS_NOT_FOUND - (0x00) - No Options found    **
**                      : SD_UDP_OPTIONS_MASK - (0x02) - UDP options found    **
**                      : SD_OPTIONS_MALFORMED_MASK - Options malformed       **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_GetIpAddrFromV4Option      **
**                          Sd_GetIpAddrFromV6Option                          **
**                                                                            **
** Design ID            : SD_SDD_0304                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_GetIpAddrFromMulticastOption(
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    TcpIp_SockAddrType * LpIpAddrUdp)
{
  Std_ReturnType LddReturnValue;
  uint8 LucIndex1 = SD_ZERO;
  uint8 LucIndex2 = SD_ZERO;
  uint8 LucNoOfOptions1 = SD_ZERO;
  uint8 LucNoOfOptions2 = SD_ZERO;
  uint8 LucReturnCode;
  uint16 LusCount;

  const Sd_Entry2DataType * LpEntry2;
  const Sd_OptionsDataType * LpCurrOption;

  boolean LblTcpOptionFound;
  boolean LblUdpOptionFound;
  boolean LblMalformedOption;

  TcpIp_SockAddrType LstIpAddrTcpDummy;

  LddReturnValue = E_OK;
  LucReturnCode = SD_OPTIONS_NOT_FOUND;
  LblUdpOptionFound = SD_FALSE;
  LblMalformedOption = SD_FALSE;

  /* polyspace +6 RTE:UNR [Justified:Low]
  "This check will be false when SD_SUBSCRIBE_ACK_ENTRY is
   is not equal to entry type " */
  LblTcpOptionFound = SD_TRUE;
  if (SD_SUBSCRIBE_ACK_ENTRY != LpEntryData->enTypeOfEntry)
  {
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    LpEntry2 = &(LpEntryData->unEntryData).stEntry2;
    LucIndex1 = LpEntry2->ucIndex1;
    LucNoOfOptions1 = LpEntry2->ucNoOfOptions1;
    LucIndex2 = LpEntry2->ucIndex2;
    LucNoOfOptions2 = LpEntry2->ucNoOfOptions2;
  }
  /* polyspace +3 RTE:UNR [Justified:Low]
    "This condition shall be true when
     the LddReturnValue is  equal to E_OK . */
  if (E_OK == LddReturnValue)
  {
    if (((LucIndex1 + LucNoOfOptions1) > LucTotalNoOfOptions) ||
        ((LucIndex2 + LucNoOfOptions2) > LucTotalNoOfOptions))
    {
      LddReturnValue = E_NOT_OK;
      LblMalformedOption = SD_TRUE;
    }

    for (LusCount = LucIndex1; LusCount < ((uint16)LucIndex1 + LucNoOfOptions1);
         LusCount++)
    {
      LpCurrOption = &LpOptionsData[LusCount];
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      /* SD_SWS_377*/
      if (SD_IPV4_MULTICAST_OPTION == LpCurrOption->enTypeOfOption)
      {
        Sd_GetIpAddrFromV4Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 &LstIpAddrTcpDummy, LpIpAddrUdp);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_IPV6_MULTICAST_OPTION == LpCurrOption->enTypeOfOption)
      {
#if (STD_ON == SD_IPV6_ENABLED)
        Sd_GetIpAddrFromV6Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 &LstIpAddrTcpDummy, LpIpAddrUdp);
#else

        LddReturnValue = E_NOT_OK;
        LblMalformedOption = SD_TRUE;
#endif
      }
      else
      {
        /* Do Nothing */
      }
    }
    for (LusCount = LucIndex2; LusCount < ((uint16)LucIndex2 + LucNoOfOptions2);
         LusCount++)
    {
      LpCurrOption = &LpOptionsData[LusCount];
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      if (SD_IPV4_MULTICAST_OPTION == LpCurrOption->enTypeOfOption)
      {
        Sd_GetIpAddrFromV4Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 &LstIpAddrTcpDummy, LpIpAddrUdp);
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (SD_IPV6_MULTICAST_OPTION == LpCurrOption->enTypeOfOption)
      {
#if (STD_ON == SD_IPV6_ENABLED)
        Sd_GetIpAddrFromV6Option(LpCurrOption, &LblTcpOptionFound,
                                 &LblUdpOptionFound, &LddReturnValue, &LblMalformedOption,
                                 &LstIpAddrTcpDummy, LpIpAddrUdp);
#else

        LddReturnValue = E_NOT_OK;
        LblMalformedOption = SD_TRUE;
#endif
      }
      else
      {
        /* Do Nothing */
      }
    }
    if (SD_TRUE == LblMalformedOption)
    {
      LucReturnCode = SD_OPTIONS_MALFORMED_MASK;
    }
    if (E_OK == LddReturnValue)
    {
      if (SD_TRUE == LblUdpOptionFound)
      {
        LucReturnCode = LucReturnCode | (SD_UDP_OPTIONS_MASK);
      }
    }
  }
  return (LucReturnCode);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_MatchIpAddr                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Takes two Ipv6 addresses and returns  **
**                            TRUE if equal, else FALSE                       **
**                          - (Comparison is done based on domain).           **
**                              If domain is Ipv4 only 1 byte is compared     **
**                          - else 4 bytes of addr are compared.              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpAddr1 - First IP address to be compared           **
**                      : LpAddr2 - Second IP address to be compared          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : SD_TRUE - addresses are equal                       **
**                      : SD_FALSE - Addresses are not equal                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0318                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchIpAddr(
    const TcpIp_SockAddrType * LpAddr1,
    const TcpIp_SockAddrType * LpAddr2)
{
  uint8 LusCount;
  boolean LblMatch;
  LblMatch = SD_TRUE;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
  if (LpAddr1->domain != LpAddr2->domain)
  {
    LblMatch = SD_FALSE;
  }
  else
  {
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    if (TCPIP_AF_INET == LpAddr2->domain)
    {
      for (LusCount = 0; (LusCount < SD_SIX) && (LblMatch == SD_TRUE); LusCount++)
      {
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
        if (LpAddr1->aaSockAddrInetData[LusCount] ==
            LpAddr2->aaSockAddrInetData[LusCount])
        {
          LblMatch = SD_TRUE;
        }
        else
        {
          LblMatch = SD_FALSE;
        }
      }
    }
#if (STD_ON == SD_IPV6_ENABLED)
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (TCPIP_AF_INET6 == LpAddr2->domain)
    {
      for (LusCount = 0; (LusCount < SD_EIGHTTEEN) && (LblMatch == SD_TRUE);
           LusCount++)
      {
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers
                                                  with this orange flag are
        made sure that they are initialized with proper Value " */
        if (LpAddr1->aaSockAddrInetData[LusCount] ==
            LpAddr2->aaSockAddrInetData[LusCount])
        {
          LblMatch = SD_TRUE;
        }
        else
        {
          LblMatch = SD_FALSE;
        }
      }
    }
    else
    {
      LblMatch = SD_FALSE;
    }
#endif
  }
  return (LblMatch);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_MatchIpWildcard                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function matches the IP adddress with wildcard **
**                          - (Comparison is done based on domain).           **
**                              If domain is Ipv4 only 1 byte is compared     **
**                          - else 4 bytes of addr are compared.              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpAddr - Input IP address                           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : SD_TRUE - Match successful                          **
**                      : SD_FALSE - Match not successful                     **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0319                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_MatchIpWildcard(
    const TcpIp_SockAddrType * LpAddr)
{
  uint8 LusCount;
  uint8 LusportCounter;
  uint8 LusipCounter;
  boolean LblMatch;

  LusportCounter = SD_ZERO;
  LusipCounter = SD_ZERO;

  if (TCPIP_AF_INET == LpAddr->domain)
  {
    /*for wildcard port number 2 bytes*/
    for (LusCount = 0; (LusCount < SD_TWO); LusCount++)
    {
      if (SD_ZERO == LpAddr->aaSockAddrInetData[LusCount])
      {
        ++LusportCounter;
      }
      else
      {
        --LusportCounter;
      }
    }

    /*for wildcard ip address 4 bytes*/
    for (LusCount = SD_TWO; (LusCount < SD_SIX); LusCount++)
    {
      if (SD_ZERO == LpAddr->aaSockAddrInetData[LusCount])
      {
        ++LusipCounter;
      }
      else
      {
        --LusipCounter;
      }
    }
    if ((LusportCounter == SD_TWO) && (LusipCounter == SD_FOUR))
    {
      /*ip is wild card*/
      LblMatch = SD_TRUE;
    }
    else
    {
      LblMatch = SD_FALSE;
    }
  }
#if (STD_ON == SD_IPV6_ENABLED)
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (TCPIP_AF_INET6 == LpAddr->domain)
  {
    /*for wildcard port number 2 bytes*/
    for (LusCount = 0; (LusCount < SD_TWO); LusCount++)
    {
      if (SD_ZERO == LpAddr->aaSockAddrInetData[LusCount])
      {
        ++LusportCounter;
      }
      else
      {
        --LusportCounter;
      }
    }

    /*for wildcard ip address 16 bytes*/
    for (LusCount = SD_TWO; (LusCount < SD_EIGHTTEEN); LusCount++)
    {
      if (SD_ZERO == LpAddr->aaSockAddrInetData[LusCount])
      {
        ++LusipCounter;
      }
      else
      {
        --LusipCounter;
      }
    }
    if ((LusportCounter == SD_TWO) && (LusipCounter == SD_SIXTEEN))
    {
      LblMatch = SD_TRUE;
    }
    else
    {
      LblMatch = SD_FALSE;
    }
  }
#endif
  else
  {
    LblMatch = SD_FALSE;
  }
  return (LblMatch);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Ipv6NetmaskToIpAddr                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function converts the netmask from the CIDR    **
**                        notation to the IP address                          **
**                        Care is taken to convert properly for IPv4 and IPv6 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LucNetmask : Netmask in CIDR notation               **
**                      : LblDomainIpv4 : indicates the domain whether IPv4   **
**                      :    or IPv6                                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpIpAddr - The Netmask in Ip Address format         **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID              : SD_SDD_0310                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_Ipv6NetmaskToIpAddr(
    uint8 LucSubnetMask,
    boolean LblDomainIpv4,
    TcpIp_SockAddrInet6Type * LpIp6Addr)
{
  uint32 LulXorValue;
  if (SD_TRUE == LblDomainIpv4)
  {
    LpIp6Addr->domain = TCPIP_AF_INET;
    if (LucSubnetMask == SD_ZERO)
    {
      LpIp6Addr->addr[SD_ZERO] = (uint32)SD_ZERO;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LucSubnetMask < SD_THIRTY_TWO)
    {
      LulXorValue = ((uint32)SD_ONE << ((uint8)(SD_THIRTY_TWO - LucSubnetMask))) - SD_ONE;
      LpIp6Addr->addr[SD_ZERO] = (uint32)(SD_IP_ADDR_MAX ^ LulXorValue);
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
      /*For little endian subnet mask to check ip address in same subnet */
      LpIp6Addr->addr[SD_ZERO] = ~LpIp6Addr->addr[SD_ZERO];
#endif
    }
    else
    {
      LpIp6Addr->addr[SD_ZERO] = (uint32)SD_IP_ADDR_MAX;
    }
  }
#if (STD_ON == SD_IPV6_ENABLED)
  else
  {
    LpIp6Addr->domain = TCPIP_AF_INET6;

    LpIp6Addr->addr[SD_ZERO] = SD_ZERO;
    LpIp6Addr->addr[SD_ONE] = SD_ZERO;
    LpIp6Addr->addr[SD_TWO] = SD_ZERO;
    LpIp6Addr->addr[SD_THREE] = SD_ZERO;

    if (LucSubnetMask <= SD_THIRTY_TWO)
    {
      /*polyspace +4 RTE:SHF [Justified:Low] "Shift operations are within bound" */
      LulXorValue = ((uint32)SD_ONE << ((uint8)(SD_THIRTY_TWO - LucSubnetMask))) - SD_ONE;
      LpIp6Addr->addr[SD_ZERO] = (uint32)(SD_IP_ADDR_MAX ^ LulXorValue);
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
      /*For little endian subnet mask to check ip address in same subnet */
      LpIp6Addr->addr[SD_ZERO] = ~LpIp6Addr->addr[SD_ZERO];
#endif
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LucSubnetMask <= SD_SIXTY_FOUR)
    {
      LpIp6Addr->addr[SD_ZERO] = SD_IP_ADDR_MAX;
      LulXorValue = ((uint32)SD_ONE << ((uint8)(SD_SIXTY_FOUR - LucSubnetMask))) - SD_ONE;
      LpIp6Addr->addr[SD_ONE] = (uint32)(SD_IP_ADDR_MAX ^ LulXorValue);
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LucSubnetMask <= SD_NINETY_SIX)
    {
      LpIp6Addr->addr[SD_ZERO] = SD_IP_ADDR_MAX;
      LpIp6Addr->addr[SD_ONE] = SD_IP_ADDR_MAX;
      LulXorValue = ((uint32)SD_ONE << ((uint8)(SD_NINETY_SIX - LucSubnetMask))) - SD_ONE;
      LpIp6Addr->addr[SD_TWO] = (uint32)(SD_IP_ADDR_MAX ^ LulXorValue);
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LucSubnetMask <= SD_ONE_TWENTY_EIGHT)
    {
      LpIp6Addr->addr[SD_ZERO] = SD_IP_ADDR_MAX;
      LpIp6Addr->addr[SD_ONE] = SD_IP_ADDR_MAX;
      LpIp6Addr->addr[SD_TWO] = SD_IP_ADDR_MAX;
      LulXorValue = ((uint32)SD_ONE << ((uint8)(SD_ONE_TWENTY_EIGHT - LucSubnetMask))) - SD_ONE;
      LpIp6Addr->addr[SD_THREE] = (uint32)(SD_IP_ADDR_MAX ^ LulXorValue);
    }
    else
    {
      LpIp6Addr->addr[SD_ZERO] = SD_IP_ADDR_MAX;
      LpIp6Addr->addr[SD_ONE] = SD_IP_ADDR_MAX;
      LpIp6Addr->addr[SD_TWO] = SD_IP_ADDR_MAX;
      LpIp6Addr->addr[SD_THREE] = SD_IP_ADDR_MAX;
    }
  }
#endif
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_CheckSubnetV4                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks whether the received options   **
**                        are within the Subnet of the instance[SWS_SD_00688] **
**                        If the IP addr is NULL (Not present) it is not      **
**                          checked against the subnet and returns E_OK       **
**                        This function checks for IPv4 addresses             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0265                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static Std_ReturnType Sd_CheckSubnetV4(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpOptionTcpAddr,
    const TcpIp_SockAddrType * LpOptionUdpAddr,
    uint8 LucOptionsCode)
{
  Std_ReturnType LddReturnValue;
  uint32 LulAddr;
  uint32 LulSubnetAddr;
  TcpIp_SockAddrType const* 
  LpIp4Addr;
  if (SD_TCP_OPTIONS_MASK != (LucOptionsCode & SD_TCP_OPTIONS_MASK))
  {
    LddReturnValue = E_OK;
  }
  else
  {
    LpIp4Addr = LpOptionTcpAddr;
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)
    /* Reverse TCP */
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_FIVE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FOUR];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_THREE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_TWO];

#else
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_TWO];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_THREE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FOUR];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FIVE];
#endif

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*redmine #67769, 67368 */
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LulSubnetAddr = LpInstance->stSubnetAddr.aaSockAddrInetData[SD_TWO];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_THREE];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FOUR];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FIVE];
#else
    /*redmine #52726 */
    LulSubnetAddr = LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FIVE];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FOUR];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_THREE];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_TWO];
#endif
    /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be true when
      the LpIp4Addr->domain is not  equal to TCPIP_AF_INET this posible for Ipv6
       type domain .*/
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    if (LpIp4Addr->domain != TCPIP_AF_INET)
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /*SWS_SD_00720*/

      LddReturnValue = Sd_Ipv4Lengthcheck(LpInstanceStatic,
                                          LpInstance, LulSubnetAddr, LulAddr);
    }
    /* [SWS_SD_00688] */
    /*LogicAnalyser WRN04: Manually Verified*/
  }
  if ((E_OK == LddReturnValue) &&
      (SD_UDP_OPTIONS_MASK != (LucOptionsCode & SD_UDP_OPTIONS_MASK)))
  {
    LddReturnValue = E_OK;
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (E_OK == LddReturnValue)
  {
    LpIp4Addr = LpOptionUdpAddr;
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)
    /*Reverse UDP*/
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
    LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_FIVE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FOUR];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_THREE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_TWO];

#else
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_TWO];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_THREE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FOUR];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FIVE];
#endif

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*redmine #52726 */
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
    LulSubnetAddr = LpInstance->stSubnetAddr.aaSockAddrInetData[SD_TWO];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_THREE];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FOUR];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FIVE];
#else
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    1 LulSubnetAddr = LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FIVE];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_FOUR];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_THREE];
    LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                    LpInstance->stSubnetAddr.aaSockAddrInetData[SD_TWO];
#endif
    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be true when
      the LpIp4Addr->domain is not  equal to TCPIP_AF_INET this posible for Ipv6 type domain .*/
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    if (LpIp4Addr->domain != TCPIP_AF_INET)
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      /* [SWS_SD_00688] */
      /* [SWS_SD_00720] */
      LddReturnValue = Sd_Ipv4Lengthcheck(LpInstanceStatic,
                                          LpInstance, LulSubnetAddr, LulAddr);
    }
    /* [SWS_SD_00688] [SD_SRS_478] [SWS_SD_00688b]*/
    /*LogicAnalyser WRN04: Manually Verified*/
  }
  else
  {
    /*Do Nothing */
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_CheckSubnetV6                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks whether the received options   **
**                        are within the Subnet of the instance[SWS_SD_00688] **
**                        If the IP addr is NULL (Not present) it is not      **
**                          checked against the subnet and returns E_OK       **
**                        This function checks for IPv6 addresses             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID              : SD_SDD_0266                                       **
*******************************************************************************/
#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
static Std_ReturnType Sd_CheckSubnetV6(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpOptionTcpAddr,
    const TcpIp_SockAddrType * LpOptionUdpAddr,
    uint8 LucOptionsCode)
{
  Std_ReturnType LddReturnValue;
  uint32 LulAddr;
  uint32 LulSubnetAddr;
  uint16 LusIndex;
  uint16 LusLocalAdressCheckLength;
#if (STD_ON == SD_IPV6_ENABLED)
  TcpIp_SockAddrType const* 
  LpIp6Addr;
  uint16 LucLoopCount;
  uint16 LucRemBits;
  uint32 LaaAddrMask[SD_FOUR];
  uint8 LucCount;
#endif
  LusLocalAdressCheckLength =
      LpInstanceStatic->usSdInstanceLocalAdressCheckLength;
  if (SD_TCP_OPTIONS_MASK != (LucOptionsCode & SD_TCP_OPTIONS_MASK))
  {
    LddReturnValue = E_OK;
  }
  else
  {
    LpIp6Addr = LpOptionTcpAddr;
    /*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +10 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    if (LpIp6Addr->domain != TCPIP_AF_INET6)
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      LucLoopCount = LusLocalAdressCheckLength / SD_THIRTY_TWO;
      LucRemBits = LusLocalAdressCheckLength % SD_THIRTY_TWO;

      for (LucCount = SD_ZERO; LucCount < SD_FOUR; LucCount++)
      {
        if (LucCount < LucLoopCount)
        {
          LaaAddrMask[LucCount] = SD_THIRTY_TWO_SET_BIT;
        }
        else
        {
          LaaAddrMask[LucCount] = SD_ZERO;
        }
        if ((LucLoopCount != SD_FOUR) && (LucLoopCount != SD_ZERO))
        {
          LaaAddrMask[LucCount] = ~(SD_THIRTY_TWO_SET_BIT >> LucRemBits);
        }
      }
      LddReturnValue = E_OK;
      LusIndex = SD_EIGHTTEEN;
      for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
      { /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
        LusIndex--;
        LulAddr = (uint32)LpIp6Addr->aaSockAddrInetData[LusIndex];
        LulSubnetAddr = LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];
        /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
            made sure that they are within their range by having necessary boundary
            checks in order to prevent them from being illegally dereferenced." */
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
              made sure that they are initialized with proper Value " */
        LusIndex--;
        LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                  LpIp6Addr->aaSockAddrInetData[LusIndex];
        LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                        LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];
        /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
            made sure that they are within their range by having necessary boundary
            checks in order to prevent them from being illegally dereferenced." */
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
              made sure that they are initialized with proper Value " */
        LusIndex--;
        LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                  LpIp6Addr->aaSockAddrInetData[LusIndex];
        LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                        LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];
        /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
        /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
        LusIndex--;
        LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                  LpIp6Addr->aaSockAddrInetData[LusIndex];
        LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                        LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];

        /* [SWS_SD_00688] */
        /* [SWS_SD_00720] */
        LddReturnValue = Sd_Ipv6Lengthcheck(LpInstanceStatic, LpInstance,
                                            LulSubnetAddr, LulAddr, LaaAddrMask, LucCount);
      }
    }
  }

  if ((E_OK == LddReturnValue) &&
      (SD_UDP_OPTIONS_MASK != (LucOptionsCode & SD_UDP_OPTIONS_MASK)))
  {

    LddReturnValue = E_OK;
  }
  else
  {
    if (E_OK == LddReturnValue)
    { /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LpIp6Addr = LpOptionUdpAddr;
      if (LpIp6Addr->domain != TCPIP_AF_INET6)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        LucLoopCount = LusLocalAdressCheckLength / SD_THIRTY_TWO;
        LucRemBits = LusLocalAdressCheckLength % SD_THIRTY_TWO;

        for (LucCount = SD_ZERO; LucCount < SD_FOUR; LucCount++)
        {
          if (LucCount < LucLoopCount)
          {
            LaaAddrMask[LucCount] = SD_THIRTY_TWO_SET_BIT;
          }
          else
          {
            LaaAddrMask[LucCount] = SD_ZERO;
          }
          if ((LucLoopCount != SD_FOUR) && (LucLoopCount != SD_ZERO))
          {
            LaaAddrMask[LucCount] = ~(SD_THIRTY_TWO_SET_BIT >> LucRemBits);
          }
        }
        LddReturnValue = E_OK;
        LusIndex = SD_EIGHTTEEN;
        for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
        {
          /* [SWS_SD_00688]*/
          /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LulAddr = (uint32)LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSubnetAddr = LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];
          /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                          LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];
          /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                          LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];
          /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSubnetAddr = (uint32)(LulSubnetAddr << SD_EIGHT) |
                          LpInstance->stSubnetAddr.aaSockAddrInetData[LusIndex];

          LddReturnValue = Sd_Ipv6Lengthcheck(LpInstanceStatic,
                                              LpInstance, LulSubnetAddr, LulAddr, LaaAddrMask, LucCount);
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
** Function Name        : Sd_CheckSubnet                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks whether the received options   **
**                        are within the Subnet of the instance[SWS_SD_00688] **
**                       If the IP addr is NULL (Not present) it is not       **
**                          checked against the subnet and returns E_OK       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : Sd_CheckSubnetV4              **
**                          Sd_CheckSubnetV6                                  **
**                                                                            **
** Design ID            : SD_SDD_0264                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_CheckSubnet(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpOptionTcpAddr,
    const TcpIp_SockAddrType * LpOptionUdpAddr,
    uint8 LucOptionsCode)
{
  Std_ReturnType LddReturnValue;
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
    the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
  if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
  {
    LddReturnValue = Sd_CheckSubnetV4(LpInstance, LpInstanceStatic, LpOptionTcpAddr,
                                      LpOptionUdpAddr, LucOptionsCode);
  }
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be false when
    the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
  else
#if (STD_ON == SD_IPV6_ENABLED)
  {
    LddReturnValue = Sd_CheckSubnetV6(LpInstance,
                                      LpInstanceStatic, LpOptionTcpAddr,
                                      LpOptionUdpAddr, LucOptionsCode);
  }
#else
  {
    LddReturnValue = E_NOT_OK;
  }
#endif

  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_Ipv6LoadData                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function loads the Ipv6 Domain, port and       **
                          Address from Input pointer to output pointer.       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInput : Pointer to input data                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpOutput : Pointer to output data                   **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0341                                         **
*******************************************************************************/
#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_Ipv6LoadData(
    const Sd_OptionsDataType * LpInData,
    TcpIp_SockAddrType * LpOutData)
{
  uint16 LusPort;
  uint32 LulAddr;
  uint16 LusCount;
  uint16 LusIndex;

  LpOutData->domain = TCPIP_AF_INET6;
  /*[SWS_SD_00415] */
  LusPort = (LpInData->unOptionsData).stOptionsIpv6.usPortNo;
  LpOutData->aaSockAddrInetData[SD_ZERO] = (uint8)LusPort;
  LpOutData->aaSockAddrInetData[SD_ONE] = (uint8)((LusPort) >> SD_EIGHT);

  /* Load 128 bit address */
  LusIndex = SD_ONE;

  for (LusCount = SD_ZERO; LusCount < SD_FOUR; LusCount++)
  {
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (LpInData->unOptionsData).stOptionsIpv6.pIpAddr[LusCount];

    LusIndex++;
    LpOutData->aaSockAddrInetData[LusIndex] = (uint8)(LulAddr);
    LusIndex++;
    LpOutData->aaSockAddrInetData[LusIndex] =
        (uint8)((LulAddr) >> SD_EIGHT);
    LusIndex++;
    LpOutData->aaSockAddrInetData[LusIndex] =
        (uint8)((LulAddr) >> SD_SIXTEEN);
    LusIndex++;
    LpOutData->aaSockAddrInetData[LusIndex] =
        (uint8)((LulAddr) >> SD_TWENTY_FOUR);
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_GetEvHandlerSubGrpIndex                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the event handler sub      **
**                        group depending on the received remote address and  **
**                        counter fields.                                     **
**                        If not found, it stores the received remote         **
**                        address and counter in a new location and returns   **
**                        it's index.                                         **
**                        If all indexes are full, it returns appropriate     **
**                        code.                                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEvHandlerStatic - Pointer to Static Event Handler **
**                          structure                                         **
**                      : LpRemoteAddr - Pointer to Remote address of SD      **
**                          message recd                                      **
**                      : LucCounterIn - This is the Counter received in the  **
**                          Subscribe/ Stop Subscribe entry                   **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpEvhandlerSubGrpIndex - This is the pointer to     **
**                          the event handler subscribed group index          **
**                                                                            **
** Return parameter     : uint8 - LucSubGrpReturnCode                         **
**                        0x00 - SD_MATCHED_AND_EXISTING                      **
**                        0x01 - SD_NOT_MATCHED_AND_FREE                      **
**                        0x02 - SD_NOT_MATCHED_AND_NOT_FREE                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandlerSubGrp         **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr, Sd_CopyIpAddr **
**                                                                            **
** Design ID            : SD_SDD_0160                                         **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_GetEvHandlerSubGrpIndex(
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucCounterIn,
    Sd_ServicesType * LpEvhandlerSubGrpIndex)
{
  uint16 LusBaseIndex;
  uint16 LusCount;
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp;
  boolean LblBreak;
  boolean LblMatch;
  uint8 LucSubGrpReturnCode;
  /*[SWS_SD_00291] */
  /*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  LblBreak = FALSE;
  LusBaseIndex = (uint16)(LpEvHandlerStatic->usEvHandlerSelfIndex) *
                 SD_MAX_EVENT_SUB_GROUPS;
  LucSubGrpReturnCode = SD_NOT_MATCHED_AND_NOT_FREE;
  *LpEvhandlerSubGrpIndex = (Sd_ServicesType)LusBaseIndex;
  for (LusCount = LusBaseIndex;
       (LusCount < (LusBaseIndex + SD_MAX_EVENT_SUB_GROUPS)) && (SD_FALSE == LblBreak); LusCount++)
  {
    /*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
    LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount];
    if ((SD_TRUE == LpEvHandlerSubGrp->stEvHandlerFlag.blTcpActiveEv) ||
        (SD_TRUE == LpEvHandlerSubGrp->stEvHandlerFlag.blUdpActiveEv))
    {
      if (LucCounterIn == LpEvHandlerSubGrp->ucSubGrpCounter)
      {
        LblMatch = Sd_MatchIpAddr(LpRemoteAddr,
                                  &LpEvHandlerSubGrp->LstSubGrpRemoteAddr);
        if (SD_TRUE == LblMatch)
        {
          *LpEvhandlerSubGrpIndex = (Sd_ServicesType)LusCount;
          LucSubGrpReturnCode = SD_MATCHED_AND_EXISTING;
          LblBreak = SD_TRUE;
        }
      }
    }
  }

  if (SD_MATCHED_AND_EXISTING != LucSubGrpReturnCode)
  {
    LblBreak = SD_FALSE;
    for (LusCount = LusBaseIndex;
         (LusCount < (LusBaseIndex + SD_MAX_EVENT_SUB_GROUPS)) && (SD_FALSE == LblBreak); LusCount++)
    {
      LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount];
      if ((SD_FALSE == LpEvHandlerSubGrp->stEvHandlerFlag.blTcpActiveEv) &&
          (SD_FALSE == LpEvHandlerSubGrp->stEvHandlerFlag.blUdpActiveEv))
      {

        *LpEvhandlerSubGrpIndex = (Sd_ServicesType)LusCount;
        LucSubGrpReturnCode = SD_NOT_MATCHED_AND_FREE;

        LpEvHandlerSubGrp->ucSubGrpCounter = LucCounterIn;
        Sd_CopyIpAddr(&LpEvHandlerSubGrp->LstSubGrpRemoteAddr, LpRemoteAddr);
        LblBreak = SD_TRUE;
      }
    }
  }
  return (LucSubGrpReturnCode);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_GetSessionIdAndFlag                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function determines the session ID and reboot  **
**                        flag to be transmitted based on the remote address. **
**                        If there is no match. It creates a session id of    **
**                        0x001 for a new cummuincation partner and stores    **
**                        the remote address in the structure.                **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LblUnicast - SD_TRUE if transmission is unicast     **
**                         else SD_FALSE for multicast                        **
**                      : LpRemoteAddr - Pointer to Remote address of SD      **
**                          message recd                                      **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : LpSessionId - This is the pointer to the session ID **
**                          to transmit                                       **
**                      : LpRebootFlag - This is the pointer to the reboot    **
**                          flag to transmit                                  **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstancePartner         **
**                        Function(s) invoked : SoAd_IfTransmit               **
**                          Sd_MatchIpAddr, Sd_CopyIpAddr                     **
**                                                                            **
** Design ID              : SD_SDD_0274                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetSessionIdAndFlag(
    Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    boolean LblUnicast,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint16 * LpSessionId,
    boolean * LpRebootFlag)
{
  Sd_InstancePartnerType * LpInstancePartner;
  uint16 LusCount;
  uint16 LusBaseIndex;
  boolean LblBreak;
  boolean LblMatch;
  /*[SWS_SD_00035] , [SWS_SD_00036] , [SWS_SD_00150] , [SWS_SD_00151]*/

  if (SD_FALSE == LblUnicast)
  {
    /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    *LpSessionId = LpInstance->usMulticastSessionIdTx;
    *LpRebootFlag = LpInstance->blMulticastRebootFlagTx;

    if (SD_SESSION_ID_MAX == LpInstance->usMulticastSessionIdTx)
    {
      LpInstance->usMulticastSessionIdTx = SD_ONE;
      LpInstance->blMulticastRebootFlagTx = SD_FALSE;
    }
    else
    {
      LpInstance->usMulticastSessionIdTx++;
    }
  }
  else
  {
    LblBreak = SD_FALSE;
    LblMatch = SD_FALSE;

    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    LusBaseIndex = (uint16)(LpInstanceStatic->ucInstanceSelfIndex) *
                   SD_MAX_INSTANCE_PARTNER;
    for (LusCount = LusBaseIndex;
         (LusCount < (LusBaseIndex + SD_MAX_INSTANCE_PARTNER)) &&
         (SD_FALSE == LblBreak);
         LusCount++)
    {
      /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
      LpInstancePartner = &Sd_GaaInstancePartner[LusCount];
      if (SD_TRUE == LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive)
      {
        LblMatch = Sd_MatchIpAddr(LpRemoteAddr,
                                  &LpInstancePartner->stRemoteAddr);
        if (SD_TRUE == LblMatch)
        {
          /* Send the outputs */
          *LpSessionId = LpInstancePartner->usUnicastSessionIdTx;
          *LpRebootFlag = LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagTx;

          if (SD_SESSION_ID_MAX == LpInstancePartner->usUnicastSessionIdTx)
          {
            LpInstancePartner->usUnicastSessionIdTx = SD_ONE;

            LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagTx = SD_FALSE;
          }
          else
          {
            LpInstancePartner->usUnicastSessionIdTx =
                LpInstancePartner->usUnicastSessionIdTx + SD_ONE;
          }
          LblBreak = SD_TRUE;
        }
      }
    }

    if (SD_FALSE == LblMatch)
    {
      for (LusCount = LusBaseIndex;
           (LusCount < (LusBaseIndex + SD_MAX_INSTANCE_PARTNER)) &&
           (SD_FALSE == LblBreak);
           LusCount++)
      {
        LpInstancePartner = &Sd_GaaInstancePartner[LusCount];

        if (SD_FALSE == LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive)
        {

          LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive = SD_TRUE;
          Sd_CopyIpAddr(&LpInstancePartner->stRemoteAddr, LpRemoteAddr);
          *LpSessionId = LpInstancePartner->usUnicastSessionIdTx;
          *LpRebootFlag = LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagTx;
          LpInstancePartner->usUnicastSessionIdTx =
              LpInstancePartner->usUnicastSessionIdTx + SD_ONE;
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_DetectRebootSingle                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function detects the reboot for a single       **
**                          Instance Partner as per [SWS_SD_00688]            **
**                        It detects for Unicast as well as Multicast         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstancePartner - Pointer to Instance Partner     **
**                          structure                                         **
**                      : LblUnicast - Indicates whether the frame was recd   **
**                          via unicast or multicast                          **
**                      : LusSessionIdRecd - The session ID received in the   **
**                          input frame                                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                      : LblRebootFlagRecd - This is SD_TRUE if the reboot   **
**                           flag received was '1' else SD_FALSE              **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType : E_OK - Reboot not detected         **
**                      : E_NOT_OK - Reboot detected                          **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID              : SD_SDD_0273                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
static Std_ReturnType Sd_DetectRebootSingle(
    Sd_InstancePartnerType * LpInstancePartner,
    boolean LblUnicast,
    uint16 LusSessionIdRecd,
    boolean LblRebootFlagRecd)
{
  Std_ReturnType LddReturnValue;
  /* [SWS_SD_00446] */
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  if (SD_TRUE == LblUnicast)
  {
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    if ((SD_TRUE == LblRebootFlagRecd) &&
        (SD_FALSE == LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagRecd))
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    else if ((SD_TRUE == LblRebootFlagRecd) &&
             (LusSessionIdRecd < LpInstancePartner->usUnicastSessionIdRecd))
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      LddReturnValue = E_OK;
    }

    LpInstancePartner->usUnicastSessionIdRecd = LusSessionIdRecd;
    LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagRecd = LblRebootFlagRecd;
  }
  else
  {
    if ((SD_TRUE == LblRebootFlagRecd) &&
        (SD_FALSE == LpInstancePartner->stInstancePartnerFlag.blMulticastRebootFlagRecd))
    {
      LddReturnValue = E_NOT_OK;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if ((SD_TRUE == LblRebootFlagRecd) &&
             (LusSessionIdRecd < LpInstancePartner->usMulticastSessionIdRecd))
    {
      LddReturnValue = E_NOT_OK;
    }
    else
    {
      LddReturnValue = E_OK;
    }

    LpInstancePartner->usMulticastSessionIdRecd = LusSessionIdRecd;
    LpInstancePartner->stInstancePartnerFlag.blMulticastRebootFlagRecd = LblRebootFlagRecd;
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_DetectReboot                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function detects reboot using the session ID   **
**                        and remote address. If no reboot, returns E_OK,     **
**                        else if reboot detected returns E_NOT_OK.           **
**                        If the remote address is matched, it will detect    **
**                        reboot based on the unicast, session id recd and    **
**                        reboot flag recd                                    **
**                        If the remote address is not matched, it will find  **
**                        an inactive structure, store the remote address,    **
**                        session Id and reboot flag recd and set the         **
**                        instance partner as active                          **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpRemoteAddr - Pointer to the remote address recd   **
**                          for the input frame                               **
**                      : LblUnicast - Indicates whether the frame was recd   **
**                          via unicast or multicast                          **
**                      : LusSessionIdRecd - The session ID received in the   **
**                          input frame                                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                      : LblRebootFlagRecd - This is SD_TRUE if the reboot   **
**                           flag received was '1' else SD_FALSE              **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType : E_OK - Reboot not detected         **
**                      : E_NOT_OK - Reboot detected                          **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstancePartner         **
**                                                                            **
**                        Function(s) invoked : Sd_DetectRebootSingle         **
**                          Sd_MatchIpAddr, Sd_CopyIpAddr                     **
**                                                                            **
** Design ID              : SD_SDD_0272                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_DetectReboot(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpRemoteAddr,
    boolean LblUnicast,
    uint16 LusSessionIdRecd,
    boolean LblRebootFlagRecd)
{
  /*[SWS_SD_00445], [SWS_SD_00446][SWS_SD_00446b][SWS_SD_00447], [SWS_SD_00448]
  [SWS_SD_00153], [SWS_SD_00154 ] [SWS_SD_00156]*/
  uint16 LusCount;
  uint16 LusBaseIndex;
  boolean LblBreak;
  boolean LblMatch;
  Std_ReturnType LddReturnValue;
  Sd_InstancePartnerType * LpInstancePartner;

  LddReturnValue = E_OK;
  LusBaseIndex = (uint16)(LpInstanceStatic->ucInstanceSelfIndex) *
                 SD_MAX_INSTANCE_PARTNER;
  LblBreak = SD_FALSE;
  LblMatch = SD_FALSE;
  for (LusCount = LusBaseIndex;
       (LusCount < (LusBaseIndex + SD_MAX_INSTANCE_PARTNER)) &&
       (SD_FALSE == LblBreak);
       LusCount++)
  {
    LpInstancePartner = &Sd_GaaInstancePartner[LusCount];
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being illegally dereferenced." */
    if (SD_TRUE == LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive)
    {
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LblMatch = Sd_MatchIpAddr(LpRemoteAddr,
                                &LpInstancePartner->stRemoteAddr);
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      if (SD_TRUE == LblMatch)
      {
        LddReturnValue = Sd_DetectRebootSingle(LpInstancePartner, LblUnicast,
                                               LusSessionIdRecd, LblRebootFlagRecd);
        LblBreak = SD_TRUE;
      }
    }
  }

  if (SD_FALSE == LblMatch)
  {
    LblBreak = SD_FALSE;
    for (LusCount = LusBaseIndex;
         (LusCount < (LusBaseIndex + SD_MAX_INSTANCE_PARTNER)) &&
         (SD_FALSE == LblBreak);
         LusCount++)
    {
      LpInstancePartner = &Sd_GaaInstancePartner[LusCount];

      if (SD_FALSE == LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive)
      {
        LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive = SD_TRUE;

        LddReturnValue = E_OK;

        Sd_CopyIpAddr(&LpInstancePartner->stRemoteAddr, LpRemoteAddr);
        if (SD_TRUE == LblUnicast)
        {
          LpInstancePartner->usUnicastSessionIdRecd = LusSessionIdRecd;
          LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagRecd = LblRebootFlagRecd;
        }
        else
        {
          LpInstancePartner->usMulticastSessionIdRecd = LusSessionIdRecd;
          LpInstancePartner->stInstancePartnerFlag.blMulticastRebootFlagRecd = LblRebootFlagRecd;
        }
        LblBreak = SD_TRUE;
      }
    }
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_RebootActions                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called after reboot is detected.   **
**                        It performs the actions to be performed under       **
**                        reboot                                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientService,          **
**                          Sd_GaaClientServiceStatic, Sd_GaaServerService,   **
**                          Sd_GaaServerServiceStatic, Sd_GaaEvHandler,       **
**                          Sd_GaaEvHandlerStatic, Sd_GaaEvHandlerSubGrp      **
**                                                                            **
**                        Function(s) invoked : Sd_StopOfferRecdActions       **
**                          Sd_RemoveClientFromFanout, Sd_MatchIpAddr         **
**                          BswM_Sd_EventHandlerCurrentState                  **
**                                                                            **
** Design ID              : SD_SDD_0275                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#if (STD_OFF == SD_EV_HANDLER_CONFIGURED) && (STD_OFF == SD_CLIENT_CONFIGURED)
void Sd_RebootActions(
    const Sd_InstanceStaticType * LpInstanceStatic)
#else
void Sd_RebootActions(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const TcpIp_SockAddrType * LpRemoteAddr)
#endif
{
#if (STD_ON == SD_SERVER_CONFIGURED)
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  const Sd_ServerServiceStaticType * LpServerServiceStatic;
  Sd_EvHandlerType * LpEvHandler;
  const Sd_EvHandlerStaticType * LpEvHandlerStatic;
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp;
#endif
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
  Sd_ClientServiceType * LpClientService;
  const Sd_ClientServiceStaticType * LpClientServiceStatic;
#endif

#if (STD_ON == SD_SERVER_CONFIGURED) || (STD_ON == SD_CLIENT_CONFIGURED)
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  uint16 LusCount;
#endif
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  uint16 LusBaseIndex2;
  uint16 LusNoOfElements2;
  uint16 LusCount2;
  uint16 LusBaseIndex3;
  uint16 LusNoOfElements3;
  uint16 LusCount3;
#endif
#if (STD_ON == SD_EV_HANDLER_CONFIGURED) || (STD_ON == SD_CLIENT_CONFIGURED)
  boolean LblMatch;
#endif

  /* [SWS_SD_00448] [SWS_SD_00448a] [SWS_SD_00448b]  */

#if (STD_ON == SD_CLIENT_CONFIGURED)
  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;
  LusNoOfElements = LpInstanceStatic->usNoOfClientServices;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
       LusCount++)
  {
    LpClientService = &Sd_GaaClientService[LusCount];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount);
#endif
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    if ((SD_TRUE == LpClientService->stClientFlag.blTcpActive) ||
        (SD_TRUE == LpClientService->stClientFlag.blUdpActive))
    {

      LblMatch = Sd_MatchIpAddr(LpRemoteAddr,
                                &LpClientService->stOfferRemoteAddr);
      if (SD_TRUE == LblMatch)
      {

        Sd_StopOfferRecdActions(LpClientService,
                                LpClientServiceStatic);
      }
    }
  }
#endif

/*  SWS_SD_00345  [SWS_SD_00345b] */
#if (STD_ON == SD_SERVER_CONFIGURED)
  LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;
  LusNoOfElements = LpInstanceStatic->usNoOfServerServices;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
       LusCount++)
  {

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)

#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
    LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount);
    LusBaseIndex2 = LpServerServiceStatic->usBaseEvHandlerIndex;
    LusNoOfElements2 = LpServerServiceStatic->usNoOfEvHandlers;
#else
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];
    /*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    LusBaseIndex2 = LpServerServiceStatic->usBaseEvHandlerIndex;
    LusNoOfElements2 = LpServerServiceStatic->usNoOfEvHandlers;
#endif

    for (LusCount2 = LusBaseIndex2; LusCount2 <
                                    (LusBaseIndex2 + LusNoOfElements2);
         LusCount2++)
    {
      LpEvHandler = &Sd_GaaEvHandler[LusCount2];

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount2];
#else
      LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount2);
#endif
      /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      LusBaseIndex3 = (uint16)LpEvHandlerStatic->usEvHandlerSelfIndex *
                      SD_MAX_EVENT_SUB_GROUPS;
      LusNoOfElements3 = SD_MAX_EVENT_SUB_GROUPS;
      for (LusCount3 = LusBaseIndex3;
           LusCount3 < (LusBaseIndex3 + LusNoOfElements3); LusCount3++)
      {
        /*polyspace +6 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
        LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount3];

        if ((SD_TRUE == LpEvHandlerSubGrp->stEvHandlerFlag.blTcpActiveEv) ||
            (SD_TRUE == LpEvHandlerSubGrp->stEvHandlerFlag.blUdpActiveEv))
        {
          LblMatch = Sd_MatchIpAddr(LpRemoteAddr,
                                    &LpEvHandlerSubGrp->LstSubGrpRemoteAddr);
          if (SD_TRUE == LblMatch)
          {
            /*polyspace +6 RTE:IDP [Justified:Low] "Pointers with this orange flag are
              made sure that they are within their range by having necessary boundary
              checks in order to prevent them from being illegally dereferenced." */
            LpEvHandlerSubGrp->ulEvSubGrpTtlCount = SD_ZERO;
            Sd_RemoveClientFromFanout(LpEvHandler, LpEvHandlerStatic,
                                      LpEvHandlerSubGrp);
            if ((SD_ZERO == LpEvHandler->ucNoOfSubGrpsTcp) &&
                (SD_ZERO == LpEvHandler->ucNoOfSubGrpsUdp))
            {
              LpEvHandler->enEvHandlerCurrState =
                  SD_EVENT_HANDLER_RELEASED;
              BswM_Sd_EventHandlerCurrentState(
                  LpEvHandlerStatic->usHandleId,
                  LpEvHandler->enEvHandlerCurrState);
            }
          }
        }
      }
      /*7.3.6 Flags field update*/
      if (LpServerServiceStatic->pTcpSoConGrp != SD_NULL_PTR)
      {
        LusBaseIndex = LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
        LusNoOfElements = LpServerServiceStatic->pTcpSoConGrp->usNoOfSockets;
        for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
             LusCount++)
        {
          /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
                made sure that they are within their range by having necessary boundary
                checks in order to prevent them from being out of bounds." */
          if (SD_TRUE == Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened)
          {
            (void)SoAd_CloseSoCon(Sd_GaaSoConId[LusCount], (boolean)SD_TRUE);
            (void)SoAd_OpenSoCon(Sd_GaaSoConId[LusCount]);
          }
        }
      }
    }
#endif
  }
#endif
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_RxIndicationProcessEntry                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function processes a single entry for receptn  **
**                          It calls a switch to call the appropriate         **
**                          reception functions of Sd                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpEntry - Pointer to Entry structure                **
**                      : LpRemoteAddr - Pointer to remote address recd       **
**                      : LpSduDataPtr - Pointer to the SDU data received in  **
**                          the RxIndication function                         **
**                      : LucNoOfOptions - The number of options in the       **
**                          incoming frame                                    **
**                      : LucNoOfEntries - The number of entries in the       **
**                          incoming frame                                    **
**                      : LblUnicast - Boolean indicating whether the         **
**                          incoming frame was received by unicast or         **
**                          multicast                                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaRxOptionsData           **
**                                                                            **
**                        Function(s) invoked : Sd_FindRecd, Sd_OfferRecd     **
**                          Sd_SubscribeRecd, Sd_StopSubscribeRecd,           **
**                          Sd_SubscribeAckRecd, Sd_SubscribeNackRecd         **
**                                                                            **
** Design ID              : SD_SDD_0237                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_RxIndicationProcessEntry(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntry,
    const TcpIp_SockAddrType * LpRemoteAddr,
    const uint8 LpSduDataPtr[],
    uint8 LucNoOfOptions,
    uint8 LucNoOfEntries,
    boolean LblUnicast)
{

#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
  uint8 LucReturncode;
  LucReturncode = SD_ZERO;
  if (Sd_GaaAclPolicyFlag == SD_TRUE)
  {
    LucReturncode = SD_ZERO;
  }
#else
#if (STD_ON == SD_CLIENT_CONFIGURED)
  uint8 LucReturncode;
  LucReturncode = SD_THREE;
#else
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  uint8 LucReturncode;
  LucReturncode = SD_THREE;
#endif
#endif

#endif
  /*SWS_SD_00040*/
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  switch (LpEntry->enTypeOfEntry)
  {
  case SD_FIND_SERVICE_ENTRY:
  {
#if (STD_ON == SD_SERVER_CONFIGURED)
    (void)Sd_FindRecd(LpInstanceStatic, LpEntry,
                      LpRemoteAddr, Sd_GaaRxOptionsData);
#endif
    break;
  }

  case SD_OFFER_SERVICE_ENTRY:
  {
#if (STD_ON == SD_CLIENT_CONFIGURED)

    /*[SWS_Sd_00765]{DRAFT} dIn ClientService, if the ACL SdClientServiceAllowedProvider is not configured, the ACL check shall be disabled for this ClientService.c*/
    if (Sd_GaaAclPolicyFlag == SD_TRUE)
    {
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
      LucReturncode = Sd_AcL_IP_Client_policy_Check(LpInstance,
                                                    LpInstanceStatic, LpEntry, Sd_GaaRxOptionsData,
                                                    LucNoOfOptions, LpRemoteAddr, LblUnicast);
#endif

#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
      if (LucReturncode != SD_NO_IDSM_EVENT)
      {

        /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
        /*PRQA S 3112 3 */
        if (LucReturncode == SD_SOME_IP_ACL_CHECK_FAILED_OFFER)
        {
          IdsM_SetSecurityEvent(SD_SEV_SOME_IP_ACL_CHECK_FAILED_OFFER);
        }
        if (LucReturncode == SD_DUPLICATE_OFFER)
        {
          IdsM_SetSecurityEvent(SD_SEV_DUPLICATE_OFFER);
        }
      }

#else
      if (LucReturncode == SD_ZERO)
      {
        SD_UNUSED(LblUnicast);
        SD_UNUSED(LpInstance);
        SD_UNUSED(LucNoOfOptions);
      }
      else
      { /*Do Nothing*/
      }

#endif
    }
    else
    {
      (void)Sd_OfferRecd(LpInstance, LpInstanceStatic, LpEntry,
                         Sd_GaaRxOptionsData, LucNoOfOptions, LpRemoteAddr, LblUnicast, LucReturncode);
    }

#else
    /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
    /*PRQA S 3112 3 */
    SD_UNUSED(LblUnicast);
    SD_UNUSED(LpInstance);
    SD_UNUSED(LucNoOfOptions);
#endif
    break;
  }

  case SD_STOP_OFFER_SERVICE_ENTRY:
  {
#if (STD_ON == SD_CLIENT_CONFIGURED)
    (void)Sd_StopOfferRecd(LpInstanceStatic, LpEntry, Sd_GaaRxOptionsData);
#endif
    break;
  }

  case SD_SUBSCRIBE_ENTRY:
  {

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
    if (Sd_GaaAclPolicyFlag == SD_TRUE)
    {
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
      Sd_AcL_IP_Server_policy_Check(LpInstance, LpInstanceStatic, LpEntry,
                                    Sd_GaaRxOptionsData, LucNoOfOptions, LpRemoteAddr);
#endif
    }
    else
    {
      (void)Sd_SubscribeRecd(LpInstance, LpInstanceStatic, LpEntry,
                             LpRemoteAddr, Sd_GaaRxOptionsData, LucNoOfOptions, LucReturncode);
    }

#else

    if (Sd_GaaAclPolicyFlag)
    {
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
      IdsM_SetSecurityEvent(SD_SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION);
#endif
      SD_UNUSED(LpInstanceStatic);
      SD_UNUSED(LpEntry);
      SD_UNUSED(LpRemoteAddr);
      /*Sd_AcL_IP_Server_policy_Check(LpInstance, LpInstanceStatic, LpEntry,
        LpRemoteAddr, Sd_GaaRxOptionsData, LucNoOfOptions);*/
    }
    else
    {
      (void)Sd_SubscribeRecd(LpInstanceStatic, LpEntry,
                             LpRemoteAddr);
    }
#endif

    break;
  }

  case SD_STOP_SUBSCRIBE_ENTRY:
  {
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
    (void)Sd_StopSubscribeRecd(LpInstanceStatic, LpEntry,
                               LpRemoteAddr, Sd_GaaRxOptionsData);
#endif
    break;
  }

  case SD_SUBSCRIBE_ACK_ENTRY:
  {
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
    (void)Sd_SubscribeAckRecd(LpInstance, LpInstanceStatic,
                              LpEntry, Sd_GaaRxOptionsData, LucNoOfOptions);
#endif
    break;
  }

  case SD_SUBSCRIBE_NACK_ENTRY:
  {
#if (STD_ON == SD_CLIENT_CONFIGURED)
    (void)Sd_SubscribeNackRecd(LpInstanceStatic, LpEntry,
                               &LpSduDataPtr[SD_SIXTEEN], LucNoOfEntries,
                               Sd_GaaRxOptionsData, LucNoOfOptions, LpRemoteAddr);
#else
    /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
    /*PRQA S 3112 2 */
    SD_UNUSED(LpSduDataPtr);
    SD_UNUSED(LucNoOfEntries);

#endif
    break;
  }
    /* polyspace +5 RTE:UNR [Justified:Low] "This check will be true when
       No entry Is Recieved" */
  default:
  {
    /*Do Nothing */
    break;
  }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_LocalIpAssignmentServer                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions for the server   **
**                          when the the local ip address goes from           **
**                          TCPIP_IPADDR_STATE_ASSIGNED to any other state.   **
**                        For the server, it sets all the server services for **
**                          that instance to DOWN phase and all event handlers**
**                          within those servers to RELEASED state            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerService,          **
**                          Sd_GaaServerServiceStatic, Sd_GaaEvHandler,       **
**                          Sd_GaaEvHandlerStatic,                            **
**                                                                            **
**                        Function(s) invoked : Sd_ServerServiceDownEntered,  **
**                          Sd_EvHandlerRelease, Sd_LocalIpAddrAssignmentChg, **
**                          SoAd_DisableRouting,                              **
**                          BswM_Sd_EventHandlerCurrentState                  **
**                                                                            **
** Design ID              : SD_SDD_0309                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_LocalIpAssignmentServer(
    const Sd_InstanceStaticType * LpInstanceStatic)
{
  uint16 LusCount;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  Sd_ServerServiceType * LpServerService;
  const Sd_ServerServiceStaticType * LpServerServiceStatic;
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  uint16 LusCount2;
  uint16 LusBaseIndex2;
  uint16 LusNoOfElements2;
  Sd_EvHandlerType * LpEvHandler;
  const Sd_EvHandlerStaticType * LpEvHandlerStatic;
#endif

  LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;
  LusNoOfElements = LpInstanceStatic->usNoOfServerServices;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
       LusCount++)
  {
    LpServerService = &Sd_GaaServerService[LusCount];

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];
#else
    LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount);
#endif

    /* SWS_SD_00325 */
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    if (SD_SERVER_INITIAL_WAIT == LpServerService->enServerPhase)
    {

      Sd_ServerServiceDownEntered(LpServerServiceStatic);

      LpServerService->enServerPhase = SD_SERVER_DOWN;

      (void)SoAd_DisableRouting(
          LpServerServiceStatic->ddActivationRoGrpId);
    }
    /* [SWS_SD_00340] */

    else
    {
      if ((SD_SERVER_REPETITION == LpServerService->enServerPhase) ||
          (SD_SERVER_MAIN == LpServerService->enServerPhase))
      {
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)

        LusBaseIndex2 = LpServerServiceStatic->usBaseEvHandlerIndex;
        LusNoOfElements2 = LpServerServiceStatic->usNoOfEvHandlers;

        for (LusCount2 = LusBaseIndex2; LusCount2 < (LusBaseIndex2 +
                                                     LusNoOfElements2);
             LusCount2++)
        {
          LpEvHandler = &Sd_GaaEvHandler[LusCount2];

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
          LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount2];
#else
          LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount2);
#endif
          /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
            made sure that they are within their range by having necessary boundary
            checks in order to prevent them from being illegally dereferenced." */
          if (SD_EVENT_HANDLER_RELEASED != LpEvHandler->enEvHandlerCurrState)
          {
            LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;

            Sd_EvHandlerRelease(LpEvHandler, LpEvHandlerStatic);
            BswM_Sd_EventHandlerCurrentState(LpEvHandlerStatic->usHandleId,
                                             LpEvHandler->enEvHandlerCurrState);
          }
        }
#endif

        (void)SoAd_DisableRouting(LpServerServiceStatic->ddActivationRoGrpId);

        Sd_ServerServiceDownEntered(LpServerServiceStatic);

        LpServerService->enServerPhase = SD_SERVER_DOWN;
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_LocalIpAssignmentClient                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions for the Client   **
**                          when the the local ip address goes from           **
**                          TCPIP_IPADDR_STATE_ASSIGNED to any other state.   **
**                        For the client, it sets all the client services for **
**                          that instance to DOWN phase and all Consumed      **
**                          event groups to the DOWN state                    **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientService,          **
**                          Sd_GaaClientServiceStatic, Sd_GaaConsumedEvGrp,   **
**                          Sd_GaaConsumedEvGrpStatic,                        **
**                                                                            **
**                        Function(s) invoked : Sd_LocalIpAddrAssignmentChg   **
**                          Sd_ConsumedEvGrpRelease, Sd_ClientInactive        **
**                          Sd_ClientServiceDownEntered,                      **
**                          BswM_Sd_ClientServiceCurrentState,                **
**                          BswM_Sd_ConsumedEventGroupCurrentState,           **
**                          BswM_Sd_ConsumedEventGroupCurrentState,           **
**                                                                            **
** Design ID              : SD_SDD_0308                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_LocalIpAssignmentClient(
    const Sd_InstanceStaticType * LpInstanceStatic)
{
  uint16 LusCount;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  Sd_ClientServiceType * LpClientService;
  const Sd_ClientServiceStaticType * LpClientServiceStatic;

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  uint16 LusCount2;
  uint16 LusBaseIndex2;
  uint16 LusNoOfElements2;
  Sd_ConsumedEvGrpType * LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[SD_ZERO];
  #if (STD_ON == SD_PRE_COMPILE_SINGLE)
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[SD_ZERO];
  #else
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic)
    + SD_ZERO);
  #endif
  
#endif

  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;
  LusNoOfElements = LpInstanceStatic->usNoOfClientServices;
  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
       LusCount++)
  {
    LpClientService = &Sd_GaaClientService[LusCount];

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];
#else
    LpClientServiceStatic =
        ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount);
#endif

    /* SWS_SD_00380, SWS_SD_00373, SWS_SD_00357 [SWS_SD_00373b] SD_SRS_1311*/
    /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    if (SD_CLIENT_DOWN != LpClientService->enClientPhase)
    {
      /* SWS 00712b , ETC_1237, SRS_2078, SDD_0308 */
      if (SD_CLIENT_SERVICE_DOWN != LpClientService->enClientCurrState)
      {
        LpClientService->enClientCurrState = SD_CLIENT_SERVICE_DOWN;

        BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                                          LpClientService->enClientCurrState);
      }
/* SWS 00712c, ETC_1238, SRS_2079, SDD_0308 */
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)

      LusBaseIndex2 = LpClientServiceStatic->usBaseConEventGrp;
      LusNoOfElements2 = LpClientServiceStatic->usNoOfConEventGrp;

      for (LusCount2 = LusBaseIndex2; LusCount2 < (LusBaseIndex2 +
                                                   LusNoOfElements2);
           LusCount2++)
      {
        LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount2];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount2];
#else
        LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount2);
#endif
        /*[SWS_SD_00373c]*/
        /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
        if (SD_CONSUMED_EVENTGROUP_DOWN !=
            LpConsumedEvGrp->enConEvGrpCurrState)
        {
          LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_DOWN;
          BswM_Sd_ConsumedEventGroupCurrentState(
              LpConsumedEvGrpStatic->usHandleId,
              LpConsumedEvGrp->enConEvGrpCurrState);
          Sd_ConsumedEvGrpRelease(LpConsumedEvGrp, LpConsumedEvGrpStatic);
        }
      }
#endif

/* SWS 00712d , ETC_1239, SRS_2080, SDD_0308 */
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
      if (SD_CLIENT_MAIN == LpClientService->enClientPhase)
      {
        /* polyspace +6 RTE:UNR [Justified:Low]  LpClientService->
        enClientCurrState is false when enClientCurrState
        is when enClientCurrState is SD_CLIENT_SERVICE_AVAILABLE*/
        if (SD_ZERO < (LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax)
        {
          LpClientService->ulClientRetrySubDelayCount = SD_ZERO;
          LpConsumedEvGrp->ulConEvGrpRetryCount = SD_ZERO;
        }
      }
#endif
#endif

      Sd_ClientInactive(LpClientService);

      Sd_ClientServiceDownEntered(LpClientService, LpClientServiceStatic);

      /* SWS 00712a ,ETC_1236, SRS_2077, SDD_0308 */
      LpClientService->enClientPhase = SD_CLIENT_DOWN;
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_InitServer                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Initialises the Server and the Event  **
**                        handler variables on startup                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpServerService - Pointer to Server structure       **
**                      : LpServerServiceStatic - Pointer to Static server    **
**                          structure                                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandler,              **
**                          Sd_GaaEvHandlerStatic, Sd_GaaEvHandlerSubGrp      **
**                                                                            **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0140                                         **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_InitServer(void)
{
  const Sd_InstanceStaticType * LpInstanceStatic;
  const Sd_ServerServiceStaticType * LpServerServiceStatic;
  Sd_ServerServiceType * LpServerService;
  uint16 LusCountInstance;
  uint16 LusBaseIndexInstance;
  uint16 LusNoOfServerService;
  uint16 LusCountServerService;
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  Sd_EvHandlerType * LpEvHandler;
  const Sd_EvHandlerStaticType * LpEvHandlerStatic;
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp;
  uint16 LusBaseEvHandIndex;
  uint16 LusNoOfEventHandler;
  uint16 LusCount;
  uint16 LusBaseIndexEvHandler;
  uint16 LusNoOfElements2;
  uint16 LusCount2;
#endif

#if (SD_NO_OF_INSTANCES != SD_ONE)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  for (LusCountInstance = SD_ZERO; LusCountInstance < SD_NO_OF_INSTANCES;
       LusCountInstance++)
#else
  for (LusCountInstance = SD_ZERO; LusCountInstance < SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS; LusCountInstance++)
#endif
#else
  LusCountInstance = SD_ZERO;
#endif
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpInstanceStatic = &Sd_GaaInstanceStatic[LusCountInstance];
#else
    LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LusCountInstance);
#endif

    LusBaseIndexInstance = LpInstanceStatic->usBaseServerServiceIndex;
    LusNoOfServerService = LpInstanceStatic->usNoOfServerServices;
    for (LusCountServerService = LusBaseIndexInstance;
         LusCountServerService < (LusBaseIndexInstance +
                                  LusNoOfServerService);
         LusCountServerService++)
    {
      LpServerService = &Sd_GaaServerService[LusCountServerService];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCountServerService];
#else
      LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCountServerService);
#endif

      /* [SWS_SD_00020] */
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
      LpServerService->ulServerDelayCount = SD_ZERO;
      LpServerService->ulServerTtlCount = SD_ZERO;
      LpServerService->enServerPhase = SD_SERVER_DOWN;
      LpServerService->ucNoOfOffersSent = SD_ZERO;

      /* polyspace +6 RTE:UNR [Justified:Low] "This check will be true when
          (LpServerServiceStatic->stServerStaticFlag).blAutoAvaliable)
          is not equal to SD_TRUE " */
      if ((SD_TRUE == (LpServerServiceStatic->stServerStaticFlag).blAutoAvaliable))

      {
        LpServerService->enServerServiceSetState = SD_SERVER_SERVICE_AVAILABLE;
      }
      else
      {
        LpServerService->enServerServiceSetState = SD_SERVER_SERVICE_DOWN;
      }

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)

      LusBaseEvHandIndex = LpServerServiceStatic->usBaseEvHandlerIndex;
      LusNoOfEventHandler = LpServerServiceStatic->usNoOfEvHandlers;

      for (LusCount = LusBaseEvHandIndex;
           LusCount < LusNoOfEventHandler; LusCount++)
      {
        LpEvHandler = &Sd_GaaEvHandler[LusCount];

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount];
#else
        LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount);
#endif
        /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
        LpEvHandler->ucNoOfSubGrpsTcp = SD_ZERO;
        LpEvHandler->ucNoOfSubGrpsUdp = SD_ZERO;

        LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;

        LusBaseIndexEvHandler = (uint16)(LpEvHandlerStatic->usEvHandlerSelfIndex) * SD_MAX_EVENT_SUB_GROUPS;
        LusNoOfElements2 = SD_MAX_EVENT_SUB_GROUPS;

        for (LusCount2 = LusBaseIndexEvHandler; LusCount2 <
                                                (LusBaseIndexEvHandler + LusNoOfElements2);
             LusCount2++)
        {
          /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
            made sure that they are within their range by having necessary boundary
            checks in order to prevent them from being illegally dereferenced." */
          LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount2];
          LpEvHandlerSubGrp->ucSubGrpCounter = SD_ZERO;
          LpEvHandlerSubGrp->ulEvSubGrpTtlCount = SD_ZERO;
          LpEvHandlerSubGrp->ddSoConTcpIndex = SD_ZERO;
          LpEvHandlerSubGrp->ddSoConUdpIndex = SD_ZERO;
          LpEvHandlerSubGrp->stEvHandlerFlag.blTcpActiveEv = SD_FALSE;
          LpEvHandlerSubGrp->stEvHandlerFlag.blUdpActiveEv = SD_FALSE;
          LpEvHandlerSubGrp->stEvHandlerFlag.ucEvHandlerReserved = SD_FALSE;
        }
      }
#endif
    }
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_InitClient                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Initialises the Client and the        **
**                        Consumed Event Group variables on startup           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp           **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GddIpv4Wildcard     **
**                          Sd_GddIpv6Wildcard                                **
**                                                                            **
**                        Function(s) invoked : Sd_CopyIpAddr                 **
**                                                                            **
** Design ID            : SD_SDD_0139                                         **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_InitClient(void)
{
  Sd_ClientServiceType * LpClientService;
  const Sd_ClientServiceStaticType * LpClientServiceStatic;
  const Sd_InstanceStaticType * LpInstanceStatic;
  uint16 LusBaseIndex2;
  uint16 LusNoOfElements2;
  uint16 LusCount3;
  uint16 LusCount2;
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  Sd_ConsumedEvGrpType * LpConsumedEvGrp;
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  uint16 LusCount;
  boolean LblInitialWaitFlag;
  LblInitialWaitFlag = SD_FALSE;
#endif

#if (SD_NO_OF_INSTANCES != SD_ONE)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  for (LusCount3 = SD_ZERO; LusCount3 < SD_NO_OF_INSTANCES; LusCount3++)
#else
  for (LusCount3 = SD_ZERO; LusCount3 < SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS; LusCount3++)
#endif
#else
  LusCount3 = SD_ZERO;
#endif
  {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)

    LpInstanceStatic = &Sd_GaaInstanceStatic[LusCount3];
#else
    LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LusCount3);
#endif
    LusBaseIndex2 = LpInstanceStatic->usBaseClientServiceIndex;
    LusNoOfElements2 = LpInstanceStatic->usNoOfClientServices;

    for (LusCount2 = LusBaseIndex2; LusCount2 < (LusBaseIndex2 + LusNoOfElements2); LusCount2++)
    {
      LpClientService = &Sd_GaaClientService[LusCount2];

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount2];
#else
      LpClientServiceStatic =
          ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LusCount2);
#endif

      /* [SWS_SD_00021]  */
      /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being illegally dereferenced." */
      LpClientService->enClientCurrState = SD_CLIENT_SERVICE_DOWN;

      /*[SWS_SD_00354] [SWS_SD_00354b] */
      if (SD_CLIENT_INITIAL_WAIT == LpClientService->enClientPhase)
      {

        BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                                          LpClientService->enClientCurrState);

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
        LblInitialWaitFlag = SD_TRUE;
#endif
      }

      /* [SWS_SD_00021] */
      LpClientService->ulClientDelayCount = SD_ZERO;
      LpClientService->enClientPhase = SD_CLIENT_DOWN;
      LpClientService->ulOfferTtlCount = SD_ZERO;
      LpClientService->ucNoOfOffersSent = SD_ZERO;
      LpClientService->ddOfferSoConIndexTcp = SD_ZERO;
      LpClientService->ddOfferSoConIndexUdp = SD_ZERO;
      LpClientService->stClientFlag.blOfferAvailable = SD_FALSE;
      LpClientService->stClientFlag.blOfferMaxTtl = SD_FALSE;
      LpClientService->stClientFlag.blOfferTtlExpired = SD_FALSE;
      LpClientService->stClientFlag.blTcpActive = SD_FALSE;
      LpClientService->stClientFlag.blUdpActive = SD_FALSE;
      /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be true when
         the SD_PRE_COMPILE_SINGLE is STD_ON */

      if (SD_TRUE == LpClientServiceStatic->stClientStaticFlag.blAutoRequire)

      {
        LpClientService->enClientSetState = SD_CLIENT_SERVICE_REQUESTED;
      }
      else
      {
        LpClientService->enClientSetState = SD_CLIENT_SERVICE_RELEASED;
      }
      /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
        the domain is IpV4 is enabled */
      if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
      {
        Sd_CopyIpAddr(
            &LpClientService->stOfferEndpointAddrTcp, &Sd_GddIpv4Wildcard);
        Sd_CopyIpAddr(
            &LpClientService->stOfferEndpointAddrUdp, &Sd_GddIpv4Wildcard);
        Sd_CopyIpAddr(&LpClientService->stOfferRemoteAddr, &Sd_GddIpv4Wildcard);
      }
      /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be true when
       the domain is IpV6 is enabled */
#if (STD_ON == SD_IPV6_ENABLED)
      else
      {
        Sd_CopyIpAddr(
            &LpClientService->stOfferEndpointAddrTcp, &Sd_GddIpv6Wildcard);
        Sd_CopyIpAddr(
            &LpClientService->stOfferEndpointAddrUdp, &Sd_GddIpv6Wildcard);
        Sd_CopyIpAddr(&LpClientService->stOfferRemoteAddr, &Sd_GddIpv6Wildcard);
      }
#endif

/* [SWS_SD_00440] */
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)

      LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;
      LusNoOfElements = LpClientServiceStatic->usNoOfConEventGrp;

      for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
           LusCount++)
      {
        LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
        LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif
        /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
        LpConsumedEvGrp->ulConEvGrpTtlCount = SD_ZERO;
        LpConsumedEvGrp->ddSoConIdTcp = SD_ZERO;
        LpConsumedEvGrp->ddSoConIdUdp = SD_ZERO;
        LpConsumedEvGrp->ddSoConIdMulticast = SD_ZERO;
        LpConsumedEvGrp->ddSoConGrpIndexMulticast = SD_ZERO;
        LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_DOWN;
        /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be true when
             the blAutoRequire is true */
        if (SD_TRUE == LblInitialWaitFlag)
        {
          LblInitialWaitFlag = SD_FALSE;
          /*[SWS_SD_00354c] */
          BswM_Sd_ConsumedEventGroupCurrentState(
              LpConsumedEvGrpStatic->usHandleId,
              LpConsumedEvGrp->enConEvGrpCurrState);
        }
        /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be true when
        the blAutoRequire is true */
        if (SD_TRUE == LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blAutoRequire)
        {
          LpConsumedEvGrp->enConEvGrpSetState =
              SD_CONSUMED_EVENTGROUP_REQUESTED;
        }
        else
        {
          LpConsumedEvGrp->enConEvGrpSetState = SD_CONSUMED_EVENTGROUP_RELEASED;
        }

        LpConsumedEvGrp->stConsumedEvGrpFlag.blRoutingEnabled = SD_FALSE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blMulticastRoutingEnabled =
            SD_FALSE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blConEvGrpTtlExpired = SD_FALSE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blUnicastOfferRecd = SD_FALSE;

        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeSent = SD_FALSE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeAckRecd = SD_FALSE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeNAckRecd = SD_FALSE;
        LpConsumedEvGrp->stConsumedEvGrpFlag.ucReserved = SD_FALSE;
      }
#endif
    }
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_SubscibeEventGroupRetry                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Retries Subsciption for Eventgroups   **
**                        after the Dealy timer has been elapsed.             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp           **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GddIpv4Wildcard     **
**                          Sd_GddIpv6Wildcard                                **
**                                                                            **
**                        Function(s) invoked : Sd_CopyIpAddr                 **
**                                                                            **
** Design ID            : SD_SDD_0459                                         **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_SubscibeEventGroupRetry(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    Sd_ConsumedEvGrpType * LpConsumedEvGrp,
    Sd_ClientServiceType * LpClientService,
    const TcpIp_SockAddrType * LpRemoteAddr)
{
  /*SWS_SD_00739a*/
  /*SWS_SD_00739b*/
  if (((SD_RETRY_MAX ==
        (LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax)) &&
      (SD_ZERO == LpClientService->ulClientRetrySubDelayCount))
  {
    if ((SD_CONSUMED_EVENTGROUP_REQUESTED ==
         LpConsumedEvGrp->enConEvGrpSetState) &&
        ((SD_FALSE == ((LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeAckRecd)) &&
         SD_FALSE == ((LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeNAckRecd)))
    {
      Sd_SendStopSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, SD_ZERO);
      Sd_SendSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, SD_ZERO);
      LpClientService->ulClientRetrySubDelayCount =
          (LpConsumedEvGrpStatic->pClientTimer)->ulSubscribeEventgroupRetryDelay;
    }
  }
  else
  {
    /*SWS_SD_00738a*/
    /*SWS_SD_00738b*/
    /*SWS_SD_00738c*/
    if (((SD_FALSE == ((LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeAckRecd)) &&
         SD_FALSE == ((LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeNAckRecd)) &&
        (SD_CONSUMED_EVENTGROUP_RELEASED !=
         LpConsumedEvGrp->enConEvGrpSetState))
    {
      /* SWS_SD_00737 */
      if ((SD_ZERO == LpClientService->ulClientRetrySubDelayCount) &&
          (LpConsumedEvGrp->ulConEvGrpRetryCount <=
           (LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax))
      {

        Sd_SendStopSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, SD_ZERO);
        Sd_SendSubscribe(LpConsumedEvGrpStatic, LpRemoteAddr, SD_ZERO);
        LpClientService->ulClientRetrySubDelayCount =
            (LpConsumedEvGrpStatic->pClientTimer)->ulSubscribeEventgroupRetryDelay;
        LpConsumedEvGrp->ulConEvGrpRetryCount++;
      }

      if (LpConsumedEvGrp->ulConEvGrpRetryCount >
          (LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax)

      {
        LpClientService->ulClientRetrySubDelayCount = SD_ZERO;
#if (STD_ON == SD_DEV_ERROR_DETECT)
        (void)Det_ReportRuntimeError(SD_MODULE_ID, SD_INSTANCE_ID,
                                     SD_E_COUNT_OF_RETRY_SUBSCRIPTION_EXCEEDED, SD_E_INV_ID);
#endif
      }
    }
    /* SWS_SD_00740 */
    if ((
            (SD_TRUE == ((LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeAckRecd)) ||
            SD_TRUE == ((LpConsumedEvGrp->stConsumedEvGrpFlag).blSubscribeNAckRecd)) ||
        (SD_CONSUMED_EVENTGROUP_RELEASED ==
         LpConsumedEvGrp->enConEvGrpSetState))
    {
      LpClientService->ulClientRetrySubDelayCount = SD_ZERO;
    }
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif
#endif
/*******************************************************************************
** Function Name        : Sd_Ipv4Lengthcheck                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks Leangth of IpV4 if the that is **
**                        topologically Correct.                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp           **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GddIpv4Wildcard     **
**                          Sd_GddIpv6Wildcard                                **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0464                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_Ipv4Lengthcheck(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_InstanceType * LpInstance,
    uint32 LulSubnetAddr,
    uint32 LulAddr)
{
  Std_ReturnType LddReturnValue;
  uint16 LusLocalAdressCheckLength;

  uint32 LulLocalAdressCheckMask2 = (uint32)SD_ZERO;
  LusLocalAdressCheckLength =
      LpInstanceStatic->usSdInstanceLocalAdressCheckLength;

  if (SD_INVALID == LusLocalAdressCheckLength)
  {
    if (((LulSubnetAddr)&LpInstance->stSubnetNetmask.addr[SD_ZERO]) ==
        ((LulAddr) & (LpInstance->stSubnetNetmask.addr[SD_ZERO])))
    {
      LddReturnValue = E_OK;
    }
    else
    {
      LddReturnValue = E_NOT_OK;
    }
  }
  else if (SD_ZERO != LusLocalAdressCheckLength)
  {

#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)
    LulLocalAdressCheckMask2 =
        ~(SD_THIRTY_TWO_SET_BIT >> LusLocalAdressCheckLength);
    if (((LulSubnetAddr)&LulLocalAdressCheckMask2) ==
        (LulAddr & LulLocalAdressCheckMask2))
#else
    /*polyspace +4 RTE:ISO [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being Invalidly Shift." */
    if (SD_THIRTY_TWO > LusLocalAdressCheckLength)
    {
      LulLocalAdressCheckMask2 =
          ~(SD_THIRTY_TWO_SET_BIT >> LusLocalAdressCheckLength);
    }
    if (((LulSubnetAddr) & ~LulLocalAdressCheckMask2) ==
        (LulAddr & ~LulLocalAdressCheckMask2))
#endif
    {

      /*  Address is in same subnet, return E_OK */
      LddReturnValue = E_OK;
    }
    else
    {
      /*Address is not in same subnet */
      LddReturnValue = E_NOT_OK;
    }
  }
  else
  {
    /*No Need check at all Return E_OK*/
    LddReturnValue = E_OK;
  }
  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
/*******************************************************************************
** Function Name        : Sd_Ipv6Lengthcheck                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Checks leangth of IPV6 Ip address if  **
**                        that is topologically correct.                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp           **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GddIpv4Wildcard     **
**                          Sd_GddIpv6Wildcard                                **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0463                                         **
*******************************************************************************/
#if (STD_ON == SD_IPV6_ENABLED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_Ipv6Lengthcheck(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_InstanceType * LpInstance,
    uint32 LulSubnetAddr,
    uint32 LulAddr,
    uint32 LaaAddrMask[],
    uint8 LucCount)
{
  Std_ReturnType LddReturnValue;
  uint16 LusLocalAdressCheckLength;

  LusLocalAdressCheckLength =
      LpInstanceStatic->usSdInstanceLocalAdressCheckLength;
  LddReturnValue = E_OK;
  if (SD_INVALID == LusLocalAdressCheckLength)
  {

    if (((LulSubnetAddr) &
         (LpInstance->stSubnetNetmask.addr[LucCount - SD_ONE])) !=
        (LulAddr & LpInstance->stSubnetNetmask.addr[LucCount - SD_ONE]))
    {
      LddReturnValue = E_NOT_OK;
    }
  }
  else if (SD_ZERO != LusLocalAdressCheckLength)
  {

#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)
    if (((LulSubnetAddr)&LaaAddrMask[LucCount - SD_ONE]) !=
        (LulAddr & LaaAddrMask[LucCount - SD_ONE]))

#else
    if (((LulSubnetAddr) & ~LaaAddrMask[LucCount - SD_ONE]) !=
        (LulAddr & ~LaaAddrMask[LucCount - SD_ONE]))
#endif

    {
      /*If any address is not matched, return E_NOT_OK */
      LddReturnValue = E_NOT_OK;
    }
  }
  else
  {

    /* No Need check at all Return E_OK  */
    LddReturnValue = E_OK;
  }

  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_SharedClTimer                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Checks Common Service group and       **
**                        SdClientServiceAutoRequire for common client timer. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0464                                         **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientSharedTimer(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    const Sd_ClientTimerStaticType * LpClientTimer)
{
  uint16 LusCount, LusCount2;

  LpClientTimer = LpClientServiceStatic->pClientTimer;
  if (LpClientTimer != SD_NULL_PTR)
  {
    for (LusCount = SD_ZERO; LusCount < SD_CLIENT_REF_SERVICEGRP_CONFIGURED;
         LusCount++)
    {
      if ((LpClientServiceStatic->pServiceGroupRef) != SD_NULL_PTR)

      {
        /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True
         when the blAutoRequire value is SD_FALSE */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        if (((LpClientServiceStatic->pServiceGroupRef) ==
             &Sd_GaaServicegroupStatic[LusCount]) ||
            (LpClientServiceStatic->stClientStaticFlag).blAutoRequire ==
                SD_TRUE)
        {

          for (LusCount2 = SD_ZERO; LusCount2 < SD_NO_OF_CLIENT_TIMERS;
               LusCount2++)
#else
        if (((LpClientServiceStatic->pServiceGroupRef) ==
             (Sd_GpConfigPtr->pServgrpStatic) + LusCount) ||
            (LpClientServiceStatic->stClientStaticFlag).blAutoRequire ==
                SD_TRUE)
          {
          for (LusCount2 = SD_ZERO; LusCount2 < Sd_GpConfigPtr->ucSdClientTimerCount; LusCount2++)
#endif
          {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
            if ((LpClientServiceStatic->pClientTimer) ==
                &Sd_GSaaClientTimerStatic[LusCount2])
#else
            if ((LpClientServiceStatic->pClientTimer) ==
                ((Sd_GpConfigPtr->pSd_GSaaClientTimerStatic) + LusCount2))
#endif
            {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
              LpClientTimer = &Sd_GSaaClientTimerStatic[LusCount2];
#else
              LpClientTimer = ((Sd_GpConfigPtr->pSd_GSaaClientTimerStatic) + LusCount2);
#endif
            }
          }
        }
      }
      else
      {
        /*Do Nothing*/
      }
    }
  }
  if (LpClientTimer != SD_NULL_PTR)

  {
    /*Do nothing*/
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Sd_OfferNtExpire                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Checks leangth of IPV6 Ip address if  **
**                        that is topologically correct.                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp           **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GddIpv4Wildcard     **
**                          Sd_GddIpv6Wildcard                                **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0465                                         **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
boolean Sd_OfferNtExpire(
    Sd_ClientServiceType * LpClientService,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    boolean LblSoConOnline)
{
  uint16 LusNoOfElements;
  uint16 LusNoOfElement2;
  uint16 LusCount2;
  uint16 LusCount3;
  SoAd_SoConModeType LenSoConMode;
  SoAd_SoConIdType LddSoConId;
  uint16 LusBaseIndex2;
  uint16 LusBaseIndex3;

  /* SD_SRS_2065, SD_SRS_2066, SD_SRS_2067
     SD_SDD_0231 */
  if (LpClientServiceStatic->pTcpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex2 = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;

    for (LusCount2 = LusBaseIndex2; (LusCount2 < (LusBaseIndex2 +
                                                  LusNoOfElements)) &&
                                    (SD_FALSE == LblSoConOnline);
         LusCount2++)
    {
      /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being out of bounds." */
      LddSoConId = Sd_GaaSoConId[LusCount2];

      SoAd_GetSoConMode(LddSoConId, &LenSoConMode);
      if (LenSoConMode == SOAD_SOCON_ONLINE)
      {
        LblSoConOnline = SD_TRUE;
      }
    }
  }
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pUdpSoConGrp is not equal to SD_NULL_PTR. */
  if (LpClientServiceStatic->pUdpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex2 = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount2 = LusBaseIndex2; (LusCount2 < (LusBaseIndex2 +
                                                  LusNoOfElements)) &&
                                    (SD_FALSE == LblSoConOnline);
         LusCount2++)
    {
      /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
      LddSoConId = Sd_GaaSoConId[LusCount2];

      SoAd_GetSoConMode(LddSoConId, &LenSoConMode);
      if (LenSoConMode == SOAD_SOCON_ONLINE)
      {
        LblSoConOnline = SD_TRUE;
      }
    }
  }
  if (LblSoConOnline == SD_TRUE)
  {
    if ((SD_CLIENT_SERVICE_AVAILABLE != LpClientService->enClientCurrState))
    {

      if (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp)
      {
        LusBaseIndex3 = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
        LusNoOfElement2 = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
        for (LusCount3 = LusBaseIndex3; LusCount3 < (LusBaseIndex3 +
                                                     LusNoOfElement2);
             LusCount3++)
        {

          if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag).blActivationRoGrpIdPresent)
          {
            /* SWS_SD_00721d, SD_SRS_2066, SD_SDD_0247, SD_ETC_1244 */
            /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag
            are made sure that they are within their range by having necessary
            boundary checks in order to prevent them from being out of bounds." */
            (void)SoAd_EnableSpecificRouting(
                LpClientServiceStatic->ddActivationRoGrpId,
                Sd_GaaSoConId[LusCount3]);
          }
        }
      }

      if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
      {
        LusBaseIndex3 = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
        LusNoOfElement2 = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
        for (LusCount3 = LusBaseIndex3; LusCount3 < (LusBaseIndex3 +
                                                     LusNoOfElement2);
             LusCount3++)
        {
          if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag).blActivationRoGrpIdPresent)
          {
            /* SWS_SD_00721d, SD_SRS_2066, SD_SDD_0247, SD_ETC_1244 */
            /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag
            are made sure that they are within their range by having necessary
            boundary checks in order to prevent them from being out of bounds." */
            (void)SoAd_EnableSpecificRouting(
                LpClientServiceStatic->ddActivationRoGrpId,
                Sd_GaaSoConId[LusCount3]);
          }
        }
      }

      /* SWS_SD_00721e, SD_SRS_2067, SD_SDD_0247, SD_ETC_1245 */
      if (SD_CLIENT_SERVICE_DOWN == LpClientService->enClientCurrState)
      {

        LpClientService->enClientCurrState = SD_CLIENT_SERVICE_AVAILABLE;
        BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                                          LpClientService->enClientCurrState);
      }
    }
  }
  return (LblSoConOnline);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_MulticastMatchSocket_Rem_Addr_Off                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : If SdSetRemAddrOfClientRxMulticastSoCon is set to   **
**                        FALSE, a Wildcard Socket Connection of this service **
**                        shall be used without updating the according        **
**                        remote Address                                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId                 **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0599                                         **
*******************************************************************************/
#if ((STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) &&     \
     (STD_ON == SD_MULTICAST_GRP_INDEX_CONFIGURED) && \
     (STD_OFF == SD_SET_REM_ADDR_OF_CLIENT_RX_MULTICAST_SO_CON))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_MulticastMatchSocket_Rem_Addr_Off(
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_SoConGroupStaticType * LpSoConGrpStatic,
    SoAd_SoConIdType * LpSoConId)
{

  Std_ReturnType LddReturnValue;
  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  uint16 LusMatchIndex = SD_ZERO;
  uint16 LusWildcardMatchIndex = SD_ZERO;
  uint16 LusBaseIndex;
  uint16 LusCount;
  TcpIp_SockAddrType WldCrdIpAddr;
  TcpIp_SockAddrType LstIpAddrRemote;
  LusBaseIndex = LpSoConGrpStatic->usBaseSocketConIndex;

  LblMatchRecd = SD_FALSE;
  LblWildcardMatch = SD_FALSE;

  /* SD_SRS_828, SD_SDD_0599, SWS_SD_00377c , SD_ETC_1217, SD_ETC_1218 */

  for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex +
                                             LpSoConGrpStatic->usNoOfSockets)) &&
                                (SD_FALSE == LblMatchRecd);
       LusCount++)
  {
    /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     blDomainIpv4 is not equal to SD_TRUE. */
    if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
    {
      LstIpAddrRemote.domain = TCPIP_AF_INET;
      WldCrdIpAddr.domain = TCPIP_AF_INET;
    }
    else
    {
      LstIpAddrRemote.domain = TCPIP_AF_INET6;
      WldCrdIpAddr.domain = TCPIP_AF_INET6;
    }

    (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddrRemote);

    LblMatchRecd = Sd_MatchIpAddr(&LstIpAddrRemote, &WldCrdIpAddr);
    LusMatchIndex = LusCount;
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
    LblWildcardMatch is equal to SD_FALSE */
    if (SD_FALSE == LblWildcardMatch)
    {
      LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddrRemote);
      LusWildcardMatchIndex = LusCount;
    }
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
  LblMatchRecd & LblWildcardMatch is equal to SD_FALSE */
  if ((SD_FALSE == LblMatchRecd) && (SD_FALSE == LblWildcardMatch))
  {
    LddReturnValue = E_NOT_OK;
    SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((SD_FALSE == LblMatchRecd) && (SD_TRUE == LblWildcardMatch))
  {
    LddReturnValue = E_OK;
    *LpSoConId = Sd_GaaSoConId[LusWildcardMatchIndex];

    (void)SoAd_SetRemoteAddr(*LpSoConId, &WldCrdIpAddr);
  }

  else
  {
    LddReturnValue = E_OK;
    *LpSoConId = Sd_GaaSoConId[LusMatchIndex];
  }

  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_AcL_IP_Client_policy_Check                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Checks Common Service group and       **
**                        SdClientServiceAutoRequire for common client timer. **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0464                                         **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
uint8 Sd_AcL_IP_Client_policy_Check(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr,
    boolean LblUnicast)
{
  Std_ReturnType LddReturnValue = E_OK;
  Std_ReturnType LddRoutingTcp_Value = E_OK;
  Std_ReturnType LddRoutingUdp_Value = E_OK;
  Sd_ProviderConsumerType Request_type = SD_PROVIDER_TYPE;
  boolean LblAclCheckTCP;
  boolean LblAclCheckUDP;
  boolean LblAclCheckRemote;
  boolean LblServiceMatch;
  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint32 LulMinorVersion;
  uint32 LusCount;
  uint16 LusBaseIndex;
  TcpIp_SockAddrType LstIpAddrTcp;
  TcpIp_SockAddrType LstIpAddrUdp;
  static Sd_SoconIndexRertunType *LddWildcardSocketIndex1;
  SoAd_SoConIdType LddUdpIndex;
  SoAd_SoConIdType LddTcpIndex;
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
  Sd_TypeOfSecurityEventsType LddEventReturnCode;
#endif

  uint8 LucReturnCode;
  uint8 LucReturnCode2 = SD_ZERO;
  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  Sd_ClientServiceType *LpClientService;
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
  LblAclCheckTCP = SD_FALSE;
  LblAclCheckUDP = SD_FALSE;
  LblAclCheckRemote = SD_FALSE;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[SD_ZERO];
#else
  LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + SD_ZERO);
#endif
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
  LddEventReturnCode = SD_NO_IDSM_EVENT;
#endif
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusServiceId = (LpEntryData->unEntryData).stEntry1.usServiceId;
  LusInstanceId = (LpEntryData->unEntryData).stEntry1.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry1.ucMajorVersion;
  LulMinorVersion = (LpEntryData->unEntryData).stEntry1.ulMinorVersion;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusBaseIndex = LpInstanceStatic->usBaseClientServiceIndex;

  /* SWS_SD_00487a  */
  for (LusCount = SD_ZERO; LusCount < (LusBaseIndex +
                                       (uint16)LpInstanceStatic->usNoOfClientServices);
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
    if ((SD_TRUE == LblServiceMatch) &&
        (LusInstanceId == LpClientServiceStatic->usInstanceId) &&
        (LucMajorVersion == LpClientServiceStatic->ucMajorVersion) &&
        (((uint32)SD_MINOR_VERSION_ALL_MATCH ==
          LpClientServiceStatic->ulMinorVersion) ||
         (LulMinorVersion == LpClientServiceStatic->ulMinorVersion)) &&
        (LpClientServiceStatic->EndrivenBehaviour ==
         SD_EXACT_OR_ANY_MINOR_VERSION))

    {

      LpClientService = &Sd_GaaClientService[LusCount];
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
      if (LpClientService->enClientCurrState != SD_CLIENT_SERVICE_DOWN)
      {

        LddEventReturnCode = SD_DUPLICATE_OFFER;
      }
      else
#endif
      {
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
          if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
          {

            LucReturnCode2 = Sd_CheckRemote(&LstIpAddrTcp, &LstIpAddrUdp, LpRemoteAddr,
                                            LucReturnCode, LusServiceId,
                                            Request_type, LblAclCheckTCP, LblAclCheckUDP, LblAclCheckRemote, SD_FALSE);

            LddWildcardSocketIndex1 = Sd_Acl_UniqueAddress(
                LpClientServiceStatic, &LstIpAddrTcp,
                &LstIpAddrUdp, LucReturnCode2, LpInstance);
            LddUdpIndex = LddWildcardSocketIndex1->usIndexUDP;
            LddTcpIndex = LddWildcardSocketIndex1->usIndexTCP;

            if (LucReturnCode2 == SD_ZERO)
            {
              LddReturnValue = E_NOT_OK;
            }
            else
            {
              if (E_OK == LddReturnValue)
              {
                (LpClientService->stClientFlag).blOfferAvailable = SD_TRUE;

                Sd_CopyIpAddr(&LpClientService->stOfferRemoteAddr, LpRemoteAddr);

                if ((LucReturnCode2 == SD_TWO) || (LucReturnCode2 == SD_THREE))
                {
                  LddRoutingTcp_Value = Sd_AclTcpClientRouting(LpConsumedEvGrpStatic, LpClientServiceStatic, LpClientService, LpRemoteAddr,
                                                               LucReturnCode2, LddTcpIndex);
                }

                if ((LucReturnCode2 == SD_ONE) || (LucReturnCode2 == SD_THREE))
                {
                  LddRoutingUdp_Value = Sd_AclUdpClientRouting(LpConsumedEvGrpStatic, LpClientServiceStatic,
                                                               LpClientService, LpRemoteAddr,
                                                               LucReturnCode2, LddUdpIndex);
                }
              }
            }
          }
          /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be false when
            the LpInstanceStatic->blDomainIpv4 is of IPV6 Type .*/
          else
#if (STD_ON == SD_IPV6_ENABLED)
          {
            LucReturnCode2 = Sd_CheckServerIPV6(&LstIpAddrTcp,
                                                &LstIpAddrUdp, LpRemoteAddr, LucReturnCode, LusServiceId,
                                                Request_type,
                                                LblAclCheckTCP, LblAclCheckUDP,
                                                LblAclCheckRemote, SD_FALSE);
            LddWildcardSocketIndex1 = Sd_Acl_UniqueAddress(
                LpClientServiceStatic, &LstIpAddrTcp,
                &LstIpAddrUdp, LucReturnCode2, LpInstance);
            LddUdpIndex = LddWildcardSocketIndex1->usIndexUDP;
            LddTcpIndex = LddWildcardSocketIndex1->usIndexTCP;

            if (LucReturnCode2 == SD_ZERO)
            {
              LddReturnValue = E_NOT_OK;
            }
            else
            {
              LddReturnValue = Sd_OfferRecdCheckOptions(LpInstanceStatic,
                                                        LpClientServiceStatic, LucReturnCode);
              if (E_OK == LddReturnValue)
              {
                (LpClientService->stClientFlag).blOfferAvailable = SD_TRUE;

                Sd_CopyIpAddr(&LpClientService->stOfferRemoteAddr, LpRemoteAddr);

                if ((LucReturnCode2 == SD_TWO) || (LucReturnCode2 == SD_THREE))
                {
                  LddRoutingTcp_Value = Sd_AclTcpClientRouting(LpConsumedEvGrpStatic, LpClientServiceStatic, LpClientService, LpRemoteAddr,
                                                               LucReturnCode2, LddTcpIndex);
                }

                if ((LucReturnCode2 == SD_ONE) || (LucReturnCode2 == SD_THREE))
                {
                  LddRoutingUdp_Value = Sd_AclUdpClientRouting(LpConsumedEvGrpStatic, LpClientServiceStatic,
                                                               LpClientService, LpRemoteAddr,
                                                               LucReturnCode2, LddUdpIndex);
                }
              }
            }
          }
#else
          {
            LddReturnValue = E_NOT_OK;
          }
#endif
        }
        /* SWS_SD_00352 */
      }
    }
  }
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
  if ((LucReturnCode2 == SD_ZERO) && (LddEventReturnCode != SD_DUPLICATE_OFFER))
  {
    LddEventReturnCode = SD_SOME_IP_ACL_CHECK_FAILED_OFFER;
  }
  else
  {
    if (((!LddRoutingTcp_Value) && (!LddRoutingUdp_Value)))
    {
      (void)Sd_OfferRecd(LpInstance, LpInstanceStatic, LpEntryData,
                         Sd_GaaRxOptionsData, LucTotalNoOfOptions, LpRemoteAddr, LblUnicast, LucReturnCode2);
    }
    else
    {
      LddEventReturnCode = SD_ZERO;
      SD_UNUSED(LblUnicast);
      SD_UNUSED(LpInstance);
      SD_UNUSED(LucTotalNoOfOptions);
    }
  }
  return (LddEventReturnCode);
#else
  if (LucReturnCode2 != SD_ZERO)
  {
    if (((!LddRoutingTcp_Value) && (!LddRoutingUdp_Value)))
    {
      (void)Sd_OfferRecd(LpInstance, LpInstanceStatic, LpEntryData,
                         Sd_GaaRxOptionsData, LucTotalNoOfOptions, LpRemoteAddr, LblUnicast, LucReturnCode2);
    }
    else
    {
      LucReturnCode2 = SD_ZERO;
    }
  }

  return (LucReturnCode2);

#endif
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Sd_Acl_UniqueAddress                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks whether the received options   **
**                        are within the Subnet of the instance[SWS_SD_00688] **
**                        If the IP addr is NULL (Not present) it is not      **
**                          checked against the subnet and returns E_OK       **
**                        This function checks for IPv4 addresses             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0265                                         **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Sd_SoconIndexRertunType * 
Sd_Acl_UniqueAddress(
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    TcpIp_SockAddrType * LpOptionTcpAddr,
    TcpIp_SockAddrType * LpOptionUdpAddr,
    uint8 LucOptionsCode,
    const Sd_InstanceType * LpInstance)
{
  SoAd_SoConIdType LddAssignedSoConId;
  TcpIp_SockAddrType LstIpAddr;
  Sd_SoconIndexRertunType LddReturnIndexval2;
  Sd_SoconIndexRertunType *LddReturnIndexval;
  uint16 LusBaseIndex;

  uint16 LusNoOfElements;
  uint32 LusCount2;
  boolean LblWildcardMatch = SD_FALSE;
  boolean LblMatchRecd = SD_FALSE;
  (void)SD_MEMSET(&LddReturnIndexval2, (SoAd_SoConIdType)SD_ZERO, sizeof(Sd_SoconIndexRertunType));
  (void)SD_MEMSET(&LstIpAddr, (sint32)SD_ZERO, sizeof(TcpIp_SockAddrType));
  LddReturnIndexval = &LddReturnIndexval2;
  if ((LucOptionsCode == SD_TWO) || (LucOptionsCode == SD_THREE))
  {

    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount2 = SD_ZERO; (LusCount2 < (LusBaseIndex + LusNoOfElements) &&
                               (LusCount2 < SD_NO_OF_SOCKET_CONNECTIONS) && (!LblMatchRecd));
         LusCount2++)
    {
      LstIpAddr.domain = LpOptionTcpAddr->domain;
      (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount2], &LstIpAddr);

      LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpOptionTcpAddr);
      if (SD_TRUE == LblMatchRecd)
      {
        LddReturnIndexval->usIndexTCP = (SoAd_SoConIdType)LusCount2;
      }
      if (SD_FALSE == LblWildcardMatch)
      {
        LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddr);
        if (SD_TRUE == LblWildcardMatch)
        {
          LddReturnIndexval->usIndexTCP = (SoAd_SoConIdType)LusCount2;
        }
      }
    }
    if (SD_TRUE == LblWildcardMatch)
    {
      (void)SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LddReturnIndexval->usIndexTCP],
                                     LpOptionTcpAddr, &LddAssignedSoConId);
    }
  }
  else
  {
    SD_UNUSED(LpInstance);
  }

  if ((LucOptionsCode == SD_ONE) || LucOptionsCode == SD_THREE)
  {
    LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount2 = SD_ZERO; (LusCount2 < (LusBaseIndex + LusNoOfElements) &&
                               (LusCount2 < SD_NO_OF_SOCKET_CONNECTIONS) && (!LblMatchRecd));
         LusCount2++)
    {
      LstIpAddr.domain = LpOptionUdpAddr->domain;
      (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount2], &LstIpAddr);

      LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpOptionUdpAddr);
      if (SD_TRUE == LblMatchRecd)
      {
        LddReturnIndexval->usIndexUDP = (SoAd_SoConIdType)LusCount2;
      }
      if (SD_FALSE == LblWildcardMatch)
      {
        LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddr);
        if (SD_TRUE == LblWildcardMatch)
        {
          LddReturnIndexval->usIndexUDP = (SoAd_SoConIdType)LusCount2;
        }
      }
    }
    if (SD_TRUE == LblWildcardMatch)
    {
      (void)SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LddReturnIndexval->usIndexUDP],
                                     LpOptionUdpAddr, &LddAssignedSoConId);
    }
  }

  else
  {
    SD_UNUSED(LpInstance);
  }
  return (LddReturnIndexval);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
/*******************************************************************************
** Function Name        : Sd_AcL_IP_Client_policy_Check                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Checks if the Ip address within       **
**                        subscribe entry are present in the ACL List.        **
**                                                                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Structure       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                           structure                                        **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked : NA                            **
**                                                                            **
** Design ID            : SD_SDD_0589                                         **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_AcL_IP_Server_policy_Check(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr)
{
  boolean LblAclCheckTCP;
  boolean LblAclCheckUDP;
  boolean LblAclCheckRemote;
  boolean LblAclInstanceorMajorVersion;
  boolean LblAclEventgroupId;
  boolean LblAclCheckPassed;
  Sd_ProviderConsumerType Request_type;
  TcpIp_SockAddrType LstIpAddrTcp;
  TcpIp_SockAddrType LstIpAddrUdp;
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  uint16 LusServiceId;
  uint16 LusInstanceId;
  uint8 LucMajorVersion;
  uint16 LusEventGroupId;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint16 LusCount2;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  uint16 LusBaseEventIndex;
  boolean LblServiceMatch = SD_FALSE;
#endif

  uint8 LucReturnCode;
  uint8 LucReturnCode2 = SD_ZERO;
  LblAclCheckTCP = SD_FALSE;
  LblAclCheckUDP = SD_FALSE;
  LblAclCheckRemote = SD_FALSE;
  LblAclInstanceorMajorVersion = SD_FALSE;
  LblAclEventgroupId = SD_FALSE;
  LblAclCheckPassed = SD_FALSE;
  Request_type = SD_CONSUMER_TYPE;

  LusServiceId = (LpEntryData->unEntryData).stEntry2.usServiceId;
  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
  LusInstanceId = (LpEntryData->unEntryData).stEntry2.usInstanceId;
  LucMajorVersion = (LpEntryData->unEntryData).stEntry2.ucMajorVersion;

  /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
  LusEventGroupId = (LpEntryData->unEntryData).stEntry2.usEventGroupId;
  LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;

  /* SWS_SD_00487a  */
  for (LusCount = SD_ZERO; LusCount < (LusBaseIndex +
                                       (uint16)LpInstanceStatic->usNoOfServerServices);
       LusCount++)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];
#else
    LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount);
#endif

    LblServiceMatch = Sd_MatchService(LusServiceId,
                                      LpServerServiceStatic->usServiceId, LpServerServiceStatic->pConfigOption,
                                      LpServerServiceStatic->usOtherServKeyIndex,
                                      LpServerServiceStatic->usOtherServKeyLength, LpEntryData, LpOptionsData);
    if (SD_TRUE == LblServiceMatch)
    {
      if (LusInstanceId == LpServerServiceStatic->usInstanceId &&
          (LucMajorVersion == LpServerServiceStatic->ucMajorVersion))
      {
        LblAclInstanceorMajorVersion = SD_TRUE;

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
          if ((SD_EVENT_GROUP_ID_ALL_MATCH == LusEventGroupId) ||
              (LusEventGroupId == LpEvHandlerStatic->usEventGroupId))
          {
            LblAclEventgroupId = SD_TRUE;
            LucReturnCode = Sd_GetIpAddrFromOptions(LpEntryData, LpOptionsData,
                                                    LucTotalNoOfOptions, &LstIpAddrTcp, &LstIpAddrUdp);
            if (SD_TRUE == LpInstanceStatic->blDomainIpv4)
            {
              LucReturnCode2 = Sd_CheckRemote(&LstIpAddrTcp,
                                              &LstIpAddrUdp, LpRemoteAddr, LucReturnCode, LusServiceId,
                                              Request_type,
                                              LblAclCheckTCP, LblAclCheckUDP, LblAclCheckRemote,
                                              SD_TRUE);
            }
            else
            {
#if (STD_ON == SD_IPV6_ENABLED)
              LucReturnCode2 = Sd_CheckServerIPV6(&LstIpAddrTcp,
                                                  &LstIpAddrUdp, LpRemoteAddr, LucReturnCode, LusServiceId,
                                                  Request_type,
                                                  LblAclCheckTCP, LblAclCheckUDP,
                                                  LblAclCheckRemote, SD_TRUE);
#endif
            }
            if (LucReturnCode2 == SD_ZERO)
            {
              SD_UNUSED(LpInstance);
              SD_UNUSED(LpOptionsData);
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
              IdsM_SetSecurityEvent(SD_SEV_SOME_IP_ACL_CHECK_FAILED_EVENT_SUBSCRIPTION);
#endif
            }
            else
            {
              if ((LucReturnCode2 == SD_TWO) || (LucReturnCode2 == SD_THREE))
              {
                Sd_AclTcpServerRouting(LpServerServiceStatic,
                                       LpEvHandlerStatic,
                                       LstIpAddrTcp);
              }
              if ((LucReturnCode2 == SD_ONE) || (LucReturnCode2 == SD_THREE))
              {
                Sd_AclUdpServerRouting(LpServerServiceStatic, LpEvHandlerStatic,
                                       LstIpAddrUdp);
              }
            }
          }
        }
      }

      if (LucReturnCode2 != SD_ZERO)
      {

        Sd_ServerRemoteCodeReturn(LpInstance, LpInstanceStatic, LpEntryData,
                                  LpOptionsData, LucTotalNoOfOptions,
                                  LpRemoteAddr, LucReturnCode2, LblServiceMatch);
        LblAclCheckPassed = SD_TRUE;
      }
    }
  }

  if (((!LblServiceMatch) || (!LblAclInstanceorMajorVersion) ||
       (!LblAclEventgroupId)) &&
      (!LblAclCheckPassed))
  {
    Sd_SendSubscribeNack(LpInstanceStatic, LpEntryData, LpRemoteAddr, SD_ZERO);
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : Sd_CheckRemote                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function take extracted IPv4 adresss of Options**
**                        and verify it with the ACL Server list.             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0590                                         **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_CheckRemote(
    TcpIp_SockAddrType * LpOptionTcpAddr,
    TcpIp_SockAddrType * LpOptionUdpAddr,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    uint16 Userviceid,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckTCP,
    boolean LblAclCheckUDP,
    boolean LblAclCheckRemote,
    boolean LblClientorServer)

{
  uint8 LucReturnCode;
  LucReturnCode = SD_ZERO;
  if (Sd_GaaAclPolicyFlag)
  {
    uint8 LusNoOfCounsumerProvider;

    uint32 LulAddr;
    TcpIp_SockAddrType const *LpIp4Addr;
    LucReturnCode = SD_ZERO;

    if (LblClientorServer == SD_TRUE)
    {
      LusNoOfCounsumerProvider = SD_NO_OF_PROVIDED_SERVER_CONSUMER;
    }
    else
    {
      LusNoOfCounsumerProvider = SD_NO_OF_ALLOWED_CLIENT_PROVIDER;
    }

    if (LpRemoteAddr != SD_NULL_PTR)
    {
      LpIp4Addr = LpRemoteAddr;
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_FIVE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FOUR];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_THREE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_TWO];

#else
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_TWO];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_THREE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FOUR];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FIVE];
#endif
      LblAclCheckRemote = Sd_CheckRemote_Remote(LpIp4Addr, LusNoOfCounsumerProvider, Userviceid,
                                                LulAddr, Request_type, LblAclCheckRemote);
    }
    if (SD_TCP_OPTIONS_MASK != (LucOptionsCode & SD_TCP_OPTIONS_MASK))
    {
    }
    else
    {
      LpIp4Addr = LpOptionTcpAddr;
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)
      // Reverse TCP
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_FIVE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FOUR];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_THREE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_TWO];

#else
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_TWO];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_THREE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FOUR];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FIVE];
#endif
      LblAclCheckTCP = Sd_CheckRemote_Tcp_Addr(LpIp4Addr, LusNoOfCounsumerProvider, Userviceid,
                                               LulAddr, Request_type, LblAclCheckTCP, LblClientorServer);
    }

    if (SD_UDP_OPTIONS_MASK != (LucOptionsCode & SD_UDP_OPTIONS_MASK))
    {
    }
    else
    {

      LpIp4Addr = LpOptionUdpAddr;
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)
      // Reverse TCP
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_FIVE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FOUR];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_THREE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_TWO];

#else
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_TWO];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_THREE];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FOUR];
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
         made sure that they are initialized with proper Value " */
      LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                LpIp4Addr->aaSockAddrInetData[SD_FIVE];
#endif
      LblAclCheckUDP = Sd_CheckRemote_Udp_Addr(LpIp4Addr, LusNoOfCounsumerProvider, Userviceid,
                                               LulAddr, Request_type, LblAclCheckUDP, LblClientorServer);
    }
    LucReturnCode = Sd_CheckRemote_Return(LucReturnCode, LblAclCheckTCP,
                                          LblAclCheckUDP, LblAclCheckRemote, LblClientorServer);
  }
  return (LucReturnCode);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_CheckServerIPV6                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Verifies the IPV6 address             **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0591                                         **
*******************************************************************************/
#if (STD_ON == SD_IPV6_ENABLED)
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_CheckServerIPV6(
    TcpIp_SockAddrType * LpOptionTcpAddr,
    TcpIp_SockAddrType * LpOptionUdpAddr,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    uint16 Userviceid,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckTCP,
    boolean LblAclCheckUDP,
    boolean LblAclCheckRemote,
    boolean LblClientorServer)
{
  uint8 LucReturnCode;
  LucReturnCode = SD_ZERO;
  if (Sd_GaaAclPolicyFlag)
  {
    uint8 LusCount;
    uint8 LucCount;
    uint8 lucFcount;
    uint8 LusNoOfCounsumerProvider;
    uint32 LulAddr;

    uint16 LusIndex;
    uint16 LusIndex2;
    uint32 LulSdAllowedAddr;
    TcpIp_SockAddrType const *LpIp6Addr;
    TcpIp_SockAddrType const *LpIp6RemoteAddr;

    Sd_ProviderConsumerListType const *Lp_ConsumerServerProvider;
    LucReturnCode = SD_ZERO;
    LusNoOfCounsumerProvider = SD_ZERO;

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    if (LblClientorServer || !LblClientorServer)
    {
      if ((void *)SD_NVMBLOCK_ID != NULL_PTR)
      {
#if (SD_RAM_BLOCK == STD_ON)
        LusNoOfCounsumerProvider = SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
      }
      else
      {
#if (SD_ROM_BLOCK == STD_ON)
        LusNoOfCounsumerProvider = SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
      }
      if (LpRemoteAddr != SD_NULL_PTR)
      {

        for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
        {
          LpIp6RemoteAddr = LpRemoteAddr;
          Lp_ConsumerServerProvider =
              &Sd_GaaClient_Server_List[LusCount];
          LusIndex = SD_EIGHTTEEN;
          LusIndex2 = SD_EIGHTTEEN;
          lucFcount = SD_ZERO;
          for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
          {
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
            LusIndex--;
            LusIndex2--;
            LulAddr = (uint32)LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
            LulSdAllowedAddr = Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                  made sure that they are initialized with proper Value " */
            LusIndex--;
            LusIndex2--;
            LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                      LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
            LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                               Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                  made sure that they are initialized with proper Value " */
            LusIndex--;
            LusIndex2--;
            LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                      LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
            LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                               Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
            /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
            made sure that they are initialized with proper Value " */
            LusIndex--;
            LusIndex2--;
            LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                      LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
            LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                               Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];

            /* [SWS_SD_00688] */
            /* [SWS_SD_00720] */

            if ((Lp_ConsumerServerProvider->domain == LpIp6RemoteAddr->domain) &&
                (LulSdAllowedAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
            {
              lucFcount++;
            }
          }
          if (lucFcount == SD_FOUR)
          {
            LblAclCheckRemote = SD_TRUE;
          }
        }
      }
    }

#else
    if (LblClientorServer == SD_TRUE)
    {
      LusNoOfCounsumerProvider = SD_NO_OF_PROVIDED_SERVER_CONSUMER;
    }
    else
    {
      LusNoOfCounsumerProvider = SD_NO_OF_ALLOWED_CLIENT_PROVIDER;
    }
    if (LpRemoteAddr != SD_NULL_PTR)
    {

      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        LpIp6RemoteAddr = LpRemoteAddr;

        Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + LusCount);

        LusIndex = SD_EIGHTTEEN;
        LusIndex2 = SD_SIXTEEN;
        lucFcount = SD_ZERO;
        for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
        {
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6RemoteAddr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];

          /* [SWS_SD_00688] */
          /* [SWS_SD_00720] */

          if ((Lp_ConsumerServerProvider->domain == LpIp6RemoteAddr->domain) &&
              (LulSdAllowedAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
          {
            lucFcount++;
          }
        }
        if (lucFcount == SD_FOUR)
        {
          LblAclCheckRemote = SD_TRUE;
        }
      }
    }
#endif

    if (SD_TCP_OPTIONS_MASK != (LucOptionsCode & SD_TCP_OPTIONS_MASK))
    {
      /*  Do Nothing*/
    }
    else
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpIp6Addr = LpOptionTcpAddr;
      if (!LblClientorServer || LblClientorServer)
      {
#if (SD_RAM_BLOCK == STD_ON)
        LusNoOfCounsumerProvider = SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#else
        LusNoOfCounsumerProvider = SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
      }

      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        Lp_ConsumerServerProvider =
            &Sd_GaaClient_Server_List[LusCount];

        LusIndex = SD_EIGHTTEEN;
        LusIndex2 = SD_EIGHTTEEN;
        lucFcount = SD_ZERO;
        for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
        {
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];

          if ((Lp_ConsumerServerProvider->domain == LpIp6Addr->domain) &&
              (LulSdAllowedAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
          {
            lucFcount++;
          }

          /* [SWS_SD_00688] */
          /* [SWS_SD_00720] */
        }
        if (lucFcount == SD_FOUR)
        {
          LblAclCheckTCP = SD_TRUE;
        }
      }
#else

      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        LpIp6Addr = LpOptionTcpAddr;
        if (LblClientorServer == SD_TRUE)
        {

          Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + LusCount);
        }
        else
        {

          Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedProviderStatic) + LusCount);
        }

        LusIndex = SD_EIGHTTEEN;
        LusIndex2 = SD_SIXTEEN;
        lucFcount = SD_ZERO;
        for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
        {
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];

          if ((Lp_ConsumerServerProvider->domain == LpIp6Addr->domain) &&
              (LulSdAllowedAddr == LulAddr))
          {
            lucFcount++;
          }

          /* [SWS_SD_00688] */
          /* [SWS_SD_00720] */
        }
        if (lucFcount == SD_FOUR)
        {
          LblAclCheckTCP = SD_TRUE;
        }
      }
#endif
    }

    if (SD_UDP_OPTIONS_MASK != (LucOptionsCode & SD_UDP_OPTIONS_MASK))
    {
      /*  Do Nothing*/
    }
    else
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpIp6Addr = LpOptionUdpAddr;
      if (!LblClientorServer || LblClientorServer)
      {
#if (SD_RAM_BLOCK == STD_ON)
        LusNoOfCounsumerProvider = SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#else
        LusNoOfCounsumerProvider = SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
      }

      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        Lp_ConsumerServerProvider =
            &Sd_GaaClient_Server_List[LusCount];

        LusIndex = SD_EIGHTTEEN;
        LusIndex2 = SD_EIGHTTEEN;
        lucFcount = SD_ZERO;
        for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
        {
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];

          if ((Lp_ConsumerServerProvider->domain == LpIp6Addr->domain) &&
              (LulSdAllowedAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
          {
            lucFcount++;
          }

          /* [SWS_SD_00688] */
          /* [SWS_SD_00720] */
        }
        if (lucFcount == SD_FOUR)
        {
          LblAclCheckUDP = SD_TRUE;
        }
      }
#else

      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        LpIp6Addr = LpOptionUdpAddr;
        if (LblClientorServer == SD_TRUE)
        {

          Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + LusCount);
        }
        else
        {

          Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedProviderStatic) + LusCount);
        }

        LusIndex = SD_EIGHTTEEN;
        LusIndex2 = SD_SIXTEEN;
        lucFcount = SD_ZERO;
        for (LucCount = SD_FOUR; LucCount > SD_ZERO; LucCount--)
        {
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
                made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];
          /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
          LusIndex--;
          LusIndex2--;
          LulAddr = (uint32)(LulAddr << SD_EIGHT) |
                    LpIp6Addr->aaSockAddrInetData[LusIndex];
          LulSdAllowedAddr = (uint32)(LulSdAllowedAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[LusIndex2];

          if ((Lp_ConsumerServerProvider->domain == LpIp6Addr->domain) &&
              (LulSdAllowedAddr == LulAddr))
          {
            lucFcount++;
          }

          /* [SWS_SD_00688] */
          /* [SWS_SD_00720] */
        }
        if (lucFcount == SD_FOUR)
        {
          LblAclCheckUDP = SD_TRUE;
        }
      }
#endif
    }
    LucReturnCode = Sd_CheckRemote_Return(LucReturnCode, LblAclCheckTCP,
                                          LblAclCheckUDP, LblAclCheckRemote, LblClientorServer);
  }
  return (LucReturnCode);
}

#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
#endif

/*******************************************************************************
** Function Name        : Sd_AclTcpRouting                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Verifies the IPV6 address             **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0588                                         **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclTcpClientRouting(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    Sd_ClientServiceType * LpClientService,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    SoAd_SoConIdType LddTcpIndex)
{
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;
  if (Sd_GaaAclPolicyFlag)
  {
    uint32 LusBaseIndex;
    uint32 LusNoOfElements;
    uint32 LusCount;

    Sd_ConsumedEvGrpType *LpConsumedEvGrp;
    TcpIp_ReturnType LddConnectionReturnValue;

    LddReturnValue = E_OK;
    if ((LucOptionsCode == SD_TWO) || (LucOptionsCode == SD_THREE))
    {

      LddConnectionReturnValue = SoAd_IsConnectionReady(
          Sd_GaaSoConId[LddTcpIndex], LpRemoteAddr);
      if (LddConnectionReturnValue != TCPIP_E_OK)
      {
        LddReturnValue = E_NOT_OK;
      }

      // else
      //   {
      if (!LddReturnValue)
      {
        if (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp)
        {
          LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
          LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
          for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
               LusCount++)
          {
            /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
               stClientStaticFlag is not equal to False. */
            if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag).blActivationRoGrpIdPresent)
            {

              /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
               made sure that they are within their range by having necessary boundary
                  checks in order to prevent them from being out of bounds." */
              (void)SoAd_EnableSpecificRouting(
                  LpClientServiceStatic->ddActivationRoGrpId,
                  Sd_GaaSoConId[LusCount]);
            }
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
            LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
            LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif
            LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];

            if (SD_FALSE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled)
            {
              (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled = SD_TRUE;
              /*polyspace +6 RTE:UNR [Justified:Low] "This Condition shall be True when
              LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent
              is Set as SD_FALSE" */
              if (SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).blTcpActivationRoGrpIdPresent)
              {
                if (LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
                {
                  (void)SoAd_EnableSpecificRouting(
                      LpConsumedEvGrpStatic->ddTcpActivationRoGrpId,
                      Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp]);
                }
              }
            }
          }
        }
      }
      else
      {
        /*Do Nothing*/
      }
      //  }
    }
    else
    {
      /*Do Nothing*/
    }
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_AclUdpRouting                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Verifies the IPV6 address             **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0587                                         **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON) || \
    (SD_ROM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclUdpClientRouting(
    const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
    const Sd_ClientServiceStaticType * LpClientServiceStatic,
    Sd_ClientServiceType * LpClientService,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucOptionsCode,
    SoAd_SoConIdType LddUdpIndex)
{

  Std_ReturnType LddReturnValue = E_OK;
  if (Sd_GaaAclPolicyFlag)
  {
    uint32 LusBaseIndex;
    uint32 LusNoOfElements;
    uint32 LusCount;
    Sd_ConsumedEvGrpType *LpConsumedEvGrp;
    Std_ReturnType LddConnectionReturnValue;
    if ((LucOptionsCode == SD_ONE) || (LucOptionsCode == SD_THREE))
    {

      LddConnectionReturnValue = SoAd_IsConnectionReady(
          Sd_GaaSoConId[LddUdpIndex], LpRemoteAddr);
      if (LddConnectionReturnValue == TCPIP_E_NOT_OK)
      {
        LddReturnValue = E_NOT_OK;
      }

      //   else
      //   {
      if (!LddReturnValue)
      {
        if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
        {
          LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
          LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
          for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
               LusCount++)
          {
            /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
               stClientStaticFlag is not equal to False. */
            if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag).blActivationRoGrpIdPresent)
            {

              /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
               made sure that they are within their range by having necessary boundary
                  checks in order to prevent them from being out of bounds." */
              (void)SoAd_EnableSpecificRouting(
                  LpClientServiceStatic->ddActivationRoGrpId,
                  Sd_GaaSoConId[LusCount]);
            }
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
            LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
#else
            LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount);
#endif
            LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];

            if (SD_FALSE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled)
            {
              (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled = SD_TRUE;
              /*polyspace +6 RTE:UNR [Justified:Low] "This Condition shall be True when
              LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent
              is Set as SD_FALSE" */
              if (SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).blUdpActivationRoGrpIdPresent)
              {
                if (LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
                {
                  (void)SoAd_EnableSpecificRouting(
                      LpConsumedEvGrpStatic->ddUdpActivationRoGrpId,
                      Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp]);
                }
              }
            }
          }
        }
      }
      else
      {
        /*Do Nothing*/
      }
      //}
    }
  }
  return (LddReturnValue);
}

#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_AclTcpServerRouting                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Verifies the IPV6 address             **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            :                                          **
*******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_AclTcpServerRouting(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    TcpIp_SockAddrType LstIpAddrTcp)
{
  if (Sd_GaaAclPolicyFlag)
  {
    uint32 LusBaseIndex;
    uint32 LusNoOfElements;
    uint32 LusCount;
    SoAd_SoConIdType LddWildcardSocketIndex;
    TcpIp_SockAddrType LstIpAddr;
    boolean LblMatchRecdTCP;
    LblMatchRecdTCP = SD_FALSE;
    LddWildcardSocketIndex = SD_ZERO;
    LusBaseIndex = LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpServerServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = SD_ZERO; (LusCount < (LusBaseIndex + LusNoOfElements)) && (SD_FALSE == LblMatchRecdTCP); LusCount++)
    {
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LstIpAddr.domain = LstIpAddrTcp.domain;
      (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddr);

      LblMatchRecdTCP = Sd_MatchIpAddr(&LstIpAddr, &LstIpAddrTcp);
      if (SD_TRUE == LblMatchRecdTCP)
      {
        LddWildcardSocketIndex = (SoAd_SoConIdType)LusCount;
      }
    }

    (void)SoAd_EnableSpecificRouting(
        LpEvHandlerStatic->ddTcpActivationRoGrpId,
        Sd_GaaSoConId[LddWildcardSocketIndex]);

    (void)SoAd_EnableSpecificRouting(
        LpEvHandlerStatic->ddTcpTriggeringRoGrpId,
        Sd_GaaSoConId[LddWildcardSocketIndex]);
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_AclUdpServerRouting                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function Verifies the IPV6 address             **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            :                                          **
*******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_AclUdpServerRouting(
    const Sd_ServerServiceStaticType * LpServerServiceStatic,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    TcpIp_SockAddrType LstIpAddrUdp)
{
  if (Sd_GaaAclPolicyFlag)
  {
    uint32 LusBaseIndex;
    uint32 LusNoOfElements;
    uint32 LusCount;
    SoAd_SoConIdType LddWildcardSocketIndex;
    TcpIp_SockAddrType LstIpAddr;
    boolean LblMatchRecdUDP;
    LblMatchRecdUDP = SD_FALSE;
    LddWildcardSocketIndex = SD_ZERO;

    LusBaseIndex = LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpServerServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = SD_ZERO; (LusCount < (LusBaseIndex + LusNoOfElements)) && (SD_FALSE == LblMatchRecdUDP); LusCount++)
    {
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LstIpAddr.domain = LstIpAddrUdp.domain;
      (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddr);

      LblMatchRecdUDP = Sd_MatchIpAddr(&LstIpAddr, &LstIpAddrUdp);
      if (SD_TRUE == LblMatchRecdUDP)
      {
        LddWildcardSocketIndex = (SoAd_SoConIdType)LusCount;
      }
    }

    (void)SoAd_EnableSpecificRouting(
        LpEvHandlerStatic->ddUdpActivationRoGrpId,
        Sd_GaaSoConId[LddWildcardSocketIndex]);

    (void)SoAd_EnableSpecificRouting(
        LpEvHandlerStatic->ddUdpTriggeringRoGrpId,
        Sd_GaaSoConId[LddWildcardSocketIndex]);
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_CheckRemote_Remote                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function checks remote address                 **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0381                                         **
*******************************************************************************/
#if (SD_ROM_BLOCK == STD_ON) || \
    (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_CheckRemote_Remote(
    const TcpIp_SockAddrType * LpIp4Addr,
    uint8 LusNoOfCounsumerProvider,
    uint16 Userviceid,
    uint32 LulAddr,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckRemote)
{
  if (Sd_GaaAclPolicyFlag)
  {
    uint8 LusCount;
    uint32 LulSdAllowedReAddr;
    Sd_ProviderConsumerListType const *Lp_ConsumerServerProvider;
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    if ((void *)SD_NVMBLOCK_ID != NULL_PTR)
    {
#if (SD_RAM_BLOCK == STD_ON)
      LusNoOfCounsumerProvider = SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
    }
    else
    {
#if (SD_ROM_BLOCK == STD_ON)
      LusNoOfCounsumerProvider = SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
    }
#endif

    if (!LusNoOfCounsumerProvider)
    {
      /*Do Nothing*/
    }
    else
    {
      /*Do nothing*/
    }
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
    {
      Lp_ConsumerServerProvider = &Sd_GaaClient_Server_List[LusCount];
      LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
      if ((Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
          (LulSdAllowedReAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
      {

        LblAclCheckRemote = SD_TRUE;
      }
    }
#else
    for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
    {
      Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + LusCount);

      LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_ZERO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ONE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];

      if ((Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
          (LulSdAllowedReAddr == LulAddr))
      {

        LblAclCheckRemote = SD_TRUE;
      }
    }
#endif
  }
  return (LblAclCheckRemote);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_CheckRemote_TCPAddr                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function checks remote address                 **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            :SD_SDD_0381                                          **
*******************************************************************************/
#if (SD_ROM_BLOCK == STD_ON) || \
    (SD_RAM_BLOCK == STD_ON)

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_CheckRemote_Tcp_Addr(
    const TcpIp_SockAddrType * LpIp4Addr,
    uint8 LusNoOfCounsumerProvider,
    uint16 Userviceid,
    uint32 LulAddr,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckTCP,
    boolean LblClientorServer)
{
  if (Sd_GaaAclPolicyFlag)
  {
    uint8 LusCount;
    uint32 LulSdAllowedReAddr;

    Sd_ProviderConsumerListType const *Lp_ConsumerServerProvider;

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    if ((void *)SD_NVMBLOCK_ID != NULL_PTR)
    {
#if (SD_RAM_BLOCK == STD_ON)
      LusNoOfCounsumerProvider = SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
    }
    else
    {
#if (SD_ROM_BLOCK == STD_ON)
      LusNoOfCounsumerProvider = SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
    }

    if (LblClientorServer || !LblClientorServer)
    {
      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        Lp_ConsumerServerProvider = &Sd_GaaClient_Server_List[LusCount];
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)

        LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
#else

        LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
#endif

        if ((Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
            (LulSdAllowedReAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
        {

          LblAclCheckTCP = SD_TRUE;
        }
      }
    }
#else

    for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
    {
      if (LblClientorServer == SD_TRUE)
      {

        Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + LusCount);
      }
      else
      {

        Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedProviderStatic) + LusCount);
      }

#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)

      LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_ZERO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ONE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
#else

      LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ONE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ZERO];
#endif
      if ((Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
          (LulSdAllowedReAddr == LulAddr))
      {

        LblAclCheckTCP = SD_TRUE;
      }
    }

#endif
  }
  return (LblAclCheckTCP);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_CheckRemote_TCPAddr                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function checks remote address                 **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0381                                          **
*******************************************************************************/
#if ((SD_ROM_BLOCK == STD_ON) || (SD_RAM_BLOCK == STD_ON))
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_CheckRemote_Udp_Addr(
    const TcpIp_SockAddrType * LpIp4Addr,
    uint8 LusNoOfCounsumerProvider,
    uint16 Userviceid,
    uint32 LulAddr,
    Sd_ProviderConsumerType Request_type,
    boolean LblAclCheckUDP,
    boolean LblClientorServer)
{

  if (Sd_GaaAclPolicyFlag)
  {
    uint8 LusCount;
    uint32 LulSdAllowedReAddr;

    Sd_ProviderConsumerListType const *Lp_ConsumerServerProvider;

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    if ((void *)SD_NVMBLOCK_ID != NULL_PTR)
    {
#if (SD_RAM_BLOCK == STD_ON)
      LusNoOfCounsumerProvider = SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
    }
    else
    {
#if (SD_ROM_BLOCK == STD_ON)
      LusNoOfCounsumerProvider = SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER;
#endif
    }
    if (LblClientorServer || !LblClientorServer)
    {
      for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
      {
        Lp_ConsumerServerProvider = &Sd_GaaClient_Server_List[LusCount];
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)

        LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
#else

        LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
        LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                             Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
#endif

        if ((Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
            (LulSdAllowedReAddr == LulAddr) && (Lp_ConsumerServerProvider->usServiceId == Userviceid) && (Lp_ConsumerServerProvider->ListMemberType == Request_type))
        {

          LblAclCheckUDP = SD_TRUE;
        }
      }
    }
#else

    for (LusCount = 0; LusCount < LusNoOfCounsumerProvider; LusCount++)
    {
      if (LblClientorServer == SD_TRUE)
      {

        Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + LusCount);
      }
      else
      {

        Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedProviderStatic) + LusCount);
      }

#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)

      LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_ZERO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ONE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
#else

      LulSdAllowedReAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ONE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Lp_ConsumerServerProvider->SdIpAddress[SD_ZERO];
#endif

      if ((Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
          (LulSdAllowedReAddr == LulAddr))
      {

        LblAclCheckTCP = SD_TRUE;
      }
    }

#endif
  }

  return (LblAclCheckUDP);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_CheckRemote_TCPAddr                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function checks remote address                 **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            :                                          **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_CheckRemote_Return(
    uint8 LucReturnCode,
    boolean LblAclCheckTCP,
    boolean LblAclCheckUDP,
    boolean LblAclCheckRemote,
    boolean LblClientorServer)
{
  if (Sd_GaaAclPolicyFlag)
  {
    if (LblClientorServer == SD_TRUE)
    {
      if (((LblAclCheckTCP == SD_TRUE) &&
           (LblAclCheckUDP == SD_TRUE)) &&
          (LblAclCheckRemote == SD_TRUE))
      {
        LucReturnCode = SD_THREE;
      }

      else if ((LblAclCheckTCP == SD_FALSE) &&
               (LblAclCheckUDP == SD_TRUE) &&
               (LblAclCheckRemote == SD_TRUE))
      {
        LucReturnCode = SD_ONE;
      }
      else if ((LblAclCheckTCP == SD_TRUE) &&
               (LblAclCheckUDP == SD_FALSE) &&
               (LblAclCheckRemote == SD_TRUE))
      {
        LucReturnCode = SD_TWO;
      }
      else
      {
        LucReturnCode = SD_ZERO;
      }
    }
    else
    {
      if (((LblAclCheckTCP == SD_TRUE) &&
           (LblAclCheckUDP == SD_TRUE)))
      {
        LucReturnCode = SD_THREE;
      }
      else if (((LblAclCheckTCP == SD_FALSE) &&
                (LblAclCheckUDP == SD_TRUE)))
      {
        LucReturnCode = SD_ONE;
      }
      else if (((LblAclCheckTCP == SD_TRUE) &&
                (LblAclCheckUDP == SD_FALSE)))
      {
        LucReturnCode = SD_TWO;
      }
      else
      {
        LucReturnCode = SD_ZERO;
      }
    }
  }
  return (LucReturnCode);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_CheckRemote_TCPAddr                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function checks remote address                 **
**                          in the ACL List.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to instance structure          **
**                      : LpOptionTcpAddr - Pointer to addr of TCP option     **
**                      : LpOptionUdpAddr - Pointer to addr of UDP option     **
**                      : LucOptionsCode - Code which indicates which options **
**                          are active ( as in function                       **
**                           Sd_GetIpAddrFromOptions)                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - if address is in subnet     **
**                         range.                                             **
**                        E_NOT_OK - if address is not in subnet range        **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
** Design ID            : SD_SDD_0381                                         **
*******************************************************************************/
#if ((SD_RAM_BLOCK == STD_ON) || \
     (SD_ROM_BLOCK == STD_ON))
/* SWS_SD_00487a  */
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerRemoteCodeReturn(
    const Sd_InstanceType * LpInstance,
    const Sd_InstanceStaticType * LpInstanceStatic,
    const Sd_EntryType * LpEntryData,
    const Sd_OptionsDataType * LpOptionsData,
    uint8 LucTotalNoOfOptions,
    const TcpIp_SockAddrType * LpRemoteAddr,
    uint8 LucReturnCode2,
    uint8 LblServiceMatch)
{
  if (Sd_GaaAclPolicyFlag)
  {
    uint16 LusCount2;
    uint16 LusMatchIndex = SD_ZERO;
    uint16 LddWildcardMatchIndex;
    TcpIp_ReturnType LddConnectionReturnValue;
    TcpIp_SockAddrType LstIpAddr;
    boolean LblMatchRecd;
    boolean LblWildcardMatch;
    SoAd_SoConIdType LddAssignedSoConId;
    LblWildcardMatch = SD_FALSE;
    LblMatchRecd = SD_FALSE;
    LddConnectionReturnValue = TCPIP_E_OK;
    LddWildcardMatchIndex = SD_ZERO;
    (void)SD_MEMSET(&LstIpAddr, (sint32)SD_ZERO, sizeof(TcpIp_SockAddrType));
    if (LucReturnCode2 != SD_ZERO)
    {
      for (LusCount2 = SD_ZERO; LusCount2 <
                                    (SD_NO_OF_SOCKET_CONNECTIONS) &&
                                (SD_FALSE == LblMatchRecd);
           LusCount2++)
      {
        if (LpInstanceStatic->blDomainIpv4)
        {

          LstIpAddr.domain = TCPIP_AF_INET;
        }
        else
        {
          LstIpAddr.domain = TCPIP_AF_INET6;
        }

        (void)SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount2], &LstIpAddr);
        LblMatchRecd = Sd_MatchIpAddr(LpRemoteAddr, &LstIpAddr);
        LusMatchIndex = LusCount2;
        if (!LblWildcardMatch)
        {
          LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddr);
          LddWildcardMatchIndex = LusCount2;
        }
      }
      if (LblMatchRecd)
      {
        LddConnectionReturnValue =
            SoAd_IsConnectionReady(Sd_GaaSoConId[LusMatchIndex],
                                   LpRemoteAddr);
        if (LddConnectionReturnValue == TCPIP_E_NOT_OK)
        {
          SD_UNUSED(LpInstance);
          SD_UNUSED(LpOptionsData);
        }
      }
      else if (LblWildcardMatch)
      {
        (void)SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LddWildcardMatchIndex],
                                       LpRemoteAddr, &LddAssignedSoConId);
        /*TBD:*/
        LddConnectionReturnValue =
            SoAd_IsConnectionReady(Sd_GaaSoConId[LddWildcardMatchIndex],
                                   LpRemoteAddr);
        if (LddConnectionReturnValue == TCPIP_E_NOT_OK)
        {
          SD_UNUSED(LpInstance);
          SD_UNUSED(LpOptionsData);
        }
      }
      else
      {
        LucReturnCode2 = SD_ZERO;
        SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
      }
    }
    if ((LucReturnCode2 != SD_ZERO) && !LddConnectionReturnValue && LblServiceMatch)
    {
      (void)Sd_SubscribeRecd(LpInstance, LpInstanceStatic, LpEntryData,
                             LpRemoteAddr, Sd_GaaRxOptionsData, LucTotalNoOfOptions, LucReturnCode2);
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_AclUpdate                                        **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0381                                        **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddProviderToClientService(uint16 usServiceId,
                              uint16 usServiceInstanceId,
                              const Sd_ProviderConsumerType Request_Type,
                              const TcpIp_SockAddrType * LpRemoteAddr)
{
  uint8 LucIndex;
  uint8 Sd_Configured_Address_Count;
  uint16 LusCount;
  Sd_ProviderConsumerType Req;
  Std_ReturnType LddReturnValue = E_NOT_OK;
  boolean LbReturnValue = SD_FALSE;
  Sd_AclUpdateReturnType Val;
  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  LucIndex = 0;
  Val.Wildcard = 0;
  Val.usindex = 0;
  Req = Request_Type;
  for (LusCount = SD_ZERO; (LusCount < SD_NO_OF_CLIENT_SERVICES) && !LbReturnValue;
       LusCount++)
  {
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];

    if ((usServiceId == LpClientServiceStatic->usServiceId) &&
        usServiceInstanceId == LpClientServiceStatic->usInstanceId)
    {
      if ((LpClientServiceStatic->usMaxNumOfIpAddressesInAcl == 0) && (LpClientServiceStatic->blAclEnable_Disable_Check == SD_TRUE))
      {

        LbReturnValue = Sd_IpAclWildCard(usServiceId, Req, LucIndex, &Val);
      }
      else
      {
        Sd_Configured_Address_Count = Sd_IpAddressCnt(LpClientServiceStatic->usServiceId, Request_Type);
        if (LpClientServiceStatic->usMaxNumOfIpAddressesInAcl > Sd_Configured_Address_Count)
        {
          LbReturnValue = Sd_IpAclWildCard(usServiceId, Req, LucIndex, &Val);
        }
        else
        {
          if ((LpClientServiceStatic->usMaxNumOfIpAddressesInAcl == 0) && (SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER > Sd_Configured_Address_Count))
          {

            LbReturnValue = Sd_IpAclWildCard(usServiceId, Req, LucIndex, &Val);
          }
        }
      }
    }
    else
    {
      /*Do Nothing*/
    }
  }
  LbReturnValue = Val.Wildcard;
  LucIndex = Val.usindex;
  if (LbReturnValue)
  {
    /*How to  store this has to  be decided.*/
    Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].domain = LpRemoteAddr->domain;
    memcpy(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress, &(LpRemoteAddr->aaSockAddrInetData), sizeof(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress));
    LddReturnValue = NvM_WriteBlock(SD_NVMBLOCK_ID, Sd_Gaa_NvMRamBlockData);
  }
  else
  {
    LddReturnValue = E_NOT_OK;
  }
  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_AclUpdate                                        **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0381                                       **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddConsumerToServerService(uint16 usServiceId,
                              uint16 usServiceInstanceId,
                              const Sd_ProviderConsumerType Request_Type,
                              const TcpIp_SockAddrType * LpRemoteAddr)
{
  uint8 LucIndex;
  uint8 Sd_Configured_Address_Count;
  uint16 LusCount;

  Sd_AclUpdateReturnType Val;
  Sd_ProviderConsumerType Req;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Std_ReturnType LddReturnValue = E_NOT_OK;
  boolean LbReturnValue = SD_FALSE;
  Req = Request_Type;
  LucIndex = 0;
  Val.Wildcard = 0;
  Val.usindex = 0;
  for (LusCount = SD_ZERO; (LusCount < SD_NO_OF_SERVER_SERVICES) && !LbReturnValue;
       LusCount++)
  {
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];

    if ((usServiceId == LpServerServiceStatic->usServiceId) &&
        usServiceInstanceId == LpServerServiceStatic->usInstanceId)
    {
      if ((LpServerServiceStatic->usMaxNumOfIpAddressesInAcl == 0) && (LpServerServiceStatic->blAclEnable_Disable_Check == SD_TRUE))
      {

        LbReturnValue = Sd_IpAclWildCard(usServiceId, Req, LucIndex, &Val);
      }
      else
      {
        Sd_Configured_Address_Count = Sd_IpAddressCnt(LpServerServiceStatic->usServiceId, Request_Type);
        if (LpServerServiceStatic->usMaxNumOfIpAddressesInAcl > Sd_Configured_Address_Count)
        {
          LbReturnValue = Sd_IpAclWildCard(usServiceId, Req, LucIndex, &Val);
        }
        else
        {
          if ((LpServerServiceStatic->usMaxNumOfIpAddressesInAcl == 0) && (SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER > Sd_Configured_Address_Count))
          {

            LbReturnValue = Sd_IpAclWildCard(usServiceId, Req, LucIndex, &Val);
          }
        }
      }
    }
    else
    {
      /*Do Nothing*/
    }
  }
  LbReturnValue = Val.Wildcard;
  LucIndex = Val.usindex;
  if (LbReturnValue)
  {
    /*How to  store this has to  be decided.*/
    Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].domain = LpRemoteAddr->domain;
    memcpy(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress, &(LpRemoteAddr->aaSockAddrInetData), sizeof(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress));
    LddReturnValue = NvM_WriteBlock(SD_NVMBLOCK_ID, Sd_Gaa_NvMRamBlockData);
  }
  else
  {
    LddReturnValue = E_NOT_OK;
  }
  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_IpAclWildCard                                     **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0381                                        **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_IpAclWildCard(
    uint16 usServiceId,
    const Sd_ProviderConsumerType Request_type,
    uint8 LucIndex,
    Sd_AclUpdateReturnType * Return_Data)
{
  uint8 luscount;

  boolean lbreturn = SD_FALSE;

  for (luscount = 0; (luscount < SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER) &&
                     (lbreturn == SD_FALSE);
       luscount++)
  {
    if ((Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].domain == SD_WILDCARD_DOMAIN) && (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].ListMemberType == Request_type) &&
        (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].usServiceId == usServiceId))
    {

      LucIndex = luscount;
      lbreturn = SD_TRUE;
    }
    else
    {
      if ((Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].domain == SD_WILDCARD_DOMAIN) && (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].ListMemberType == SD_ANY_TYPE) &&
          (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].usServiceId == 0xFFFFU))
      {
        Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].usServiceId = usServiceId;
        Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].ListMemberType = Request_type;
        LucIndex = luscount;
        lbreturn = SD_TRUE;
      }
    }
  }
  if (LucIndex != SD_ZERO)
  {
    /*Do Nothing*/
  }
  else
  {
    /*Do Nothing*/
  }
  Return_Data->usindex = LucIndex;
  Return_Data->Wildcard = lbreturn;
  if (Return_Data != NULL_PTR)
  {
    /*Do Nothing*/
  }
  else
  {
    /*Do Nothing*/
  }
  return lbreturn;
}

#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_AclUpdate                                        **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              :SD_SDD_0381                                       **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RemoveProviderToClientService(uint16 usServiceId,
                                 uint16 usServiceInstanceId,
                                 Sd_ProviderConsumerType Request_Type,
                                 const TcpIp_SockAddrType * LpRemoteAddr)
{
  uint8 SdIpAddress[18];

  uint16 LusCount;
  static uint8 LucIndex;
  Std_ReturnType LddReturnValue = E_NOT_OK;
  boolean LbReturnValue = SD_FALSE;
  Sd_AclUpdateReturnType Val;
  Sd_ClientServiceStaticType const *LpClientServiceStatic;
  SD_MEMSET(SdIpAddress, (sint32)SD_ZERO, sizeof(SdIpAddress));
  Val.Wildcard = 0;
  Val.usindex = 0;

  for (LusCount = SD_ZERO; (LusCount < SD_NO_OF_SERVER_SERVICES) && (!LbReturnValue);
       LusCount++)
  {
    LpClientServiceStatic = &Sd_GaaClientServiceStatic[LusCount];

    if ((usServiceId == LpClientServiceStatic->usServiceId) &&
        (usServiceInstanceId == LpClientServiceStatic->usInstanceId))
    {

      LbReturnValue = Sd_IpAddAclWildCard(usServiceId, Request_Type, LucIndex, LpRemoteAddr, &Val);
    }
    else
    {
      /*Do Nothing*/
    }
  }
  LbReturnValue = Val.Wildcard;
  LucIndex = Val.usindex;
  if (LbReturnValue)
  {
    Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].domain = SD_WILDCARD_DOMAIN;
    memcpy(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress, SdIpAddress, sizeof(SdIpAddress));
    LddReturnValue = NvM_WriteBlock(SD_NVMBLOCK_ID, Sd_Gaa_NvMRamBlockData);
  }
  else
  {
    LddReturnValue = E_NOT_OK;
  }
  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_AclUpdate                                        **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              :SD_SDD_0381                                        **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_RemoveConsumerToServerService(uint16 usServiceId,
                                 uint16 usServiceInstanceId,
                                 Sd_ProviderConsumerType Request_Type,
                                 const TcpIp_SockAddrType * LpRemoteAddr)
{
  uint8 SdIpAddress[18];

  uint16 LusCount;
  static uint8 LucIndex;
  Std_ReturnType LddReturnValue = E_NOT_OK;
  boolean LbReturnValue = SD_FALSE;
  Sd_AclUpdateReturnType Val;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  SD_MEMSET(SdIpAddress, (sint32)SD_ZERO, sizeof(SdIpAddress));
  Val.Wildcard = 0;
  Val.usindex = 0;

  for (LusCount = SD_ZERO; (LusCount < SD_NO_OF_SERVER_SERVICES) && (!LbReturnValue);
       LusCount++)
  {
    LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount];

    if ((usServiceId == LpServerServiceStatic->usServiceId) &&
        (usServiceInstanceId == LpServerServiceStatic->usInstanceId))
    {

      LbReturnValue = Sd_IpAddAclWildCard(usServiceId, Request_Type, LucIndex, LpRemoteAddr, &Val);
    }
    else
    {
      /*Do Nothing*/
    }
  }
  LbReturnValue = Val.Wildcard;
  LucIndex = Val.usindex;
  if (LbReturnValue)
  {
    Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].domain = SD_WILDCARD_DOMAIN;
    memcpy(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress, SdIpAddress, sizeof(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[LucIndex].SdIpAddress));
    LddReturnValue = NvM_WriteBlock(SD_NVMBLOCK_ID, Sd_Gaa_NvMRamBlockData);
  }
  else
  {
    LddReturnValue = E_NOT_OK;
  }
  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_IpAclWildCard                                     **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0381                                        **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
boolean Sd_IpAddAclWildCard(
    uint16 usServiceId,
    Sd_ProviderConsumerType Request_type,
    uint8 LucIndex,
    const TcpIp_SockAddrType * LpRemoteAddr,
    Sd_AclUpdateReturnType * Return_Data)
{
  uint8 luscount;
  uint32 LulAddr;
  uint32 LulSdAllowedReAddr;
  TcpIp_SockAddrType const *LpIp4Addr;
  boolean lbreturn = SD_FALSE;
  LulAddr = SD_ZERO;

  if (LpRemoteAddr != SD_NULL_PTR)
  {
    LpIp4Addr = LpRemoteAddr;

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_TWO];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_THREE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FOUR];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FIVE];

#else
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
           made sure that they are within their range by having necessary boundary
           checks in order to prevent them from being illegally dereferenced." */
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (uint32)LpIp4Addr->aaSockAddrInetData[SD_FIVE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
        made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_FOUR];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
     made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_THREE];
    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
       made sure that they are initialized with proper Value " */
    LulAddr = (uint32)(LulAddr << SD_EIGHT) |
              LpIp4Addr->aaSockAddrInetData[SD_TWO];

#endif
  }
  for (luscount = 0; (luscount < SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER) &&
                     (lbreturn == SD_FALSE);
       luscount++)
  {
    if ((Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].domain == LpRemoteAddr->domain) && (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].ListMemberType == Request_type) &&
        (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].usServiceId == usServiceId))
    {

      LulSdAllowedReAddr = Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].SdIpAddress[SD_TWO];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].SdIpAddress[SD_THREE];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].SdIpAddress[SD_FOUR];
      LulSdAllowedReAddr = (uint32)(LulSdAllowedReAddr << SD_EIGHT) |
                           Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luscount].SdIpAddress[SD_FIVE];
      if (LulSdAllowedReAddr == LulAddr)
      {
        LucIndex = luscount;
        lbreturn = SD_TRUE;
      }
    }
  }
  Return_Data->Wildcard = lbreturn;
  Return_Data->usindex = LucIndex;

  if (LucIndex != SD_ZERO)
  {
    /*Do Nothing*/
  }
  else
  {
    /*Do Nothing*/
  }
  if (Return_Data != NULL_PTR)
  {
    /*Do Nothing*/
  }
  else
  {
    /*Do Nothing*/
  }
  return lbreturn;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_IpAddressCpy                                     **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Update Service ACL SdClientServiceAllowedProviders or**
**                      SdServerServiceAllowedConsumers depending on Client or**
**                      Server service by adding or removing this IP address. **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServiceId,ServiceInstanceId, RemoteAddrPtr,       **
**                        RequestType                                         **
**                                                                            **
**                                                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  :Sd_GaaAclPolicyFlag            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              :SD_SDD_0444,SD_SDD_0446,SD_SDD_6022,SD_SDD_6023,   **
**                           SD_SDD_6024,SD_SDD_6025,SD_SDD_6020,SD_SDD_6021, **
**						   SD_SDD_0560,SD_SDD_0562,SD_SDD_0561,SD_SDD_6026,   **
**						   SD_SDD_0564,SD_SDD_6027,SD_SDD_0563,SD_SDD_6028,   **
**						   SD_SDD_6029,SD_SDD_0565,SD_SDD_0557,SD_SDD_0556,   **
**						   SD_SDD_60331,SD_SDD_0559,SD_SDD_0558               **
*******************************************************************************/
#if (SD_RAM_BLOCK == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
uint8 Sd_IpAddressCnt(
    uint16 UsserviceId,
    const Sd_ProviderConsumerType Address_Type)
{

  uint8 luccount;
  uint8 Sd_Configured_IP;
  Sd_Configured_IP = SD_ZERO;
  for (luccount = 0; luccount < SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER; luccount++)
  {

    if ((Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luccount].ListMemberType == Address_Type) &&
        (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luccount].usServiceId == UsserviceId) &&
        (Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList[luccount].domain != SD_WILDCARD_DOMAIN))
    {

      Sd_Configured_IP++;
    }
  }

  return (Sd_Configured_IP);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/****************************************************************************
**                   Parasoft violations end Section                       **
****************************************************************************/

/* parasoft-end-suppress MISRAC2012-RULE_20_1-a-4 */
/* parasoft-end-suppress MISRAC2012-RULE_5_4-c-2 */
/* parasoft-end-suppress MISRAC2012-RULE_5_4-d-2 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
