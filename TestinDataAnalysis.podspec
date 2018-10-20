Pod::Spec.new do |s|

s.name         = 'TestinDataAnalysis'
s.version      = '5.0.4'
s.license      = { :type => 'MIT' }
s.homepage     = 'https://github.com/abtesttestin/TestinDataAnalysis'
s.authors      = { 'Testin' => 'abtest@testin.cn' }

s.summary      = 'A delightful iOS framework.'
s.source       = { :git => 'https://github.com/abtesttestin/TestinDataAnalysis.git', :tag => s.version }

s.platform     = :ios, '7.0'
s.default_subspec = 'testincore'
#s.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
s.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
#s.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
s.libraries    = 'sqlite3','icucore','z'
s.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'


s.subspec 'testincore' do |cm|
cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
end

s.subspec 'forbid_bugout' do |cm|
cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'TESTIN_BUGOUT_DISENABLED=1'}
end

s.subspec 'forbid_ab' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'TESTIN_AB_DISENABLED=1'}
end

s.subspec 'forbid_data' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'TESTIN_DATA_DISENABLED=1'}
end

end

