#include "version.h"
#include <cstdlib>
#include <iostream>
#include <vector>

#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

int main(int argc, char * argv[])
{
    typedef matrix<double,2,1> sample_type;

    typedef radial_basis_kernel<sample_type> kernel_type;


    kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 8);

    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;

    sample_type m;

    int num_clusters;

    for (int i = 0; i < argc; ++i)
    {
        num_clusters = atoi(argv[i]);
    }

    for(string line; getline(cin, line);)
    {
        stringstream ss;
        ss << line;
        char ch;
        ss >> m(0) >> ch >> m(1);
        samples.push_back(m);
    }

    test.set_number_of_centers(num_clusters);

    pick_initial_centers(num_clusters, initial_centers, samples, test.get_kernel());

    test.train(samples,initial_centers);

    for (unsigned long i = 0; i < samples.size(); ++i)
    {
        cout << samples[i](0) << ";" << samples[i](1) << ";" << test(samples[i]) << endl;
    }

    return 0;
}
