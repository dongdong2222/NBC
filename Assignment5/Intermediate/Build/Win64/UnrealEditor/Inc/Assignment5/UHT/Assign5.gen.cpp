// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Assignment5/Assign5.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssign5() {}

// Begin Cross Module References
ASSIGNMENT5_API UClass* Z_Construct_UClass_AAssign5();
ASSIGNMENT5_API UClass* Z_Construct_UClass_AAssign5_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_Assignment5();
// End Cross Module References

// Begin Class AAssign5
void AAssign5::StaticRegisterNativesAAssign5()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAssign5);
UClass* Z_Construct_UClass_AAssign5_NoRegister()
{
	return AAssign5::StaticClass();
}
struct Z_Construct_UClass_AAssign5_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Assign5.h" },
		{ "ModuleRelativePath", "Assign5.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAssign5>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AAssign5_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Assignment5,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAssign5_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAssign5_Statics::ClassParams = {
	&AAssign5::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAssign5_Statics::Class_MetaDataParams), Z_Construct_UClass_AAssign5_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAssign5()
{
	if (!Z_Registration_Info_UClass_AAssign5.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAssign5.OuterSingleton, Z_Construct_UClass_AAssign5_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAssign5.OuterSingleton;
}
template<> ASSIGNMENT5_API UClass* StaticClass<AAssign5>()
{
	return AAssign5::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAssign5);
AAssign5::~AAssign5() {}
// End Class AAssign5

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE5_Assignment5_Source_Assignment5_Assign5_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAssign5, AAssign5::StaticClass, TEXT("AAssign5"), &Z_Registration_Info_UClass_AAssign5, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAssign5), 43221982U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5_Assignment5_Source_Assignment5_Assign5_h_2576472463(TEXT("/Script/Assignment5"),
	Z_CompiledInDeferFile_FID_UE5_Assignment5_Source_Assignment5_Assign5_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5_Assignment5_Source_Assignment5_Assign5_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
