/*******************************************************************************
**                               QORIX GmbH                                   **
**                                                                            **
** QORIX GmbH owns all the rights to this work. This work shall not be copied,**
** reproduced, used, modified or its information disclosed without the prior  **
** written authorization of QORIX GmbH.                                       **
**                                                                            **
**  SRC-MODULE: Sd_Version.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Sd                                                    **
**                                                                            **
**  PURPOSE   : Provision of version macros                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
** Prev. AUTOSAR Version : R23-11                                             **
**                                                                            **
** Prev. Software Version : 1.0.0                                             **
**                                                                            **
**  Design ID : SD_SDD_0447                                                   **
*******************************************************************************/
/**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Date         Changed By          Description                               **
********************************************************************************
** 07-Jul-2025  Samarth Golwalker   Initial Release.              	      **
** 08-Aug-2025  Gourav Purohit      Version Updated to 0.2.0.     	      **
** 01-Sep-2025  Gourav Purohit      Version Updated to 0.3.0.     	      **
*******************************************************************************/
#ifndef SD_VERSION_H
#define SD_VERSION_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/*Design ID : SD_SDD_0447 */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/*Design ID : SD_SDD_0030*/
#define SD_DET_AR_RELEASE_MAJOR_VERSION 4
/*Design ID : SD_SDD_0030*/
#define SD_DET_AR_RELEASE_MINOR_VERSION 10

/*Design ID : SD_SDD_0030*/
#define SD_DEM_AR_RELEASE_MAJOR_VERSION 4
/*Design ID : SD_SDD_0030*/
#define SD_DEM_AR_RELEASE_MINOR_VERSION 10

/*Design ID : SD_SDD_0030*/
#define SD_BSWM_AR_RELEASE_MAJOR_VERSION 4
/*Design ID : SD_SDD_0030*/
#define SD_BSWM_AR_RELEASE_MINOR_VERSION 10

/*Design ID : SD_SDD_0030*/
#define SD_SOAD_AR_RELEASE_MAJOR_VERSION 4
/*Design ID : SD_SDD_0030*/
#define SD_SOAD_AR_RELEASE_MINOR_VERSION 10

/* Redmine #64539 :Schm version is depend on BSWMD.arxml
so, this version will be same as Sd module major and minor version.*/

#define SD_SCHM_AR_RELEASE_MAJOR_VERSION 4
#define SD_SCHM_AR_RELEASE_MINOR_VERSION 10

#define SD_VERSION_AR_RELEASE_MAJOR_VERSION 4
#define SD_VERSION_AR_RELEASE_MINOR_VERSION 10
#define SD_VERSION_AR_RELEASE_REVISION_VERSION 0

#define SD_VERSION_SW_MAJOR_VERSION 0
#define SD_VERSION_SW_MINOR_VERSION 3
#define SD_VERSION_SW_PATCH_VERSION 0

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/*Design ID : SD_SDD_038,SD_SDD_038,SD_SDD_046, SD_SDD_038, SD_SDD_0460*/
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
