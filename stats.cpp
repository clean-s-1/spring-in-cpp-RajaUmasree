#include "stats.h"
#include <vector>

Stats Statistics::ComputeStatistics(const std::vector<float>&vec ) {
    Stats Stats1;
    if(vec.size()>0) {
        float sum = 0.0;
        float min = vec[0];
        float max = vec[0];

        for(int i =0; i<vec.size(); i++) {
            if(min>vec[i]) {
                min = vec[i];
            } else if(max<vec[i]) {
                max = vec[i];
            }

            sum = sum + vec[i] ;
            Stats1.average = (sum)/vec.size();
            Stats1.min = min;
            Stats1.max = max;

         }
    }
    return Stats1;
}

    
 StatsAlerter::StatsAlerter(float maxthreshold, struct EmailAlert emailAlert,
    struct LEDAlert ledAlert) {
            m_maxthreshold = maxthreshold;
            emailAlert.emailSent = false;
                  ledAlert.ledGlows = false;
                 
            
 }
 void StatsAlerter::checkAndAlert(const std::vector<float>&vec) {
      for(int i =0; i<vec.size();i++) {
             if(vec[i]>m_maxthreshold) {
                 emailAlert.emailSent = true;
                  ledAlert.ledGlows = true;
              }
        }
            
  }
    
    
