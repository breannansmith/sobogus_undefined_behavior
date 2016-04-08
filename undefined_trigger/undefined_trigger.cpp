#include "SobogusInterface.h"

static void sobogusTest()
{
  bogus::SobogusInterface sobogus_interface;

  const unsigned num_bodies = 1;
  Eigen::VectorXd masses( 4 );
  masses << 8, 0, 0, 8;
  Eigen::VectorXd f_in( 2 );
  f_in << 0, 0;
  const unsigned num_contacts = 1;
  Eigen::VectorXd mu( 1 );
  mu << 0.5;
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic,Eigen::ColMajor> contact_bases( 2, 2 );
  contact_bases << -0.506399, -0.862299, 0.862299, -0.506399;
  Eigen::VectorXd w_in( 2 );
  w_in << 0, 0;
  Eigen::VectorXi obj_a( 1 );
  obj_a << 0;
  Eigen::VectorXi obj_b( 1 );
  obj_b << -1;

  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> HA( 2, 2 );
  HA << -0.506399, 0.862299, -0.862299, -0.506399;
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic,Eigen::RowMajor> HB( 2, 2 );
  HB << 0.0, 0.0, 0.0, 0.0;

  sobogus_interface.fromPrimal( num_bodies, masses, f_in, num_contacts, mu, contact_bases, w_in, obj_a, obj_b, HA, HB );

  Eigen::VectorXd r( 2 );
  r << 0, 0;
  Eigen::VectorXd v( 2 );
  v << 0, 0;
  unsigned num_iterations;
  const unsigned max_threads = 0;
  const double tol = 1.0e-12;
  const unsigned max_iters = 5000;
  const unsigned eval_every = 1;
  const bool use_infinity_norm = 1;

  sobogus_interface.solve( r, v, num_iterations, max_threads, tol, max_iters, eval_every, use_infinity_norm );
}

int main( int argc, char** argv )
{
  sobogusTest();
}
