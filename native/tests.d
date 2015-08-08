contourloadertest.o: contourloadertest.cpp contourloader.h contour.h  coord.h gridfilesetdeterminer.h gridfiledeterminer.h coordset.h  contourpruner.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c contourloadertest.cpp

contourprunertest.o: contourprunertest.cpp contourloader.h contour.h  coord.h gridfilesetdeterminer.h gridfiledeterminer.h coordset.h  contourpruner.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c contourprunertest.cpp

crossinfotest.o: crossinfotest.cpp crossinfo.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c crossinfotest.cpp

gridfiledeterminertest.o: gridfiledeterminertest.cpp gridfiledeterminer.h  coord.h latlong.h coordconverter.h args.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c gridfiledeterminertest.cpp

iteratorpairtest.o: iteratorpairtest.cpp iteratorpair.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c iteratorpairtest.cpp

maintest.o: maintest.cpp args.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c maintest.cpp

realdatacrossfindertest.o: realdatacrossfindertest.cpp latlong.h  coordconverter.h coord.h crossfinder.h contour.h cross.h testdata.h
	$(CXX) $(CXXFLAGS) $(TESTCXXFLAGS) -c realdatacrossfindertest.cpp

