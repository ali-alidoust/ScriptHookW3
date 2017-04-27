from SignatureParser import SignatureParser
import json
parser = SignatureParser(left_recursion=False)
print(parser.parse("red::x&::y::TDynArray<class Bomb,1,2,3>::hey(void)", rule_name='full_function_name'))
print("")
print(parser.parse("class CName<1> const & __ptr64 __cdecl red::TDynArray<class CStorySceneEventCameraInterpolationKey,2,0>::GetTypeName(void)"))
print("")
print(parser.parse("void __cdecl ExtractCommandLineArguments(class TString<wchar_t> const & __ptr64,struct CommandLineArguments & __ptr64)"))
print("")
print(parser.parse("public: void __cdecl CFileManager::FindFilesRelative(class TString<wchar_t> const & __ptr64,class TString<wchar_t> const & __ptr64,class TString<wchar_t> const & __ptr64,class TDynArray<class TString<wchar_t>,2,0> & __ptr64,bool) __ptr64"))
print("")