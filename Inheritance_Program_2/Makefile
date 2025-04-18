CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
program: main.o Appliance.o SmartLight.o SmartThermostat.o SmartTV.o
	$(CXX) $(CXXFLAGS) -o program main.o Appliance.o SmartLight.o SmartThermostat.o SmartTV.o

# Object rules
main.o: main.cpp Appliance.h SmartLight.h SmartThermostat.h SmartTV.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Appliance.o: Appliance.cpp Appliance.h
	$(CXX) $(CXXFLAGS) -c Appliance.cpp -o Appliance.o

SmartLight.o: SmartLight.cpp SmartLight.h Appliance.h
	$(CXX) $(CXXFLAGS) -c SmartLight.cpp -o SmartLight.o

SmartThermostat.o: SmartThermostat.cpp SmartThermostat.h Appliance.h
	$(CXX) $(CXXFLAGS) -c SmartThermostat.cpp -o SmartThermostat.o

SmartTV.o: SmartTV.cpp SmartTV.h Appliance.h
	$(CXX) $(CXXFLAGS) -c SmartTV.cpp -o SmartTV.o

# Clean rule for Windows
clean:
	@if exist program.exe del program.exe
	@if exist *.o del *.o