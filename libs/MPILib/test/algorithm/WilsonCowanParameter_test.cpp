/*
 * MPINetwork_test.cpp
 *
 *  Created on: 31.05.2012
 *      Author: david
 */

#include <boost/mpi.hpp>
#include <boost/mpi/communicator.hpp>

//Hack to test privat members
#define private public
#define protected public
#include <MPILib/include/algorithm/WilsonCowanParameter.hpp>
#undef protected
#undef private

#include <boost/test/minimal.hpp>
using namespace boost::unit_test;
using namespace MPILib::algorithm;

namespace mpi = boost::mpi;

mpi::communicator world;

void test_Constructor() {
	WilsonCowanParameter wp;

	BOOST_CHECK(wp._f_input==0.0);
	BOOST_CHECK(wp._f_noise==0.0);
	BOOST_CHECK(wp._rate_maximum==0.0);
	BOOST_CHECK(wp._time_membrane==0.0);

	WilsonCowanParameter wp1(1.0, 2.0, 3.0, 4.0);

	BOOST_CHECK(wp1._f_input==4.0);
	BOOST_CHECK(wp1._f_noise==3.0);
	BOOST_CHECK(wp1._rate_maximum==2.0);
	BOOST_CHECK(wp1._time_membrane==1.0);

}

int test_main(int argc, char* argv[]) // note the name!
		{

	boost::mpi::environment env(argc, argv);
	// we use only two processors for this testing

	if (world.size() != 2) {
		BOOST_FAIL( "Run the test with two processes!");
	}

	test_Constructor();

	return 0;
//    // six ways to detect and report the same error:
//    BOOST_CHECK( add( 2,2 ) == 4 );        // #1 continues on error
//    BOOST_CHECK( add( 2,2 ) == 4 );      // #2 throws on error
//    if( add( 2,2 ) != 4 )
//        BOOST_ERROR( "Ouch..." );          // #3 continues on error
//    if( add( 2,2 ) != 4 )
//        BOOST_FAIL( "Ouch..." );           // #4 throws on error
//    if( add( 2,2 ) != 4 ) throw "Oops..."; // #5 throws on error
//
//    return add( 2, 2 ) == 4 ? 0 : 1;       // #6 returns error code
}
