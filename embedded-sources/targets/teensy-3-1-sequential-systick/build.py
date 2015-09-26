#! /usr/bin/env python
# -*- coding: UTF-8 -*-

#----------------------------------------------------------------------------------------------------------------------*

import sys, os

#----------------------------------------------------------------------------------------------------------------------*

sys.path.append (os.path.dirname (os.path.abspath (sys.argv [0])) + "/sources")
import plm

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#                         Object files directories                                                                     *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def archiveBaseURL ():
  return "http://crossgcc.rts-software.org/downloads/plm-tools/"

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Tool dir                                                                                                           *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def toolDir ():
  (SYSTEM_NAME, MODE_NAME, RELEASE, VERSION, MACHINE) = os.uname ()
  if SYSTEM_NAME == "Darwin":
    MACHINE = "i386"
  return os.path.expanduser ("~/plm-tools/plm-" + SYSTEM_NAME + "-" + MACHINE + "-llvm-3.7.0-binutils-2.25-libusb-1.0.19")

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLVM optimizer invocation                                                                                          *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def llvmOptimizerCompiler ():
  return [toolDir () + "/bin/opt", "-disable-simplify-libcalls", "-S"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLVM optimizer options                                                                                             *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def llvmOptimizerOptions ():
  result = []
  result.append ("-<<OPTIMIZATION_OPTION>>")
  return result

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLC Compiler invocation                                                                                            *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def LLCcompiler ():
  return [toolDir () + "/bin/llc"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   AS assembler invocation                                                                                            *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def asAssembler ():
  return [toolDir () + "/bin/arm-eabi-as", "-mthumb", "-mcpu=cortex-m4"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Display object size invocation                                                                                     *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def displayObjectSize ():
  return [toolDir () + "/bin/arm-eabi-size", "-t"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Object Dump invocation                                                                                             *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def dumpObjectCode ():
  return [toolDir () + "/bin/arm-eabi-objdump", "-Sdh", "-Mforce-thumb"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Linker invocation                                                                                                  *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def linker ():
  return [toolDir () + "/bin/arm-eabi-ld"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Linker options                                                                                                     *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def linkerOptions ():
  result = []
  result.append ("-nostartfiles")
  result.append ("--fatal-warnings")
  result.append ("--warn-common")
  result.append ("--no-undefined")
  result.append ("--cref")
  result.append ("-static")
  result.append ("-s")
  result.append ("--gc-sections")
  return result

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   objcopy invocation                                                                                                 *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def objcopy ():
  return [toolDir () + "/bin/arm-eabi-objcopy"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLVM Source files                                                                                                  *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def LLVMsourceList ():
  return ["source-plm.ll"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Product directory                                                                                                  *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def productDir ():
  return "product"

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#                         Object files directories                                                                     *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def objectDir ():
  return "objects"

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Run executable                                                                                                      *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def runExecutableOnTarget ():
  return [toolDir () + "/bin/teensy-loader-cli", "-w", "-v", "-mmcu=mk20dx128"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   MAIN                                                                                                               *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

currentFile = os.path.abspath (sys.argv [0])
plm.runMakefile (toolDir (), archiveBaseURL (), LLVMsourceList (), objectDir (), \
                 LLCcompiler (), llvmOptimizerCompiler (), llvmOptimizerOptions (),
                 asAssembler (), productDir (), \
                 linker (), linkerOptions (), \
                 objcopy (), dumpObjectCode (), displayObjectSize (), runExecutableOnTarget (), \
                 currentFile)

#----------------------------------------------------------------------------------------------------------------------*
