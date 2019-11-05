;----------------------------------------------------------------------------------------------------------------------*
;    Target specific code                                                                                              *
;----------------------------------------------------------------------------------------------------------------------*

;--- For LLVM < 9.0.0
;target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"

;--- For LLVM >= 9.0.0
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"

;---
target triple = "thumbv7em-none--eabi"


;----------------------------------------------------------------------------------------------------------------------*
;    User Defined Types                                                                                                *
;----------------------------------------------------------------------------------------------------------------------*

%U = type {i32}
%V = type {%U}

;----------------------------------------------------------------------------------------------------------------------*
;    Type U
;----------------------------------------------------------------------------------------------------------------------*

define internal void @setter.U.0 (%U* %target, i32 %value) {
entry:
  %ptr = getelementptr inbounds %U, %U* %target, i32 0, i32 0
  store i32 %value, i32* %ptr
  ret void
}


;----------------------------------------------------------------------------------------------------------------------*
;    Type V
;----------------------------------------------------------------------------------------------------------------------*

define internal void @setter.V.0 (%V* %target, %U %value)  {
entry:
  %ptr = getelementptr inbounds %V, %V* %target, i32 0, i32 0
  store %U %value, %U* %ptr
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*

define internal %U @getter.V.0 (%V* %target)  {
entry:
  %ptr = getelementptr inbounds %V, %V* %target, i32 0, i32 0
  %v = load %U, %U* %ptr
  ret %U %v
}

;----------------------------------------------------------------------------------------------------------------------*
;    Sample code
;----------------------------------------------------------------------------------------------------------------------*

define void @myFunctionU (%U* %variable) {
entry:
  call void @setter.U.0 (%U* %variable, i32 55)
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*

define void @myFunctionV (%V* %variable) {
entry:
  %tempU = alloca %U
  %champU = call %U @getter.V.0 (%V* %variable)
  store %U %champU, %U* %tempU
  call void @setter.U.0 (%U* %tempU, i32 55)
  %v = load %U, %U* %tempU
  call void @setter.V.0 (%V* %variable, %U %v)
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*
;    Getter et setter en arguments
;----------------------------------------------------------------------------------------------------------------------*

define void @myFunctionW (i32 ()* %getter, void (i32)* %setter) {
  %value = call i32 %getter ()
  %result = add i32 %value, 1
  call void %setter (i32 %result)
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*

define void @myFunctionW (i32 ()* %getter, void (i32)* %setter) {
  %value = call i32 %getter ()
  %result = add i32 %value, 1
  call void %setter (i32 %result)
  ret void
}

;----------------------------------------------------------------------------------------------------------------------*