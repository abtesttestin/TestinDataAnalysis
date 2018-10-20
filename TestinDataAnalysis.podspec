Pod::Spec.new do |s|

s.name         = 'TestinDataAnalysis'
s.version      = '5.0.5'
s.license      = { :type => 'MIT' }
s.homepage     = 'https://github.com/abtesttestin/TestinDataAnalysis'
s.authors      = { 'Testin' => 'abtest@testin.cn' }

s.summary      = 'A delightful iOS framework.'
s.source       = { :git => 'https://github.com/abtesttestin/TestinDataAnalysis.git', :tag => s.version }

s.platform     = :ios, '7.0'
s.default_subspec = 'testincore'



s.subspec 'testincore' do |cm|
cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
end

s.subspec 'forbid_bugout' do |cm|
cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
cm.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'TESTIN_BUGOUT_DISENABLED=1'}
end

s.subspec 'forbid_ab' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
cm.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'TESTIN_AB_DISENABLED=1'}
end

s.subspec 'forbid_data' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
cm.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'TESTIN_DATA_DISENABLED=1'}
end

end

