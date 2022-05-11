#include <vector>

struct Stats {
    float average;
    float min;
    float max;
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>vec);
}
