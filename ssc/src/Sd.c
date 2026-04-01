/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd.c                                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the main function and API's of the         **
**              Service Discovery module                                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
** Prev. AUTOSAR Version : R23-11                                             **
**                                                                            **
** Prev. Software Version : 1.0.0                                             **
**                                                                            **
**  Design ID : SD_SDD_0016                                                   **
**                                                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Date         Changed By          Description                               **
********************************************************************************
** 15-Sep-2025  Gourav Purohit      Initial Release.                          **
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

/* parasoft-begin-suppress MISRAC2012-RULE_1_1-c-2 "Reason: The warning is 
* getting reported for the memory section declaration which can not be avoided,
* These macros are part of AUTOSAR Specific definitions for inclusion of 
* memory map files for Code and Global data sections and configuration 
* Specific macros present in .h, so this warning needs to be deviated." */

/*******************************************************************************
**                   MISRA-C:2012 violations Section                          **
*******************************************************************************/
/** At section SD_c_REF_1
* Violates MISRA 2012 Advisory Rule 2.2, This statement has no side effects.
* This statement is required for polyspace.
* Justification: For the unused variables or variables which are set but not
* used for specific configuration compiler shows warning. QAC shows dead code
* for the steps which are implemented to avoid such compiler warnings.

* #section SD_C_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* All the #include statements in a particular code file should be grouped
* together near the head of the file. The rule states that the only items which
* may precede a #include in a file are other preprocessor directives or comments
* Justification: As per RS_BSW_00437 in AUTOSAR_SRS_BSWGeneral document Memory
* mapping is provided as start and stop memory sections. This is approved
* by AUTOSAR.

* #section SD_C_REF_3
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
 * PRQA S 5087
 * violates #ref SD_C_REF_1 Violates MISRA 2012 Required Rule 20.1
 * As per KPIT coding guidelines, macro name should start from module name
 * (upper case) and hence this violation is suppressed as it does not impact the module funtionality
 * #violates #ref SD_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)
 * PRQA S 0857
 * Part of common deviation.
 * violates #ref SD_c_REF_3 Violates MISRA 2012 Dir-1.1
 * PRQA S 0380
 * Part of common deviation
 * #Violates #ref SD_c_REF_7, DCL00 Msg(qac-10.1.0-3227)
 * PRQA S 3227
 * The message can be suppressed in case of AUTOSAR provided Standard API input arguments:
 * Since the function parameters that are pointers to values of standard API are
 * provided by AUTOSAR specifications, it cannot be modified.
 * It does not impact the module funtionality and hence this violation is suppressed.
 * 2. The message can be suppressed case to case deviation in case of internal functions:
 * The function argument is not used in the current function, but inturn passed
 * to another function to retrieve data. Hence the argument is still used as
 * pointer to variable instead of pointer to constant. It can be suppressed and
 * hence does'nt have impact on functionality.
 *
 * #Violates #ref SD_State_c_REF_9,PRE04 Msg(certccm-2.1.0-5001)
 *PRQA S 5001 EOF
 * All the files in the header files  start with a specific format <Sd_xyz.h>
 * due to guidelines of the Autosar
 *
 * #Violates #ref SD_c_REF_6,INT02 Msg(qac-10.1.0-2100)
 * PRQA S 2100
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 *
 * #Violates #ref SD_c_REF_7,INT02 Msg(qac-10.1.0-2101)
 * PRQA S 2101
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 * #Violates #ref SD_c_REF_8,INT02 Msg(qac-10.1.0-1251)
 * PRQA S 1251
 * This is waived Off whenever the Conversion  required accoding to design of  functionality .
 * #Violates #ref SD_c_REF_8,PRE08 Msg(certccm-2.1.0-5002)
 * PRQA S 5002
 * All the files in the header files  start with a specific format <Sd_xyz.h> due to guidelines of the Autosar.
 * #Violates #ref SD_c_REF_4,INT30 Msg(qac-10.1.0-3383)
 * PRQA S 3383
 * Deviation:77966
 * #Violates #ref SD_c_REF_5,MSC01 Msg(qac-10.1.0-2000)
 * PRQA S 2000
 * Deviation:77966
 * #Violates #ref SD_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)
 * PRQA S 4810
 * Deviation:77966
 *
 **/
/* PRQA S 5087 EOF */
/* violates #ref SD_C_REF_1 Violates MISRA 2012 Required Rule 20.1 */

/*#violates #ref SD_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)*/
/*PRQA S 0857 EOF*/

/* violates #ref SD_c_REF_3 Violates MISRA 2012 Dir-1.1 */
/* PRQA S 0380 EOF */

/* #Violates #ref SD_c_REF_7, DCL00 Msg(qac-10.1.0-3227) */
/* PRQA S 3227 EOF */

/* #Violates #ref SD_c_REF_4,INT30 Msg(qac-10.1.0-3383) */
/*PRQA S 3383 EOF*/

/* #Violates #ref SD_c_REF_5,MSC01 Msg(qac-10.1.0-2000) */
/*PRQA S 2000 EOF*/

/* #Violates #ref SD_c_REF_6,INT02 Msg(qac-10.1.0-2100) */
/*PRQA S 2100 EOF*/

/* #Violates #ref SD_c_REF_7,INT02 Msg(qac-10.1.0-2101) */
/*PRQA S 2101 EOF*/

/* #Violates #ref SD_c_REF_8,INT02 Msg(qac-10.1.0-1251) */
/*PRQA S 1251 EOF*/

/* #Violates #ref SD_State_c_REF_9,PRE04 Msg(certccm-2.1.0-5001) */
/*PRQA S 5001 EOF*/

/* #Violates #ref SD_c_REF_8,PRE08 Msg(certccm-2.1.0-5002)  */
/*PRQA S 5002 EOF*/

/* #Violates #ref SD_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
/*PRQA S 4810 EOF */
/*PRQA S 2017,3131,3408,3447,3602,3621 EOF*/
/* #Violates #ref SD_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-0488)  */
/*PRQA S 0488 EOF*/
/*PRQA S 1252 EOF*/

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
#include "SoAd.h"
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
/* Design ID : SD_SDD_0053 */

/*Design ID : SD_SDD_0418*/
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GblInitCalled;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0425*/
#define SD_START_SEC_VAR_CLEARED_8
#include "Sd_MemMap.h"
uint8 Sd_GucSdInstanceIndex;
#define SD_STOP_SEC_VAR_CLEARED_8
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0423*/
#define SD_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sd_MemMap.h"
PduInfoType Sd_GddPduInfoPtr;
#define SD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0400*/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GaaBswMEvNotifiFlag[SD_NO_OF_EV_HANDLERS];
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif
/*Design ID : SD_SDD_0420*/
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GblTxSuccessFLag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
 boolean Sd_GblBswClientRepitionStateFlag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
 boolean Sd_GblBswServerRepitionStateFlag;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GblSubscribeInQueue;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif

/*Design ID : SD_SDD_0405*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_InstanceType Sd_GaaInstance[SD_NO_OF_INSTANCES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_InstancePartnerType Sd_GaaInstancePartner
    [SD_NO_OF_INSTANCES * SD_MAX_INSTANCE_PARTNER];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0414*/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_ServerServiceType Sd_GaaServerService
    [SD_NO_OF_SERVER_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
/*Design ID : SD_SDD_0403*/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_EvHandlerType Sd_GaaEvHandler[SD_NO_OF_EV_HANDLERS];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
/*Design ID : SD_SDD_0404*/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_EvHandlerSubGrpType Sd_GaaEvHandlerSubGrp
    [SD_NO_OF_EV_HANDLERS * SD_SIXTEEN];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_ClientServiceType Sd_GaaClientService
    [SD_NO_OF_CLIENT_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_ConsumedEvGrpType Sd_GaaConsumedEvGrp
    [SD_NO_OF_CONSUMED_EV_GRP];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
/*Design ID : SD_SDD_0412*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_OptionsDataType Sd_GaaRxOptionsData[SD_SIXTEEN];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0417*/
#define SD_START_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"
uint8 Sd_GaaTxSduData[SD_MAX_PDU_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0413*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_EntryType Sd_GaaSendEntrys[SD_MAX_ENTRIES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0409*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_QueueType Sd_GaaQueue[SD_QUEUE_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0411*/
#define SD_START_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"
uint8 Sd_GaaQueueStatus[SD_QUEUE_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_8
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0408*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_OptionsRefType Sd_GaaOptionsRef[SD_SIXTEEN];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0410*/
#define SD_START_SEC_VAR_NO_INIT_16
#include "Sd_MemMap.h"
uint16 Sd_GaaQueueSend[SD_QUEUE_SIZE];
#define SD_STOP_SEC_VAR_NO_INIT_16
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0407*/
#define SD_START_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
uint32 Sd_GaaIpAddr[SD_SIXTY_FOUR];
#define SD_STOP_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0421*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
TcpIp_SockAddrType Sd_GddIpv4Wildcard;
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0422*/
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
TcpIp_SockAddrType Sd_GddIpv6Wildcard;
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0424*/
#define SD_START_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
sint32 Sd_GslRandomState;
#define SD_STOP_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0426*/
#define SD_START_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
uint32 Sd_GulRandomValue;
#define SD_STOP_SEC_VAR_NO_INIT_32
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0419*/
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GblRandomCalled;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
/*Design ID : SD_SDD_0416*/

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_SoConGroupType Sd_GaaSoConGroup[SD_NO_OF_SO_CON_GRPS];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0415*/

#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_SoConType Sd_GaaSoCon[SD_NO_OF_SOCKET_CONNECTIONS];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"

/*Design ID : SD_SDD_0450,SD_SDD_0451*/
#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_CLIENT_CONFIGURED))
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_ClientCounterType Sd_GaaClientRequestCounter[SD_NO_OF_CLIENT_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
/*Design ID : SD_SDD_0450,SD_SDD_0451*/
#if ((STD_ON == SD_SERVICE_GROUP_CONFIGURED) && \
     (STD_ON == SD_SERVER_CONFIGURED))
#define SD_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
Sd_ServerAvailabilityCounterType Sd_GaaServerAvailabilityCounter[SD_NO_OF_SERVER_SERVICES];
#define SD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
/*Design ID : SD_SDD_0450,SD_SDD_0451*/
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GaaServiceGrpIdFlag[SD_SERVICE_GROUP];
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
#endif
#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
#define SD_START_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
const Sd_ConfigType * Sd_GpConfigPtr;
#define SD_STOP_SEC_CONST_UNSPECIFIED
#include "Sd_MemMap.h"
#endif
#if (SD_NVM_BLOCK_LENGTH != SD_ZERO)
static Sd_NvMRamBlockData_type SdShadowNvMRamBlockData[SD_ONE ];
#endif
#if (SD_RAM_BLOCK == STD_ON)

static boolean Sd_NvmReadInit = SD_FALSE;
#endif
#define SD_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"
boolean Sd_GaaAclPolicyFlag  = SD_ZERO;
#define SD_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sd_MemMap.h"

/*******************************************************************************
**                              In-line Functions                             **
*******************************************************************************/

/*******************************************************************************
**                      	Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Sd_ServerServiceSetState                            **
**                                                                            **
** Service ID           : 0x07                                                **
**                                                                            **
** Description          : This API function is used by the BswM to set the    **
**                      : Server Service Instance state.                      **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdServerServiceHandleId : ID to identify the        **
**                           Server Service Instance.                         **
**                                                                            **
**                      : ServerServiceState : The state the Server Service   **
**                      : Instance shall be set to.                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK: State accepted               **
**                             E_NOT_OK: State not accepted                   **
**                                                                            **
** Preconditions        : Sd must be initialised                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerHandleMapArray    **
**                          Sd_GaaServerService, Sd_GblInitCalled             **
**                                                                            **
**                        Function(s) invoked : Det_ReportError               **
** Design ID              : SD_SDD_0283,SD_SDD_0075,SD_SDD_0079,SD_SDD_0444,  **
**                          SD_SDD_0025                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_ServerServiceSetState(
    uint16 SdServerServiceHandleId,
    Sd_ServerServiceSetStateType ServerServiceState)
{
  Std_ReturnType LddReturnValue;
#if (STD_ON == SD_SERVER_CONFIGURED)
  uint16 LusIndex;
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  const Sd_ServerServiceStaticType *const LpServerServiceStatic =
      &Sd_GaaServerServiceStatic[SdServerServiceHandleId];
#else
  const Sd_ServerServiceStaticType *const LpServerServiceStatic =
      ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) +
       SdServerServiceHandleId);
#endif
#endif
#endif

  LddReturnValue = E_OK;

/* SWS ID SWS_SD_00407 SWS_SD_00496c SWS_SD_00496d SWS_SD_00408a*/
/* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be False when
   the sd module is in INITIALIZED state.
   Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00407" */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  if (!Sd_GblInitCalled)

  {
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_SERVER_SERVICE_SET_STATE_SID, SD_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
  the sd module is in INITIALIZED state.
  Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00407" */
  if (E_OK == LddReturnValue)
#endif
  {
    /* SWS ID  SWS_SD_00472 SWS_SD_00408b SWS_SD_00472a SWS_SD_00472b */
    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be False when
       the ServerServiceState is not equal to Sd_Server Service SetState Type.
       Module Test Case Reference SD_ETC_416, SWS ID SWS_SD_00472" */
    if ((ServerServiceState != SD_SERVER_SERVICE_AVAILABLE) &&
        (ServerServiceState != SD_SERVER_SERVICE_DOWN))
    {
      LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
      (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                            SD_SERVER_SERVICE_SET_STATE_SID, SD_E_INV_MODE);
#endif
    }

    /* SWS ID SWS_SD_00610 SWS_SD_00607a  SWS_SD_00607b */
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
      when the LddReturnValue is  equal to E_OK .
      Module Test Case Reference SD_SRS_407, SWS ID SWS_SD_00610" */
    if (E_OK == LddReturnValue)
#if (STD_ON == SD_SERVER_CONFIGURED)
    {
      if (SdServerServiceHandleId >= SD_NO_OF_SERVER_SERVICES)
      {
        LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
        (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                              SD_SERVER_SERVICE_SET_STATE_SID, SD_E_INV_ID);
#endif
      }
    }
    if (E_OK == LddReturnValue)
    {
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
      if (LpServerServiceStatic->pServiceGroupRef == SD_NULL_PTR)
#endif

      { /* SWS ID  SWS_SD_00005   SWS_SD_00496e  SWS_SD_00496f   SWS_SD_00496i */
        /* polyspace +7 RTE:UNR [Justified:Low] "This condition shall be Truewhen
           when the LddReturnValue is  equal to E_OK .
       Module Test Case Reference SD_SRS_407, SWS ID SWS_SD_00610" */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LusIndex = Sd_GaaServerHandleMapArray[SdServerServiceHandleId];
#else
        LusIndex = Sd_GpConfigPtr->pSd_GaaServerHandleMapArray[SdServerServiceHandleId];
#endif
        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
           made sure that they are within their range by having necessary boundary
           checks in order to prevent them from being out of bounds." */
        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaServerService[LusIndex].enServerServiceSetState =
            ServerServiceState;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
    }

#else
    { /* SWS ID   SWS_SD_00496j */
      /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
      /*PRQA S 3112 2 */

      SD_UNUSED(SdServerServiceHandleId);
      LddReturnValue = E_NOT_OK;
    }
#endif
  }
  return LddReturnValue;
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_ClientServiceSetState                            **
**                                                                            **
** Service ID           : 0x08                                                **
**                                                                            **
** Description          : This API function is used by the BswM to set the    **
**                      : Client Service Instance state.                      **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ClientServiceHandleId : ID to identify the          **
**                           Client Service Instance.                         **
**                                                                            **
**                      : ClientServiceState : The state the Client Service   **
**                      : Instance shall be set to.                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK: State accepted               **
**                             E_NOT_OK: State not accepted                   **
**                                                                            **
** Preconditions        : Sd must be initialised                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaClientHandleMapArray    **
**                          Sd_GaaClientService, Sd_GblInitCalled             **
**                                                                            **
**                        Function(s) invoked : Det_ReportError               **
** Design ID            : SD_SDD_0281,SD_SDD_0029                             **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_ClientServiceSetState(
    uint16 ClientServiceHandleId,
    Sd_ClientServiceSetStateType ClientServiceState)
{
  Std_ReturnType LddReturnValue;
#if (STD_ON == SD_CLIENT_CONFIGURED)
  uint16 LusIndex;

#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  const Sd_ClientServiceStaticType *const LpClientServiceStatic = &Sd_GaaClientServiceStatic[ClientServiceHandleId];
#else
  const Sd_ClientServiceStaticType *const LpClientServiceStatic =
      ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + ClientServiceHandleId);
#endif
#endif
#endif

  LddReturnValue = E_OK;

/* SWS ID   SWS_SD_00410   SWS_SD_00409c */
/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
the sd module is in INITIALIZED state.
Module Test Case Reference SD_ETC_423, SWS ID SWS_SD_00410" */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  if (!Sd_GblInitCalled)
  {
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_CLIENT_SERVICE_SET_STATE_SID, SD_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
  the sd module is in INITIALIZED state.
  Module Test Case Reference SD_ETC_423, SWS ID SWS_SD_00410" */
  if (E_OK == LddReturnValue)
#endif
  {
    /* SWS ID   SWS_SD_00443   SWS_SD_00350b   SWS_SD_00409e */
    /* SWS ID   SWS_SD_00411   SWS_SD_0411b */
    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be False when
       the ClientServiceState is not equal to Sd_ClientServiceSetStateType.
       Module Test Case Reference SD_ETC_279, SWS ID SWS_SD_00443" */
    if ((ClientServiceState != SD_CLIENT_SERVICE_REQUESTED) &&
        (ClientServiceState != SD_CLIENT_SERVICE_RELEASED))
    {
      LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
      (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                            SD_CLIENT_SERVICE_SET_STATE_SID, SD_E_INV_MODE);
#endif
    }
    /* SWS ID   SWS_SD_00608   SWS_SD_00608b */
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
    the LddReturnValue is  equal to E_OK .
    Module Test Case Reference SD_SRS_1009, SWS ID SWS_SD_00608" */
    if (E_OK == LddReturnValue)
#if (STD_ON == SD_CLIENT_CONFIGURED)
    {
      if (ClientServiceHandleId >= SD_NO_OF_CLIENT_SERVICES)
      {
        LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
        (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                              SD_CLIENT_SERVICE_SET_STATE_SID, SD_E_INV_ID);
#endif
      }
    }
    /* SWS ID  SWS_SD_00005  SWS_SD_00409f  SWS_SD_00409i */
    if (E_OK == LddReturnValue)
    {
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
      /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
      the pServiceGroupRef is not equal to NULL_PTR .
      Module Test Case Reference SWS ID SWS_SD_00409 */
      if (LpClientServiceStatic->pServiceGroupRef == (Sd_ServiceGroupType *)SD_NULL_PTR)
#endif
      {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LusIndex = Sd_GaaClientHandleMapArray[ClientServiceHandleId];
#else
        LusIndex = Sd_GpConfigPtr->pSd_GaaClientHandleMapArray[ClientServiceHandleId];
#endif
        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
         checks in order to prevent them from being out of bounds." */
        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaClientService[LusIndex].enClientSetState = ClientServiceState;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
    }
#else
    {
      /* SWS ID   SWS_SD_00409j */
      LddReturnValue = E_NOT_OK;

      /* #violates #ref SD_C_REF_3 Violates MISRA 2012 Required Rule 2.2*/
      /*PRQA S 3112 2 */

      SD_UNUSED(ClientServiceHandleId);
    }
#endif
  }
  return LddReturnValue;
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_ConsumedEventGroupSetState                       **
**                                                                            **
** Service ID           : 0x09                                                **
**                                                                            **
** Description          : This API function is used by the BswM to set the    **
**                      : requested state of the EventGroupStatus.            **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SdConsumedEventGroupHandleId : ID to identify the   **
**                           Consumed Eventgroup.                             **
**                                                                            **
**                      : ConsumedEventGroupState : The state the             **
**                      : Eventgroup shall be set to.                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK: State accepted               **
**                             E_NOT_OK: State not accepted                   **
**                                                                            **
** Preconditions        : Sd must be initialised                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConEvGrpHandleMapArray, **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GaaClientService,   **
**                          Sd_GaaConsumedEvGrp, Sd_GblInitCalled             **
**                                                                            **
**                        Function(s) invoked : Det_ReportError               **
** Design ID              : SD_SDD_0282                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_ConsumedEventGroupSetState(
    uint16 SdConsumedEventGroupHandleId,
    Sd_ConsumedEventGroupSetStateType ConsumedEventGroupState)
{
  Std_ReturnType LddReturnValue;
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  uint16 LusIndex;
  Sd_ClientServiceType const *LpClientService;
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
#endif

  LddReturnValue = E_OK;

/* SWS ID  SWS_SD_00469   SWS_SD_00560c  SWS_SD_00560i   SWS_SD_00470a  */
/* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be False when
the sd module is in INITIALIZED state.
Module Test Case Reference SD_ETC_424, SWS ID SWS_SD_00469" */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  if (!Sd_GblInitCalled)
  {
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_CONSUMED_EVENT_GROUP_SET_STATE_SID, SD_E_UNINIT);
    LddReturnValue = E_NOT_OK;
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
  the sd module is in INITIALIZED state.
  Module Test Case Reference SD_ETC_424, SWS ID SWS_SD_00469" */
  if (E_OK == LddReturnValue)
#endif
  {
    /* SWS ID  SWS_SD_00472 */
    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
     the sd module is in INITIALIZED state.
     Module Test Case Reference SD_SRS_1041, SWS ID SWS_SD_00472 */
    if ((ConsumedEventGroupState != SD_CONSUMED_EVENTGROUP_REQUESTED) &&
        (ConsumedEventGroupState != SD_CONSUMED_EVENTGROUP_RELEASED))
    {
      LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
      (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                            SD_CONSUMED_EVENT_GROUP_SET_STATE_SID, SD_E_INV_MODE);
#endif
    }
    /* SWS ID   SWS_SD_00609   SWS_SD_00470b   SWS_SD_00609b  */
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
    when the LddReturnValue is  equal to E_OK .
  Module Test Case Reference SD_SRS_1027, SWS ID SWS_SD_00609" */
    if (E_OK == LddReturnValue)
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
    {
      if (SdConsumedEventGroupHandleId >= SD_NO_OF_CONSUMED_EV_GRP)
      {
        LddReturnValue = E_NOT_OK;
#if (STD_ON == SD_DEV_ERROR_DETECT)
        (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                              SD_CONSUMED_EVENT_GROUP_SET_STATE_SID, SD_E_INV_ID);
#endif
      }
    }
    /* SWS ID   SWS_SD_00005   SWS_SD_00560e   SWS_SD_00560f  */
    if (E_OK == LddReturnValue)
    {
/* SWS ID   SWS_SD_00442  */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LusIndex = Sd_GaaConEvGrpHandleMapArray[SdConsumedEventGroupHandleId];
      LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusIndex];
#else
      LusIndex =
          Sd_GpConfigPtr->pSd_GaaConEvGrpHandleMapArray[SdConsumedEventGroupHandleId];
      LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusIndex);
#endif
      /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
     checks in order to prevent them from being illegally dereferenced." */
      /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
          made sure that they are initialized with proper Value " */
      LpClientService = &Sd_GaaClientService
                            [LpConsumedEvGrpStatic->usClientServiceIndex];
      if (SD_CLIENT_SERVICE_RELEASED == LpClientService->enClientSetState)
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {

        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being out of bounds." */
        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaConsumedEvGrp[LusIndex].enConEvGrpSetState = ConsumedEventGroupState;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
        LddReturnValue = E_OK;
      }
    }

#else
    {
      /* SWS ID  SWS_SD_00560j */
      LddReturnValue = E_NOT_OK;

      /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
      /*PRQA S 3112 2 */

      SD_UNUSED(SdConsumedEventGroupHandleId);
    }
#endif
  }
  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_GetVersionInfo                                   **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : This service returns the version information of     **
**                        Sd module. The version information includes:        **
**                        - Module Id                                         **
**                        - Vendor Id                                         **
**                        - Vendor specific version numbers.                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : versioninfo                                         **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : Det_ReportError            **
** Design ID              : SD_SDD_0152, SD_SDD_0057                          **
*******************************************************************************/
#if (STD_ON == SD_GET_VERSION_INFO)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_GetVersionInfo(
    Std_VersionInfoType * versioninfo)
{
/*SWS ID  SWS_SD_00497  SWS_SD_00124c   SWS_SD_00124g*/
/* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
the versioninfo is equal to SD_NULL_PTR.
Module Test Case Reference SD_ETC_009, SWS ID SWS_SD_00497" */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  if (SD_NULL_PTR == versioninfo)
  {
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_GET_VERSION_INFO_SID, SD_E_PARAM_POINTER);
  }
  else
#endif
  /* SWS ID  SWS_Sd_00125 */
  {

    versioninfo->vendorID = SD_VENDOR_ID;

    versioninfo->moduleID = SD_MODULE_ID;

    versioninfo->sw_major_version = (uint8)SD_SW_MAJOR_VERSION;

    versioninfo->sw_minor_version = (uint8)SD_SW_MINOR_VERSION;

    versioninfo->sw_patch_version = (uint8)SD_SW_PATCH_VERSION;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_Init                                             **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : Initializes the Service Discovery                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : ConfigPtr : Pointer to a selected configuration     **
**                           structure.                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstance,               **
**                          Sd_GaaInstanceStatic, Sd_GaaServerService,        **
**                          Sd_GaaServerServiceStatic, Sd_GaaClientService,   **
**                          Sd_GaaClientServiceStatic, Sd_GaaQueueStatus,     **
**                          Sd_GaaQueueSend, Sd_GaaSoCon,                     **
**                          Sd_GaaInstancePartner, Sd_GaaSoConGroup           **
**                          Sd_GblInitCalled, Sd_GddIpv4Wildcard,             **
**                          Sd_GddIpv6Wildcard, Sd_GslRandomState,            **
**                          Sd_GblRandomCalled, Sd_GulRandomValue             **
**                                                                            **
**                        Function(s) invoked : Det_ReportError               **
**                          Sd_InitServer, Sd_InitClient, Sd_GetRandomVal     **
**                                                                            **
** Design ID              : SD_SDD_0134, SD_SDD_0016,SD_SDD_0063              **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_Init(
    const Sd_ConfigType * ConfigPtr)
{
  Sd_InstanceType *LpInstance;
  Sd_SoConType *LpSocket;
  Sd_InstanceStaticType const *LpInstanceStatic;
  Sd_InstancePartnerType *LpInstancePartner;
  Sd_SoConGroupType *LpSoConStructure;
  uint16 LusCount;
#if (STD_ON == SD_DEV_ERROR_DETECT)
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;
#endif

  if ((void *)SD_NVMBLOCK_ID != NULL_PTR)
  {
  #if (SD_NVM_BLOCK_LENGTH != SD_ZERO)
   NvM_ReadBlock(SD_NVMBLOCK_ID, SdShadowNvMRamBlockData);
   Sd_NvmReadInit = SD_TRUE;
  #endif

  }
  else
  {
    #if (SD_ROM_BLOCK == STD_ON)

      Sd_GaaAclPolicyFlag = Sd_Gaa_NvMRomBlockData[0].bl_Sd_ACL_PolicyCheck;
      memcpy(Sd_GaaClient_Server_List, Sd_Gaa_NvMRomBlockData[0].Sd_GaaServerClientList, sizeof(Sd_Gaa_NvMRomBlockData[0].Sd_GaaServerClientList));
    #endif
  }
/* SWS ID  SWS_SD_00119  SWS_SD_00119e  SWS_SD_00122 */
#if (STD_ON == SD_DEV_ERROR_DETECT)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be false when
  the ConfigPtr is equal to NULL .
  Module Test Case Reference SD_ETC_002, SWS ID SWS_SD_00119" */
  if (ConfigPtr != SD_NULL_PTR)
  {

    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_INIT_SID, SD_E_INIT_FAILED);

    LddReturnValue = E_NOT_OK;
  }
#else

  if ((ConfigPtr == SD_NULL_PTR) ||
      (SD_DBTOC_VALUE != ConfigPtr->ulStartOfDbToc))
  {

    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_INIT_SID, SD_E_INIT_FAILED);

    LddReturnValue = E_NOT_OK;
  }
#endif
  if (E_OK == LddReturnValue)
#else
  /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
  /*PRQA S 3112 1 */
  SD_UNUSED(ConfigPtr);
#endif
  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be true when
  the ConfigPtr is NOT NULL .
  Module Test Case Reference SD_ETC_002, SWS ID SWS_SD_00119" */
  {
/* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
/*PRQA S 3112 1 */
/* Store the config pointer to a global pointer */
#if (STD_OFF == SD_PRE_COMPILE_SINGLE)
    Sd_GpConfigPtr = ConfigPtr;
#else
    /* #violates #ref SD_C_REF_2 Violates MISRA 2012 Required Rule 2.2*/
    /*PRQA S 3112 1 */
    SD_UNUSED(ConfigPtr);
#endif
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#if (SD_NO_OF_EV_HANDLERS != SD_ONE)
    for (LusCount = SD_ZERO; LusCount < SD_NO_OF_EV_HANDLERS; LusCount++)

#else
    LusCount = SD_ZERO;

#endif
    {
      Sd_GaaBswMEvNotifiFlag[LusCount] = (boolean)SD_FALSE;
    }

#endif

    Sd_GblTxSuccessFLag = (boolean)SD_TRUE;

    Sd_GddIpv4Wildcard.domain = TCPIP_AF_INET;
    Sd_GddIpv4Wildcard.aaSockAddrInetData[SD_ZERO] = SD_WILDCARD_PORT;
    Sd_GddIpv4Wildcard.aaSockAddrInetData[SD_ONE] = SD_WILDCARD_PORT;
    Sd_GddIpv4Wildcard.aaSockAddrInetData[SD_TWO] = SD_WILDCARD_ADDR;
    Sd_GddIpv4Wildcard.aaSockAddrInetData[SD_THREE] = SD_WILDCARD_ADDR;
    Sd_GddIpv4Wildcard.aaSockAddrInetData[SD_FOUR] = SD_WILDCARD_ADDR;
    Sd_GddIpv4Wildcard.aaSockAddrInetData[SD_FIVE] = SD_WILDCARD_ADDR;

#if (STD_ON == SD_IPV6_ENABLED)
    Sd_GddIpv6Wildcard.domain = TCPIP_AF_INET6;
    Sd_GddIpv6Wildcard.aaSockAddrInetData[SD_ZERO] = SD_WILDCARD_PORT;
    Sd_GddIpv6Wildcard.aaSockAddrInetData[SD_ONE] = SD_WILDCARD_PORT;
    for (LusCount = SD_ZERO; LusCount < SD_EIGHTTEEN; LusCount++)
    {
      Sd_GddIpv6Wildcard.aaSockAddrInetData[LusCount] = SD_WILDCARD_ADDR;
    }
#endif
#if (SD_NO_OF_INSTANCES != SD_ONE)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    for (LusCount = SD_ZERO; LusCount < SD_NO_OF_INSTANCES; LusCount++)
#else
    for (LusCount = SD_ZERO; LusCount < (SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS); LusCount++)
#endif
#else
    LusCount = SD_ZERO;
#endif
    {

      LpInstance = &Sd_GaaInstance[LusCount];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      {
        LpInstanceStatic = &Sd_GaaInstanceStatic[LusCount];
      }
#else
      {
        LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LusCount);
      }
#endif

      LpInstance->usSendPduSize = SD_ZERO;
      LpInstance->usMulticastSessionIdTx = SD_ONE;
      LpInstance->enIpAddrState = TCPIP_IPADDR_STATE_UNASSIGNED;
      LpInstance->usSendNoOfEntrys = SD_ZERO;
      LpInstance->usSendNoOfOptions = SD_ZERO;

      LpInstance->blMulticastRebootFlagTx = (boolean)SD_TRUE;

      /* polyspace +8 RTE:UNR [Justified:Low] "This condition shall be true when
      the ConfigPtr is NOT NULL . */
      if (LpInstanceStatic->blDomainIpv4)
      {
        (LpInstance->stSubnetAddr).domain = TCPIP_AF_INET;
      }
      else
      {
        (LpInstance->stSubnetAddr).domain = TCPIP_AF_INET6;
      }
      /* [SWS_SD_00723]  (void) SoAd_OpenSoCon( LpInstanceStatic->ddTxPduId); */
      (void)SoAd_OpenSoCon(LpInstanceStatic->ddIpAddrSoConId);
      (void)SoAd_OpenSoCon(LpInstanceStatic->ddRxMulticastSoConId);
      (void)SoAd_OpenSoCon(LpInstanceStatic->ddRxUnicastSoConId);
    }
#if (STD_ON == SD_SERVER_CONFIGURED)
    {
      Sd_InitServer();
    }
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
    {
      Sd_InitClient();
    }
#endif

#if (SD_QUEUE_SIZE != SD_ONE)
    for (LusCount = SD_ZERO; LusCount < SD_QUEUE_SIZE; LusCount++)
#else
    LusCount = SD_ZERO;
#endif
    {
      Sd_GaaQueueStatus[LusCount] = SD_QUEUE_EMPTY;
      Sd_GaaQueueSend[LusCount] = SD_ZERO;
    }

#if (SD_NO_OF_SOCKET_CONNECTIONS != SD_ONE)
    for (LusCount = SD_ZERO; LusCount < SD_NO_OF_SOCKET_CONNECTIONS; LusCount++)
#else
    LusCount = SD_ZERO;
#endif
    {
      LpSocket = &Sd_GaaSoCon[LusCount];
      LpSocket->usNoOfSubClients = SD_ZERO;
      LpSocket->usNoOfSubServers = SD_ZERO;
      LpSocket->stSoConFlag.blWildcardSocketClient = (uint8)SD_FALSE;
      LpSocket->stSoConFlag.blWildcardSocketServer = (uint8)SD_FALSE;
      LpSocket->stSoConFlag.blSocketOpened = (uint8)SD_FALSE;
      LpSocket->stSoConFlag.ucReserved = SD_ZERO;
    }
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    for (LusCount = SD_ZERO;
         LusCount < (SD_NO_OF_INSTANCES * SD_MAX_INSTANCE_PARTNER); LusCount++)
#else
    for (LusCount = SD_ZERO;
         LusCount < ((SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS) * SD_MAX_INSTANCE_PARTNER); LusCount++)
#endif
    {
      /* SWS ID  SWS_SD_00034 */
      LpInstancePartner = &Sd_GaaInstancePartner[LusCount];
      LpInstancePartner->usUnicastSessionIdRecd = SD_ONE;
      LpInstancePartner->usMulticastSessionIdRecd = SD_ONE;
      LpInstancePartner->usUnicastSessionIdTx = SD_ONE;
      LpInstancePartner->stInstancePartnerFlag.blInstancePartnerActive = (boolean)SD_FALSE;

      LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagRecd = (boolean)SD_TRUE;
      LpInstancePartner->stInstancePartnerFlag.blMulticastRebootFlagRecd = (boolean)SD_TRUE;
      LpInstancePartner->stInstancePartnerFlag.blUnicastRebootFlagTx = (boolean)SD_TRUE;
      LpInstancePartner->stInstancePartnerFlag.ucReserved = SD_ZERO;
    }

#if (SD_NO_OF_SO_CON_GRPS != SD_ONE)
    for (LusCount = SD_ZERO; LusCount < SD_NO_OF_SO_CON_GRPS; LusCount++)
#else
    LusCount = SD_ZERO;
#endif
    {
      LpSoConStructure = &Sd_GaaSoConGroup[LusCount];
      LpSoConStructure->usNoOfSubConEvGrp = SD_ZERO;
      LpSoConStructure->blWildcardConEvGrp = (boolean)SD_FALSE;
    }

    Sd_GslRandomState = SD_RANDOM_NUM_INIT;
    Sd_GblRandomCalled = (boolean)SD_FALSE;
    Sd_GulRandomValue = Sd_GetRandomVal();

    Sd_GblInitCalled = (boolean)SD_TRUE;
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_MainFunction                                     **
**                                                                            **
** Service ID           : 0x06                                                **
**                                                                            **
** Description          : Main Function for Service Discovery                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstance,               **
**                          Sd_GaaInstanceStatic, Sd_GaaServerService,        **
**                          Sd_GaaServerServiceStatic, Sd_GaaEvHandler,       **
**                          Sd_GaaEvHandlerStatic, Sd_GaaClientService,       **
**                          Sd_GaaClientServiceStatic, Sd_GaaConsumedEvGrp,   **
**                          Sd_GaaConsumedEvGrpStatic, Sd_GblInitCalled       **
**                          Sd_GblRandomCalled, Sd_GulRandomValue             **
**                                                                            **
**                        Function(s) invoked : Det_ReportError,              **
**                          Sd_ServerStateMachine, Sd_EvHandlerMain,          **
**                          Sd_ClientStateMachine, Sd_ConsumedEvGrpMain,      **
**                          Sd_CombineQueue, Sd_GetRandomVal                  **
**                                                                            **
** Design ID              : SD_SDD_0146                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_MainFunction(void)
{
  /* SWS ID   SWS_SD_00004 */
  Sd_InstanceStaticType const *LpInstanceStatic;
#if (STD_ON == SD_SERVER_CONFIGURED)
  Sd_InstanceType const *LpInstance;
  Sd_ServerServiceType *LpServerService;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  Sd_EvHandlerType *LpEvHandler;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
#endif
#endif
#if (STD_ON == SD_CLIENT_CONFIGURED)
  Sd_ClientServiceType *LpClientService;
  Sd_ClientServiceStaticType const *LpClientServiceStatic;
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  Sd_ConsumedEvGrpType *LpConsumedEvGrp;
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
#endif
#endif
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
  uint8 LucSoADTxFlag = E_NOT_OK;
#endif

  uint16 LusBaseIndex;
  uint16 LusCount;
  uint16 LusBaseIndex2;
  uint16 LusNoOfElements2;
  uint16 LusCount2;
#if (SD_RAM_BLOCK == STD_ON) 
  NvM_RequestResultType errorstate;
#endif

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED) || \
    (STD_ON == SD_EV_HANDLER_CONFIGURED)
  uint16 LusBaseIndex3;
  uint16 LusNoOfElements3;
  uint16 LusCount3;
#endif

/* SWS ID  SWS_SD_00132 */
#if (STD_ON == SD_DEV_ERROR_DETECT)
  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;
  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be False when
  the sd module is in INITIALIZED state.
  Module Test Case Reference SD_ETC_419, SWS ID SWS_SD_00132" */
  if (!Sd_GblInitCalled)
  {
    LddReturnValue = E_NOT_OK;
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_MAIN_FUNCTION_SID, SD_E_UNINIT);
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be true when
  the sd module is in INITIALIZED state.
  Unit Test Case Reference SD_UTP_0019, SWS ID SWS_SD_00132" */
  if (E_OK == LddReturnValue)
#endif
  {
#if (SD_NVM_BLOCK_LENGTH != SD_ZERO )
	  if ((void *)SD_NVMBLOCK_ID != NULL_PTR && Sd_NvmReadInit )
  {
	  errorstate = E_NOT_OK;
     NvM_GetErrorStatus ( SD_NVMBLOCK_ID, &errorstate);
     if ((errorstate == E_OK) || (errorstate == 0x03) || (errorstate == 0x08))
     {
		Sd_NvmReadInit = SD_FALSE;
	  #if (SD_RAM_BLOCK == STD_ON)
	   if (SdShadowNvMRamBlockData[0].bl_Sd_Nvm_Read_Write_Block_Flag == SD_TRUE)
	   {
			memcpy(Sd_Gaa_NvMRamBlockData, SdShadowNvMRamBlockData, 
			sizeof(Sd_Gaa_NvMRamBlockData));
			Sd_GaaAclPolicyFlag = Sd_Gaa_NvMRamBlockData[0].bl_Sd_ACL_PolicyCheck;
			memcpy(Sd_GaaClient_Server_List, Sd_Gaa_NvMRamBlockData[0].
			Sd_GaaServerClientList, sizeof(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList));
	   }
	   else
	   {
		   #if (SD_RAM_BLOCK == STD_ON)
			Sd_Gaa_NvMRamBlockData[0].bl_Sd_Nvm_Read_Write_Block_Flag = (uint8)SD_TRUE;
			memcpy(Sd_GaaClient_Server_List, Sd_Gaa_NvMRamBlockData[0].
			Sd_GaaServerClientList, sizeof(Sd_Gaa_NvMRamBlockData[0].Sd_GaaServerClientList));
			Sd_GaaAclPolicyFlag = Sd_Gaa_NvMRamBlockData[0].bl_Sd_ACL_PolicyCheck;
			(void)NvM_WriteBlock(SD_NVMBLOCK_ID, Sd_Gaa_NvMRamBlockData);
		   #endif
		   
	   }
	   #endif
    }
  }
 #endif
    /* SWS ID  SWS_SD_00131 */
    LusBaseIndex = SD_ZERO;

    if (!Sd_GblTxSuccessFLag)
    {
      Sd_GblTxSuccessFLag = (boolean)SD_TRUE;
      /* SWS ID   SWS_SD_00709 */
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      if (Sd_GucSdInstanceIndex < SD_NO_OF_INSTANCES)
#else
      if (Sd_GucSdInstanceIndex < (SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS))
#endif
      {
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LucSoADTxFlag = SoAd_IfTransmit(Sd_GaaInstanceStatic[Sd_GucSdInstanceIndex].ddTxPduId, &Sd_GddPduInfoPtr);
#else
        LucSoADTxFlag = SoAd_IfTransmit((Sd_GpConfigPtr->pInstanceStatic[Sd_GucSdInstanceIndex].ddTxPduId), 
          &Sd_GddPduInfoPtr);
#endif
#else
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        (void)SoAd_IfTransmit(Sd_GaaInstanceStatic[Sd_GucSdInstanceIndex].ddTxPduId, &Sd_GddPduInfoPtr);
#else
    (void)SoAd_IfTransmit((Sd_GpConfigPtr->pInstanceStatic[Sd_GucSdInstanceIndex].ddTxPduId), 
      &Sd_GddPduInfoPtr);
         
#endif
#endif

      }
    }

#if (SD_NO_OF_INSTANCES != SD_ONE)
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                              SD_NO_OF_INSTANCES);
         LusCount++)
#else
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex +
                                              (SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS));
         LusCount++)
#endif
#else
    LusCount = LusBaseIndex;

#endif
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpInstanceStatic = &Sd_GaaInstanceStatic[LusCount];
#else
      LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LusCount);
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)
      LpInstance = &Sd_GaaInstance[LusCount];
      LusBaseIndex2 = LpInstanceStatic->usBaseServerServiceIndex;
      LusNoOfElements2 = LpInstanceStatic->usNoOfServerServices;

      for (LusCount2 = LusBaseIndex2; LusCount2 < (LusBaseIndex2 + LusNoOfElements2); LusCount2++)
      {
        LpServerService = &Sd_GaaServerService[LusCount2];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpServerServiceStatic = &Sd_GaaServerServiceStatic[LusCount2];
#else
        LpServerServiceStatic =
            ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LusCount2);
#endif
        Sd_ServerStateMachine(LpInstance, LpInstanceStatic, LpServerService,
                              LpServerServiceStatic);

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
        LusBaseIndex3 = LpServerServiceStatic->usBaseEvHandlerIndex;
        LusNoOfElements3 = LpServerServiceStatic->usNoOfEvHandlers;

        for (LusCount3 = LusBaseIndex3; LusCount3 < (LusBaseIndex3 + LusNoOfElements3); LusCount3++)
        {
          LpEvHandler = &Sd_GaaEvHandler[LusCount3];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
          LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount3];
#else
          LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount3);
#endif
          Sd_EvHandlerMain(LpServerService, LpEvHandler, LpEvHandlerStatic);
        }
#endif
      }
#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)
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
        Sd_ClientStateMachine(LpClientService, LpClientServiceStatic);

#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
        LusBaseIndex3 = LpClientServiceStatic->usBaseConEventGrp;
        LusNoOfElements3 = LpClientServiceStatic->usNoOfConEventGrp;

        for (LusCount3 = LusBaseIndex3; LusCount3 < (LusBaseIndex3 + LusNoOfElements3); LusCount3++)
        {
          LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount3];
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
          LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount3];
#else
          LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic) + LusCount3);
#endif
          Sd_ConsumedEvGrpMain(LpClientService, LpConsumedEvGrp,
                               LpConsumedEvGrpStatic);

/* Design ID : SD_SDD_0360,SD_SDD_0362,SD_SDD_0120,SD_SDD_0364,SD_SDD_0122,SD_SDD_0363,SD_SDD_0121,SD_SDD_0124,SD_SDD_0365, SD_SDD_0123,SD_SDD_0367,SD_SDD_0125*/
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
          if (!Sd_GblSubscribeInQueue)
          {

            if ((SD_CONSUMED_EVENTGROUP_REQUESTED ==
                 LpConsumedEvGrp->enConEvGrpSetState) &&
                (LpClientService->enClientCurrState ==
                 SD_CLIENT_SERVICE_AVAILABLE))
            {
              if ((LpConsumedEvGrpStatic->pClientTimer)->ucSubscribeEventgroupRetryMax > SD_ZERO)
              {
                /* #violates #ref Sd_c_CERT_REF_3 Violates MISRA 2012
                        Required Rules INT02*/
                /* PRQA S 2120 5 */
                if (((LpConsumedEvGrp->stConsumedEvGrpFlag.blSubscribeSent) == SD_TRUE) &&
                    ((uint32)SD_ONE <= LpConsumedEvGrp->ulConEvGrpRetryCount))
                {
                  Sd_SubscibeEventGroupRetry(LpConsumedEvGrpStatic,
                                             LpConsumedEvGrp, LpClientService,
                                             &LpClientService->stOfferRemoteAddr);
                }
              }
            }
          }
#endif
        }
#endif
      }
#endif
    }
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
    if (E_NOT_OK == LucSoADTxFlag)
    {
      Sd_GblSubscribeInQueue = (boolean)SD_FALSE;
    }
    else
    {
      Sd_GblSubscribeInQueue = (boolean)SD_TRUE;
    }
#endif
    Sd_CombineQueue();

    if (Sd_GblRandomCalled)
    {
      Sd_GblRandomCalled = (boolean)SD_FALSE;
      Sd_GulRandomValue = Sd_GetRandomVal();
    }
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
/*******************************************************************************
** Function Name        : Sd_ServiceGroupStart                                **
**                                                                            **
** Service ID           : 0x44                                                **
**                                                                            **
** Description          : This API function is used by the BswM to set the    **
**                        group  of Server & Client Service Instance state.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different SdServiceGroupS.            **
**                        Non reentrant for the same SdServiceGroup.          **
**                                                                            **
** Input Parameters     : ServiceGroupId                                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstance,               **
**                                              Sd_GaaClientServiceStatic,    **
**                                              Sd_GaaClientServic            **
**                                              usClientRequestCounter        **
**                                              usServerAvailabilityCounter   **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked : Det_ReportError               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0450                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ServiceGroupStart(
    Sd_ServiceGroupIdType ServiceGroupId)
{

#if (STD_ON == SD_CLIENT_CONFIGURED)

  Sd_ClientServiceType *LpClientService;
  uint16 LpClientArraySize;
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)

  Sd_ServerServiceType *LpServerService;
  uint16 LpServerArraySize;
#endif
  uint8 LusCount;

  uint16 LpSize;

  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;

  if (ServiceGroupId >= SD_SERVICE_GROUP)
  {
    LddReturnValue = E_NOT_OK;
#if (SD_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_SERVICE_GROUP_START_SID, SD_E_INV_ID);
#endif
  }

#if (STD_ON == SD_SERVER_CONFIGURED)

  if (E_OK == LddReturnValue)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpSize = Sd_GaaServicegroupServerStatic[ServiceGroupId].usArray_size;
#else
    LpSize = (*(Sd_GpConfigPtr->pServgrpSerStatic + ServiceGroupId)).usArray_size;
#endif
    for (LusCount = (uint8)SD_ZERO; LusCount < LpSize; LusCount++)
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpServerArraySize = Sd_GaaServicegroupServerArray[ServiceGroupId][LusCount];
#else
      LpServerArraySize = Sd_GpConfigPtr->pServgrpSerArray[(ServiceGroupId * SD_SERVICE_GROUP) + LusCount];
#endif
      LpServerService = &Sd_GaaServerService[LpServerArraySize];

      if ((LpServerService->enServerServiceSetState == SD_SERVER_SERVICE_DOWN) && (!Sd_GaaServiceGrpIdFlag[ServiceGroupId]))
      {

        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        LpServerService->enServerServiceSetState = SD_SERVER_SERVICE_AVAILABLE;
        Sd_GaaServerAvailabilityCounter[LpServerArraySize].usServerAvailabilityCounter++;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }

      else if ((LpServerService->enServerServiceSetState == SD_SERVER_SERVICE_AVAILABLE) && (!Sd_GaaServiceGrpIdFlag[ServiceGroupId]))
      {

        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaServerAvailabilityCounter[LpServerArraySize].usServerAvailabilityCounter++;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }

      else
      {
        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        LpServerService->enServerServiceSetState = SD_SERVER_SERVICE_AVAILABLE;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
    }
  }

#endif

#if (STD_ON == SD_CLIENT_CONFIGURED)

  if (E_OK == LddReturnValue)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpSize = Sd_GaaServicegroupClientStatic[ServiceGroupId].usArray_size;
#else
    LpSize = (*(Sd_GpConfigPtr->pServgrpCliStatic + ServiceGroupId)).usArray_size;
#endif
    for (LusCount = (uint8)SD_ZERO; LusCount < LpSize; LusCount++)
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpClientArraySize = Sd_GaaServicegroupClientArray[ServiceGroupId][LusCount];
#else
      LpClientArraySize = Sd_GpConfigPtr->pServgrpCliArray[(ServiceGroupId * SD_SERVICE_GROUP) + LusCount];
#endif
      LpClientService = &Sd_GaaClientService[LpClientArraySize];

      if ((LpClientService->enClientSetState == SD_CLIENT_SERVICE_RELEASED) && (!Sd_GaaServiceGrpIdFlag[ServiceGroupId]))
      {

        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        LpClientService->enClientSetState = SD_CLIENT_SERVICE_REQUESTED;
        Sd_GaaClientRequestCounter[LpClientArraySize].usClientRequestCounter++;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
      else if ((LpClientService->enClientSetState == SD_CLIENT_SERVICE_REQUESTED) && (!Sd_GaaServiceGrpIdFlag[ServiceGroupId]))
      {
        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaClientRequestCounter[LpClientArraySize].usClientRequestCounter++;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
      else
      {
        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        LpClientService->enClientSetState = SD_CLIENT_SERVICE_REQUESTED;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
    }
  }
#endif
  /*polyspace +6 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being out of bounds." */
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  Sd_GaaServiceGrpIdFlag[ServiceGroupId] = (boolean)SD_TRUE;
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ServiceGroupStop                                 **
**                                                                            **
** Service ID           : 0x45                                                **
**                                                                            **
** Description          : This API function is used by the BswM to set the    **
**                         group  of Server & Client Service Instance state.  **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ServiceGroupId                                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstance,               **
**                                              Sd_GaaClientServiceStatic,    **
**                                              Sd_GaaClientServic            **
**                                              usClientRequestCounter        **
**                                              usServerAvailabilityCounter   **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked : Det_ReportError               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0451                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ServiceGroupStop(Sd_ServiceGroupIdType ServiceGroupId)
{

#if (STD_ON == SD_CLIENT_CONFIGURED)
  Sd_ClientServiceType *LpClientService;
  uint16 LpClientArraySize;
#endif

#if (STD_ON == SD_SERVER_CONFIGURED)

  Sd_ServerServiceType *LpServerService;
  uint16 LpServerArraySize;
#endif
  uint8 LusCount;

  uint16 LpSize;

  Std_ReturnType LddReturnValue;
  LddReturnValue = E_OK;

  if (ServiceGroupId >= SD_SERVICE_GROUP)
  {

    LddReturnValue = E_NOT_OK;
#if (SD_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(SD_MODULE_ID, SD_INSTANCE_ID,
                          SD_SERVICE_GROUP_STOP_SID, SD_E_INV_ID);
#endif
  }

#if (STD_ON == SD_CLIENT_CONFIGURED)

  if (E_OK == LddReturnValue)
  {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpSize = Sd_GaaServicegroupClientStatic[ServiceGroupId].usArray_size;
#else
    LpSize = (*(Sd_GpConfigPtr->pServgrpCliStatic + ServiceGroupId)).usArray_size;
#endif
    for (LusCount = (uint8)SD_ZERO; LusCount < LpSize; LusCount++)
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpClientArraySize = Sd_GaaServicegroupClientArray[ServiceGroupId][LusCount];
#else
      LpClientArraySize = Sd_GpConfigPtr->pServgrpCliArray[(ServiceGroupId * SD_SERVICE_GROUP) + LusCount];
#endif
      LpClientService = &Sd_GaaClientService[LpClientArraySize];

      if ((LpClientService->enClientSetState == SD_CLIENT_SERVICE_REQUESTED) || (Sd_GaaClientRequestCounter[LpClientArraySize].usClientRequestCounter != SD_ZERO))
      {

        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaClientRequestCounter[LpClientArraySize].usClientRequestCounter--;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();

        if ((Sd_GaaClientRequestCounter[LpClientArraySize].usClientRequestCounter == SD_ZERO) && (LpClientService->enClientSetState == SD_CLIENT_SERVICE_REQUESTED))
        {

          SchM_Enter_Sd_MODE_STATUS_PROTECTION();
          LpClientService->enClientSetState = SD_CLIENT_SERVICE_RELEASED;
          SchM_Exit_Sd_MODE_STATUS_PROTECTION();
        }
      }
    }
  }

#endif

#if (STD_ON == SD_SERVER_CONFIGURED)

  if (E_OK == LddReturnValue)
  {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    LpSize = Sd_GaaServicegroupServerStatic[ServiceGroupId].usArray_size;
#else
    LpSize = (*(Sd_GpConfigPtr->pServgrpSerStatic + ServiceGroupId)).usArray_size;
#endif
    for (LusCount = (uint8)SD_ZERO; LusCount < LpSize; LusCount++)
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpServerArraySize = Sd_GaaServicegroupServerArray[ServiceGroupId][LusCount];
#else
      LpServerArraySize = Sd_GpConfigPtr->pServgrpSerArray[(ServiceGroupId * SD_SERVICE_GROUP) + LusCount];
#endif
      LpServerService = &Sd_GaaServerService[LpServerArraySize];

      if ((LpServerService->enServerServiceSetState ==
           SD_SERVER_SERVICE_AVAILABLE) ||
          (Sd_GaaServerAvailabilityCounter[LpServerArraySize].usServerAvailabilityCounter != SD_ZERO))
      {

        SchM_Enter_Sd_MODE_STATUS_PROTECTION();
        Sd_GaaServerAvailabilityCounter[LpServerArraySize].usServerAvailabilityCounter--;
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();

        if ((Sd_GaaServerAvailabilityCounter[LpServerArraySize].usServerAvailabilityCounter == SD_ZERO) && (LpServerService->enServerServiceSetState ==
                                                                                                            SD_SERVER_SERVICE_AVAILABLE))
        {

          SchM_Enter_Sd_MODE_STATUS_PROTECTION();
          LpServerService->enServerServiceSetState = SD_SERVER_SERVICE_DOWN;
          SchM_Exit_Sd_MODE_STATUS_PROTECTION();
        }
      }
    }
  }
#endif
  /*polyspace +8 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
   made sure that they are within their range by having necessary boundary
   checks in order to prevent them from being out of bounds." */
  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  Sd_GaaServiceGrpIdFlag[ServiceGroupId] = (boolean)SD_FALSE;
  SchM_Exit_Sd_MODE_STATUS_PROTECTION();
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_RequestRoutingGroupEnable                        **
**                                                                            **
** Service ID           : 0x47                                                **
**                                                                            **
** Description          : Callback function, which will be provided           **
**                        to SoAd to be able to trigger the ACL policy check  **
**                        or explicitly grand access on the received Method   **
**						  call request.                                       **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : PduHeaderID,SoConId                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstance,               **
**                                              Sd_GaaClientServiceStatic,    **
**                                              Sd_GaaClientServic            **
**                                              usClientRequestCounter        **
**                                              usServerAvailabilityCounter   **
**                                                                            **
**                                                                            **
**                                                                            **
**                        Function(s) invoked :                               **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Design ID              : SD_SDD_0598                                       **
*******************************************************************************/
#if (SD_SERVER_CONFIGURED == STD_ON)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_RequestRoutingGroupEnable(uint32 PduHeaderID,
                             SoAd_SoConIdType SoConId)
{
  uint32 lusCount, lusCount2;
  uint32 LusServiceId;
  uint32 LusBaseIndex;

  boolean LbServiceFlag;
  Std_ReturnType LddReturnValue;
  Sd_InstanceStaticType const *LpInstanceStatic;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  #if ((SD_ROM_BLOCK == STD_ON) || \
     (SD_RAM_BLOCK == STD_ON))
  if (Sd_GaaAclPolicyFlag)
  {
    uint32 lusCount, lusCount2, lusCount3;
    uint32 LusServiceId;
    uint32 LusBaseIndex;
    uint32 LulAddr;

    uint32 LulSdProvidedAddr;
	
    TcpIp_SockAddrType const *LpIp4Addr;
    TcpIp_SockAddrType LstRemoteAddr1;

    Sd_ProviderConsumerListType const *Lp_ConsumerServerProvider;
    Std_ReturnType LddConnectionReturnValue;
    boolean LblAclCheck;
    (void)SD_MEMSET(&LstRemoteAddr1, (sint32)SD_ZERO, sizeof(TcpIp_SockAddrType));
    LblAclCheck = (boolean)SD_FALSE;
    LddReturnValue = E_NOT_OK;

    LusServiceId = (PduHeaderID >> SD_SIXTEEN);
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    for (lusCount = SD_ZERO; (lusCount < SD_NO_OF_INSTANCES) &&
                             ((LddReturnValue == E_NOT_OK));
         lusCount++)
#else
    for (lusCount = SD_ZERO; (lusCount < SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS) &&
                             ((LddReturnValue == E_NOT_OK));
         lusCount++)
#endif
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)

      LpInstanceStatic = &Sd_GaaInstanceStatic[lusCount];

#else

      LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + lusCount);

#endif
      LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;
      for (lusCount2 = LusBaseIndex; lusCount2 < (LusBaseIndex +
                                                  (LpInstanceStatic->usNoOfServerServices));
           lusCount2++)
      {

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpServerServiceStatic = &Sd_GaaServerServiceStatic[lusCount2];
#else
        LpServerServiceStatic =
            ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + lusCount2);
#endif
        if (LpServerServiceStatic->usServiceId == LusServiceId)
        {
          if (LpInstanceStatic->blDomainIpv4)
          {
            LstRemoteAddr1.domain = TCPIP_AF_INET;

            (void)SoAd_GetRemoteAddr(SoConId, &LstRemoteAddr1);
          }

#if (STD_ON == SD_IPV6_ENABLED)

          if (LpInstanceStatic->blDomainIpv4)
          {
            LstRemoteAddr1.domain = TCPIP_AF_INET6;

            (void)SoAd_GetRemoteAddr(SoConId, &LstRemoteAddr1);
          }
#endif

          LddConnectionReturnValue = (uint8)SoAd_IsConnectionReady(SoConId,
                                                                   &LstRemoteAddr1);
          if (LddConnectionReturnValue == (uint8)TCPIP_E_NOT_OK)
          {
            SD_UNUSED(PduHeaderID);
            SD_UNUSED(SoConId);
            LddReturnValue = E_NOT_OK;
          }
          else
          {
            LddReturnValue = E_OK;
            LpIp4Addr = &LstRemoteAddr1;
#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)

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

#if (STD_ON == SD_PRE_COMPILE_SINGLE)
#if ((SD_ROM_BLOCK == STD_ON) && \
     (SD_RAM_BLOCK == STD_ON))
            for (lusCount3 = SD_ZERO; lusCount3 < SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER; lusCount3++)
#else
         #if (SD_ROM_BLOCK == STD_ON)
            for (lusCount3 = SD_ZERO; lusCount3 < SD_NO_OF_ROM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER; lusCount3++)
        #endif
         #if (SD_RAM_BLOCK == STD_ON)
            for (lusCount3 = SD_ZERO; lusCount3 < SD_NO_OF_RAM_ALLOWED_SERVER_CLIENT_PROVIDER_CONSUMER; lusCount3++)
        #endif
#endif
#else
            for (lusCount3 = SD_ZERO; lusCount3 < Sd_GpConfigPtr->ucSdAllowedConsumerStaticCount; lusCount3++)
#endif
            {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
#if ((SD_ROM_BLOCK == STD_ON) || \
     (SD_RAM_BLOCK == STD_ON))
              Lp_ConsumerServerProvider = &Sd_GaaClient_Server_List[lusCount3];
#else
#endif
#else
              Lp_ConsumerServerProvider = ((Sd_GpConfigPtr->pSdAllowedConsumerStatic) + lusCount3);
#endif

#if (CPU_BYTE_ORDER != LOW_BYTE_FIRST)

              LulSdProvidedAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
              LulSdProvidedAddr = (uint32)(LulSdProvidedAddr << SD_EIGHT) |
                                  Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
              LulSdProvidedAddr = (uint32)(LulSdProvidedAddr << SD_EIGHT) |
                                  Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
              LulSdProvidedAddr = (uint32)(LulSdProvidedAddr << SD_EIGHT) |
                                  Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
#else

              LulSdProvidedAddr = Lp_ConsumerServerProvider->SdIpAddress[SD_FIVE];
              LulSdProvidedAddr = (uint32)(LulSdProvidedAddr << SD_EIGHT) |
                                  Lp_ConsumerServerProvider->SdIpAddress[SD_FOUR];
              LulSdProvidedAddr = (uint32)(LulSdProvidedAddr << SD_EIGHT) |
                                  Lp_ConsumerServerProvider->SdIpAddress[SD_THREE];
              LulSdProvidedAddr = (uint32)(LulSdProvidedAddr << SD_EIGHT) |
                                  Lp_ConsumerServerProvider->SdIpAddress[SD_TWO];
#endif
              if (((uint16)Lp_ConsumerServerProvider->domain == LpIp4Addr->domain) &&
                  (LulSdProvidedAddr == LulAddr))
              {

                LblAclCheck = (boolean)SD_TRUE;
              }
            }

            if (!LblAclCheck)
            {
              SD_UNUSED(PduHeaderID);
              SD_UNUSED(SoConId);
#if (SD_ENABLE_SECURITY_EVENT_REPORTING == STD_ON)
              IdsM_SetSecurityEvent(SD_SEV_SOME_IP_ACL_CHECK_FAILED_METHOD_REQUEST);
#endif
              LddReturnValue = E_NOT_OK;
            }
            else
            {
              (void)SoAd_EnableSpecificRouting(
                  LpServerServiceStatic->ddActivationRoGrpId,
                  SoConId);
            }
          }
        }
      }
    }
  }
  else
#endif

  {
    LddReturnValue = E_NOT_OK;
	LbServiceFlag  = (boolean)SD_FALSE;
    LusServiceId = (PduHeaderID >> SD_SIXTEEN);
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
    for (lusCount = SD_ZERO; (lusCount < (uint32)SD_NO_OF_INSTANCES) &&
                             ((LddReturnValue == E_NOT_OK));
         lusCount++)
#else
    for (lusCount = SD_ZERO; ((lusCount < (SD_NO_OF_INSTANCES / SD_NUM_OF_CFG_SETS)) &&
                              (LddReturnValue == E_NOT_OK));
         lusCount++)
#endif
    {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpInstanceStatic = &Sd_GaaInstanceStatic[lusCount];
#else
      LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + lusCount);
#endif
      LusBaseIndex = LpInstanceStatic->usBaseServerServiceIndex;
      for (lusCount2 = LusBaseIndex; (lusCount2 < (LusBaseIndex +
                                                  (LpInstanceStatic->usNoOfServerServices))) && (!LbServiceFlag) ;
           lusCount2++)
      {
#if (STD_ON == SD_PRE_COMPILE_SINGLE)
        LpServerServiceStatic = &Sd_GaaServerServiceStatic[lusCount2];
#else
        LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + lusCount2);
#endif
        if (LpServerServiceStatic->usServiceId == LusServiceId)
        {
          LddReturnValue = E_OK;
		  LbServiceFlag = (boolean)SD_TRUE;
          (void)SoAd_EnableSpecificRouting(
              LpServerServiceStatic->ddActivationRoGrpId,
              SoConId);
        }
        else
        {
          SD_UNUSED(PduHeaderID);
          SD_UNUSED(SoConId);
          LddReturnValue = E_NOT_OK;
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
** Function Name        : Sd_AclCheckEnable                                   **
**                                                                            **
** Service ID           : 0x48                                                **
**                                                                            **
** Description          :Enabling or Disabling ACL policy check for           **
**                       all service instance                                 **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : PduHeaderID,SoConId                                 **
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
** Design ID              :                                                   **
*******************************************************************************/

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclCheckEnable(boolean EnableAcl)
{
#if (SD_RAM_BLOCK == STD_ON)
  Std_ReturnType LddReturnValue = E_NOT_OK;
  Sd_Gaa_NvMRamBlockData[0].bl_Sd_ACL_PolicyCheck = EnableAcl;
  Sd_GaaAclPolicyFlag = Sd_Gaa_NvMRamBlockData[0].bl_Sd_ACL_PolicyCheck;
  LddReturnValue = NvM_WriteBlock(SD_NVMBLOCK_ID, Sd_Gaa_NvMRamBlockData);
#else
  Std_ReturnType LddReturnValue = E_NOT_OK;
  if ((EnableAcl) || (!EnableAcl))
  {
    LddReturnValue = E_NOT_OK;
  }

#endif

  return LddReturnValue;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_AclUpdate                                        **
**                                                                            **
** Service ID           : 0x46                                                **
**                                                                            **
** Description          :Enabling or Disabling ACL policy check for           **
**                       all service instance                                 **
**						                                                                **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : PduHeaderID,SoConId                                 **
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
** Design ID              :                                                   **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AclUpdate(
    uint16 SdServiceId,
    uint16 ServiceInstanceId,
    const TcpIp_SockAddrType * RemoteAddrPtr,
    Sd_AclUpdateType RequestType)
{
  Sd_ProviderConsumerType Sd_Request_type;
  Std_ReturnType LddReturnValue = E_OK;

  if ((void *)SD_NVMBLOCK_ID == NULL_PTR)
  {
    LddReturnValue = E_NOT_OK;
  }
  else
  {
    switch (RequestType)
    {
    case SD_ACL_ADD_PROVIDER:
      Sd_Request_type = SD_PROVIDER_TYPE;
      LddReturnValue = Sd_AddProviderToClientService(SdServiceId, ServiceInstanceId, Sd_Request_type, RemoteAddrPtr);
      break;

    case SD_ACL_ADD_CONSUMER:
      Sd_Request_type = SD_CONSUMER_TYPE;
      LddReturnValue = Sd_AddConsumerToServerService(SdServiceId, ServiceInstanceId, Sd_Request_type, RemoteAddrPtr);
      break;
    case SD_ACL_REMOVE_PROVIDER:
      Sd_Request_type = SD_PROVIDER_TYPE;
      LddReturnValue = Sd_RemoveProviderToClientService(SdServiceId, ServiceInstanceId, Sd_Request_type, RemoteAddrPtr);
      break;
    case SD_ACL_REMOVE_CONSUMER:
      Sd_Request_type = SD_CONSUMER_TYPE;
      LddReturnValue = Sd_RemoveConsumerToServerService(SdServiceId, ServiceInstanceId, Sd_Request_type, RemoteAddrPtr);
      break;
    default:
      LddReturnValue = E_NOT_OK;
      break;
    }
  }
  return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/****************************************************************************
**                   Parasoft violations end Section                       **
****************************************************************************/

/* parasoft-end-suppress MISRAC2012-RULE_20_1-a-4 */
/* parasoft-end-suppress MISRAC2012-RULE_5_4-c-2 */
/* parasoft-end-suppress MISRAC2012-RULE_5_4-d-2 */
/* parasoft-end-suppress MISRAC2012-RULE_1_1-c-2 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
