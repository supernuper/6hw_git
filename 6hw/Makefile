CXX=g++
CCLINK=$(CXX)
CXXFLAGS=-g -Wall -std=c++11
OBJS=main.o libfirewall.so libinput.so 

firewall.exe: $(OBJS)
	$(CCLINK) main.o -o firewall.exe -lfirewall -linput -L.
string.o: string.cpp string.h
	$(CXX) $(CXXFLAGS) -c -fpic string.cpp
ip.o: ip.cpp ip.h string.h generic-field.h
	$(CXX) $(CXXFLAGS) -c -fpic ip.cpp
port.o: port.cpp port.h string.h generic-field.h
	$(CXX) $(CXXFLAGS) -c -fpic port.cpp
main.o: main.cpp string.h ip.h port.h input.h
	$(CXX) $(CXXFLAGS) -c -fpic main.cpp				
libfirewall.so: string.o ip.o port.o
	$(CCLINK) -shared string.o ip.o port.o -o libfirewall.so 
	
clean:
	rm -fr *.o *.exe libfirewall.so
		