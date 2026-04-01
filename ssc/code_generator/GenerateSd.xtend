/*
 *                       QORIX India Private Limited
 *
 * QORIX India Private Limited owns all the rights to this work. This
 * work shall not be copied, reproduced, used, modified or its information
 * disclosed without the prior written authorization of QORIX India Private
 * Limited.
 *
 * File Name     : GenerateSd.xtend
 *
 * Description   : This file is used for output files generation.
 *
 */

/*
 * Revision History:
 * Date            Changed By             Description
 * 15-Sep-2025    Gourav Purohit   Schema Migration Release R24-11.

 */


package com.kpit.c4k.bsw.sd.codegen

import com.kpit.c4k.core.workflow.annotations.Requires
import com.kpit.c4k.core.workflow.annotations.WorkflowComponent
import java.util.List
import com.kpit.c4k.bsw.templates.AbstractCodeGenerator
import org.eclipse.emf.common.util.URI
import com.kpit.c4k.bsw.workflow.AutosarLoader
import autosar40.autosartoplevelstructure.AUTOSAR
import com.kpit.c4k.ecuc.types.autosar.ecucdefs.Sd
import java.io.File
import com.kpit.c4k.bsw.sd.codegen.Sd_Cfg_H
import java.util.Map

@WorkflowComponent
class GenerateSd extends AbstractCodeGenerator<Sd> {

  @Requires
  AUTOSAR model

  @Requires
  String output

  @Requires
  List<String> input

  @Requires
  List<URI> inputURIs

  override doExecuteTemplates() throws Exception {
        Sd_Cfg_H.invoke [
      it.inputModel = model
      it.inputUris = inputURIs
      it.output = outputHdr + File.separator + "Sd_Cfg.h"
      ]

      if((module.implementationConfigVariant.toString == "VARIANT-PRE-COMPILE")){
      Sd_Cfg_C.invoke [
      it.inputModel = model
      it.inputUris = inputURIs
      it.output = outputSrc + File.separator + "Sd_Cfg.c"
      ]
      
      }
      else
       {
         Sd_Cfg_PBcfg_H.invoke [
          it.inputModel = model
          it.inputUris = inputURIs
          it.output = outputHdr + File.separator + "Sd_PBCfg.h"
        ]
        
          Sd_Cfg_PBcfg_C.invoke [
          it.inputModel = model
         it.inputUris = inputURIs
         it.output = outputSrc + File.separator + "Sd_PBCfg.c"
        ]
        
        Sd_Cfg_Lcfg_C.invoke [
          it.inputModel = model
         it.inputUris = inputURIs
         it.output = outputSrc + File.separator + "Sd_Lcfg.c"
        ]
        
        
        }
        
        
    }

  override doInitialize() {
    stopOnError = true
    showCauseForTermination = true
    eraseOnException = false
    stopOnWarning = false
if (!input.nullOrEmpty) {
    val loader = AutosarLoader.invoke [
      it.inputUris = input
    ]
    model = loader.model
    inputURIs = loader.getURIs
  }
}
  override getInputURIs() {
    inputURIs
  }

  override getModel() {
    model
  }

  override getModuleClass() {
   Sd
  }

  override getOutputDirectory() {
    output
  }

  override getValidationFilter() {
    "SdRuleSet"
  }
  
  override runInUI(AUTOSAR input, List<URI> inputURIs, String output, Map<String, String> options) {
		this.model = input
		this.inputURIs = inputURIs
		this.output = output
	}
}
