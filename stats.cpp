#include "stats.h"

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
