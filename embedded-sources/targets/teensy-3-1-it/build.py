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
  return os.path.expanduser ("~/plm-tools/plm-" + SYSTEM_NAME + "-" + MACHINE + "-llvm-3.7.1-binutils-2.26-libusb-1.0.19")

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLVM optimizer invocation                                                                                          *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def llvmOptimizerCompiler ():
  return [toolDir () + "/bin/opt", "-<<OPT_OPTIMIZATION_OPTION>>", "-disable-simplify-libcalls", "-S"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLC Compiler invocation                                                                                            *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def LLCcompiler ():
  return [toolDir () + "/bin/llc", "-<<LLC_OPTIMIZATION_OPTION>>"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLVM Linker invocation                                                                                             *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def LLVMLinkercompiler ():
  return [toolDir () + "/bin/llvm-link", "-S"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   CLANG Compiler invocation                                                                                          *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def CLANGcompiler ():
  return [toolDir () + "/bin/clang", "--target=armv7-none--eabi", "-mcpu=cortex-m4"]

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
  result = [toolDir () + "/bin/arm-eabi-ld"]
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
#   Linker libraries                                                                                                   *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def linkerLibraries ():
  result = ["libgcc-armv7e-m.a"]
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
#   C Source files                                                                                                     *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def CsourceList ():
  return ["src.c"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   LLVM Source files                                                                                                  *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def LLVMsourceList ():
  return ["src.ll"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   Assembler Source files                                                                                             *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

def assemblerSourceList ():
  return ["src.s"]

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
  return [toolDir () + "/bin/teensy-loader-cli", "-w", "-v", "-mmcu=mk20dx256"]

#----------------------------------------------------------------------------------------------------------------------*
#                                                                                                                      *
#   MAIN                                                                                                               *
#                                                                                                                      *
#----------------------------------------------------------------------------------------------------------------------*

currentFile = os.path.abspath (sys.argv [0])
plm.runMakefile (toolDir (), archiveBaseURL (), LLVMsourceList (), assemblerSourceList (), objectDir (), \
                 LLCcompiler (), llvmOptimizerCompiler (), \
                 asAssembler (), productDir (), \
                 linker (), linkerLibraries (), \
                 objcopy (), dumpObjectCode (), displayObjectSize (), runExecutableOnTarget (), \
                 CLANGcompiler (), CsourceList (), LLVMLinkercompiler (), \
                 currentFile)

#----------------------------------------------------------------------------------------------------------------------*
