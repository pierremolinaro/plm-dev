#!/usr/bin/python
# -*- coding: utf-8 -*-

#----------------------------------------------------------------------------------------------------------------------*

import os
import sys
import subprocess

#----------------------------------------------------------------------------------------------------------------------*
#   FOR PRINTING IN COLOR                                                                                              *
#----------------------------------------------------------------------------------------------------------------------*

def BLACK () :
  return '\033[90m'

#----------------------------------------------------------------------------*

def RED () :
  return '\033[91m'

#----------------------------------------------------------------------------*

def GREEN () :
  return '\033[92m'

#----------------------------------------------------------------------------*

def YELLOW () :
  return '\033[93m'

#----------------------------------------------------------------------------*

def BLUE () :
  return '\033[94m'

#----------------------------------------------------------------------------*

def MAGENTA () :
  return '\033[95m'

#----------------------------------------------------------------------------*

def CYAN () :
  return '\033[96m'

#----------------------------------------------------------------------------*

def WHITE () :
  return '\033[97m'

#----------------------------------------------------------------------------*

def ENDC () :
  return '\033[0m'

#----------------------------------------------------------------------------*

def BOLD () :
  return '\033[1m'

#----------------------------------------------------------------------------*

def UNDERLINE () :
  return '\033[4m'

#----------------------------------------------------------------------------*

def BLINK () :
  return '\033[5m'

#----------------------------------------------------------------------------------------------------------------------*

def runCommand (command) :
  childProcess = subprocess.Popen (command)
  childProcess.wait ()
  if childProcess.returncode != 0 :
    sys.exit (childProcess.returncode)

#----------------------------------------------------------------------------------------------------------------------*

def compileSource (source) :
  print MAGENTA() + BOLD () + "********** Compile " + source + ENDC ()
  command = ["../../../makefile-macosx/plm-debug", "--no-panic-generation", "-v", "--Oz", source]
  returncode = subprocess.call (command)
  if returncode != 0 :
    sys.exit (returncode)
  command = ["../../../makefile-macosx/plm-debug", "-v", "--Oz", source]
  returncode = subprocess.call (command)
  if returncode != 0 :
    sys.exit (returncode)

#----------------------------------------------------------------------------------------------------------------------*

#--- Get script absolute path
scriptDir = os.path.dirname (os.path.abspath (sys.argv [0]))
os.chdir (scriptDir)
#--- Compile PLM
print MAGENTA() + BOLD () + "********** Compile PLM" + ENDC ()
runCommand (["python", "../../../makefile-macosx/build+debug.py"])
#--- Compile PLM sources
for dirname, dirnames, filenames in os.walk (scriptDir):
  for file in filenames :
    extension = os.path.splitext (file)[1]
    if extension == ".plm" :
      #print "  Dependence file : '" + file + "'"
      compileSource (file)

#----------------------------------------------------------------------------------------------------------------------*
