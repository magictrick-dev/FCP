*
*
*
      SUBROUTINE PRIME_SEIVE(N_SIZE) BIND(C, NAME="prime_seive")
          INTEGER*8 :: N_SIZE
          LOGICAL BARR(*)
          POINTER(BP, BARR)
          BP=MALLOC((N_SIZE+1)*4)
          BARR(1)=.FALSE.
          BARR(2)=.FALSE.
          DO 1 I=3,N_SIZE
          
1         CONTINUE
      END
