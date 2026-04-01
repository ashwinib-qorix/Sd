/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_State.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the functions for state machine of Client  **
**              and server                                                    **
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
** 15-Sep-2025  Gourav Purohit	    Implementing 24_11 SWS_Sd_00453           **
** 15-Sep-2025  Gourav Purohit	    Initial Release.                          **
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
/** At section SD_STATE_c_REF_1
* Violates MISRA 2012 Advisory Rule 2.2, This statement has no side effects.
* This statement is required for polyspace.
* Justification: For the unused variables or variables which are set but not
* used for specific configuration compiler shows warning. QAC shows dead code
* for the steps which are implemented to avoid such compiler warnings.

* #section SD_STATE_C_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* All the #include statements in a particular code file should be grouped
* together near the head of the file. The rule states that the only items which
* may precede a #include in a file are other preprocessor directives or comments
* Justification: As per RS_BSW_00437 in AUTOSAR_SRS_BSWGeneral document Memory
* mapping is provided as start and stop memory sections. This is approved
* by AUTOSAR.

* #section SD_STATE_C_REF_3
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
*
* #Violates #ref SD_State_REF_7, DCL00 Msg(qac-10.1.0-3227)   
* PRQA S 3227 EOF  
* The message can be suppressed in case of AUTOSAR provided Standard API input arguments:
* Since the function parameters that are pointers to values of standard API are
* provided by AUTOSAR specifications, it cannot be modified.
* It does not impact the module funtionality and hence this violation is suppressed.
* 2. The message can be suppressed case to case deviation in case of internal functions:
* The function argument is not used in the current function, but inturn passed
* to another function to retrieve data. Hence the argument is still used as
* pointer to variable instead of pointer to constant. It can be suppressed and
* hence does'nt have impact on functionality. 
* #Violates #ref SD_State_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)    
* PRQA S 4810 EOF
* Common Deviation 

* #Violates #ref SD_State_c_REF_9,DCL07 Msg(qac-10.1.0-3450)   
* PRQA S 553,2017,3219 EOF  
* Deviation:77966
* #Violates #ref SD_State_c_REF_9,MSC09 Msg(qac-10.1.0-0288)   
*PRQA S 2017,3211,3408,3625 EOF 
* Deviation:77966
* #Violates #ref SD_State_c_REF_4,MSC01 Msg(qac-10.1.0-2000)   
*PRQA S 2000 EOF 
* Deviation:77966
* #Violates #ref SD_State_c_REF_4,INT30 Msg(qac-10.1.0-3383)   
* PRQA S 3383 EOF  
* Deviation:77966
*
*
* #Violates #ref SD_State_REF_7, Rule-17.7 Msg(qac-10.1.0-3200)   
*PRQA S 2017,3198,3408,3447 EOF   
* * PRQA S 5087 EOF 
* violates #ref SD_INTERNAL_C_REF_1 Violates MISRA 2012 Required Rule 20.1   
* As per KPIT coding guidelines, macro name should start from module name 
* (upper case) and hence this violation is suppressed as it does not impact the 
* module funtionality 
*
* violates #ref SD_Internal_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)  
* PRQA S 0857 EOF
  Part of  Common Deviation   
*
* violates #ref SD_Internal_c_REF_3 Violates MISRA 2012 Dir-1.1   
* PRQA S 0380 EOF 
*
* #Violates #ref SD_State_c_REF_6,INT02 Msg(qac-10.1.0-2101)   
*PRQA S 2101 EOF  
* This is waived Off whenever the Conversion  required accoding to design of  
* functionality .
* 
* #Violates #ref SD_State_c_REF_7,INT02 Msg(qac-10.1.0-2100)   
*PRQA S 2100 EOF  
* This is waived Off whenever the Conversion  required accoding to design of  
* functionality .

* #Violates #ref SD_State_c_REF_8,INT02 Msg(qac-10.1.0-2120)   
*PRQA S 2120 EOF  
* This is waived Off whenever the Conversion  required accoding to design of  functionality .

* #Violates #ref SD_State_c_REF_9,INT02 Msg(qac-10.1.0-1251)   
* PRQA S 1251 EOF  
* This is waived Off whenever the Conversion  required accoding to design of  functionality .
*
* #Violates #ref SD_State_c_REF_9,PRE04 Msg(certccm-2.1.0-5001)   
*PRQA S 5001 EOF  
*All the files in the header files  start with a specific format <Sd_xyz.h> 
*due to guidelines of the Autosar

* #Violates #ref SD_State_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)    
*PRQA S 5002 EOF  
*All the files in the header files  start with a specific format <Sd_xyz.h> 
*due to guidelines of the Autosar. 
*
   
**/
/* PRQA S 5087 EOF */
/* violates #ref SD_INTERNAL_C_REF_1 Violates MISRA 2012 Required Rule 20.1 */

/*#violates #ref SD_Internal_c_REF_1 Violates MISRA 2012 Dir-1.1 (Required)*/
/*PRQA S 0857 EOF*/

/* violates #ref SD_Internal_c_REF_3 Violates MISRA 2012 Dir-1.1 */
/* PRQA S 0380 EOF */

/* #Violates #ref SD_State_REF_7, DCL00 Msg(qac-10.1.0-3227) */
/* PRQA S 3227 EOF */

/* #Violates #ref SD_State_REF_7, Rule-17.7 Msg(qac-10.1.0-3200) */
/*PRQA S 2017,3198,3408,3447 EOF */

/* #Violates #ref SD_State_c_REF_4,INT30 Msg(qac-10.1.0-3383) */
/*PRQA S 3383 EOF*/

/* #Violates #ref SD_State_c_REF_4,MSC01 Msg(qac-10.1.0-2000) */
/*PRQA S 2000 EOF*/

/* #Violates #ref SD_State_c_REF_6,INT02 Msg(qac-10.1.0-2101) */
/*PRQA S 2101 EOF*/

/* #Violates #ref SD_State_c_REF_7,INT02 Msg(qac-10.1.0-2100) */
/*PRQA S 2100 EOF*/

/* #Violates #ref SD_State_c_REF_8,INT02 Msg(qac-10.1.0-2120) */
/*PRQA S 2120 EOF*/

/* #Violates #ref SD_State_c_REF_9,INT02 Msg(qac-10.1.0-1251) */
/*PRQA S 1251 EOF*/
/* #Violates #ref SD_State_c_REF_9,MSC09 Msg(qac-10.1.0-0288) */
/*PRQA S 2017,3211,3408,3625 EOF*/
/* #Violates #ref SD_State_c_REF_9,DCL07 Msg(qac-10.1.0-3450) */
/*PRQA S 553,2017,3219 EOF*/
/* #Violates #ref SD_State_c_REF_9,PRE04 Msg(certccm-2.1.0-5001) */
/*PRQA S 5001 EOF*/

/* #Violates #ref SD_State_c_REF_9,PRE08 Msg(certccm-2.1.0-5002)  */
/*PRQA S 5002 EOF*/

/* #Violates #ref SD_State_c_REF_9,CMN-0:CMN-0.1,CMN-0.1 Msg(qac-10.1.0-4810)  */
/*PRQA S 4810 EOF */
/*PRQA S 2017,3210,3205,3408,3447 EOF*/
/*PRQA S 1302,1303,3200,3209,3227,3408,3447,3602 EOF*/
/*PRQA S 2017,3210,3205,3408,3447,3335,1302,2110 EOF*/
/* #Violates #ref SD_State_c_REF_9,M3CM-1,M3CM-2-C99,02_DCL,03_EXP:Rule-17.3,Rule-1.1-C99,DCL31,DCL07,EXP37  */
/*PRQA S 3335 EOF*/
/* #Violates #ref SD_State_c_REF_9, 04_INT:INT02  */
/*PRQA S 2110 EOF*/
/* #Violates #ref SD_State_c_REF_9, M3CM-3,03_EXP:Rule-18.4,EXP08 Msg(qac-10.1.0-0488)  */
/*PRQA S 0488 EOF*/
/*******************************************************************************
**                       PolySpace violations Section                         **
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
/*Design ID : SD_SDD_0449*/
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
**                      	Function Definitions                          **
*******************************************************************************/
/*Design ID : SD_SDD_0339,SD_SDD_0002,SD_SDD_0405*/

/*******************************************************************************
** Function Name        : Sd_ServerServiceDownEntered                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the server service     **
**                      : state machine enters the DOWN state                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - Pointer to server service   **
**                          static structure                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId                 **
**                        Function(s) invoked : SoAd_CloseSoCon               **
** Design ID            : SD_SDD_0162,SD_SDD_0004                             **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerServiceDownEntered(
const Sd_ServerServiceStaticType * LpServerServiceStatic)
{
  uint16 LusCount;
  SoAd_SoConIdType const *LpSocketCon;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;

  /* SWS_SD_00605 */
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pTcpSoConGrp is not equal to SD_NULL_PTR. */ 
  if (LpServerServiceStatic->pTcpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements =  LpServerServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                                                                  LusCount++)
    {
      LpSocketCon = &Sd_GaaSoConId[LusCount];
	 /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      (void) SoAd_CloseSoCon( * LpSocketCon, (boolean)SD_FALSE);
    }
  }
  /* SWS_SD_00605 */
   /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pUdpSoConGrp is not equal to SD_NULL_PTR. */
  if (LpServerServiceStatic->pUdpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpServerServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                                                                  LusCount++)
    {
      LpSocketCon = &Sd_GaaSoConId[LusCount];
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      (void) SoAd_CloseSoCon( * LpSocketCon, (boolean)SD_FALSE);
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ServerServiceWaitEntered                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the server service     **
**                      : state machine enters the WAIT state                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpServerService - Pointer to server service         **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to the server       **
**                         service static structure                           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId                 **
**                        Function(s) invoked : Sd_Rand,                      **
**                          SoAd_EnableRouting, SoAd_OpenSoCon                **
**                                                                            **
** Design ID              : SD_SDD_0163                                       **
*******************************************************************************/

#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerServiceWaitEntered (
Sd_ServerServiceType * LpServerService,
const Sd_ServerServiceStaticType * LpServerServiceStatic)
{
  Sd_ServerTimerStaticType const *LpTimer;
  SoAd_SoConIdType const *LpSocketCon;
  uint16 LusCount;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;

  /* SWS_SD_00330
     SWS_SD_00606a*/
/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     blActivationRoGrpIdPresent is not equal to SD_FALSE. */	 
  if (SD_TRUE == (LpServerServiceStatic->stServerStaticFlag).
                                                blActivationRoGrpIdPresent)
  {
    (void) SoAd_DisableRouting(LpServerServiceStatic->ddActivationRoGrpId);
  }
  LpTimer = LpServerServiceStatic->pServerTimer;
  LpServerService->ulServerDelayCount
        = Sd_Rand ( (uint32) LpTimer->ulInitialOfferDelayMin,
                    (uint32) LpTimer->ulInitialOfferDelayMax);
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pTcpSoConGrp is not equal to SD_NULL_PTR. */ 
  if (LpServerServiceStatic->pTcpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpServerServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                                                                    LusCount++)
    {
      LpSocketCon = &Sd_GaaSoConId[LusCount] ;
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */	  
      (void) SoAd_OpenSoCon( * LpSocketCon);
    }
  }
   /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pUdpSoConGrp is not equal to SD_NULL_PTR. */
  if (LpServerServiceStatic->pUdpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements =  LpServerServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                                                                    LusCount++)
    {
/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      LpSocketCon = &Sd_GaaSoConId[LusCount] ;
      (void) SoAd_OpenSoCon( * LpSocketCon);
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ServerStateInitialWait                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the activities for the       **
**                          server state machine in the INITIAL WAIT phase    **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpServerService - Pointer to server service         **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to the server       **
**                         service static structure                           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandler,              **
**                          Sd_GaaEvHandlerStatic                             **
**                                                                            **
**                        Function(s) invoked : Sd_ServerServiceDownEntered   **
**                          Sd_EvHandlerRelease, Sd_SendOffer,                **
**                          BswM_Sd_EventHandlerCurrentState                  **
**                                                                            **
** Design ID              : SD_SDD_0164                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateInitialWait(
  Sd_ServerServiceType * LpServerService,
  const Sd_ServerServiceStaticType * LpServerServiceStatic)
{
  #if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  Sd_EvHandlerType *LpEvHandler;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  uint16 LusBaseIndex;
  uint16 LusCount;
  uint16 LusNoOfElements;
  #endif
  Sd_ServerTimerStaticType const *LpServerTimer;
  LpServerTimer = LpServerServiceStatic->pServerTimer;


  /* SWS_SD_00323
     SWS_SD_00320
	 SWS_SD_00323b  */
  if (SD_SERVER_SERVICE_AVAILABLE != LpServerService->enServerServiceSetState)
  {
    Sd_ServerServiceDownEntered(LpServerServiceStatic);
    LpServerService->enServerPhase = SD_SERVER_DOWN;

    #if (STD_ON == SD_EV_HANDLER_CONFIGURED)
    LusBaseIndex = LpServerServiceStatic->usBaseEvHandlerIndex;
    LusNoOfElements = LpServerServiceStatic->usNoOfEvHandlers;

    for (LusCount = LusBaseIndex;
            LusCount < (LusBaseIndex + LusNoOfElements); LusCount++)
    {
      LpEvHandler = &Sd_GaaEvHandler[LusCount];
      
	  #if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount];
      #else
      LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount);
      #endif
      {
   /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
        LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;
        Sd_EvHandlerRelease(LpEvHandler, LpEvHandlerStatic);
        BswM_Sd_EventHandlerCurrentState( LpEvHandlerStatic->usHandleId,
                  LpEvHandler->enEvHandlerCurrState);
				  
	    /* Reset the timer SWS_SD_00323c */
        LpServerService -> ulServerDelayCount = SD_ZERO; 
      }
    }
    #endif
  }
  else
  {
    if (LpServerService->ulServerDelayCount == (uint32)SD_ZERO)
    {
      Sd_SendOffer(LpServerServiceStatic, SD_NULL_PTR, SD_ZERO, (boolean)SD_FALSE);
      /*  SWS_SD_00435 
          SWS_SD_00318  
		  SWS_SD_00321 */
    /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
     the ucInitialOfferRepetitionsMax is not zero. */   
      if (LpServerTimer->ucInitialOfferRepetitionsMax == SD_ZERO)
      {
        /*  SWS_SD_00450   */
        LpServerService->ulServerDelayCount =
                                   LpServerTimer->ulTimerOfferCyclicDelay;
        LpServerService->enServerPhase = SD_SERVER_MAIN;
      }
      /*  SWS_SD_00434  */
     /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
     the ucInitialOfferRepetitionsMax is not zero. */  
	  else
      {
        /*LpServerService->ulServerDelayCount  =
                  LpServerTimer->ulInitialOfferRepetitionBaseDelay;*/
        Sd_GblBswServerRepitionStateFlag = (boolean)SD_TRUE;
        LpServerService->ucNoOfOffersSent = SD_ZERO;
        LpServerService->enServerPhase = SD_SERVER_REPETITION;
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ServerStateRepetition                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the activities for the       **
**                          server state machine in the REPETITION Phase      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpServerService - Pointer to server service         **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to the server       **
**                         service static structure                           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandler,              **
**                          Sd_GaaEvHandlerStatic                             **
**                                                                            **
**                        Function(s) invoked : Sd_EvHandlerRelease           **
**                          Sd_SendStopOffer, Sd_ServerServiceDownEntered,    **
**                          Sd_SendOffer, SoAd_DisableRouting,                **
**                          BswM_Sd_EventHandlerCurrentState                  **
**                                                                            **
** Design ID              : SD_SDD_0167                                       **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
 void Sd_ServerStateRepetition(
  Sd_ServerServiceType * LpServerService,
  const Sd_ServerServiceStaticType * LpServerServiceStatic)
{
  #if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  Sd_EvHandlerType *LpEvHandler;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  #endif
  uint16 LusMultiple;
  uint16 LusCount;
  SoAd_SoConIdType LddSoConId;
  SoAd_SoConModeType LenSoConMode;
  boolean LblSoConOnline = (boolean)SD_FALSE;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
 
  Sd_ServerTimerStaticType const *LpServerTimer;
  LpServerTimer = LpServerServiceStatic->pServerTimer;

/* SWS_SD_00732  */
/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pTcpSoConGrp is not equal to SD_NULL_PTR. */ 
 if (( LpServerService->enServerPhase == SD_SERVER_REPETITION ) && Sd_GblBswServerRepitionStateFlag)
 {
   LpServerService->ulServerDelayCount =
          LpServerTimer->ulInitialOfferRepetitionBaseDelay;
   Sd_GblBswServerRepitionStateFlag = (boolean)SD_FALSE;
 }	 
  if (LpServerServiceStatic -> pTcpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpServerServiceStatic ->pTcpSoConGrp -> usBaseSocketConIndex;
     LusNoOfElements =  LpServerServiceStatic -> pTcpSoConGrp -> usNoOfSockets;
     for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfElements)) 
		                            && (!LblSoConOnline); LusCount++)
     {
	    /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag
        are made sure that they are within their range by having necessary 
        boundary checks in order to prevent them from being out of bounds." */
       LddSoConId = Sd_GaaSoConId[LusCount];
       
       SoAd_GetSoConMode(LddSoConId, &LenSoConMode);
       if (LenSoConMode == SOAD_SOCON_ONLINE)
       {
         LblSoConOnline = (boolean)SD_TRUE;
       }
     }
  }
  	/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pUdpSoConGrp is not equal to SD_NULL_PTR. */ 
  if (LpServerServiceStatic -> pUdpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements =  LpServerServiceStatic -> pUdpSoConGrp -> usNoOfSockets;
    for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfElements))
                                   && (!LblSoConOnline); LusCount++)
    {
	    /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag
        are made sure that they are within their range by having necessary 
        boundary checks in order to prevent them from being out of bounds." */
      LddSoConId = Sd_GaaSoConId[LusCount];
      
      SoAd_GetSoConMode (LddSoConId, &LenSoConMode);
      if (LenSoConMode == SOAD_SOCON_ONLINE)
      {
       LblSoConOnline = (boolean)SD_TRUE;
      }
    }
  } 
  
  /*  SWS_SD_00340 
      SWS_SD_00358 */
  /*  SWS_SD_00338  
      SWS_SD_00338b 
	  SD_SRS_1271 */
 if (LblSoConOnline)
 {
   if (SD_SERVER_SERVICE_AVAILABLE != LpServerService->enServerServiceSetState)
   {
    #if (STD_ON == SD_EV_HANDLER_CONFIGURED)
    LusBaseIndex = LpServerServiceStatic->usBaseEvHandlerIndex;
    LusNoOfElements = LpServerServiceStatic->usNoOfEvHandlers;

    for (LusCount = LusBaseIndex;
                 LusCount < (LusBaseIndex + LusNoOfElements); LusCount++)
    {
      LpEvHandler = &Sd_GaaEvHandler[LusCount];
      
	   #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
      LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount];
      #else
      LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount);
      #endif
/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      if (LpEvHandler->enEvHandlerCurrState != SD_EVENT_HANDLER_RELEASED)
      {
        LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;
        Sd_EvHandlerRelease(LpEvHandler, LpEvHandlerStatic);
        BswM_Sd_EventHandlerCurrentState( LpEvHandlerStatic->usHandleId,
            LpEvHandler->enEvHandlerCurrState);
      }
    }
    #endif

    /*  SWS_SD_00341  */
    (void) SoAd_DisableRouting(LpServerServiceStatic->ddActivationRoGrpId);

    /* As per bugzilla 70713 */
    Sd_SendStopOffer(LpServerServiceStatic, SD_ZERO);
    LpServerService->enServerPhase = SD_SERVER_DOWN;
    Sd_ServerServiceDownEntered(LpServerServiceStatic);
  }
  else
  { /* SWS_SD_00329 
       SWS_SD_00336b 
	   SWS_SD_00457 */
    if (LpServerService->ulServerDelayCount == (uint32)SD_ZERO)
    {

      Sd_SendOffer(LpServerServiceStatic, SD_NULL_PTR, SD_ZERO, (boolean)SD_FALSE);

      LpServerService->ucNoOfOffersSent ++;
   /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be False when
   the ucInitialOfferRepetitionsMax is greater than ucNoOfOffersSent. */     
	 if (LpServerService->ucNoOfOffersSent <
                            LpServerTimer->ucInitialOfferRepetitionsMax)
      {
        LusMultiple = SD_ONE;
        /*  SWS_SD_00331
     		SWS_SD_00363a 
		    SWS_SD_00363b */
	 /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
        LusCount is greater to ucNoOfOffersSent.*/
        for (LusCount = SD_ZERO; LusCount < LpServerService->ucNoOfOffersSent;
                            LusCount++)
        {
          LusMultiple = LusMultiple * SD_TWO;
        }
        LpServerService->ulServerDelayCount  = (uint32) LusMultiple *
                        LpServerTimer->ulInitialOfferRepetitionBaseDelay;
      }
      /*  SWS_SD_00336  */
      else
      {
        /*  SWS_SD_00450  */
        LpServerService->ulServerDelayCount =
                              LpServerTimer->ulTimerOfferCyclicDelay;
        LpServerService->enServerPhase = SD_SERVER_MAIN;
      }
    }
  }
 }
 else
  {
    LpServerService -> enServerPhase = SD_SERVER_INITIAL_WAIT;
    Sd_ServerServiceWaitEntered(LpServerService, LpServerServiceStatic);
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ServerStateMain                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the activities for the       **
**                          server state machine in the MAIN Phase            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpServerService - Pointer to server service         **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to the server       **
**                         service static structure                           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandler,              **
**                          Sd_GaaEvHandlerStatic                             **
**                                                                            **
**                        Function(s) invoked : Sd_EvHandlerRelease,          **
**                          Sd_SendStopOffer, Sd_ServerServiceDownEntered,    **
**                          Sd_SendOffer, SoAd_DisableRouting,                **
**                          BswM_Sd_EventHandlerCurrentState,                 **
**                                                                            **
** Design ID              : SD_SDD_0166                                     **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateMain(
  Sd_ServerServiceType * LpServerService,
  const Sd_ServerServiceStaticType * LpServerServiceStatic)
{
  #if (STD_ON == SD_EV_HANDLER_CONFIGURED)
  Sd_EvHandlerType *LpEvHandler;
  Sd_EvHandlerStaticType const *LpEvHandlerStatic;
  uint16 LusCount;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  #endif
  Sd_ServerTimerStaticType const *LpServerTimer;

  LpServerTimer = LpServerServiceStatic->pServerTimer;

  /*  SWS_SD_00342  
      SWS_SD_00342b */
  /*  SWS_SD_00347 
      SWS_SD_00347b  */
  /*  SWS_SD_00348 
      SWS_SD_00348b 
	  SWS_SD_00348c*/
  if (SD_SERVER_SERVICE_DOWN == LpServerService->enServerServiceSetState)
  {
    #if (STD_ON == SD_EV_HANDLER_CONFIGURED)
    LusBaseIndex = LpServerServiceStatic->usBaseEvHandlerIndex;
    LusNoOfElements = LpServerServiceStatic->usNoOfEvHandlers;

    for (LusCount = LusBaseIndex;
            LusCount< (LusBaseIndex + LusNoOfElements); LusCount++)
    {
      LpEvHandler = &Sd_GaaEvHandler[LusCount];
      
	   #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
      LpEvHandlerStatic = &Sd_GaaEvHandlerStatic[LusCount];
      #else
      LpEvHandlerStatic = ((Sd_GpConfigPtr->pSd_GaaEvHandlerStatic) + LusCount);
      #endif
     /* polyspace +10 RTE:IDP [Justified:Low] "This condition shall be True when
   the SD_EVENT_HANDLER_RELEASED is not equal to LpEvHandler. */
   /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
   the SD_EVENT_HANDLER_RELEASED is not equal to LpEvHandler. */
      if (SD_EVENT_HANDLER_RELEASED  != LpEvHandler->enEvHandlerCurrState)
      {
        LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;
        Sd_EvHandlerRelease(LpEvHandler, LpEvHandlerStatic);
        BswM_Sd_EventHandlerCurrentState( LpEvHandlerStatic->usHandleId,
                 LpEvHandler->enEvHandlerCurrState);
      }
    }
    #endif

    /* as per SWS_SD_00348 */
    Sd_SendStopOffer(LpServerServiceStatic, SD_ZERO);
    LpServerService->enServerPhase = SD_SERVER_DOWN;
    /* as per SWS_SD_00349 */
    (void) SoAd_DisableRouting(LpServerServiceStatic->ddActivationRoGrpId);
    Sd_ServerServiceDownEntered(LpServerServiceStatic);
  }
  else
  {
    /*  SWS_SD_00449
     	SWS_SD_00451*/
    /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
   the ulTimerOfferCyclicDelay is greater than zero.
   Module Test Case Reference SD_ETC_152, SWS ID SWS_SD_00449" */
    if ((LpServerTimer -> ulTimerOfferCyclicDelay > (uint32)SD_ZERO)
            && ((uint32)SD_ZERO == (uint32)LpServerService->ulServerDelayCount))
    {
      LpServerService->ulServerDelayCount =
                              LpServerTimer->ulTimerOfferCyclicDelay;
      Sd_SendOffer(LpServerServiceStatic, SD_NULL_PTR, SD_ZERO, (boolean)SD_FALSE);
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ServerServiceStateMachine                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is the main server state machine      **
**                      : It is called  called in the main function for       **
**                      : each ServerService configured.                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to Instance static structure   **
**                      : LpServerService - Pointer to server service         **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to the server       **
**                         service static structure                           **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GblInitCalled              **
**                        Function(s) invoked : Sd_ServerServiceWaitEntered   **
**                          Sd_ServerStateInitialWait, Sd_ServerStateMain,    **
**                          Sd_ServerStateRepetition, Sd_ServerStateMachine   **
**                                                                            **
** Design ID           : SD_SDD_0165,SD_SDD_0335                              **
*******************************************************************************/
#if (STD_ON == SD_SERVER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ServerStateMachine(
  const Sd_InstanceType * LpInstance,
  const Sd_InstanceStaticType * LpInstanceStatic,
  Sd_ServerServiceType * LpServerService,
  const Sd_ServerServiceStaticType * LpServerServiceStatic)
{
	/*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (LpServerService->ulServerDelayCount > (uint32)SD_ZERO)
  {
    LpServerService->ulServerDelayCount --;
  }
  /* polyspace +10 RTE:UNR [Justified:Low] Default switch clause is unreachable 
              because server is in one of the service state of state machine  */
  switch (LpServerService-> enServerPhase)
  {
    case SD_SERVER_DOWN:
    {
      /*  SWS_SD_00317  */
      /*  SWS_SD_00606b  */
      if ((Sd_GblInitCalled) &&
        (SD_SERVER_SERVICE_AVAILABLE ==
                                LpServerService->enServerServiceSetState) &&
        (TCPIP_IPADDR_STATE_ASSIGNED == LpInstance->enIpAddrState))
      {
        LpServerService->enServerPhase = SD_SERVER_INITIAL_WAIT;
        /*Redmine : 28582 */
        /*Bugzilla : 75555*/
        (void) SoAd_OpenSoCon(LpInstanceStatic->ddIpAddrSoConId);
        Sd_ServerServiceWaitEntered(LpServerService, LpServerServiceStatic);
      }
      break;
    }
    /* SD_SRS_00317a 
       SWS_SD_00317b
	   SWS_SD_00317b */
    case SD_SERVER_INITIAL_WAIT :
    {
      Sd_ServerStateInitialWait(LpServerService, LpServerServiceStatic);
      break;
    }
    case SD_SERVER_REPETITION :
    {
      Sd_ServerStateRepetition(LpServerService, LpServerServiceStatic);
      break;
    }
    case SD_SERVER_MAIN :
    {
      Sd_ServerStateMain(LpServerService, LpServerServiceStatic);
      break;
    }
	/* polyspace +10 RTE:UNR [Justified:Low] "Default switch clause is 
	unreachable because server is in one of the service state of state machine"*/
    default :
    {
		/* Do Nothing */
      break;
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_EvHandlerMain                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This is called from within main for each Ev_handler **
**                      : configured                                          **
**                        This is not a state machine                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : LpServerService - Pointer to server service         **
**                          structure                                         **
**                      : LpServerServiceStatic - Pointer to the server       **
**                         service static structure                           **
**                      : LpEvHandlerStatic - Pointer to event handler static **
**                         structure                                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaEvHandlerSubGrp,        **
**                                                                            **
**                        Function(s) invoked : Sd_RemoveClientFromFanout,    **
**                          BswM_Sd_EventHandlerCurrentState                  **
**                                                                            **
** Design ID              : SD_SDD_0158                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)

#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_EvHandlerMain(
    const Sd_ServerServiceType * LpServerService,
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic)
{
  Sd_EvHandlerSubGrpType *LpEvHandlerSubGrp;
  uint16 LusCount;
  boolean LblEvHandlerTtlExpired;
  uint16 LusBaseIndex;

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
 /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
 made sure that they are within their range by having necessary boundary
 checks in order to prevent them from being out of bounds." */
 // LusBaseIndex = (uint16)LpEvHandlerStatic->usEvHandlerSelfIndex;
  if (Sd_GaaBswMEvNotifiFlag[LpEvHandlerStatic->usHandleId])
  {
    BswM_Sd_EventHandlerCurrentState(LpEvHandlerStatic->usHandleId,
           SD_EVENT_HANDLER_REQUESTED);

    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
    Sd_GaaBswMEvNotifiFlag[LpEvHandlerStatic->usHandleId] = (boolean)SD_FALSE;
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  }
#endif
 /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
 made sure that they are within their range by having necessary boundary
 checks in order to prevent them from being out of bounds." */
  LusBaseIndex = (uint16)LpEvHandlerStatic->usEvHandlerSelfIndex * SD_SIXTEEN;

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + SD_SIXTEEN);
       LusCount++)
  {
    LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount];

    LblEvHandlerTtlExpired = (boolean)SD_FALSE;
   /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    if (LpEvHandlerSubGrp->ulEvSubGrpTtlCount > (uint32)SD_ZERO)
    {
      LpEvHandlerSubGrp->ulEvSubGrpTtlCount =
          LpEvHandlerSubGrp->ulEvSubGrpTtlCount - (uint32)SD_ONE;
      if ((uint32)SD_ZERO ==  (uint32)LpEvHandlerSubGrp->ulEvSubGrpTtlCount)
      {
        LblEvHandlerTtlExpired = (boolean)SD_TRUE;
      }
    }

    if ((SD_SERVER_REPETITION  == LpServerService->enServerPhase) ||
        (SD_SERVER_MAIN  == LpServerService->enServerPhase))
    {
      /* SWS_SD_00458 ,  SWS_SD_00403  */
      if (LblEvHandlerTtlExpired)
      {
        /*  SWS_SD_00452 */
        Sd_RemoveClientFromFanout(LpEvHandler, LpEvHandlerStatic,
                                        LpEvHandlerSubGrp);
   /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
        if ((SD_ZERO == LpEvHandler->ucNoOfSubGrpsTcp) &&
            (SD_ZERO == LpEvHandler->ucNoOfSubGrpsUdp))
        {
          LpEvHandler->enEvHandlerCurrState = SD_EVENT_HANDLER_RELEASED;
          BswM_Sd_EventHandlerCurrentState( LpEvHandlerStatic->usHandleId,
                      LpEvHandler->enEvHandlerCurrState);
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ResetToWildcardServer                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to reset the socket         **
**                        connection of the event handler back to wildcard if **
**                        required                                            **
**                        It decrements usNoOfSubServers counter              **
**                        It sets the remote addr of the socket connection if **
**                        blWildcardSocketServer is TRUE                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoCon, Sd_GaaSoConId,   **
**                          Sd_GddIpv4Wildcard, Sd_GddIpv6Wildcard            **
**                                                                            **
**                        Function(s) invoked : SoAd_SetRemoteAddr            **
**                                                                            **
** Design ID              : SD_SDD_0161                                       **
*******************************************************************************/

#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ResetToWildcardServer(
  const Sd_InstanceStaticType * LpInstanceStatic,
  const Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  Sd_TcpUdpEnumType enTcpUdp)
{
  Sd_SoConType *LpSoConStructure;
  SoAd_SoConIdType LddSoConId;

  if (SD_TCP == enTcpUdp)
  {
    LddSoConId = LpEvHandlerSubGrp->ddSoConTcpIndex;
  }
  else
  {
    LddSoConId = LpEvHandlerSubGrp->ddSoConUdpIndex;
  }

  LpSoConStructure = &Sd_GaaSoCon[LddSoConId];/*PB : ??*/
   /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (LpSoConStructure->usNoOfSubServers > SD_ZERO)
  {
    LpSoConStructure->usNoOfSubServers =
          LpSoConStructure->usNoOfSubServers - SD_ONE;
    if ((SD_ZERO == LpSoConStructure->usNoOfSubServers) &&
        (SD_TRUE == LpSoConStructure->stSoConFlag.blWildcardSocketServer))
    {
      LpSoConStructure->stSoConFlag.blWildcardSocketServer = SD_FALSE;
	  /* polyspace +10 RTE:UNR [Justified:Low] If condition is always set to
	  True cause blDomainIpv4 is never false */
      if (LpInstanceStatic->blDomainIpv4)
      {
        (void) SoAd_SetRemoteAddr(Sd_GaaSoConId[LddSoConId],
            &Sd_GddIpv4Wildcard);
      }
      #if (STD_ON == SD_IPV6_ENABLED)
      else
      {
        (void) SoAd_SetRemoteAddr(Sd_GaaSoConId[LddSoConId],
          &Sd_GddIpv6Wildcard);
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
** Function Name        : Sd_EvHandlerRelease                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function stops all subscriptions of the Event  **
**                          Handler                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEvHandler - Pointer to event handler structure    **
**                      : LpEvHandlerStatic - Pointer to event handler static **
**                          structure                                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic     **
**                          Sd_GaaInstanceStatic, Sd_GaaEvHandlerSubGrp,      **
**                          Sd_GaaSoConId                                     **
**                                                                            **
**                        Function(s) invoked : Sd_ResetToWildcardServer      **
**                          SoAd_DisableSpecificRouting                       **
**                                                                            **
** Design ID              : SD_SDD_0159                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_EvHandlerRelease(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic)
{
  SoAd_SoConIdType LddGaaSoConIdTcp;
  SoAd_SoConIdType LddGaaSoConIdUdp;
  Sd_EvHandlerSubGrpType *LpEvHandlerSubGrp;
  Sd_InstanceStaticType const *LpInstanceStatic;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  uint16 LusCount;
  uint16 LusBaseIndex;

  
  #if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpServerServiceStatic = &Sd_GaaServerServiceStatic[LpEvHandlerStatic->usServerServiceIndex];
  #else
  LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LpEvHandlerStatic->usServerServiceIndex);
  #endif 	  

  #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
  LpInstanceStatic =
      &Sd_GaaInstanceStatic[LpServerServiceStatic->ucSdInstanceIndex];
	 
#else
	LpInstanceStatic = ((Sd_GpConfigPtr->pInstanceStatic) + LpServerServiceStatic->ucSdInstanceIndex);
#endif

  LusBaseIndex = (uint16)LpEvHandlerStatic->usEvHandlerSelfIndex * SD_SIXTEEN;

  /* Loop over each subscribed eventgroup. */

  for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + SD_SIXTEEN);
       LusCount++)
  {
    LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount];

    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
   /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
	if (LpEvHandlerSubGrp -> ddSoConTcpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
	{
    LddGaaSoConIdTcp = Sd_GaaSoConId[LpEvHandlerSubGrp -> ddSoConTcpIndex];
    if (SD_TRUE == (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv)
    {
      SchM_Exit_Sd_MODE_STATUS_PROTECTION();
	  /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False. */ 
      if ((SD_TRUE ==  LpEvHandlerStatic->stEvHandlerStaticFlag.
                                              blTcpActivationRoGrpIdPresent))
      {
        (void) SoAd_DisableSpecificRouting (
            LpEvHandlerStatic->ddTcpActivationRoGrpId, LddGaaSoConIdTcp);
      }
      Sd_ResetToWildcardServer(LpInstanceStatic, LpEvHandlerSubGrp, SD_TCP);
      (LpEvHandlerSubGrp->stEvHandlerFlag). blTcpActiveEv = SD_FALSE;
      LpEvHandlerSubGrp->ulEvSubGrpTtlCount = SD_ZERO;
    }
    else
    {
      SchM_Exit_Sd_MODE_STATUS_PROTECTION();
    }
   }
  }

  if ((SD_ZERO == LpEvHandlerStatic->usMulticastThreshold) ||
      (LpEvHandler->ucNoOfSubGrpsUdp <LpEvHandlerStatic->usMulticastThreshold))
  {
    LusBaseIndex = (uint16)LpEvHandlerStatic->usEvHandlerSelfIndex * SD_SIXTEEN;

    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + SD_SIXTEEN);
         LusCount++)
    {
      LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount];

      SchM_Enter_Sd_MODE_STATUS_PROTECTION();

    if (LpEvHandlerSubGrp -> ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
	{
      LddGaaSoConIdUdp = Sd_GaaSoConId[LpEvHandlerSubGrp -> ddSoConUdpIndex];
      if (SD_TRUE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv)
      {
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
		 /* polyspace +4 RTE:UNR [Justified:Low]"This condition shall be True 
		         when  blTcpActivationRoGrpIdPresent is not equal to False. */
        if ((SD_TRUE ==  LpEvHandlerStatic->stEvHandlerStaticFlag.
                                                blUdpActivationRoGrpIdPresent))
        {
          (void) SoAd_DisableSpecificRouting (
              LpEvHandlerStatic->ddUdpActivationRoGrpId, LddGaaSoConIdUdp);
        }
        Sd_ResetToWildcardServer(LpInstanceStatic, LpEvHandlerSubGrp, SD_UDP);
        (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv = SD_FALSE;
        LpEvHandlerSubGrp->ulEvSubGrpTtlCount = SD_ZERO;
      }
      else
      {
        SchM_Exit_Sd_MODE_STATUS_PROTECTION();
      }
    }
   }
  }
  else
  {
	 /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False. */
    if ((SD_TRUE == (LpEvHandlerStatic->stEvHandlerStaticFlag).
                      blMulticastActivationRoGrpIdPresent))
    {
      (void) SoAd_DisableSpecificRouting(
               LpEvHandlerStatic->ddMulticastActivationRoGrpId,
               LpEvHandlerStatic->ddMulticastEventSoConId);
    }
    LusBaseIndex = (uint16)LpEvHandlerStatic->usEvHandlerSelfIndex * SD_SIXTEEN;

    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + SD_SIXTEEN);
         LusCount++)
    {
      LpEvHandlerSubGrp = &Sd_GaaEvHandlerSubGrp[LusCount];

      if (SD_TRUE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv)
      {
        Sd_ResetToWildcardServer(LpInstanceStatic, LpEvHandlerSubGrp, SD_UDP);

        (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv = SD_FALSE;

        LpEvHandlerSubGrp->ulEvSubGrpTtlCount = SD_ZERO;
      }
    }
  }
  LpEvHandler->ucNoOfSubGrpsTcp = SD_ZERO;
  LpEvHandler->ucNoOfSubGrpsUdp = SD_ZERO;
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_FindTcpIndex                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function adds a TCP client to the fanout.      **
**                        It matches the socket connection based on the TCP   **
**                          address received in the subscribe option.         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - Pointer to the static       **
**                           server structure                                 **
**                      : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                      : LpIpAddrTcp - pointer to the TCP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Socket is matched or        **
**                        E_NOT_OK - The socket is not matched and a NACK     **
**                          should be sent                                    **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId, Sd_GaaSoCon    **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard, SoAd_GetRemoteAddr,           **
**                          SoAd_SetRemoteAddr, SoAd_EnableSpecificRouting,   **
**                          SoAd_IfSpecificRoutingGroupTransmit               **
**                                                                            **
** Design ID              : SD_SDD_0290                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_FindTcpIndex(
  const Sd_ServerServiceStaticType * LpServerServiceStatic,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  const TcpIp_SockAddrType * LpIpAddrTcp,
  uint8 LucOptionsCode)
{
  Std_ReturnType LddReturnValue;
  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  SoAd_SoConIdType LddMatchSocketIndex;
  SoAd_SoConIdType LddWildcardSocketIndex;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  uint16 LusCount;
  TcpIp_SockAddrType LstIpAddr;
  SoAd_SoConModeType LenSoConMode;

  /*  SWS_SD_00453 
      SWS_SD_00453b  
   	  SWS_SD_00453c  */
  LddReturnValue = E_OK;
  LddMatchSocketIndex = SD_ZERO;
  LddWildcardSocketIndex = SD_ZERO;

  /* polyspace +15 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False.*/
  if ((SD_TCP_OPTIONS_MASK == (LucOptionsCode & SD_TCP_OPTIONS_MASK)) &&
    (SD_NULL_PTR !=  LpServerServiceStatic->pTcpSoConGrp) &&
    ((SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag.
    blTcpActivationRoGrpIdPresent) ||
    (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag .
    blTcpTriggeringRoGrpIdPresent)))
  {
    LblMatchRecd = (boolean)SD_FALSE;
    LblWildcardMatch = (boolean)SD_FALSE;
    LusBaseIndex = LpServerServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpServerServiceStatic->pTcpSoConGrp->usNoOfSockets;

    for (LusCount = LusBaseIndex;
      (LusCount < (LusBaseIndex + LusNoOfElements)) &&
      (!LblMatchRecd); LusCount++)
    {
	    /*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */	
      LstIpAddr.domain = LpIpAddrTcp->domain;
    /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
      (void) SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddr);
      LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpIpAddrTcp);
      if (LblMatchRecd)
      {
        LddMatchSocketIndex = (SoAd_SoConIdType) LusCount;
      }

      if (!LblWildcardMatch)
      {
        LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddr);
        if (LblWildcardMatch)
        {
          LddWildcardSocketIndex = (SoAd_SoConIdType) LusCount;
        }
      }
    }
	
    /* SRS : SD_SRS_2644, SD_SRS_2645 
     * SWS : SWS_Sd_00755, SWS_Sd_00756
     * FT : SD_ETC_1250
     * */
	  SoAd_GetSoConMode(Sd_GaaSoConId[LddMatchSocketIndex], &LenSoConMode);
	
    if (LblMatchRecd)
    {
		  if (SOAD_SOCON_ONLINE == LenSoConMode)
      {
        LpEvHandlerSubGrp->ddSoConTcpIndex = LddMatchSocketIndex;
        Sd_GaaSoCon[LddMatchSocketIndex].usNoOfSubServers =
        Sd_GaaSoCon[LddMatchSocketIndex].usNoOfSubServers + SD_ONE;
  
		  }
      else
      {
        /* SubscribeNack is sent in calling function */
        LddReturnValue = E_NOT_OK;
      }
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LblWildcardMatch)
    {
		  if (SOAD_SOCON_ONLINE == LenSoConMode)
      {
        (void) SoAd_SetRemoteAddr(Sd_GaaSoConId[LddWildcardSocketIndex],
          LpIpAddrTcp);
        LpEvHandlerSubGrp->ddSoConTcpIndex = LddWildcardSocketIndex;

        Sd_GaaSoCon[LddWildcardSocketIndex].stSoConFlag.
          blWildcardSocketServer = SD_TRUE;
        Sd_GaaSoCon[LddWildcardSocketIndex].usNoOfSubServers =
          Sd_GaaSoCon[LddWildcardSocketIndex].usNoOfSubServers + SD_ONE;
		  }			
			else
      {
        /* SubscribeNack is sent in calling function */
        LddReturnValue = E_NOT_OK;
      }
    }
    else
    {
      LddReturnValue = E_NOT_OK;
    }
  }
  else
  {
    LddReturnValue = E_OK;
  }
  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_AddClientToFanoutTcp                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : It enables the specific routing and enables the     **
**                          transmission of initial events by calling the     **
**                          SoAd functions on the matched socket ID           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - Pointer to the static       **
**                           server structure                                 **
**                      : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                      : LpIpAddrTcp - pointer to the TCP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - specific routing enabled    **
**                        and initial event transmission enabled              **
**                                               or                           **
**                        E_NOT_OK - specific routing not enabled and         **
**                        initial event transmission not sent                 **
**                                                                            **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId, Sd_GaaSoCon    **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard, SoAd_GetRemoteAddr,           **
**                          SoAd_SetRemoteAddr, SoAd_EnableSpecificRouting,   **
**                          SoAd_IfSpecificRoutingGroupTransmit               **
**                                                                            **
** Design ID              : SD_SDD_0290                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_AddClientToFanoutTcp(
  const Sd_ServerServiceStaticType * LpServerServiceStatic,
  Sd_EvHandlerType * LpEvHandler,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  const TcpIp_SockAddrType * LpIpAddrTcp,
  uint8 LucOptionsCode,
  Std_ReturnType Sd_FoundTcpIndex)
{
  Std_ReturnType LddReturnValue;
  Std_ReturnType LddConnectionReturnValue;

  /*  SWS_SD_00453 
      SWS_SD_00453b  
   	  SWS_SD_00453c  */
  LddReturnValue = Sd_FoundTcpIndex;
  LddConnectionReturnValue = (uint8)TCPIP_E_NOT_OK;

  /* polyspace +15 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False.*/
  if ((SD_TCP_OPTIONS_MASK == (LucOptionsCode & SD_TCP_OPTIONS_MASK)) &&
    (SD_NULL_PTR !=  LpServerServiceStatic->pTcpSoConGrp) &&
    ((SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag.
    blTcpActivationRoGrpIdPresent) ||
    (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag .
    blTcpTriggeringRoGrpIdPresent)))
  {
    /* SWS_SD_00760a , SD_SRS_2717, ETC_FT_1247, SD_SDD_0290 */
    if (LpEvHandlerSubGrp->ddSoConTcpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
    /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
    {
      LddConnectionReturnValue = 
        (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConTcpIndex], 
        LpIpAddrTcp));
    }
    if ((E_OK == LddReturnValue) && (LddConnectionReturnValue == (uint8)TCPIP_E_OK))
    {

	    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
      LpEvHandlerStatic is SD_TRUE. */
      if ((SD_TRUE ==  LpEvHandlerStatic->stEvHandlerStaticFlag.
        blTcpActivationRoGrpIdPresent))
      {
        if (LpEvHandlerSubGrp->ddSoConTcpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
        {
          (void) SoAd_EnableSpecificRouting (
            LpEvHandlerStatic->ddTcpActivationRoGrpId,
            Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConTcpIndex]);
	      }
      }
      /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
      LpEvHandlerStatic is SD_TRUE. */
      if ((SD_TRUE ==  LpEvHandlerStatic->stEvHandlerStaticFlag.
        blTcpTriggeringRoGrpIdPresent))
      {
        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
          (void) SoAd_IfSpecificRoutingGroupTransmit (
            LpEvHandlerStatic->ddTcpTriggeringRoGrpId,
            Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConTcpIndex]);
      }
      (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv = SD_TRUE;
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      LpEvHandler->ucNoOfSubGrpsTcp =
        LpEvHandler->ucNoOfSubGrpsTcp + SD_ONE;
    }
  }
  else
  {
    LddReturnValue = E_OK;
  }
  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_AddClienttoFanoutUdpActions                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function enables the specific routing and      **
**                          transmission of initial events by calling the     **
**                          SoAd functions on the matched socket ID. This is  **
**                          depending on the parameter of Multicast Threshold **
**                          as per SWS_SD_0455                                **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                      : LddMatchSocketIndex - This is the socket index that **
**                           has been matched for the UDP option              **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId,                **
**                          Sd_GaaEvHandlerSubGrp                             **
**                                                                            **
**                        Function(s) invoked : SoAd_EnableSpecificRouting,   **
**                          SoAd_DisableSpecificRouting,                      **
**                          SoAd_IfSpecificRoutingGroupTransmit               **
**                                                                            **
** Design ID              : SD_SDD_0292                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_AddClienttoFanoutUdpActions(
  Sd_EvHandlerType * LpEvHandler,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  SoAd_SoConIdType LddMatchSocketIndex)
{
  uint8 LucNoOfSubGrpsUdp;
  Sd_EvHandlerSubGrpType const *LpSubGrpTemp;
  uint16 LusBaseIndex;
  uint16 LusCount;

  /* SWS_SD_00455
     SWS_SD_00455a 
	 SWS_SD_00455b
     SWS_SD_00455c
     SWS_SD_00455d */
/*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  LucNoOfSubGrpsUdp = LpEvHandler->ucNoOfSubGrpsUdp + SD_ONE;
/*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if ((SD_ZERO == LpEvHandlerStatic->usMulticastThreshold) ||
    (LucNoOfSubGrpsUdp < LpEvHandlerStatic->usMulticastThreshold))
  {
	/* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
    LpEvHandlerStatic is SD_TRUE. */
    if (SD_TRUE == (LpEvHandlerStatic->stEvHandlerStaticFlag).
                                  blUdpActivationRoGrpIdPresent )
    {
      (void) SoAd_EnableSpecificRouting(
                        LpEvHandlerStatic->ddUdpActivationRoGrpId,
                        Sd_GaaSoConId[LddMatchSocketIndex]);
    }
  }
  /*LogicAnalyser WRN04: Manually Verified*/
 	/* polyspace +8 RTE:UNR [Justified:Low] "This condition shall be True when
    LpEvHandlerStatic is SD_TRUE. */
  else if (LucNoOfSubGrpsUdp == LpEvHandlerStatic->usMulticastThreshold)
  {
    LusBaseIndex = (uint16) LpEvHandlerStatic->
    usEvHandlerSelfIndex * SD_SIXTEEN;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + SD_SIXTEEN);
    LusCount++)
    {
      LpSubGrpTemp = &Sd_GaaEvHandlerSubGrp[LusCount];
	  
    /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
    LpEvHandlerStatic is SD_TRUE. */
      if (SD_TRUE == (LpEvHandlerStatic->stEvHandlerStaticFlag).
                                  blUdpActivationRoGrpIdPresent )
      {
/*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
        if (SD_TRUE == (LpSubGrpTemp->stEvHandlerFlag).blUdpActiveEv)
        {
		if (LpSubGrpTemp->ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
	     {
          (void) SoAd_DisableSpecificRouting(
                       LpEvHandlerStatic->ddUdpActivationRoGrpId,
                       Sd_GaaSoConId[LpSubGrpTemp->ddSoConUdpIndex]);
         }
	   }
      }
    }
	 /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     blMulticastActivationRoGrpIdPresent is not equal to SD_TRUE. */
    if ((SD_TRUE == (LpEvHandlerStatic->stEvHandlerStaticFlag).
                      blMulticastActivationRoGrpIdPresent))
    {
      (void) SoAd_EnableSpecificRouting(
                     LpEvHandlerStatic->ddMulticastActivationRoGrpId,
                     LpEvHandlerStatic->ddMulticastEventSoConId);
    }
  }
  else
  {
	  /*Do Nothing */
  }
  (void) SoAd_IfSpecificRoutingGroupTransmit(
                   LpEvHandlerStatic->ddUdpTriggeringRoGrpId,
                   Sd_GaaSoConId[LddMatchSocketIndex]);
  LpEvHandler->ucNoOfSubGrpsUdp = LpEvHandler->ucNoOfSubGrpsUdp + SD_ONE;
  (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv = SD_TRUE;
}
 /* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_FindUdpIndex                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function adds a UDP client to the fanout.      **
**                        It matches the socket connection based on the UDP   **
**                          address received in the subscribe option.         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - Pointer to the static       **
**                           server structure                                 **
**                      : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                      : LpIpAddrUdp - pointer to the UDP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Socket is matched or        **
**                        E_NOT_OK - The socket is not matched and a NACK     **
**                          should be sent                                    **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                          Sd_GaaSoConId, Sd_GaaSoCon                        **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard,Sd_AddClienttoFanoutUdpActions,**
**                          SoAd_SetRemoteAddr, SoAd_GetRemoteAddr,           **
**                          Dem_SetEventStatus, Dem_ReportErrorStatus         **
**                                                                            **
** Design ID              : SD_SDD_0291                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_FindUdpIndex(
  const Sd_ServerServiceStaticType * LpServerServiceStatic,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  const TcpIp_SockAddrType * LpIpAddrUdp,
  uint8 LucOptionsCode)
{
  Std_ReturnType LddReturnValue;
  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  SoAd_SoConIdType LddMatchSocketIndex;
  SoAd_SoConIdType LddWildcardSocketIndex;
  SoAd_SoConIdType LddAssignedSoConId;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  Sd_InstanceStaticType const *LpInstanceStatic;
  uint16 LusCount;

  TcpIp_SockAddrType LstIpAddr;

  LddReturnValue = E_OK;
  LddMatchSocketIndex = SD_ZERO;
  LddWildcardSocketIndex = SD_ZERO;
  #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
  LpInstanceStatic =
         &Sd_GaaInstanceStatic[LpServerServiceStatic->ucSdInstanceIndex];
  #else
	  LpInstanceStatic = (((Sd_GpConfigPtr->pInstanceStatic)) + 
      LpServerServiceStatic->ucSdInstanceIndex);
  #endif
  /* SWS_SD_00454
     SWS_SD_00454c */
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
  blTcpActivationRoGrpIdPresent is not equal to False. */
  if ((SD_UDP_OPTIONS_MASK == (LucOptionsCode & SD_UDP_OPTIONS_MASK)) &&
    (SD_NULL_PTR != LpServerServiceStatic->pUdpSoConGrp) &&
    ((SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag.
    blUdpActivationRoGrpIdPresent) ||
    (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag .
    blUdpTriggeringRoGrpIdPresent)))
  {
    LblMatchRecd = (boolean)SD_FALSE;
    LblWildcardMatch = (boolean)SD_FALSE;
    LusBaseIndex = LpServerServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpServerServiceStatic->pUdpSoConGrp->usNoOfSockets;

    for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfElements))
        && (!LblMatchRecd) ; LusCount++)
    {
	    /*polyspace +10 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
      LstIpAddr.domain =  LpIpAddrUdp->domain;
	    /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
      (void) SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LstIpAddr);

      LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpIpAddrUdp);
      if (LblMatchRecd)
      {
        LddMatchSocketIndex = (SoAd_SoConIdType) LusCount;
      }
      /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
      LblWildcardMatch is SD_FALSE. */
      if (!LblWildcardMatch)
      {
        LblWildcardMatch = Sd_MatchIpWildcard(&LstIpAddr);
        if (LblWildcardMatch)
        {
          LddWildcardSocketIndex = (SoAd_SoConIdType) LusCount;
        }
      }
    }
    if (LblMatchRecd)
    {
      LpEvHandlerSubGrp->ddSoConUdpIndex = LddMatchSocketIndex;
      Sd_GaaSoCon[LddMatchSocketIndex].usNoOfSubServers =
        Sd_GaaSoCon[LddMatchSocketIndex].usNoOfSubServers + SD_ONE;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LblWildcardMatch)
    {
		  /* Set the remote address of this wildcard socket */
      (void) SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LddWildcardSocketIndex],
        LpIpAddrUdp, &LddAssignedSoConId);
      if (LddAssignedSoConId == Sd_GaaSoConId[LddWildcardSocketIndex])
      {												
        LpEvHandlerSubGrp->ddSoConUdpIndex = LddWildcardSocketIndex;
        Sd_GaaSoCon[LddWildcardSocketIndex].stSoConFlag.
          blWildcardSocketServer = SD_TRUE;
        Sd_GaaSoCon[LddWildcardSocketIndex].usNoOfSubServers =
          Sd_GaaSoCon[LddWildcardSocketIndex].usNoOfSubServers + SD_ONE;
        LddMatchSocketIndex = LddWildcardSocketIndex;        
	    }
      else
      {
        LddReturnValue = E_NOT_OK;
      }
    }
	  /* polyspace +7 RTE:UNR [Justified:Low] "This condition shall be True when
    LddReturnValue is not equal to E_NOT_OK. */
    else
    {		
      /* SWS_SD_00454b */
	 	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
      SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
      LddReturnValue = E_NOT_OK;
    }
  }
  return(LddReturnValue);
}
 /* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif


/*******************************************************************************
** Function Name        : Sd_AddClientToFanoutUdp                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : T It enables the specific routing and enables the   **
**                          transmission of initial events by calling the     **
**                          SoAd functions on the matched socket ID           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpServerServiceStatic - Pointer to the static       **
**                           server structure                                 **
**                      : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                      : LpIpAddrUdp - pointer to the UDP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - specific routing enabled    **
**                        and initial event transmission enabled              **
**                                               or                           **
**                        E_NOT_OK - specific routing not enabled and         **
**                        initial event transmission not sent                 **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic,         **
**                          Sd_GaaSoConId, Sd_GaaSoCon                        **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard,Sd_AddClienttoFanoutUdpActions,**
**                          SoAd_SetRemoteAddr, SoAd_GetRemoteAddr,           **
**                          Dem_SetEventStatus, Dem_ReportErrorStatus         **
**                                                                            **
** Design ID              : SD_SDD_0291                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_AddClientToFanoutUdp(
  const Sd_ServerServiceStaticType * LpServerServiceStatic,
  Sd_EvHandlerType * LpEvHandler,
  const Sd_EvHandlerStaticType * LpEvHandlerStatic,
  Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  const TcpIp_SockAddrType * LpIpAddrUdp,
  uint8 LucOptionsCode,
  Std_ReturnType Sd_FoundUdpIndex)
{
  Std_ReturnType LddReturnValue;
  Std_ReturnType LddConnectionReturnValue;
  
  LddReturnValue = Sd_FoundUdpIndex;
  LddConnectionReturnValue = (uint8)TCPIP_E_NOT_OK;
  /* SWS_SD_00454
     SWS_SD_00454c */
  /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
  blTcpActivationRoGrpIdPresent is not equal to False. */
  if ((SD_UDP_OPTIONS_MASK == (LucOptionsCode & SD_UDP_OPTIONS_MASK)) &&
    (SD_NULL_PTR != LpServerServiceStatic->pUdpSoConGrp) &&
    ((SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag.
    blUdpActivationRoGrpIdPresent) ||
    (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag .
    blUdpTriggeringRoGrpIdPresent)))
  {
   /* SWS_SD_00760a , SD_SRS_2717, ETC_FT_1247, SD_SDD_0291*/
    if (LpEvHandlerSubGrp->ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
    /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
    {
      LddConnectionReturnValue = 
        (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConUdpIndex], 
        LpIpAddrUdp));
    }

    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     LddReturnValue is not equal to E_NOT_OK. */
    if ((E_OK == LddReturnValue) && (LddConnectionReturnValue == (uint8)TCPIP_E_OK))
    {

      Sd_AddClienttoFanoutUdpActions( LpEvHandler, LpEvHandlerStatic,
                  LpEvHandlerSubGrp, LpEvHandlerSubGrp->ddSoConUdpIndex);

    }
  }
  return(LddReturnValue);
}
 /* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_AddClientCheck                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function checks if the option received for     **
**                          subsequent frames after the initial addition are  **
**                          matching with the option IP address received      **
**                          in the initial frame.                             **
**                        Also calls SoAd_IsConnectionReady()                 **
**                        If there is a mismatch E_NOT_OK is returned         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpEvHandlerSubGrp - pointer to the subscribed event **
**                          group structure                                   **
**                      : LblTcp - This is SD_TRUE for TCP and SD_FALSE for   **
**                          UDP                                               **
**                      : LpIpAddr - This is the TCP or UDP option address to **
**                          check against                                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Match successful            **
**                        E_NOT_OK - Match is unsuccessful                    **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId                 **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr                **
**                          SoAd_GetRemoteAddr                                **
**                                                                            **
** Design ID              : SD_SDD_0173                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddClientCheck(
  const Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
  boolean LblTcp,
  const TcpIp_SockAddrType * LpIpAddr)
{
  Std_ReturnType LddReturnValue;
  boolean LblMatchRecd;
  Std_ReturnType LddConnectionReturnValue;
  TcpIp_SockAddrType LstIpAddr;

  LddConnectionReturnValue = (uint8)TCPIP_E_NOT_OK;

  if (LblTcp)
  {
   if (LpEvHandlerSubGrp->ddSoConTcpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
   {
    (void) SoAd_GetRemoteAddr(
     Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConTcpIndex], &LstIpAddr);
	}
  }
  else
  {
   if ( LpEvHandlerSubGrp->ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
   {
    (void) SoAd_GetRemoteAddr(
     Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConUdpIndex], &LstIpAddr);
   }
  }
  LblMatchRecd = Sd_MatchIpAddr(&LstIpAddr, LpIpAddr);
  if (LblMatchRecd)
  {
   /* SWS_SD_00760a , SD_SRS_2717, ETC_FT_1247, SD_SDD_017 */
    if (LblTcp)
    {
      if (LpEvHandlerSubGrp->ddSoConTcpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
      {
      LddConnectionReturnValue = 
			  (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConTcpIndex], 
	      LpIpAddr));
      }
    }
    else
    {
      if (LpEvHandlerSubGrp->ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        LddConnectionReturnValue = 
          (uint8)SoAd_IsConnectionReady(Sd_GaaSoConId[LpEvHandlerSubGrp->ddSoConUdpIndex], 
          LpIpAddr);
      }
    }
  }

  if ((uint8)TCPIP_E_OK == LddConnectionReturnValue)
  {    
    LddReturnValue = E_OK;
  }
  else
  {
    LddReturnValue = E_NOT_OK;
  }
  return (LddReturnValue);
}

#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_AddClientToFanout                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to add a client to the      **
**                      :   fanout. It enables the routing for the eventgroup **
**                          and sends the inital events                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                      : LpIpAddrTcp - pointer to the TCP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                      : LpIpAddrUdp - pointer to the UDP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                      : LucOptionsCode - This is the Code which indicates   **
**                          which options are active                          **
**                        It is in the same format as the return code of      **
**                          Sd_GetIpAddrFromOptions and                       **
**                          Sd_GetIpAddrFromMulticastOption                   **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : Std_ReturnType - If this is E_OK then the calling   **
**                          function should send a SubscribeAck               **
**                      : If this is E_NOT_OK then the calling function should**
**                          send a SubscribeNack                              **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic     **
**                                                                            **
**                        Function(s) invoked : Sd_AddClientToFanout,         **
**                          Sd_AddClientCheck, Sd_AddClientToFanoutUdp        **
**                                                                            **
** Design ID            : SD_SDD_0289,SD_SDD_0022                             **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
Std_ReturnType Sd_AddClientToFanout(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp,
    const TcpIp_SockAddrType * LpIpAddrTcp,
    const TcpIp_SockAddrType * LpIpAddrUdp,
    uint8 LucOptionsCode,
	  uint8 LucOptions_ACL,
    const Sd_EntryType * LpEntryData,
    const TcpIp_SockAddrType * LpRemoteAddr)
{
  Std_ReturnType LddReturnValue;
  Std_ReturnType Sd_FoundTcpIndex;
  Std_ReturnType Sd_FoundUdpIndex;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  LddReturnValue = E_NOT_OK;
  Sd_FoundTcpIndex = E_NOT_OK;
  Sd_FoundUdpIndex = E_NOT_OK;

  #if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpServerServiceStatic = &Sd_GaaServerServiceStatic[LpEvHandlerStatic->usServerServiceIndex];
  #else
  LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LpEvHandlerStatic->usServerServiceIndex);
  #endif

if ( Sd_GaaAclPolicyFlag == SD_TRUE ){

  if (SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv)
  {
    Sd_FoundTcpIndex = Sd_FindTcpIndex(LpServerServiceStatic, LpEvHandlerStatic, 
      LpEvHandlerSubGrp, LpIpAddrTcp, LucOptionsCode);
  }
  
  if ((SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv) && (Sd_FoundTcpIndex == E_OK))
  {
  Sd_FoundUdpIndex = Sd_FindUdpIndex(LpServerServiceStatic, LpEvHandlerStatic, 
    LpEvHandlerSubGrp, LpIpAddrUdp, LucOptionsCode);
  }

  if (( Sd_FoundTcpIndex == E_OK ) || ( Sd_FoundUdpIndex == E_OK ))
  {
    Sd_SendSubscribeAck(LpEvHandlerStatic, LpEntryData, LpRemoteAddr, SD_ZERO);
  }

  if ((LucOptions_ACL == SD_TWO) || (LucOptions_ACL == SD_THREE))
  {
    if (SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv)
    {
      LddReturnValue = Sd_AddClientToFanoutTcp(LpServerServiceStatic, LpEvHandler,
      LpEvHandlerStatic, LpEvHandlerSubGrp, LpIpAddrTcp, LucOptionsCode, Sd_FoundTcpIndex);
    }
    else
    {
      LddReturnValue = Sd_AddClientCheck(LpEvHandlerSubGrp, (boolean)SD_TRUE, LpIpAddrTcp);
    }
  }

  if ((LucOptions_ACL == SD_ONE) || (LucOptions_ACL == SD_THREE))
  {
    if ((SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv))
    {
      LddReturnValue = Sd_AddClientToFanoutUdp(LpServerServiceStatic, LpEvHandler,
      LpEvHandlerStatic, LpEvHandlerSubGrp, LpIpAddrUdp, LucOptionsCode, Sd_FoundUdpIndex);
    }
    
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (E_OK == LddReturnValue)
    {
      LddReturnValue = Sd_AddClientCheck(LpEvHandlerSubGrp, (boolean)SD_FALSE,
      LpIpAddrUdp);
    }
    else
    {
    /*Do Nothing */
    }
  }
}
else
{
  if (SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv)
  {
    Sd_FoundTcpIndex = Sd_FindTcpIndex(LpServerServiceStatic, LpEvHandlerStatic, 
    LpEvHandlerSubGrp, LpIpAddrTcp, LucOptionsCode);
  }
  
  if ((SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv) && (Sd_FoundTcpIndex == E_OK))
  {
    Sd_FoundUdpIndex = Sd_FindUdpIndex(LpServerServiceStatic, LpEvHandlerStatic, 
    LpEvHandlerSubGrp, LpIpAddrUdp, LucOptionsCode);
  }

  if (( Sd_FoundTcpIndex == E_OK ) || ( Sd_FoundUdpIndex == E_OK ))
  {
    Sd_SendSubscribeAck(LpEvHandlerStatic, LpEntryData, LpRemoteAddr, SD_ZERO);
  }

 if (SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv)
  {
    LddReturnValue = Sd_AddClientToFanoutTcp(LpServerServiceStatic, LpEvHandler,
    LpEvHandlerStatic, LpEvHandlerSubGrp, LpIpAddrTcp, LucOptionsCode, Sd_FoundTcpIndex);
  }
  else
  {
    LddReturnValue = Sd_AddClientCheck(LpEvHandlerSubGrp, (boolean)SD_TRUE, LpIpAddrTcp);
  }
  if ((SD_FALSE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv) &&
                  (E_OK == LddReturnValue))
  {
    LddReturnValue = Sd_AddClientToFanoutUdp(LpServerServiceStatic, LpEvHandler,
    LpEvHandlerStatic, LpEvHandlerSubGrp, LpIpAddrUdp, LucOptionsCode, Sd_FoundUdpIndex);
  }
  /*LogicAnalyser WRN04: Manually Verified*/
  else if (E_OK == LddReturnValue)
  {
    LddReturnValue = Sd_AddClientCheck(LpEvHandlerSubGrp, (boolean)SD_FALSE,
    LpIpAddrUdp);
  }
  else
  {
 /*Do Nothing */
  }
}
return (LddReturnValue);
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Sd_RemoveClientFromFanout                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when server wishes to       **
**                          remove the client from the fanout                 **
**                      : It disables the routing for the client              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LpEvHandler - Pointer to Event Handler structure.   **
**                      : LpEvHandlerStatic - Pointer to Event Handler static **
**                           structure                                        **
**                      : LpEvHandlerSubGrp - pointer to the subscribed event **
**                           group structure                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : Sd_Init must be called                              **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaServerServiceStatic,    **
**                          Sd_GaaInstanceStatic, Sd_GaaSoConId,              **
**                          Sd_GaaEvHandlerSubGrp                             **
**                                                                            **
**                        Function(s) invoked : Sd_ResetToWildcardServer,     **
**                          SoAd_EnableSpecificRouting,                       **
**                          SoAd_DisableSpecificRouting                       **
**                                                                            **
** Design ID              : SD_SDD_0293                                       **
*******************************************************************************/
#if (STD_ON == SD_EV_HANDLER_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_RemoveClientFromFanout(
    Sd_EvHandlerType * LpEvHandler,
    const Sd_EvHandlerStaticType * LpEvHandlerStatic,
    Sd_EvHandlerSubGrpType * LpEvHandlerSubGrp)
{
  SoAd_SoConIdType LddSoConIdUdp = {SD_ZERO};
  SoAd_SoConIdType LddGaaSoConIdTcp = {SD_ZERO};
  SoAd_SoConIdType LddGaaSoConIdUdp = {SD_ZERO};
  Sd_EvHandlerSubGrpType const *LpSubGrpTemp;
  Sd_ServerServiceStaticType const *LpServerServiceStatic;
  Sd_InstanceStaticType const *LpInstanceStatic;
  uint16 LusCount;
  uint16 LusBaseIndex;

  #if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpServerServiceStatic = &Sd_GaaServerServiceStatic[LpEvHandlerStatic->usServerServiceIndex];
  #else
  LpServerServiceStatic = ((Sd_GpConfigPtr->pSd_GaaServerServiceStatic) + LpEvHandlerStatic->usServerServiceIndex);
  #endif 
   #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
  LpInstanceStatic =
         &Sd_GaaInstanceStatic[LpServerServiceStatic->ucSdInstanceIndex];
  #else
	  LpInstanceStatic = (((Sd_GpConfigPtr->pInstanceStatic)) + LpServerServiceStatic->ucSdInstanceIndex);
  #endif

  SchM_Enter_Sd_MODE_STATUS_PROTECTION();
  if (LpEvHandlerSubGrp -> ddSoConTcpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
   {
  LddGaaSoConIdTcp = Sd_GaaSoConId[LpEvHandlerSubGrp -> ddSoConTcpIndex];
  }

  if (SD_TRUE == (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv)
  {
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
	 /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False. */
    if (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag.
                                                blTcpActivationRoGrpIdPresent)
    {
      (void) SoAd_DisableSpecificRouting (
            LpEvHandlerStatic->ddTcpActivationRoGrpId, LddGaaSoConIdTcp);
    }
    (LpEvHandlerSubGrp->stEvHandlerFlag).blTcpActiveEv = SD_FALSE;
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    if (LpEvHandler->ucNoOfSubGrpsTcp > SD_ZERO)
    {
      LpEvHandler->ucNoOfSubGrpsTcp = LpEvHandler->ucNoOfSubGrpsTcp - SD_ONE;
    }

    Sd_ResetToWildcardServer(LpInstanceStatic, LpEvHandlerSubGrp, SD_TCP);
  }
  else
  {
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
  }

  if (SD_TRUE == (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv )
  {
    (LpEvHandlerSubGrp->stEvHandlerFlag).blUdpActiveEv = SD_FALSE;

    SchM_Enter_Sd_MODE_STATUS_PROTECTION();
	if (LpEvHandlerSubGrp -> ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
    {
      LddGaaSoConIdUdp = Sd_GaaSoConId[LpEvHandlerSubGrp -> ddSoConUdpIndex];
   	}
    SchM_Exit_Sd_MODE_STATUS_PROTECTION();
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
    if (LpEvHandler->ucNoOfSubGrpsUdp > SD_ZERO)
    {
      LpEvHandler->ucNoOfSubGrpsUdp = LpEvHandler->ucNoOfSubGrpsUdp - SD_ONE;
    }
 /* polyspace +8 RTE:UNR [Justified:Low] "This check will be false when value of
    usMulticastThreshold is zero." */
    if (SD_ZERO == LpEvHandlerStatic->usMulticastThreshold)
    {
      if (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag .
                                              blUdpActivationRoGrpIdPresent)
      {
	/*polyspace +4 RTE:NIV [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */	
        (void) SoAd_DisableSpecificRouting (
              LpEvHandlerStatic->ddUdpActivationRoGrpId, LddGaaSoConIdUdp);
      }
    }
    else
    {

      if (LpEvHandler->ucNoOfSubGrpsUdp ==
          (LpEvHandlerStatic->usMulticastThreshold - SD_ONE))
      {
        LusBaseIndex = (uint16) LpEvHandlerStatic->usEvHandlerSelfIndex *
                                                                    SD_SIXTEEN;
        for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + SD_SIXTEEN);
                                                                  LusCount++)
        {
          SchM_Enter_Sd_MODE_STATUS_PROTECTION();
          LpSubGrpTemp = &Sd_GaaEvHandlerSubGrp[LusCount];
		  if (LpEvHandlerSubGrp -> ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
         {
	/*polyspace +15 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
	   	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
          LddSoConIdUdp = Sd_GaaSoConId[LpSubGrpTemp->ddSoConUdpIndex];
         }
	/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False.*/
   /*polyspace +10 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
          if ((SD_TRUE == (LpEvHandlerStatic -> stEvHandlerStaticFlag).
                                      blUdpActivationRoGrpIdPresent ) &&
                   (SD_TRUE == (LpSubGrpTemp -> stEvHandlerFlag).blUdpActiveEv))
          {
            SchM_Exit_Sd_MODE_STATUS_PROTECTION();
              (void) SoAd_EnableSpecificRouting(
                        LpEvHandlerStatic->ddUdpActivationRoGrpId,
                                                                 LddSoConIdUdp);
            }
          else
          {
            SchM_Exit_Sd_MODE_STATUS_PROTECTION();
          }
        }
 /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    blTcpActivationRoGrpIdPresent is not equal to False. */
        if ((SD_TRUE == (LpEvHandlerStatic->stEvHandlerStaticFlag).
                          blMulticastActivationRoGrpIdPresent))
        {
          (void) SoAd_DisableSpecificRouting(
                       LpEvHandlerStatic->ddMulticastActivationRoGrpId,
                       LpEvHandlerStatic->ddMulticastEventSoConId);
        }
      }
      /*LogicAnalyser WRN04: Manually Verified*/
      else if (LpEvHandler -> ucNoOfSubGrpsUdp <
                (LpEvHandlerStatic->usMulticastThreshold - SD_ONE))
        {
	/* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
     blTcpActivationRoGrpIdPresent is not equal to False. */
          if (SD_TRUE == LpEvHandlerStatic->stEvHandlerStaticFlag.
                                                  blUdpActivationRoGrpIdPresent)
          {
         SchM_Enter_Sd_MODE_STATUS_PROTECTION();
		 
         if (LpEvHandlerSubGrp -> ddSoConUdpIndex < SD_NO_OF_SOCKET_CONNECTIONS)
		 {			 
         LddGaaSoConIdUdp = Sd_GaaSoConId[LpEvHandlerSubGrp -> ddSoConUdpIndex];
		 }
         SchM_Exit_Sd_MODE_STATUS_PROTECTION();
	/*polyspace +4 RTE:NIVL [Justified:Low] "Pointers with this orange flag are
      made sure that they are initialized with proper Value " */
            (void) SoAd_DisableSpecificRouting (
                        LpEvHandlerStatic->ddUdpActivationRoGrpId,
                                                            LddGaaSoConIdUdp);
          }
        }
      else
      {
               /*Do Nothing */
      }
    }
    Sd_ResetToWildcardServer(LpInstanceStatic, LpEvHandlerSubGrp, SD_UDP);
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientServiceDownEntered                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the client service     **
**                      : enters the SD_DOWN state                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non - Reentrant                                     **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init should be called                            **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoCon, Sd_GaaSoConId    **
**                                                                            **
**                        Function(s) invoked : SoAd_CloseSoCon,              **
**                          SoAd_DisableSpecificRouting                       **
**                                                                            **
** Design ID              : SD_SDD_0175                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientServiceDownEntered(
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
  uint16 LusCount;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;


   /* SWS_SD_00382a , ETC_FT_142, SD_SRS_846, SD_SDD_0175 */
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
  pTcpSoConGrp is equal to NULL ptr."
  Unit Test Case Reference SD_UTP_0511 */
  /* SD_SDD_175 , SWS_SD_00722, SD_SRS_2069 */
  if (SD_NULL_PTR !=  LpClientServiceStatic->pTcpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    { /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
     stClientStaticFlag is not equal to False. */
      if ((SD_TRUE == (LpClientServiceStatic->stClientStaticFlag) .
       blActivationRoGrpIdPresent) && (SD_NO_OF_SOCKET_CONNECTIONS > LusCount))
      {
        (void) SoAd_DisableSpecificRouting(
                                  LpClientServiceStatic->ddActivationRoGrpId,
                                  Sd_GaaSoConId[LusCount]);
      }
    }
  }
  /*polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
  pUdpSoConGrp is equal to NULL ptr.
  Unit Test Case Reference SD_UTP_0511, SWS ID SWS_SD_00722, SD_SRS_2069 */
  if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
	/* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
     stClientStaticFlag is not equal to False. */	
      if ((SD_TRUE == (LpClientServiceStatic->stClientStaticFlag) .
       blActivationRoGrpIdPresent) && (SD_NO_OF_SOCKET_CONNECTIONS > LusCount))
      {
        (void) SoAd_DisableSpecificRouting(
                                  LpClientServiceStatic->ddActivationRoGrpId,
                                  Sd_GaaSoConId[LusCount]);
      }
    }
  }
   
  /* SWS_SD_00382b ,  ETC_FT_1243, SD_SRS_2086, SD_SDD_0175 
  SWS_SD_00722 */
  /* polyspace +06 RTE:UNR [Justified:Low] "This condition shall be False when
   pTcpSoConGrp is equal to NULL pointer.
   Unit Test Case Reference SD_UTP_0510, SWS ID SWS_SD_00603" */
  if (SD_NULL_PTR !=  LpClientServiceStatic->pTcpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
      /* polyspace +7 RTE:UNR [Justified:Low] "This condition shall be True
      when SD_NO_OF_SOCKET_CONNECTIONS is greater than LusCount and
      blSocketOpened is SD_TRUE.
      Unit Test Case Reference SD_UTP_0508, SWS ID SWS_SD_00603" */
      if ((SD_NO_OF_SOCKET_CONNECTIONS > LusCount) && (SD_TRUE ==
      Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened))
      {
        Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened = SD_FALSE;
        (void) SoAd_CloseSoCon(Sd_GaaSoConId[LusCount], FALSE);
      }
    }
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
  pUdpSoConGrp is equal to NULL pointer.
  Unit Test Case Reference SD_UTP_0511, SWS ID SWS_SD_00603" */
  if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
      /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True
      when SD_NO_OF_SOCKET_CONNECTIONS is greater than LusCount and
      blSocketOpened is SD_TRUE.
      Unit Test Case Reference SD_UTP_0510, SWS ID SWS_SD_00603" */
      if ((SD_NO_OF_SOCKET_CONNECTIONS > LusCount) && (SD_TRUE ==
                             Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened))
      {
        Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened = SD_FALSE;
        (void) SoAd_CloseSoCon(Sd_GaaSoConId[LusCount], FALSE);
      }
    }
  }
  LpClientService->ulClientDelayCount = SD_ZERO;
  LpClientService->ucNoOfOffersSent = SD_ZERO;
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_ClientServiceWaitEntered                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called when the client service     **
**                      : enters the WAIT state                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non - Reentrant                                     **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init should be called                            **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId                 **
**                                                                            **
**                        Function(s) invoked : SoAd_EnableSpecificRouting    **
**                                                                            **
** Design ID              : SD_SDD_0176                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientServiceWaitEntered(
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
 const Sd_ClientTimerStaticType * LpClientTimer;
  uint16 LusCount;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
//LpClientTimer = LpClientServiceStatic->pClientTimer;
  #if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
LpClientTimer = LpClientServiceStatic->pClientTimer;
Sd_ClientSharedTimer(LpClientServiceStatic, LpClientTimer);

#else
	LpClientTimer = LpClientServiceStatic->pClientTimer;
   
#endif

  /* SWS_SD_00362 */
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be false when
     pTcpSoConGrp is  equal to SD_NULL_PTR. */
  if (SD_NULL_PTR !=  LpClientServiceStatic->pTcpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
	/* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
     stClientStaticFlag is not equal to False. */		
      if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag) .
                                               blActivationRoGrpIdPresent)
      {
		  
    /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
        (void) SoAd_EnableSpecificRouting(
                               LpClientServiceStatic->ddActivationRoGrpId,
                               Sd_GaaSoConId[LusCount]);
      }
    }
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be false when
     pUdpSoConGrp is  equal to SD_NULL_PTR. */
  if (SD_NULL_PTR !=  LpClientServiceStatic->pUdpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
     /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True when
     stClientStaticFlag is not equal to False. */
      if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag).
                                               blActivationRoGrpIdPresent)
      {
	/*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
        (void) SoAd_EnableSpecificRouting(
                                LpClientServiceStatic->ddActivationRoGrpId,
                                Sd_GaaSoConId[LusCount]);
      }
    }
  }
  

  LpClientService->ulClientDelayCount = Sd_Rand(
                          (uint32) LpClientTimer->ulInitialFindDelayMin,
                          (uint32) LpClientTimer->ulInitialFindDelayMax);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientStateDown                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions for the client   **
**                          in the state DOWN                                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstance - Pointer to Instance structure          **
**                      : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GblInitCalled              **
**                                                                            **
**                        Function(s) invoked : Sd_ClientServiceSetState,     **
**                          Sd_ClientServiceWaitEntered,                      **
**                          Sd_ClientSetUpTcpUdpConnection,                   **
**                          BswM_Sd_ClientServiceCurrentState,                **
**                                                                            **
** Design ID              : SD_SDD_0180,SD_SDD_0117,SD_SDD_0116,SD_SDD_0119,  **
                            SD_SDD_0118,SD_SDD_0444,SD_SDD_0446,  **
							SD_SDD_0010,SD_SDD_0452,SD_SDD_0331,SD_SDD_0011,  **
							SD_SDD_0055,SD_SDD_0454                           **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientStateDown (
  const Sd_InstanceType * LpInstance,
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
  
  uint8 LucOptionsCode;
   uint8  LuReturncode ;
  Std_ReturnType LddReturnValue;
  uint16 LusNoOfElements;
  uint16 LusBaseIndex;
  uint16 LusCount;
  if ( Sd_GaaAclPolicyFlag )
  
  {
 LuReturncode = SD_THREE;
  }
  else
  {
	  LuReturncode = SD_THREE;
  }
/* Design ID : SD_SDD_0117,SD_SDD_0116,SD_SDD_0119,SD_SDD_0118*/
/* Design ID : SD_SDD_0444,SD_SDD_0446,SD_SDD_0452,SD_SDD_0331,SD_SDD_0011,
               SD_SDD_0055,SD_SDD_0454*/


  /* SWS_SD_00464 
     SWS_SD_00462
	 SWS_SD_00464b 
	 SWS_SD_00464c
     SWS_SD_00464d*/
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if ((Sd_GblInitCalled) &&
    (TCPIP_IPADDR_STATE_ASSIGNED == LpInstance->enIpAddrState) &&
     (SD_CLIENT_SERVICE_REQUESTED == LpClientService->enClientSetState))
  {
    if (SD_FALSE == LpClientService->stClientFlag.blOfferAvailable)
    {
      LpClientService->enClientPhase = SD_CLIENT_INITIAL_WAIT;
      Sd_ClientServiceWaitEntered(LpClientService, LpClientServiceStatic);
    }
    else
    {
      LucOptionsCode = SD_OPTIONS_NOT_FOUND;
    /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be false when
     pTcpSoConGrp is  equal to SD_NULL_PTR. */
      if (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp)
      {
        LucOptionsCode = SD_TCP_OPTIONS_MASK;
      }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be false when
     pUdpSoConGrp is  equal to SD_NULL_PTR. */
      if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
      {
        LucOptionsCode = LucOptionsCode | SD_UDP_OPTIONS_MASK;
      }
      
	  if (SD_NULL_PTR !=  LpClientServiceStatic->pTcpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
      /* polyspace +7 RTE:UNR [Justified:Low] "This condition shall be True
      when SD_NO_OF_SOCKET_CONNECTIONS is greater than LusCount and
      blSocketOpened is SD_TRUE.
      Unit Test Case Reference SD_UTP_0508, SWS ID SWS_SD_00603" */
      if ((SD_NO_OF_SOCKET_CONNECTIONS > LusCount) && (SD_FALSE ==
      Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened))
      {
        Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened = SD_TRUE;
        (void) SoAd_OpenSoCon(Sd_GaaSoConId[LusCount]);
      }
      if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag) .
                                               blActivationRoGrpIdPresent)
      {
		  
    /*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
     made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
        (void) SoAd_EnableSpecificRouting(
                               LpClientServiceStatic->ddActivationRoGrpId,
                               Sd_GaaSoConId[LusCount]);
      }
    }
  }
  /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be false when
  pUdpSoConGrp is equal to NULL pointer.
  Unit Test Case Reference SD_UTP_0511, SWS ID SWS_SD_00603" */
  if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfElements = LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex + LusNoOfElements);
                  LusCount++)
    {
      /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be True
      when SD_NO_OF_SOCKET_CONNECTIONS is greater than LusCount and
      blSocketOpened is SD_TRUE.
      Unit Test Case Reference SD_UTP_0510, SWS ID SWS_SD_00603" */
      if ((SD_NO_OF_SOCKET_CONNECTIONS > LusCount) && (SD_FALSE ==
                             Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened))
      {
        Sd_GaaSoCon[LusCount].stSoConFlag.blSocketOpened = SD_TRUE;
        (void) SoAd_OpenSoCon(Sd_GaaSoConId[LusCount]);
      }

      if (SD_TRUE == (LpClientServiceStatic->stClientStaticFlag).
                                               blActivationRoGrpIdPresent)
      {
	/*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
        (void) SoAd_EnableSpecificRouting(
                                LpClientServiceStatic->ddActivationRoGrpId,
                                Sd_GaaSoConId[LusCount]);
      }

    }
  }
  /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall be false when
     pUdpSoConGrp is  equal to SD_NULL_PTR. */
      LddReturnValue = Sd_ClientSetUpTcpUdpConnection(LpClientService,
        LpClientServiceStatic, &LpClientService->stOfferEndpointAddrTcp,
        &LpClientService->stOfferEndpointAddrUdp, LucOptionsCode, LuReturncode);
  
      if (E_OK == LddReturnValue)
      {
        LpClientService->enClientPhase = SD_CLIENT_MAIN;
        LpClientService->enClientCurrState = SD_CLIENT_SERVICE_AVAILABLE;
        BswM_Sd_ClientServiceCurrentState(
        LpClientServiceStatic->usHandleId, SD_CLIENT_SERVICE_AVAILABLE);
      }
      else
      {
        LpClientService->enClientSetState = SD_CLIENT_SERVICE_RELEASED;
      }
    }
  }
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientStateInitialWait                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions for the client   **
**                          in the state INITIAL WAIT                         **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
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
**                        Function(s) invoked : Sd_ClientServiceDownEntered   **
** Design ID              : SD_SDD_0181                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientStateInitialWait (
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
 const Sd_ClientTimerStaticType * LpClientTimer;
  Sd_InstanceStaticType const *LpInstanceStatic;
 // LpClientTimer = LpClientServiceStatic->pClientTimer;


 

  
  /* SWS_SD_00350  
     SWS_SD_00351 
	 SWS_SD_00355 
	 SWS_SD_00456*/

  /* 00355 */
#if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
	 LpClientTimer = LpClientServiceStatic->pClientTimer;
Sd_ClientSharedTimer(LpClientServiceStatic, LpClientTimer);
 
#else
	LpClientTimer = LpClientServiceStatic->pClientTimer;
    
#endif
  #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
  LpInstanceStatic =
         &Sd_GaaInstanceStatic[LpClientServiceStatic->ucSdInstanceIndex];
  #else
	  LpInstanceStatic = (((Sd_GpConfigPtr->pInstanceStatic)) + LpClientServiceStatic->ucSdInstanceIndex);

  #endif

  if (SD_CLIENT_SERVICE_RELEASED == LpClientService->enClientSetState)
  {
    LpClientService->enClientPhase = SD_CLIENT_DOWN;
    Sd_ClientServiceDownEntered(LpClientService, LpClientServiceStatic);
  }

  /* 00351is redundant on 00352 and 00353 [SWS_SD_00353b] [SWS_SD_00353c]*/
  /* SWS_SD_00353 */
  /*LogicAnalyser WRN04: Manually Verified*/
  else if ((uint32)SD_ZERO == (uint32)LpClientService -> ulClientDelayCount)
    {
        /*Redmine : 28582 Open Control path of SD*/
        /*Bugzilla : 75555*/
      (void)SoAd_OpenSoCon(LpInstanceStatic->ddIpAddrSoConId);
      Sd_SendFind(LpClientServiceStatic, SD_ZERO);
	 /* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
    the sd module Repetition state reached max.
    Module Test Case Reference SD_ETC_787, SWS ID SWS_SD_00353" */ 
	if (SD_ZERO == LpClientTimer->ucInitialFindRepetitionsMax)
      {
        LpClientService->enClientPhase = SD_CLIENT_MAIN;
      }
	/* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    the sd module Repetition state reached max.
    Module Test Case Reference SD_ETC_787, SWS ID SWS_SD_00353" */
      else
      {
        LpClientService->enClientPhase = SD_CLIENT_REPETITION;
          /* 00358 */
          Sd_GblBswClientRepitionStateFlag = (boolean)SD_TRUE;
       // LpClientService->ulClientDelayCount =
        //  LpClientTimer->ulInitialFindRepetitionsBaseDelay;
      }
    }
  else
  {
	  /*Do Nothing */
  }
}
  /* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientStateRepetition                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions for the client   **
**                          in the state REPETITION                           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
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
**                        Function(s) invoked : Sd_ClientServiceDownEntered   **
** Design ID              : SD_SDD_0184                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientStateRepetition (
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
  uint16 LusMultiple;
 const Sd_ClientTimerStaticType * LpClientTimer;
  Sd_ConsumedEvGrpType *LpConsumedEvGrp;
  uint16 LusCount;
 uint16 LusBaseIndex , LusNoOfElements;
  Sd_InstanceStaticType const *LpInstanceStatic;
 SoAd_SoConModeType LenSoConMode;
 SoAd_SoConIdType LddSoConId;
 boolean LblSoConOnline = (boolean)SD_FALSE;
 //LpClientTimer = LpClientServiceStatic->pClientTimer;
 
     #if (STD_ON == SD_SERVICE_GROUP_CONFIGURED)
		 LpClientTimer = LpClientServiceStatic->pClientTimer;
 Sd_ClientSharedTimer(LpClientServiceStatic, LpClientTimer);
   

     #else
	  LpClientTimer = LpClientServiceStatic->pClientTimer;
     
     #endif
     #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
     LpInstanceStatic =
        &Sd_GaaInstanceStatic[LpClientServiceStatic->ucSdInstanceIndex];
     #else
	   LpInstanceStatic = (((Sd_GpConfigPtr->pInstanceStatic)) + 
       LpClientServiceStatic->ucSdInstanceIndex);
    #endif

	 
 if (( LpClientService->enClientPhase == SD_CLIENT_REPETITION ) && Sd_GblBswClientRepitionStateFlag)
 {
   LpClientService->ulClientDelayCount =
          LpClientTimer->ulInitialFindRepetitionsBaseDelay;
   Sd_GblBswClientRepitionStateFlag = (boolean)SD_FALSE;
 }
if (LpClientServiceStatic -> pTcpSoConGrp != SD_NULL_PTR)
  {
     LusBaseIndex = LpClientServiceStatic ->pTcpSoConGrp -> usBaseSocketConIndex;
     LusNoOfElements =  LpClientServiceStatic -> pTcpSoConGrp -> usNoOfSockets;
     for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfElements)) 
                                   && (!LblSoConOnline); LusCount++)
     {
	        /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
       LddSoConId = Sd_GaaSoConId[LusCount];
       
       SoAd_GetSoConMode(LddSoConId, &LenSoConMode);
       if (LenSoConMode == SOAD_SOCON_ONLINE)
       {
         LblSoConOnline = (boolean)SD_TRUE;
       }
     }
	if (!LblSoConOnline)
	{
		/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
	 SoAd_GetSoConMode(LpInstanceStatic->ddIpAddrSoConId, &LenSoConMode);
       if (LenSoConMode == SOAD_SOCON_ONLINE)
       {
         LblSoConOnline = (boolean)SD_TRUE;
       }
	}
  }
  	/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be False when
     pUdpSoConGrp is not equal to SD_NULL_PTR. */ 
  if (LpClientServiceStatic -> pUdpSoConGrp != SD_NULL_PTR)
  {
    LusBaseIndex = LpClientServiceStatic -> pUdpSoConGrp -> usBaseSocketConIndex;
    LusNoOfElements =  LpClientServiceStatic -> pUdpSoConGrp -> usNoOfSockets;
    for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfElements)) 
                                 && (!LblSoConOnline); LusCount++)
    {
	/*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
       made sure that they are within their range by having necessary boundary
       checks in order to prevent them from being out of bounds." */
      LddSoConId = Sd_GaaSoConId[LusCount];
      
      SoAd_GetSoConMode (LddSoConId, &LenSoConMode);
      if (LenSoConMode == SOAD_SOCON_ONLINE)
      {
       LblSoConOnline = (boolean)SD_TRUE;
      }
    }

	if (!LblSoConOnline)
	{
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
	 SoAd_GetSoConMode(LpInstanceStatic->ddIpAddrSoConId, &LenSoConMode);
       if (LenSoConMode == SOAD_SOCON_ONLINE)
       {
         LblSoConOnline = (boolean)SD_TRUE;
       }
	}
  } 
 if (LblSoConOnline)
 {	 
  /* SWS_SD_00371 */
  if (SD_CLIENT_SERVICE_RELEASED == LpClientService->enClientSetState)
  {
    LpClientService->enClientPhase = SD_CLIENT_DOWN;
    Sd_ClientServiceDownEntered(LpClientService, LpClientServiceStatic);
  }

  /* SWS_SD_00457 */
  else
  {
    if ((uint32)SD_ZERO == (uint32)LpClientService->ulClientDelayCount)
    {
      Sd_SendFind(LpClientServiceStatic, SD_ZERO);
      LpClientService->ucNoOfOffersSent++;
        /* SWS_SD_00369 */
	 /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
    the sd module Repetition state reached max.
    Module Test Case Reference SD_ETC_809, SWS ID SWS_SD_00369" */
      if (LpClientService->ucNoOfOffersSent >=
                                LpClientTimer->ucInitialFindRepetitionsMax)
      {
        LpClientService->enClientPhase = SD_CLIENT_MAIN;
      }
	 /* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
    the sd module Repetition state reached max.
    Module Test Case Reference SD_ETC_809, SWS ID SWS_SD_00369" */
      else
      {
      /* 00363 */
        LusMultiple = SD_ONE;
	/* polyspace +10 RTE:UNR [Justified:Low] "This condition shall be True when
     the LusCount is  greater to LpClientService->ucNoOfOffersSent */ 
        for (LusCount = SD_ZERO;
              LusCount < LpClientService->ucNoOfOffersSent; LusCount++)
        {
          LusMultiple = LusMultiple * SD_TWO;
        }
        LpClientService->ulClientDelayCount = (uint32) LusMultiple *
                    LpClientTimer->ulInitialFindRepetitionsBaseDelay;
      }
    }
  }
 }
 else
 {       
        /*polyspace +3 RTE:IDP [Justified:Low] "Pointers with this orange flag are
         made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being illegally dereferenced." */
        LpClientService->enClientPhase = SD_CLIENT_INITIAL_WAIT;
        Sd_ClientServiceWaitEntered(LpClientService, LpClientServiceStatic);
	    LpClientService->ulOfferTtlCount = SD_ZERO;
		
		#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
	   LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;
        LusNoOfElements = LpClientServiceStatic->usNoOfConEventGrp;

	   for (LusCount = LusBaseIndex; LusCount < (LusBaseIndex
                        + LusNoOfElements); LusCount++)
        {
		/*polyspace +5 RTE:IDP [Justified:Low] "Pointers with this orange flag are
          made sure that they are within their range by having necessary boundary
          checks in order to prevent them from being illegally dereferenced." */
          LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];
		  LpConsumedEvGrp->ulConEvGrpTtlCount = SD_ZERO;
          
        }
		#endif
	  
	  
	
}
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientStateMain                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function performs the actions for the client   **
**                          in the state MAIN                                 **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                          structure                                         **
**                      : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                      : LblOfferTtlExpired - Boolean indicating whether the **
**                            TTL for the offer has exprired                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaConsumedEvGrp,          **
**                          Sd_GaaConsumedEvGrpStatic                         **
**                                                                            **
**                        Function(s) invoked : Sd_SendStopSubscribe,         **
**                          Sd_ConsumedEvGrpRelease, Sd_ClientInactive,       **
**                          Sd_ClientServiceDownEntered,                      **
**                          Sd_ClientServiceWaitEntered,                      **
**                          BswM_Sd_ClientServiceCurrentState,                **
**                          BswM_Sd_ConsumedEventGroupCurrentState            **
**                                                                            **
** Design ID              : SD_SDD_0183                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientStateMain (
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic,
  boolean LblOfferTtlExpired)
{
  #if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
  Sd_ConsumedEvGrpType *LpConsumedEvGrp;
  Sd_ConsumedEvGrpStaticType const *LpConsumedEvGrpStatic;
  uint16 LusBaseIndex;
  uint16 LusNoOfElements;
  uint16 LusCount;
  #endif

  /* SWS_SD_00375
     SWS_SD_00375b*/
  /* SWS_SD_00381  and SWS_SD_00380, part SWS_SD_00381b , SWS_SD_00381c
  SD_SRS_1291*/
  if (SD_CLIENT_SERVICE_RELEASED == LpClientService->enClientSetState)
  {
    #if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
    LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;
    LusNoOfElements = LpClientServiceStatic->usNoOfConEventGrp;
	/* polyspace +5 RTE:UNR [Justified:Low] "This condition shall be True when
     the LusBaseIndex + LusNoOfElements is  greater to SD_NO_OF_CONSUMED_EV_GRP */ 
	if ((LusBaseIndex + LusNoOfElements) <= SD_NO_OF_CONSUMED_EV_GRP)
  {
    for (LusCount = LusBaseIndex;
           LusCount < (LusBaseIndex + LusNoOfElements); LusCount++)
    {
      LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];
      #if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
      #else
      LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic)
                               + LusCount);
      #endif
      if (SD_CONSUMED_EVENTGROUP_DOWN !=
                            LpConsumedEvGrp->enConEvGrpCurrState)
      {
        Sd_SendStopSubscribe(LpConsumedEvGrpStatic,
                   &LpClientService->stOfferRemoteAddr, SD_ZERO);
        Sd_ConsumedEvGrpRelease(LpConsumedEvGrp, LpConsumedEvGrpStatic);
        LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_DOWN;
        BswM_Sd_ConsumedEventGroupCurrentState(
                            LpConsumedEvGrpStatic->usHandleId,
                            LpConsumedEvGrp->enConEvGrpCurrState);
        LpConsumedEvGrp->ulConEvGrpTtlCount = SD_ZERO;
      }
    }
  }
    #endif

    Sd_ClientInactive(LpClientService);
    /* SD_SRS_840, SWS_SD_00380 */
    LpClientService->enClientCurrState = SD_CLIENT_SERVICE_DOWN;
    BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
              SD_CLIENT_SERVICE_DOWN);
    LpClientService->enClientPhase = SD_CLIENT_DOWN;
    /* SD_SDD_175 , SWS_SD_00722, SD_SRS_2069 , ETC_FT_1230 */
    Sd_ClientServiceDownEntered(LpClientService, LpClientServiceStatic);
  }
  /* SWS_SD_00600  
     SWS_SD_00600b */
  if (LblOfferTtlExpired)
  {
    LpClientService->enClientPhase = SD_CLIENT_INITIAL_WAIT;
    LpClientService->enClientCurrState = SD_CLIENT_SERVICE_DOWN;
    BswM_Sd_ClientServiceCurrentState(LpClientServiceStatic->usHandleId,
                    SD_CLIENT_SERVICE_DOWN);
    Sd_ClientServiceWaitEntered(LpClientService, LpClientServiceStatic );

    #if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
    LusBaseIndex = LpClientServiceStatic->usBaseConEventGrp;
    LusNoOfElements = LpClientServiceStatic->usNoOfConEventGrp;
	/* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be True when
     the LusBaseIndex + LusNoOfElements is  greater to SD_NO_OF_CONSUMED_EV_GRP */ 
	if ((LusBaseIndex + LusNoOfElements) <= SD_NO_OF_CONSUMED_EV_GRP){
    for (LusCount = LusBaseIndex;
           LusCount < (LusBaseIndex + LusNoOfElements); LusCount++)
    {
      LpConsumedEvGrp = &Sd_GaaConsumedEvGrp[LusCount];
      #if (STD_ON == SD_PRE_COMPILE_SINGLE)
      LpConsumedEvGrpStatic = &Sd_GaaConsumedEvGrpStatic[LusCount];
      #else
      LpConsumedEvGrpStatic = ((Sd_GpConfigPtr->pSd_GaaConsumedEvGrpStatic)
                               + LusCount);
      #endif
      if (SD_CONSUMED_EVENTGROUP_DOWN !=
                            LpConsumedEvGrp->enConEvGrpCurrState)
      {
        LpConsumedEvGrp->ulConEvGrpTtlCount = SD_ZERO;
        LpConsumedEvGrp->enConEvGrpCurrState =
                       SD_CONSUMED_EVENTGROUP_DOWN;
        BswM_Sd_ConsumedEventGroupCurrentState(
          LpConsumedEvGrpStatic->usHandleId,
                        LpConsumedEvGrp->enConEvGrpCurrState);
        Sd_ConsumedEvGrpRelease(LpConsumedEvGrp, LpConsumedEvGrpStatic);
      }
    }
	}
    #endif
    /* SWS_SD_00481b */
    Sd_ClientInactive(LpClientService);
  }

}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientStateMachine                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called in the main function for    **
**                      : every ClientService configured                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non - Reentrant                                     **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Sd_Init should be called                            **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstance,               **
**                          Sd_GaaInstanceStatic                              **
**                                                                            **
**                        Function(s) invoked : Sd_ClientStateDown,           **
**                          Sd_ClientStateMain Sd_ClientStateInitialWait,     **
**                          Sd_ClientStateRepetition,                         **
**                                                                            **
** Design ID            : SD_SDD_0182, SD_SDD_0009, SD_SDD_0006               **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
void Sd_ClientStateMachine (
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic)
{
  Sd_InstanceType const *LpInstance;
  boolean LblOfferTtlExpired;

  LblOfferTtlExpired = (boolean)SD_FALSE;

  LpInstance = &Sd_GaaInstance[LpClientServiceStatic->ucSdInstanceIndex];
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (LpClientService->ulClientDelayCount > (uint32)SD_ZERO)
  {
    LpClientService->ulClientDelayCount =
                              LpClientService->ulClientDelayCount - (uint32)SD_ONE;
  }

  if (LpClientService->ulClientRetrySubDelayCount > (uint32)SD_ZERO)
  {
    LpClientService->ulClientRetrySubDelayCount =
                   LpClientService->ulClientRetrySubDelayCount - (uint32)SD_ONE;
  }
  
  if (SD_TRUE == (LpClientService->stClientFlag).blOfferAvailable)
  {
    if (SD_TRUE == (LpClientService->stClientFlag).blOfferMaxTtl)
    {
      LpClientService->ulOfferTtlCount = SD_TTL_COUNT_MAX;
    }
    else
    {
      if (LpClientService->ulOfferTtlCount > (uint32)SD_ZERO)
      {
        LpClientService->ulOfferTtlCount =
                              LpClientService->ulOfferTtlCount - (uint32)SD_ONE;
        if ((uint32)SD_ZERO == LpClientService->ulOfferTtlCount)
        {
          (LpClientService->stClientFlag).blOfferAvailable = SD_FALSE;
          LblOfferTtlExpired = (boolean)SD_TRUE;
        }
      }
    }
  }

  switch (LpClientService->enClientPhase)
  {
    case SD_CLIENT_DOWN :
    {
      Sd_ClientStateDown(LpInstance, LpClientService, LpClientServiceStatic);
      break;
    }
    case SD_CLIENT_INITIAL_WAIT:
    {
      Sd_ClientStateInitialWait(LpClientService, LpClientServiceStatic);
      break;
    }

    case SD_CLIENT_REPETITION :
    {
      Sd_ClientStateRepetition(LpClientService, LpClientServiceStatic);
      break;
    }

    case SD_CLIENT_MAIN:
    {
      Sd_ClientStateMain( LpClientService,
              LpClientServiceStatic, LblOfferTtlExpired);
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
#endif

/*******************************************************************************
** Function Name        : Sd_ConsumedEvGrpMain                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called from main per consumed      **
**                      : event group                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                      : LpConsumedEvGrpStatic - Pointer to Static consumed  **
**                            event group structure                           **
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
**                        Function(s) invoked : Sd_SendStopSubscribe,         **
**                          Sd_ConsumedEvGrpRelease,                          **
**                          BswM_Sd_ConsumedEventGroupCurrentState,           **
**                                                                            **
** Design ID              : SD_SDD_0185                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
#if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
void Sd_ConsumedEvGrpMain(
  Sd_ClientServiceType * LpClientService,
  Sd_ConsumedEvGrpType * LpConsumedEvGrp,
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic)
#else
void Sd_ConsumedEvGrpMain(
  const Sd_ClientServiceType * LpClientService,
  Sd_ConsumedEvGrpType * LpConsumedEvGrp,
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic)
#endif
{
  boolean LblConEvGrpTtlExpiredInt;

  LblConEvGrpTtlExpiredInt = (boolean)SD_FALSE;
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if (LpConsumedEvGrp->ulConEvGrpTtlCount > (uint32)SD_ZERO)
  {
    LpConsumedEvGrp->ulConEvGrpTtlCount =
                                LpConsumedEvGrp->ulConEvGrpTtlCount - 
								                                (uint32)SD_ONE;
    if ((uint32)SD_ZERO == (LpConsumedEvGrp->ulConEvGrpTtlCount))
    {
      LblConEvGrpTtlExpiredInt = (boolean)SD_TRUE;
    }
  }  
  
  if (SD_CLIENT_MAIN == LpClientService->enClientPhase)
  {
    /* SWS 00713 
       ETC SD_ETC_1240, SD_ETC_1241, SD_ETC_1242
       SRS: SD_SRS_2083, SD_SRS_2084, SD_SRS_2085
    */
    if ((SD_CONSUMED_EVENTGROUP_RELEASED == 
      LpConsumedEvGrp->enConEvGrpSetState) && 
      (SD_CONSUMED_EVENTGROUP_DOWN != LpConsumedEvGrp->enConEvGrpCurrState))
    {
      LpConsumedEvGrp->ulConEvGrpTtlCount = SD_ZERO;
      LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_DOWN;
      /* SWS 00713a , SD_ETC_1240, SD_SRS_2083 , SD_SDD_0185*/
      Sd_SendStopSubscribe(LpConsumedEvGrpStatic,
                      &LpClientService->stOfferRemoteAddr,
                          SD_ZERO);
      
      /* SWS 00713b , SD_ETC_1241, SD_SRS_2084 , SD_SDD_0185*/
      BswM_Sd_ConsumedEventGroupCurrentState(
                    LpConsumedEvGrpStatic->usHandleId,
                    LpConsumedEvGrp->enConEvGrpCurrState); 
      Sd_ConsumedEvGrpRelease(LpConsumedEvGrp, LpConsumedEvGrpStatic);     
      
      /* SWS 00713c , SD_ETC_1242, SD_SRS_2085 , SD_SDD_0185*/
      #if (STD_ON == SD_SUBSCRIBE_EVENTGROUP_RETRY_ENABLE)
      /* polyspace +6 RTE:UNR [Justified:Low]  LpClientService->
      enClientCurrState is false when enClientCurrState
      is when enClientCurrState is SD_CLIENT_SERVICE_AVAILABLE*/ 
      if (SD_ZERO < (LpConsumedEvGrpStatic->pClientTimer)->
        ucSubscribeEventgroupRetryMax)
      {
        LpClientService->ulClientRetrySubDelayCount = SD_ZERO;
        LpConsumedEvGrp->ulConEvGrpRetryCount = SD_ZERO;    
      } 
      #endif
    }
    
    /* SWS_SD_00601 , SD_SRS_845, SD_SDD_0185, SD_ETC_141 */
    if ( LblConEvGrpTtlExpiredInt )
    {
      if (SD_CONSUMED_EVENTGROUP_DOWN != LpConsumedEvGrp->enConEvGrpCurrState)
      {
        LpConsumedEvGrp->enConEvGrpCurrState = SD_CONSUMED_EVENTGROUP_DOWN;
        BswM_Sd_ConsumedEventGroupCurrentState(
                  LpConsumedEvGrpStatic->usHandleId,
                  LpConsumedEvGrp->enConEvGrpCurrState);
      }
    }         
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientSetUpTcpConnection                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to set up the TCP           **
**                          connection                                        **
**                        It sets the remote addr and calls SoAd_OpenSoCon    **
**                          to open the connection                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                            structure                                       **
**                      : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                      : LpIpAddrTcp - pointer to the TCP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Connection set up           **
**                          successfully                                      **
**                      : E_NOT_OK - Failure in connection set up             **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId, Sd_GaaSoCon    **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard, SoAd_SetRemoteAddr,           **
**                          SoAd_GetRemoteAddr, SoAd_OpenSoCon,               **
**                          Dem_SetEventStatus, Dem_ReportErrorStatus         **
**                                                                            **
** Design ID              : SD_SDD_0177                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_ClientSetUpTcpConnection(
  const Sd_InstanceStaticType * LpInstanceStatic,
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic,
  const TcpIp_SockAddrType * LpIpAddrTcp)
{
  TcpIp_SockAddrType LddStIpAddr;

  Std_ReturnType LddReturnValue;
  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  uint16 LusBaseIndex;
  SoAd_SoConIdType LusNoOfSoCon;
  uint16 LusCount;
  uint16 LusMatchCount;
  uint16 LusWildcardMatchCount;
  SoAd_SoConIdType LddAssignedSoConId;
  Std_ReturnType LddConnectionReturnValue;

  LddReturnValue = E_OK;
  LblMatchRecd = (boolean)SD_FALSE;
  LblWildcardMatch = (boolean)SD_FALSE;
  LusMatchCount = SD_ZERO;
  LusWildcardMatchCount = SD_ZERO;
  LddConnectionReturnValue = (uint8)TCPIP_E_NOT_OK;
  
  /* #violates #ref Sd_state_c_CERT_REF_3 Violates MISRA 2012 
  Required Rules */
  /* PRQA S 1331 5 */
  /* #violates #ref Sd_state_c_CERT_REF_3 Violates MISRA 2012 
   Required Rules */
  /* PRQA S 3335 5 */
   /* #violates #ref Sd_state_c_CERT_REF_3 Violates MISRA 2012
   Required Rule INT02 */
   /* PRQA S 2111 2 */
  /*  Required Rule INT02 */
   /* PRQA S 4447 2 */
 (void)SD_MEMSET(&LddStIpAddr, (sint32)SD_ZERO, sizeof(TcpIp_SockAddrType));
 /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpClientServiceStatic is  equal to SD_NULL_PTR . */ 
  if (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pTcpSoConGrp->usBaseSocketConIndex;
    LusNoOfSoCon =
    (SoAd_SoConIdType) LpClientServiceStatic->pTcpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfSoCon)) &&
                              (!LblMatchRecd) ; LusCount++)
    {
	/* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpInstanceStatic->blDomainIpv4 is  equal to SD_FALSE */ 
      if (LpInstanceStatic->blDomainIpv4)
      {
       LddStIpAddr.domain = TCPIP_AF_INET;
	    /*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
        (void) SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LddStIpAddr);
      }
	 /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpInstanceStatic->blDomainIpv4 is  equal to SD_FALSE */ 
      else
      {
        LddStIpAddr.domain = TCPIP_AF_INET6;
	/*polyspace +10 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
        made sure that they are within their range by having necessary boundary
        checks in order to prevent them from being out of bounds." */
        (void) SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LddStIpAddr);
      }

      LblMatchRecd = Sd_MatchIpAddr(&LddStIpAddr, LpIpAddrTcp);
      if (LblMatchRecd)
      {
        LusMatchCount = LusCount;
      }

      if (!LblWildcardMatch)
      {
        LblWildcardMatch =
            Sd_MatchIpWildcard(&LddStIpAddr);
        if (LblWildcardMatch)
        {
          LusWildcardMatchCount = LusCount;
        }
      }
    }

    if (LblMatchRecd)
    {
      LpClientService->ddOfferSoConIndexTcp = (SoAd_SoConIdType) LusMatchCount;
      (LpClientService->stClientFlag).blTcpActive = SD_TRUE;
      Sd_GaaSoCon[LusMatchCount].usNoOfSubClients =
            Sd_GaaSoCon[LusMatchCount].usNoOfSubClients + SD_ONE;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LblWildcardMatch)
    {
       /* SWS_SD_00721b, SD_SRS_2064, SDD_0231, SD_ETC_112 */
      (void) SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LusWildcardMatchCount],
        LpIpAddrTcp, &LddAssignedSoConId);
      if (LddAssignedSoConId == Sd_GaaSoConId[LusWildcardMatchCount])
      {
        LpClientService->ddOfferSoConIndexTcp =
          (SoAd_SoConIdType) LusWildcardMatchCount;
        (LpClientService->stClientFlag).blTcpActive = SD_TRUE;
        Sd_GaaSoCon[LusWildcardMatchCount].usNoOfSubClients =
          Sd_GaaSoCon[LusWildcardMatchCount].usNoOfSubClients + SD_ONE;
        Sd_GaaSoCon[LusWildcardMatchCount].stSoConFlag.blWildcardSocketClient
          = SD_TRUE;
      }
    }
	/* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    LblWildcardMatch is FALSE." */
    else
    {
      SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
      LddReturnValue = E_NOT_OK;
    }

    if (E_OK == LddReturnValue)
    {
      if (LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        if ((SD_FALSE == Sd_GaaSoCon[LpClientService->ddOfferSoConIndexTcp]
          .stSoConFlag.blSocketOpened))
        {
           /* SWS_SD_00721c, SD_SRS_2065, SDD_0231, SD_ETC_112 */
          (void) SoAd_OpenSoCon(
            Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp]);
          Sd_GaaSoCon[LpClientService->ddOfferSoConIndexTcp]
            .stSoConFlag.blSocketOpened = SD_TRUE;
        }
      }
      /* SWS_SD_00761, SD_SRS_2719, ETC_FT_1248, SD_SDD_0177*/
      if (LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        LddConnectionReturnValue = 
          (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp], 
          LpIpAddrTcp));
      }

      if ((uint8)TCPIP_E_NOT_OK == LddConnectionReturnValue) 
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      }    
	  }
  }
  return(LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientSetUpUdpConnection                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to set up the UDP           **
**                          connection                                        **
**                        It sets the remote addr and calls SoAd_OpenSoCon    **
**                          to open the connection                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpInstanceStatic - Pointer to Static Instance       **
**                            structure                                       **
**                      : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                      : LpIpAddrUdp - pointer to the UDP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType - E_OK - Connection set up           **
**                          successfully                                      **
**                      : E_NOT_OK - Failure in connection set up             **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoConId, Sd_GaaSoCon    **
**                                                                            **
**                        Function(s) invoked : Sd_MatchIpAddr,               **
**                          Sd_MatchIpWildcard, SoAd_SetRemoteAddr,           **
**                          SoAd_GetRemoteAddr, SoAd_OpenSoCon,               **
**                          Dem_SetEventStatus, Dem_ReportErrorStatus         **
**                                                                            **
** Design ID              : SD_SDD_0179                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
 Std_ReturnType Sd_ClientSetUpUdpConnection(
  const Sd_InstanceStaticType * LpInstanceStatic,
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic,
  const TcpIp_SockAddrType * LpIpAddrUdp)
{
  TcpIp_SockAddrType LddStIpAddr;

  Std_ReturnType LddReturnValue;

  boolean LblMatchRecd;
  boolean LblWildcardMatch;
  uint16 LusBaseIndex;
  SoAd_SoConIdType LusNoOfSoCon;
  uint16 LusCount;
  uint16 LusMatchCount;
  uint16 LusWildcardMatchCount;
  SoAd_SoConIdType LddAssignedSoConId;
  TcpIp_ReturnType LddConnectionReturnValue;

  LddReturnValue = E_OK;
  LblMatchRecd = (boolean)SD_FALSE;
  LblWildcardMatch = (boolean)SD_FALSE;
  LusMatchCount = SD_ZERO;
  LusWildcardMatchCount = SD_ZERO;

   /* #violates #ref Sd_state_c_CERT_REF_3 Violates MISRA 2012 
  Required Rules */
  /* PRQA S 1331 5 */
  /* #violates #ref Sd_state_c_CERT_REF_3 Violates MISRA 2012 
   Required Rules */
  /* PRQA S 3335 5 */
   /* #violates #ref Sd_state_c_CERT_REF_3 Violates MISRA 2012
   Required Rule INT02 */
   /* PRQA S 2111 2 */
    /*  Required Rule INT02 */
   /* PRQA S 4447 2 */
   (void)SD_MEMSET(&LddStIpAddr, (sint32)SD_ZERO, sizeof(TcpIp_SockAddrType));
   /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpClientServiceStatic is  equal to SD_NULL_PTR . */ 
  if (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp)
  {
    LusBaseIndex = LpClientServiceStatic->pUdpSoConGrp->usBaseSocketConIndex;
    LusNoOfSoCon =
    (SoAd_SoConIdType) LpClientServiceStatic->pUdpSoConGrp->usNoOfSockets;
    for (LusCount = LusBaseIndex; (LusCount < (LusBaseIndex + LusNoOfSoCon)) &&
                              (!LblMatchRecd) ; LusCount++)
    {
	 /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpInstanceStatic is  equal to SD_FALSE  */	
      if (LpInstanceStatic->blDomainIpv4)
      {
        LddStIpAddr.domain = TCPIP_AF_INET;
	/*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being out of bounds." */
        (void) SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LddStIpAddr);
      }
      else
	/* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
     the LpInstanceStatic is  equal to SD_FALSE  */	
      {
        LddStIpAddr.domain = TCPIP_AF_INET6;
	/*polyspace +5 RTE:OBAI [Justified:Low] "Pointers with this orange flag are
      made sure that they are within their range by having necessary boundary
      checks in order to prevent them from being out of bounds." */
        (void) SoAd_GetRemoteAddr(Sd_GaaSoConId[LusCount], &LddStIpAddr);
      }

      LblMatchRecd = Sd_MatchIpAddr(&LddStIpAddr, LpIpAddrUdp);
      if (LblMatchRecd)
      {
        LusMatchCount = LusCount;
      }

      if (!LblWildcardMatch)
      {
        LblWildcardMatch = Sd_MatchIpWildcard(&LddStIpAddr);
        if (LblWildcardMatch)
        {
          LusWildcardMatchCount = LusCount;
        }
      }
    }
    if (LblMatchRecd)
    {
      LpClientService->ddOfferSoConIndexUdp = (SoAd_SoConIdType) LusMatchCount;
      (LpClientService->stClientFlag).blUdpActive = SD_TRUE;

      Sd_GaaSoCon[LusMatchCount].usNoOfSubClients =
            Sd_GaaSoCon[LusMatchCount].usNoOfSubClients + SD_ONE;
    }
    /*LogicAnalyser WRN04: Manually Verified*/
    else if (LblWildcardMatch)
    {
       /* SWS_SD_00721b, SD_SRS_2064, SDD_0231, SD_ETC_112 */
      (void) SoAd_SetUniqueRemoteAddr(Sd_GaaSoConId[LusWildcardMatchCount],
        LpIpAddrUdp, &LddAssignedSoConId);
      if (LddAssignedSoConId == Sd_GaaSoConId[LusWildcardMatchCount])
      {
        LpClientService->ddOfferSoConIndexUdp =
          (SoAd_SoConIdType) LusWildcardMatchCount;
        (LpClientService->stClientFlag).blUdpActive = SD_TRUE;
        Sd_GaaSoCon[LusWildcardMatchCount].usNoOfSubClients =
          Sd_GaaSoCon[LusWildcardMatchCount].usNoOfSubClients + SD_ONE;
        Sd_GaaSoCon[LusWildcardMatchCount].stSoConFlag.blWildcardSocketClient
          = SD_TRUE;
      }

    }
	/* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be True when
    LblWildcardMatch is FALSE." */
    else
    {
      SD_REPORT_DEM_OUT_OF_RES(LpInstanceStatic);
      LddReturnValue = E_NOT_OK;
    }

    if (E_OK == LddReturnValue)
    {
 /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be False when  
 LpClientService->ddOfferSoConIndexUdp is Set as SD_NO_OF_SOCKET_CONNECTIONS" */
	 if (LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
      if ((SD_FALSE == Sd_GaaSoCon[LpClientService->ddOfferSoConIndexUdp]
                              .stSoConFlag.blSocketOpened) )
      {
         /* SWS_SD_00721c, SD_SRS_2065, SDD_0231, SD_ETC_112 */
        (void) SoAd_OpenSoCon(
                   Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp]);
        Sd_GaaSoCon[LpClientService->ddOfferSoConIndexUdp]
                              .stSoConFlag.blSocketOpened = SD_TRUE;
							  LddConnectionReturnValue = (uint8)TCPIP_E_OK;
							 
							   
      }
	  else
	  {
	   /* SWS_SD_00761, SD_SRS_2719, ETC_FT_1248, SD_SDD_0179*/
		 LddConnectionReturnValue = 
        (uint8)(SoAd_IsConnectionReady(Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp], 
        LpIpAddrUdp)); 
	
	  }
     
	
      if (LddConnectionReturnValue == TCPIP_E_NOT_OK ) 
      {
        LddReturnValue = E_NOT_OK;
      }
      else
      {
        /* Do nothing */
      } 
	  
	 }
    }
  }
  return(LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientSetUpTcpUdpConnection                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to set up the TCP and/or    **
**                          UDP connection                                    **
**                        It is called on reception of offer service          **
**                        It sets the remote addr for TCP and UDP and calls   **
**                         SoAd_OpenSoCon to open the connection              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                      : LpIpAddrTcp - pointer to the TCP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                      : LpIpAddrUdp - pointer to the UDP option received,   **
**                           SD_NULL_PTR if not received.                     **
**                      : LucOptionsCode - This is the Code which indicates   **
**                          which options are active                          **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaInstanceStatic          **
**                                                                            **
**                        Function(s) invoked : Sd_ClientSetUpTcpConnection,  **
**                          Sd_ClientSetUpUdpConnection                       **
**                                                                            **
** Design ID              : SD_SDD_0178                                       **
*******************************************************************************/
#if (STD_ON == SD_CLIENT_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
Std_ReturnType Sd_ClientSetUpTcpUdpConnection (
  Sd_ClientServiceType * LpClientService,
  const Sd_ClientServiceStaticType * LpClientServiceStatic,
  const TcpIp_SockAddrType * LpIpAddrTcp,
  const TcpIp_SockAddrType * LpIpAddrUdp,
  uint8 LucOptionsCode,
   uint8 LucReturnCode_ACL)
{
  Std_ReturnType LddReturnValue;

  Sd_InstanceStaticType const *LpInstanceStatic;

  /*PB*/
  #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
  LpInstanceStatic =
         &Sd_GaaInstanceStatic[LpClientServiceStatic->ucSdInstanceIndex];
  #else
	  LpInstanceStatic = (((Sd_GpConfigPtr->pInstanceStatic)) + LpClientServiceStatic->ucSdInstanceIndex);

  #endif

  LddReturnValue = E_OK;
/*polyspace +4 RTE:UNR [Justified:Low] "This If condition will be false */

 if (Sd_GaaAclPolicyFlag == SD_TRUE)
 {
  if ((SD_FALSE == (LpClientService->stClientFlag).blTcpActive) &&
      (SD_TCP_OPTIONS_MASK == (LucOptionsCode & SD_TCP_OPTIONS_MASK)) &&
      (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp) && 
	  ((LucReturnCode_ACL == SD_THREE) ||
 	  (LucReturnCode_ACL == SD_TWO)))
  {
    LddReturnValue = Sd_ClientSetUpTcpConnection(LpInstanceStatic,
                         LpClientService, LpClientServiceStatic, LpIpAddrTcp);
  }
  else
  {
	 /*Do nothing*/
  }

  if ((SD_FALSE == (LpClientService->stClientFlag).blUdpActive) &&
      (SD_UDP_OPTIONS_MASK == (LucOptionsCode & SD_UDP_OPTIONS_MASK)) &&
      (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp) &&
      (E_OK == LddReturnValue) && ((LucReturnCode_ACL == SD_THREE) ||
 	  (LucReturnCode_ACL == SD_ONE)))
  {
    LddReturnValue = Sd_ClientSetUpUdpConnection(LpInstanceStatic,
                         LpClientService, LpClientServiceStatic, LpIpAddrUdp);
  }
  else{
	  
	  /*Do Nothing*/
  }
 }
 else{
	   if ((SD_FALSE == (LpClientService->stClientFlag).blTcpActive) &&
      (SD_TCP_OPTIONS_MASK == (LucOptionsCode & SD_TCP_OPTIONS_MASK)) &&
      (SD_NULL_PTR != LpClientServiceStatic->pTcpSoConGrp))
  {
    LddReturnValue = Sd_ClientSetUpTcpConnection(LpInstanceStatic,
                         LpClientService, LpClientServiceStatic, LpIpAddrTcp);
  }

  if ((SD_FALSE == (LpClientService->stClientFlag).blUdpActive) &&
      (SD_UDP_OPTIONS_MASK == (LucOptionsCode & SD_UDP_OPTIONS_MASK)) &&
      (SD_NULL_PTR != LpClientServiceStatic->pUdpSoConGrp) &&
      (E_OK == LddReturnValue))
  {
    LddReturnValue = Sd_ClientSetUpUdpConnection(LpInstanceStatic,
                         LpClientService, LpClientServiceStatic, LpIpAddrUdp);
  }
}
  

  return (LddReturnValue);
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientFanIn                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
**                                                                            **
** Description          :  This function implements [SWS_SD_00702] and        **
                                                   [SWS_SD_00703]             **
**                         It is called in Sd_OfferRecd function before       **
**                         sending the SubscribeEventgroup entry.             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                      : LpClientServiceStatic - Pointer to Static Client    **
**                            service structure                               **
**                      : LpConsumedEvGrpStatic - Pointer to the consumed     **
**                            event group static strucure                     **
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
**                        Function(s) invoked : SoAd_EnableSpecificRouting    **
**                                                                            **
** Design ID              : SD_SDD_0217                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ClientFanIn (
  const Sd_ClientServiceType * LpClientService,
  Sd_ConsumedEvGrpType * LpConsumedEvGrp,
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic,
  uint8 LucReturnCode_ACL)
 
{ 
  /*SWS_SD_00701b 
  SWS_SD_00701c 
	SWS_SD_00702b 
	SWS_SD_00703b
  SWS_SD_00701e */

  if (SD_FALSE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled)
  {
    (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled = SD_TRUE;
	  /*polyspace +6 RTE:UNR [Justified:Low] "This Condition shall be True when 
	  LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent 
	  is Set as SD_FALSE" */

if ((LucReturnCode_ACL == SD_TWO ) || ( LucReturnCode_ACL == SD_THREE )){
	  if (SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).
  blTcpActivationRoGrpIdPresent)
    {
	    if (LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        (void) SoAd_EnableSpecificRouting (
          LpConsumedEvGrpStatic->ddTcpActivationRoGrpId,
          Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp]);
	    }
    }
  }
    /*polyspace +6 RTE:UNR [Justified:Low] "This Condition shall be True when 
    LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent 
    is Set as SD_FALSE" */
if ((LucReturnCode_ACL == SD_THREE)  || (LucReturnCode_ACL == SD_ONE )){
    if (SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).
                          blUdpActivationRoGrpIdPresent)
    {
      if (LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
        (void) SoAd_EnableSpecificRouting(
          LpConsumedEvGrpStatic->ddUdpActivationRoGrpId,
          Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp]);
      }
    }
}
	 

  }    
  
}
/* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"
#endif

/*******************************************************************************
** Function Name        : Sd_ClientInactive                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
**                                                                            **
** Description          :  This function sets the flags blTcpActive and       **
**                         blUdpActive as FALSE. It also decrements the       **
**                         usNoOfSubClients counter (per Socket connection)   **
**                         and sets the Socket Connection to wildcard if it   **
**                         was set to wildcard previously and the             **
**                         usNoOfSubClients is zero                           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpClientService - Pointer to Client Service         **
**                      :     structure                                       **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)  : Sd_GaaSoCon, Sd_GaaSoConId,   **
**                           Sd_GddIpv4Wildcard, Sd_GddIpv6Wildcard           **
**                                                                            **
**                        Function(s) invoked : SoAd_SetRemoteAddr            **
**                                                                            **
** Design ID              : SD_SDD_0174                                       **
*******************************************************************************/
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"

void Sd_ClientInactive(
    Sd_ClientServiceType * LpClientService)
{
  SoAd_SoConIdType LddSoConId;
  Sd_SoConType *LpSoConStructure;
  /* polyspace +3 RTE:UNR [Justified:Low] "This condition shall be true when
   the blTcpActive is  equal to SD_TRUE */
  if (SD_TRUE == (LpClientService->stClientFlag).blTcpActive)
  {
    (LpClientService->stClientFlag).blTcpActive = SD_FALSE;

    LddSoConId = LpClientService->ddOfferSoConIndexTcp;

    if (LddSoConId < SD_NO_OF_SOCKET_CONNECTIONS)
    {
      LpSoConStructure = &Sd_GaaSoCon[LddSoConId];
      /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall
      be true when the usNoOfSubClients is greater than SD_ZERO.
      Condition is covered in UT.
      Unit Test Case Reference SD_UTP_0489 " */
      if (LpSoConStructure->usNoOfSubClients > SD_ZERO)
      {
        LpSoConStructure->usNoOfSubClients =
             LpSoConStructure->usNoOfSubClients - SD_ONE;
        /* SWS_SD_00481a, SWS_SD_00481b , SWS_SD_00481c */
        /* SWS_SD_00706a, SWS_SD_00706b*/
        /* SD_ETC_133, SD_ETC_1210 */
        /* SD_SDD_0174 */
        if ((SD_ZERO == LpSoConStructure->usNoOfSubClients) &&
          (SD_TRUE == LpSoConStructure->stSoConFlag.blWildcardSocketClient))
        {
          LpSoConStructure->stSoConFlag.blWildcardSocketClient = SD_FALSE;
          /* Removing the prev. ipv6 check since same action taken for both */
          /* Replacing (void) SoAd_SetRemoteAddr with SoAd_ReleaseRemoteAddr 
            for SWS_SD_00481, SWS_SD_00706 where same action is done */
          (void) SoAd_ReleaseRemoteAddr(Sd_GaaSoConId[LddSoConId]);
        }
      }
    }
  }

  if (SD_TRUE == (LpClientService->stClientFlag).blUdpActive)
  {
    (LpClientService->stClientFlag).blUdpActive = SD_FALSE;

    LddSoConId = LpClientService->ddOfferSoConIndexUdp;

    if (LddSoConId < SD_NO_OF_SOCKET_CONNECTIONS)
    {
      LpSoConStructure = &Sd_GaaSoCon[LddSoConId];
      /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall
      be true when the usNoOfSubClients is greater than SD_ZERO.
      Condition is covered in UT.
      Unit Test Case Reference SD_UTP_0491" */
      if (LpSoConStructure->usNoOfSubClients > SD_ZERO)
      {
        LpSoConStructure->usNoOfSubClients =
             LpSoConStructure->usNoOfSubClients - SD_ONE;
        /* SWS_SD_00481a, SWS_SD_00481b , SWS_SD_00481c */
        /* SWS_SD_00706a, SWS_SD_00706b*/
        /* SD_ETC_133, SD_ETC_1210 */
        /* SD_SDD_0174 */
        if ((SD_ZERO == LpSoConStructure->usNoOfSubClients) &&
            (SD_TRUE == LpSoConStructure->stSoConFlag.blWildcardSocketClient))
        {
          LpSoConStructure->stSoConFlag.blWildcardSocketClient = SD_FALSE;
          /* Removing the prev. ipv6 check since same action taken for both */
          /* Replacing (void) SoAd_SetRemoteAddr with SoAd_ReleaseRemoteAddr 
            for SWS_SD_00481, SWS_SD_00706 where same action is done */
          (void) SoAd_ReleaseRemoteAddr(Sd_GaaSoConId[LddSoConId]);
        }
      }
    }
  }
}
#define SD_STOP_SEC_CODE
#include "Sd_MemMap.h"

/*******************************************************************************
** Function Name        : Sd_ConsumedEvGrpRelease                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          :  This function disables the routing for TCP, UDP    **
**                         and multicast. It is called whenever the           **
**                         StopSubscribe entry is sent                        **
**                         It also resets the Local address of the (multicast)**
**                         consumed event group back to wildcard if all are   **
**                         over.                                              **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LpConsumedEvGrp - Pointer to Consumed eventgroup    **
**                      :     structure                                       **
**                      : LpConsumedEvGrpStatic - Pointer to Static Consumed  **
**                            eventgroup structure                            **
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
**                          Sd_GaaClientServiceStatic, Sd_GaaInstanceStatic,  **
**                          Sd_GaaSoConGroup, Sd_GaaSoConGroupStatic,         **
**                          Sd_GaaSoConId, Sd_GddIpv4Wildcard,                **
**                          Sd_GddIpv6Wildcard,                               **
**                                                                            **
**                        Function(s) invoked : SoAd_GetLocalAddr,            **
**                          SoAd_RequestIpAddrAssignment,                     **
**                          SoAd_DisableSpecificRouting,                      **
**                                                                            **
** Design ID              : SD_SDD_0186                                       **
*******************************************************************************/
#if (STD_ON == SD_CONSUMED_EV_GRP_CONFIGURED)
#define SD_START_SEC_CODE
#include "Sd_MemMap.h"
/* polyspace-begin RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
void Sd_ConsumedEvGrpRelease(
  Sd_ConsumedEvGrpType * LpConsumedEvGrp,
  const Sd_ConsumedEvGrpStaticType * LpConsumedEvGrpStatic)
{
  Sd_ClientServiceType const *LpClientService;
  Sd_ClientServiceStaticType  const *LpClientServiceStatic;
  Sd_InstanceStaticType  const *LpInstanceStatic;
  Sd_SoConGroupStaticType  const *LpSoConGrpMulticast;
  Sd_SoConGroupType *LpSoConGrp;
  SoAd_SoConIdType LddSoConIdMulticast;
  uint8 LucNetmask;
  TcpIp_SockAddrType LddIpAddrLocal;
  TcpIp_SockAddrType LddDefaultRouter;

    /* SWS_SD_00711 */

  LpClientService = &Sd_GaaClientService[
                            LpConsumedEvGrpStatic->usClientServiceIndex];
  #if (STD_ON == SD_PRE_COMPILE_SINGLE)
  LpClientServiceStatic = &Sd_GaaClientServiceStatic[LpConsumedEvGrpStatic->usClientServiceIndex];
  #else
  LpClientServiceStatic = 
  ((Sd_GpConfigPtr->pSd_GaaClientServiceStatic) + LpConsumedEvGrpStatic->usClientServiceIndex);
  #endif
   #if  (STD_ON == SD_PRE_COMPILE_SINGLE) 
  LpInstanceStatic =
         &Sd_GaaInstanceStatic[LpClientServiceStatic->ucSdInstanceIndex];
  #else
	  LpInstanceStatic = (((Sd_GpConfigPtr->pInstanceStatic)) + LpClientServiceStatic->ucSdInstanceIndex);
  #endif

  LpSoConGrp = &Sd_GaaSoConGroup[LpConsumedEvGrp->ddSoConGrpIndexMulticast];
    /*polyspace +7 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
  if ((SD_TRUE == LpConsumedEvGrp->
      stConsumedEvGrpFlag.blMulticastRoutingEnabled) &&
      (LpSoConGrp->usNoOfSubConEvGrp > SD_ZERO))
  {
    LpSoConGrp->usNoOfSubConEvGrp = LpSoConGrp->usNoOfSubConEvGrp - SD_ONE;
    /* SD_ESRS_2091, SD_ESRS_2092 */
    /* SWS_SD_00734a, SWS_SD_00734b */
    /* SD_ETC_440 , SD_SDD_0177 */
    if ((SD_ZERO == LpSoConGrp->usNoOfSubConEvGrp) &&
        (LpSoConGrp->blWildcardConEvGrp))
    {
      LpSoConGrp->blWildcardConEvGrp = (boolean)SD_FALSE;

      LpSoConGrpMulticast =
         &Sd_GaaSoConGroupStatic[LpConsumedEvGrp->ddSoConGrpIndexMulticast];
      LddSoConIdMulticast = Sd_GaaSoConId[
                                  LpSoConGrpMulticast->usBaseSocketConIndex];
    /* polyspace +6 RTE:UNR [Justified:Low] "This condition shall
      be false when the blDomainIpv4 is Set to SD_FALSE.*/ 
      if (LpInstanceStatic->blDomainIpv4)
      {
        LddIpAddrLocal .domain = TCPIP_AF_INET;
        LddDefaultRouter.domain = TCPIP_AF_INET;

        (void) SoAd_GetLocalAddr(LddSoConIdMulticast, &LddIpAddrLocal,
            &LucNetmask, &LddDefaultRouter);

       /* Replacing SoAd_RequestIpAddrAssignment with 
          SoAd_ReleaseRemoteAddr for SWS_SD_00734 where same action is done */
        (void) SoAd_ReleaseIpAddrAssignment(LddSoConIdMulticast);

      }
    /* polyspace +4 RTE:UNR [Justified:Low] "This condition shall be true when
     the domain is IpV6 is enabled */
      #if (STD_ON == SD_IPV6_ENABLED)
      else
      {
        LddIpAddrLocal .domain = TCPIP_AF_INET6;
        LddDefaultRouter.domain = TCPIP_AF_INET6;

        (void) SoAd_GetLocalAddr(LddSoConIdMulticast, &LddIpAddrLocal,
            &LucNetmask, &LddDefaultRouter);

        /* Replacing  SoAd_RequestIpAddrAssignment with 
          SoAd_ReleaseIpAddrAssignment for SWS_SD_00734 where same action is done */
        (void) SoAd_ReleaseIpAddrAssignment(LddSoConIdMulticast);
      }
      #endif
    }
  }

  if (SD_TRUE == (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled)
  {
    (LpConsumedEvGrp->stConsumedEvGrpFlag).blRoutingEnabled = SD_FALSE;
/*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be True when  
LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent 
is Set as SD_TRUE" */
    if (SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).
                                                blTcpActivationRoGrpIdPresent)
    {
	/*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
	if ( LpClientService->ddOfferSoConIndexTcp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
      (void) SoAd_DisableSpecificRouting(
                    LpConsumedEvGrpStatic->ddTcpActivationRoGrpId,
                    Sd_GaaSoConId[LpClientService->ddOfferSoConIndexTcp ]);
	  }
    }
    /*polyspace +5 RTE:UNR [Justified:Low] "This Condition shall be True when  
	LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent 
	is Set as SD_FALSE" */
    if (SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).
                                               blUdpActivationRoGrpIdPresent)
    {
   /*polyspace +4 RTE:IDP [Justified:Low] "Pointers with this orange flag are
    made sure that they are within their range by having necessary boundary
    checks in order to prevent them from being illegally dereferenced." */
	if ( LpClientService->ddOfferSoConIndexUdp < SD_NO_OF_SOCKET_CONNECTIONS)
      {
      (void) SoAd_DisableSpecificRouting(
                   LpConsumedEvGrpStatic->ddUdpActivationRoGrpId,
                   Sd_GaaSoConId[LpClientService->ddOfferSoConIndexUdp ]);
	  }
    }
  }

  /* bugzilla 68823 SD_SRS_1371*/
  /*polyspace +6 RTE:UNR [Justified:Low] "This Condition shall be True when  
	LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag.blUdpActivationRoGrpIdPresent 
	is Set as SD_FALSE" */
  if ((SD_TRUE ==
          (LpConsumedEvGrp->stConsumedEvGrpFlag).blMulticastRoutingEnabled) &&
          ((SD_TRUE == (LpConsumedEvGrpStatic->stConsumedEvGrpStaticFlag).
                    blUdpActivationRoGrpIdPresent)))
  {
    (LpConsumedEvGrp->stConsumedEvGrpFlag).blMulticastRoutingEnabled
                                                                   = SD_FALSE;
    (void) SoAd_DisableSpecificRouting(
                LpConsumedEvGrpStatic->ddUdpActivationRoGrpId,
                LpConsumedEvGrp->ddSoConIdMulticast);
  }
}
 /* polyspace-end RTE:UNR [Justified:Low] "Refer Sd_c_Poly_REF_1"*/
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

