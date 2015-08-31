#include <animator.hpp>
#include <stdio.h>
Animator::Animator():
outputPath_{"../output/outputfile.txt"},
frames_{120}
{}


void Animator::generateFrames(){
    std::string file;

    file += std::string("define material white ")
        + "1 1 1 1 1 1 0 0 0 80 0 0 0\n\n";
    file += std::string("define material white2 ")
        + "0.8 0.8 0.8 0.1 0.1 0.1 0.2 0.2 0.2 80 0 0 0\n\n";
    file += std::string("define material green ")
        + "0 0.5 0 0 0.4 0 1 1 1 100 0.5 0 0\n\n";
    file += std::string("define material mirror ")
        + "0 0 0 0 0 0 1 1 1 100 1 0 0\n\n";
    file += std::string("define shape sphere s1 ")
    	+ "-2.5 -2.5 -7 0.25 green\n\n";
    file += std::string("define shape sphere s2 ")
    	+ "-1.5 -2.5 -7 0.25 green\n\n";
	file += std::string("define shape sphere s3 ")
    	+ "-2.5 -1.5 -7 0.25 green\n\n";
	file += std::string("define shape sphere s4 ")
    	+ "-1.5 -1.5 -7 0.25 green\n\n";
    file += std::string("define shape sphere s5 ")
    	+ "-0.5 -1.5 -7 0.25 green\n\n";
    file += std::string("define shape sphere s6 ")
    	+ "-0.5 -2.5 -7 0.25 green\n\n";
    file += std::string("define shape sphere s7 ")
    	+ "0.5 -1.5 -7 0.25 green\n\n";
    file += std::string("define shape sphere s8 ")
    	+ "0.5 -2.5 -7 0.25 green\n\n";
    file += std::string("define shape sphere mirror ")
    	+ "1.5 1.5 -9 1.5 mirror\n\n";
    file += std::string("define shape sphere mirror2 ")
    	+ "-1.5 0 -9 1.5 mirror\n\n";
    file += std::string("define shape box floor ")
    	+ "-7.5 -5.1 -8 8 -5 -15 white\n\n";
    file += std::string("define shape box lwall ")
    	+ "-7.5 -5.1 -8 -7.6 8 -15 white\n\n";
    file += std::string("define shape box bwall ")
    	+ "-7.5 -7.1 -15 8 8 -17.1 white2\n\n";	
    file += std::string("define shape composite greenSpheres ")
    	+ "s1 s2 s3 s4 s5 s6 s7 s8\n\n";	
    file += std::string("define shape composite shapes ")
    	+ "greenSpheres glas mirror mirror2\n\n";
    file += std::string("define shape composite root ")
    	+ "floor lwall bwall shapes\n\n";
    file += std::string("define light diffuse spot1 ")
    	+ "2 2 -3 0.3 0.3 0.3 1 1 1\n\n";
    file += std::string("define light ambient ambi ")
    	+ "0.05 0.05 0.05\n\n";
    file += std::string("define camera eye ")
    	+ "60.0 0 0 0\n\n";

    for(int i = 0; i < frames_; i++)
    {
    	std::string out;
    	out += std::string("define material glas ")
        + "0 0 0 0 0 0 0.5 0.5 0.5 50 0 0.999 0.75\n\n";
    	out += std::string("define shape sphere glas ")
    	+ std::to_string(-1+(0.02*i))+ " -1 -4 0.5 glas\n\n";
    	out += file;

		std::ofstream outstream("../input/outputfile"+std::to_string(i)+".txt");
		outstream << out;
		outstream.close();
    }

    for(int i = 0; i < 120; i++)
	 {
	 Sdfloader s{};
	 std::string p = "../input/outputfile"+std::to_string(i)+".txt";
	 s.readSdf(p);

	 std::shared_ptr<Scene> scene = std::make_shared<Scene>(s.scene());

	 Renderer renderer = Renderer{400, 400, "../output/output"+std::to_string(i)+".ppm", scene};
	 renderer.render();
	}
}