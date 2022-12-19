#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

// write verifiable_word small letter. otherwise wont work
bool str_corrector(std::string str, std::string verifiable_word) 
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == verifiable_word[i]);
		else if (str[i] == (verifiable_word[i] - 32));
		else return false;
	}
	return true;
}

enum switches
{
	LIGHTS_INSIDE	   = 1, // 00000001
	LIGHTS_OUTSIDE	   = 2, // 00000010
	HEATERS            = 4, // 00000100
	WATER_PIPE_HEATING = 8, // 00001000
	CONDITIONER		   = 16 // 00010000
};

int main()
{
	int switch_state = 0;
	int switch_state_before = 0;

	unsigned int houre = 0;
	// from 16.00 to 5.00 am AND somebody in outside turn on outside light
	//if turn on. output colorful temperature.

	int degreec_outside = 0; 
	// 0 > temperature outside, on heating plumbing, 
	// C > 5 off heating plumbing;

	int degreec_inside = 0;
	// if temperature in side <22 turn on heating 
	// if T > 25 turn off;
	// if t > 30 turn on air conidtioner, if T <= 25 air conditioner trun off.
	
	std::string somebody = "";
	std::string light = "";

	int lumen = 5000;
	// if 16.00 <= houre <=20.00. lumen will be smoothly change to 2700|| near 460 lm on hour
	// BUT LIGHT MUST BE ON

	std::string example_for;
	
	do
	{
		
		std::cout << "   Smart house talked\n";
		std::cout << "\t-------------\n";
		std::cout << "\t|Time: " << houre << ".00 |\n";
		std::cout << "\t-------------\n";
		
		std::cout << "Inpting counters value:\n1.temperature on outside:\n2.temperature inside:\n3.somebody on outside:\n4.Light at house:\n";
		std::getline(std::cin, example_for);
		std::stringstream temp_Str; 

		temp_Str << example_for;

		temp_Str >> degreec_outside;
		temp_Str >> degreec_inside;
		temp_Str >> somebody;
		temp_Str >> light;



		//WATER PIPE HEATING
		if (degreec_outside < 0) switch_state |= WATER_PIPE_HEATING; // turn on heating plumbing
		else if (degreec_outside > 5) switch_state &= ~WATER_PIPE_HEATING; // turn off 

		//light outside and on garden
		if (16 <= houre || houre <= 5)
		{
			if (str_corrector(somebody, "yes"))
			{
				switch_state |= LIGHTS_OUTSIDE;
			}
			else if (str_corrector(somebody, "no"))
			{
				switch_state &= ~LIGHTS_OUTSIDE;
			}
			else
			{
				std::cerr << "Invalid options: somebody";
			}
		}

		// regulate temperature inside
		if (degreec_inside < 22) switch_state |= HEATERS;
		else if (30 > degreec_inside && degreec_inside >= 25)
		{
			switch_state &= ~HEATERS;
			switch_state &= ~CONDITIONER;
		}
		else if (degreec_inside > 30)
		{
			switch_state |= CONDITIONER;
			switch_state &= ~HEATERS;
		}
		else std::cerr << "YOU DIED. HOW YOU ARE DESTROY THAT?";
		
		//light at house
		if ((16 <= houre && houre <= 20))
		{
			lumen -= 460;
		}
		if (str_corrector(light, "on"))
		{
			switch_state |= LIGHTS_INSIDE;
		}
		else if (str_corrector(light, "off"))
		{
			switch_state &= ~LIGHTS_INSIDE;
		}

		std::cout << std::endl;

		system("cls");
		//outputing information for turn on or turn of


		if (switch_state & LIGHTS_INSIDE & ~switch_state_before) std::cout << "Light: \ton\nLumen: \t" << lumen << std::endl;
		else if (~switch_state & switch_state_before & LIGHTS_INSIDE) std::cout << "Light: \toff\n";
		if (switch_state & LIGHTS_OUTSIDE & ~switch_state_before) std::cout << "Light on garden: \ton\n";
		else if (~switch_state & switch_state_before & LIGHTS_OUTSIDE) std::cout << "Light on garden: \toff\n";
		if (switch_state & HEATERS & ~switch_state_before) std::cout << "Heaters: on\n";
		else if (~switch_state & switch_state_before & HEATERS) std::cout << "Heaters: off\n";
		if (switch_state & WATER_PIPE_HEATING & ~switch_state_before) std::cout << "Water pipe heating: \ton\n";
		else if (~switch_state & switch_state_before & WATER_PIPE_HEATING) std::cout << "Water pipe heating: \toff\n";
		if (switch_state & CONDITIONER & ~switch_state_before) std::cout << "Conditioner: \ton\n";
		else if (~switch_state & switch_state_before & CONDITIONER) std::cout << "Conditioner: \toff\n";



		std::cout << std::endl;
		houre++;
		if (houre == 24)
		{
			houre = 0;
			lumen = 5000;
		}

		//for chek changed options
		switch_state_before = switch_state;

	} while (true);
	
	return 0;
}