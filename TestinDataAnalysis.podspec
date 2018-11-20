Pod::Spec.new do |s|

s.name         = 'TestinDataAnalysis'
s.version      = '5.1.2'
s.license      = { :type => 'MIT' }
s.homepage     = 'https://github.com/abtesttestin/TestinDataAnalysis'
s.authors      = { 'Testin' => 'abtest@testin.cn' }

s.summary      = 'A delightful iOS framework.'
s.source       = { :git => 'https://github.com/abtesttestin/TestinDataAnalysis.git', :tag => s.version }

s.platform     = :ios, '7.0'
s.default_subspec = 'TestinCore'



s.subspec 'TestinCore' do |cm|
cm.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
end

s.subspec 'TestinOnlyBugOut' do |cm|
cm.source_files = 'TestinDataAnalysis/TestinOnlyBugOut/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinOnlyBugOut/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinOnlyBugOut/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
end

s.subspec 'TestinOnlyAB' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinOnlyAB/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinOnlyAB/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinOnlyAB/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
end

s.subspec 'TestinOnlyData' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinOnlyData/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinOnlyData/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinOnlyData/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
end

s.subspec 'TestinOnlyABData' do |cm|

cm.source_files = 'TestinDataAnalysis/TestinOnlyABData/TestinDataAnalysis.framework/Headers/*.{h}'
cm.public_header_files = 'TestinDataAnalysis/TestinOnlyABData/TestinDataAnalysis.framework/Headers/*.h'
cm.vendored_frameworks = 'TestinDataAnalysis/TestinOnlyABData/TestinDataAnalysis.framework'
cm.libraries    = 'sqlite3','icucore','z'
cm.frameworks   = 'UIKit','Foundation','SystemConfiguration','CoreTelephony','AudioToolbox','Security','CoreMotion','ImageIO'
end

end

