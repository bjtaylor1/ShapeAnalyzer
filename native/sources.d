args.o: args.cpp args.h
	$(CXX) $(CXXFLAGS) -c args.cpp

com_bjt_ShapeAnalyzer_App.o: com_bjt_ShapeAnalyzer_App.cpp  com_bjt_ShapeAnalyzer_App.h coord.h latlong.h crossfinder.h contour.h  cross.h
	$(CXX) $(CXXFLAGS) -c com_bjt_ShapeAnalyzer_App.cpp

contour.o: contour.cpp contour.h coord.h iteratorpair.h utils.h
	$(CXX) $(CXXFLAGS) -c contour.cpp

contourloader.o: contourloader.cpp contourloader.h contour.h coord.h  gridfilesetdeterminer.h gridfiledeterminer.h coordset.h contourpruner.h  iteratorpair.h args.h hdsrvexception.h
	$(CXX) $(CXXFLAGS) -c contourloader.cpp

contourloadertest.o: contourloadertest.cpp contourloader.h contour.h  coord.h gridfilesetdeterminer.h gridfiledeterminer.h coordset.h  contourpruner.h
	$(CXX) $(CXXFLAGS) -c contourloadertest.cpp

contourprunertest.o: contourprunertest.cpp contourloader.h contour.h  coord.h gridfilesetdeterminer.h gridfiledeterminer.h coordset.h  contourpruner.h
	$(CXX) $(CXXFLAGS) -c contourprunertest.cpp

contourwriter.o: contourwriter.cpp contourwriter.h contour.h coord.h  testdata.h
	$(CXX) $(CXXFLAGS) -c contourwriter.cpp

coordconverter.o: coordconverter.cpp coordconverter.h coord.h latlong.h  hdsrvexception.h args.h
	$(CXX) $(CXXFLAGS) -c coordconverter.cpp

coord.o: coord.cpp coord.h
	$(CXX) $(CXXFLAGS) -c coord.cpp

coordset.o: coordset.cpp coordset.h coord.h contour.h
	$(CXX) $(CXXFLAGS) -c coordset.cpp

corrcontourpruner.o: corrcontourpruner.cpp contourpruner.h contour.h  coord.h coordset.h iteratorpair.h
	$(CXX) $(CXXFLAGS) -c corrcontourpruner.cpp

cross.o: cross.cpp cross.h
	$(CXX) $(CXXFLAGS) -c cross.cpp

crossfinder.o: crossfinder.cpp crossfinder.h contour.h coord.h cross.h  latlong.h iteratorpair.h crossinfo.h contourloader.h  gridfilesetdeterminer.h gridfiledeterminer.h coordset.h contourpruner.h  args.h coordconverter.h
	$(CXX) $(CXXFLAGS) -c crossfinder.cpp

crossinfo.o: crossinfo.cpp crossinfo.h
	$(CXX) $(CXXFLAGS) -c crossinfo.cpp

crossinfotest.o: crossinfotest.cpp crossinfo.h
	$(CXX) $(CXXFLAGS) -c crossinfotest.cpp

filefuncs.o: filefuncs.cpp filefuncs.h args.h
	$(CXX) $(CXXFLAGS) -c filefuncs.cpp

gridcontourpruner.o: gridcontourpruner.cpp contourpruner.h contour.h  coord.h coordset.h
	$(CXX) $(CXXFLAGS) -c gridcontourpruner.cpp

gridfiledeterminer.o: gridfiledeterminer.cpp gridfiledeterminer.h coord.h  args.h hdsrvexception.h
	$(CXX) $(CXXFLAGS) -c gridfiledeterminer.cpp

gridfiledeterminertest.o: gridfiledeterminertest.cpp gridfiledeterminer.h  coord.h latlong.h coordconverter.h args.h
	$(CXX) $(CXXFLAGS) -c gridfiledeterminertest.cpp

gridfilesetdeterminer.o: gridfilesetdeterminer.cpp  gridfilesetdeterminer.h gridfiledeterminer.h coord.h args.h
	$(CXX) $(CXXFLAGS) -c gridfilesetdeterminer.cpp

hdsrv.o: hdsrv.cpp args.h processor.h
	$(CXX) $(CXXFLAGS) -c hdsrv.cpp

hdsrvexception.o: hdsrvexception.cpp hdsrvexception.h
	$(CXX) $(CXXFLAGS) -c hdsrvexception.cpp

iteratorpairtest.o: iteratorpairtest.cpp iteratorpair.h
	$(CXX) $(CXXFLAGS) -c iteratorpairtest.cpp

latlong.o: latlong.cpp latlong.h
	$(CXX) $(CXXFLAGS) -c latlong.cpp

latlongreader.o: latlongreader.cpp latlongreader.h latlong.h
	$(CXX) $(CXXFLAGS) -c latlongreader.cpp

maintest.o: maintest.cpp args.h
	$(CXX) $(CXXFLAGS) -c maintest.cpp

realdatacrossfindertest.o: realdatacrossfindertest.cpp latlong.h  coordconverter.h coord.h crossfinder.h contour.h cross.h testdata.h
	$(CXX) $(CXXFLAGS) -c realdatacrossfindertest.cpp

socketwrapper.o: socketwrapper.cpp
	$(CXX) $(CXXFLAGS) -c socketwrapper.cpp

stringtoints.o: stringtoints.cpp stringtoints.h
	$(CXX) $(CXXFLAGS) -c stringtoints.cpp

svgelement.o: svgelement.cpp
	$(CXX) $(CXXFLAGS) -c svgelement.cpp

svgset.o: svgset.cpp
	$(CXX) $(CXXFLAGS) -c svgset.cpp

testdata.o: testdata.cpp testdata.h
	$(CXX) $(CXXFLAGS) -c testdata.cpp

tile.o: tile.cpp tile.h contour.h coord.h
	$(CXX) $(CXXFLAGS) -c tile.cpp

