#include <qpOASES.hpp>

int main( )
{
    USING_NAMESPACE_QPOASES

    /* Setup data of QP. */
    real_t H[2*2] = { 4.0, 1.0, 1.0, 2.0 };
    real_t A[2*1] = { 1.0, 1.0 };
    real_t g[2] = { 1.0, 1.0 };
    real_t lb[2] = { 0.0, 0.0 };
    real_t ub[2] = { 10000.0, 10000.0 };
    real_t lbA[1] = { 1.0 }; // lbAとubAを等しくすることで等式制約として設定可能
    real_t ubA[1] = { 1.0 };

    /* Setting up QProblem object. */
    QProblem example( 2,1 );

    Options options;
    example.setOptions( options );

    /* Solve first QP. */
    int_t nWSR = 10;
    example.init( H,g,A,lb,ub,lbA,ubA, nWSR );

    /* Get and print solution of first QP. */
    real_t xOpt[2];
    real_t yOpt[2+1];
    example.getPrimalSolution( xOpt );
    example.getDualSolution( yOpt );
    printf( "\nxOpt = [ %e, %e ];  yOpt = [ %e, %e, %e ];  objVal = %e\n\n",
            xOpt[0],xOpt[1],yOpt[0],yOpt[1],yOpt[2],example.getObjVal() );

    example.printOptions();
    example.printProperties();

    return 0;
}
