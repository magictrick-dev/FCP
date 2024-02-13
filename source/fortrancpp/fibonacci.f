* ----------------------------------------------------------------------
* Author Chris DeJong
* ----------------------------------------------------------------------
*
* Fast fibonnaci requires a different syntax.
*
        MODULE FASTFIB
        USE ISO_C_BINDING
*
        CONTAINS
*
        SUBROUTINE FAST_FIBONACCI(N_INDEX, FIB_VALUE) BIND (C,
     *      NAME="fast_fibonacci")
        INTEGER (C_INT), INTENT (IN) :: N_INDEX
        INTEGER (C_INT), INTENT (OUT) :: FIB_VALUE
        INTEGER*8 IARR(*)
        POINTER(IP,IARR)
        IP=MALLOC(10*8)
        IARR(1)=1
        IARR(2)=1
        DO 1 I=3,N_INDEX
            IARR(I)=IARR(I-1)+IARR(I-2)
1       CONTINUE
        FIB_VALUE=IARR(N_INDEX)
        CALL FREE(IP)
        RETURN
        END
*
        END MODULE FASTFIB
*
*
