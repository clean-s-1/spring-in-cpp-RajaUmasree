#include <vector>

struct Stats {
    float average;
    float min;
    float max;
};

struct EmailAlert {
    bool emailSent;
 
};

struct LEDAlert {
    bool ledGlows;
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&vec);
};
class StatsAlerter{
    public:
        float m_maxthreshold;
        struct EmailAlert emailAlert;
        struct LEDAlert ledAlert;
        StatsAlerter(float maxthreshold, struct EmailAlert emailAlert,
                 struct LEDAlert ledAlert);
        void checkAndAlert(const vector<float>&vec);
};
