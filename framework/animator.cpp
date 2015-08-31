#include animator.hpp

Animator::Animator{std::string path, int frames}
{}

void Raytracer::generate_frames() const {
    using std::to_string;
    srand(static_cast<unsigned int>(time(0)));
    std::string file;
    // A unit as the means of measuring the dimensions of a shape
    const int unit = 20;

    // Prerequisite: Part of the scene definition, that should stay the same
    // during the animated sequence
    file += std::string("define material white")
        + "1 1 1 1 1 1 0 0 0 80 0 0 0\n\n";
    file += std::string("define material white2")
        + "0.8 0.8 0.8 0.1 0.1 0.1 0.2 0.2 0.2 80 0 0 0\n\n";
    file += std::string("define material glas")
        + "0 0 0 0 0 0 0.5 0.5 0.5 50 0 0.999 0.75\n\n";
    file += std::string("define material green")
        + "1 1 1 1 1 1 0 0 0 80 0 0 0\n\n";

        + " [50 -20 -300] [0.9 0.8 0.7] [0.9 0.8 0.7]\n\n";
    file += std::string("define shape box <table> ")
        + " [-300 -200 -330] [300 200 -340] <color_3>\n";

    // Fill a vector with randomized shape definitions
    std::vector<std::string> shapes;
    for (int i = 0; i < 27; ++i) {
        std::string tmp_shape = "define shape ";
        std::string rand_shape = random_shape();

        if (rand_shape == "box") {
            tmp_shape += "box <s" + to_string(i);
        } else if (rand_shape == "sphere") {
            tmp_shape += "sphere <s" + to_string(i);
        } else {
            tmp_shape += "triangle <s" + to_string(i);
        }
        shapes.push_back(tmp_shape);
    }