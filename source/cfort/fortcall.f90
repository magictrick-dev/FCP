
subroutine double_n(n_in, n_out) bind(c)
    implicit none
    integer (C_INT), intent(in) :: n_in
    integer (C_INT), intent(out) :: n_out
    n_out = n_in * 2
end subroutine double_n

