/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Version.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Service Discovery                                     **
**                                                                            **
**  PURPOSE   : This file contains the Module version information             **
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

/****************************************************************************
**                   Parasoft violations Section                           **
****************************************************************************/

/* #section Sd_Version_c_MISRA_REF_1
* Violates MISRAC2012-RULE_20_9-b-2: "Reason: Macro might not be defined.
* Justification: Even though the code containing these macros is not enabled, 
* still parasoft is generating warning falsely" */


/*Design ID : SD_SDD_0341,SD_SDD_0337*/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "SoAd.h"
#include "BswM_Sd.h"
#include "Dem.h"
#include "BswM.h"
#if (STD_ON == SD_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "Sd_Cfg.h"
#include "Sd_Version.h"
#include "SchM_Sd.h"
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (SD_AR_RELEASE_MAJOR_VERSION != SD_VERSION_AR_RELEASE_MAJOR_VERSION)
#error "Sd_Version.c : Mismatch in Specification Major Version"
#endif

#if (SD_AR_RELEASE_MINOR_VERSION != SD_VERSION_AR_RELEASE_MINOR_VERSION)
#error "Sd_Version.c : Mismatch in Specification Minor Version"
#endif

#if (SD_AR_RELEASE_REVISION_VERSION != SD_VERSION_AR_RELEASE_REVISION_VERSION)
#error "Sd_Version.c : Mismatch in Specification Patch Version"
#endif

#if (SD_SW_MAJOR_VERSION != SD_VERSION_SW_MAJOR_VERSION)
#error "Sd_Version.c : Mismatch in Major Version"
#endif

#if (SD_SW_MINOR_VERSION != SD_VERSION_SW_MINOR_VERSION)
#error "Sd_Version.c : Mismatch in Minor Version"
#endif

#if (SD_SW_PATCH_VERSION != SD_VERSION_SW_PATCH_VERSION)
#error "Sd_Version.c : Mismatch in Patch Version"
#endif

#if (STD_ON == SD_DEV_ERROR_DETECT)
/* parasoft-begin-suppress MISRAC2012-RULE_20_9-b-2 
          "Reason: Sd_Version_c_MISRA_REF_1" */
#if (DET_AR_RELEASE_MAJOR_VERSION != SD_DET_AR_RELEASE_MAJOR_VERSION)
#error "Det.h : Mismatch in Specification Major Version"
#endif
#if (DET_AR_RELEASE_MINOR_VERSION != SD_DET_AR_RELEASE_MINOR_VERSION)
#error "Det.h : Mismatch in Specification Minor Version"
#endif
/* parasoft-end-suppress MISRAC2012-RULE_20_9-b-2 */
#endif

#if (DEM_AR_RELEASE_MAJOR_VERSION != SD_DEM_AR_RELEASE_MAJOR_VERSION)
#error "Dem.h : Mismatch in Specification Major Version"
#endif
#if (DEM_AR_RELEASE_MINOR_VERSION != SD_DEM_AR_RELEASE_MINOR_VERSION)
#error "Dem.h : Mismatch in Specification Minor Version"
#endif

#if (SOAD_AR_RELEASE_MAJOR_VERSION != SD_SOAD_AR_RELEASE_MAJOR_VERSION)
#error "SoAd.h : Mismatch in Specification Major Version"
#endif
#if (SOAD_AR_RELEASE_MINOR_VERSION != SD_SOAD_AR_RELEASE_MINOR_VERSION)
#error "SoAd.h : Mismatch in Specification Minor Version"
#endif

#if (BSWM_AR_RELEASE_MAJOR_VERSION != SD_BSWM_AR_RELEASE_MAJOR_VERSION)
#error "BswM_Sd.h : Mismatch in Specification Major Version"
#endif
#if (BSWM_AR_RELEASE_MINOR_VERSION != SD_BSWM_AR_RELEASE_MINOR_VERSION)
#error "BswM_Sd.h : Mismatch in Specification Minor Version"
#endif

#if (SCHM_SD_AR_RELEASE_MAJOR_VERSION != SD_SCHM_AR_RELEASE_MAJOR_VERSION)
#error "SchM_Sd.h : Mismatch in Specification Major Version"
#endif
#if (SCHM_SD_AR_RELEASE_MINOR_VERSION != SD_SCHM_AR_RELEASE_MINOR_VERSION)
#error "SchM_Sd.h : Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
