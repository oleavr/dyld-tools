sources = [
  'Closure.cpp',
  'ClosureBuilder.cpp',
  'ClosureFileSystemNull.cpp',
  'ClosureFileSystemPhysical.cpp',
  'ClosureWriter.cpp',
  'Diagnostics.cpp',
  'JSONReader.mm',
  'MachOAnalyzer.cpp',
  'MachOFile.cpp',
  'MachOLoaded.cpp',
  'PathOverrides.cpp',
  'shared-cache/AdjustDylibSegments.cpp',
  'shared-cache/BuilderUtils.mm',
  'shared-cache/CacheBuilder.cpp',
  'shared-cache/DyldSharedCache.cpp',
  'shared-cache/FileUtils.cpp',
  'shared-cache/Manifest.mm',
  'shared-cache/OptimizerBranches.cpp',
  'shared-cache/OptimizerLinkedit.cpp',
  'shared-cache/OptimizerObjC.cpp',
  'shared-cache/dyld_shared_cache_builder.mm',
  'shared-cache/mrm_shared_cache_builder.cpp',
]

base_args = [
  '-DBUILDING_CACHE_BUILDER',
  '-DSUPPORT_ARCH_arm64_32',
  '-DSUPPORT_ARCH_arm64e',
  '-DSUPPORT_ARCH_armv7k',
  '-Wno-non-virtual-dtor',
  '-Wno-null-conversion',
  '-Wno-reorder',
  '-Wno-unused-lambda-capture',
  '-Wno-unused-local-typedef',
  '-Wno-unused-private-field',
]

executable('dyld_shared_cache_builder', sources,
  cpp_args : base_args + [
    '-mmacosx-version-min=10.12',
  ],
  objcpp_args : base_args + [
    '-std=c++17',
    '-fobjc-arc',
  ],
  link_args : [
    '-Wl,-framework,Foundation',
    '-F/System/Library/PrivateFrameworks',
    '-Wl,-framework,Bom',
  ],
  include_directories : [
    include_directories('./shared-cache'),
    ext_incdir
  ],
  install : true,
)
