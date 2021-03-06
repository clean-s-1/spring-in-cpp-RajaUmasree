#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <math.h>
#include <vector>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    
    auto computedStats = Statistics::ComputeStatistics({});
    std::cout << isnan(computedStats.average) << std::endl;
    std::cout << isnan(computedStats.max) << std::endl;
    std::cout << isnan(computedStats.min) << std::endl;
    
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
}

TEST_CASE("raises alerts when max is greater than threshold") {
    struct EmailAlert emailAlert;
    struct LEDAlert ledAlert;
   // std::vector<IAlerter*> alerters = {&emailAlert, &ledAlert};
    
    const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(maxThreshold,emailAlert, ledAlert );
    std::vector<float>vec = {99.896, 34.256, 4.455, 6.627};
    statsAlerter.checkAndAlert(vec);

    REQUIRE(emailAlert.emailSent);
    REQUIRE(ledAlert.ledGlows);
}
