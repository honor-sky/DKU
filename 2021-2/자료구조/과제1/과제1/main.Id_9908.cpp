<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <Filter Include="소스 파일">
      <UniqueIdentifier>{4FC737F1-C7A5-4376-A066-2A32D752A2FF}</UniqueIdentifier>
      <Extensions>cpp;c;cc;cxx;c++;cppm;ixx;def;odl;idl;hpj;bat;asm;asmx</Extensions>
    </Filter>
    <Filter Include="헤더 파일">
      <UniqueIdentifier>{93995380-89BD-4b04-88EB-625FBE52EBFB}</UniqueIdentifier>
      <Extensions>h;hh;hpp;hxx;h++;hm;inl;inc;ipp;xsd</Extensions>
    </Filter>
    <Filter Include="리소스 파일">
      <UniqueIdentifier>{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}</UniqueIdentifier>
      <Extensions>rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav;mfcribbon-ms</Extensions>
    </Filter>
  </ItemGroup>
  <ItemGroup>
    <ClCompile Include="circleQueue.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="stack_P.M.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="main2.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="main3.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="postFix.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="main4cpp.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="main1.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
    <ClCompile Include="funcList.cpp">
      <Filter>소스 파일</Filter>
    </ClCompile>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="stack_PM.h">
      <Filter>헤더 파일</Filter>
    </ClInclude>
    <ClInclude Include="circleQueue.h">
      <Filter>헤더 파일</Filter>
    </ClInclude>
    <ClInclude Include="postFix.h">
      <Filter>헤더 파일</Filter>
    </ClInclude>
    <ClInclude Include="funcList.h">
      <Filter>헤더 파일</Filter>
    </ClInclude>
  </ItemGroup>
</Project>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   intArray(d, g, h, "d"); 

	start = clock();
	transpoArrays(d, g, h); //??ġ???? ????
	end = clock();
	printf("\n??ġ%f", (double)((end - start) / CLOCKS_PER_SEC));

	start = clock();
	sparseArrays(d, g, h); //???????? ????
	end = clock();
	printf("\n????%f", (double)((end - start) / CLOCKS_PER_SEC));

	freeArray(res1,m,n);
	freeArray(res2,m,k);
	freeArray(a,m,n);
	freeArray(b,m,n);
	freeArray(c,m,k);
	freeArray(d,g,h);

	return 0;