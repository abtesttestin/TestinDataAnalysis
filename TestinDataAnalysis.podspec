Pod::Spec.new do |s|

s.name         = 'TestinDataAnalysis'
s.version      = '4.1.8'
s.license      = { :type => 'MIT' }
s.homepage     = 'https://github.com/abtesttestin/TestinDataAnalysis'
s.authors      = { 'Testin' => 'abtest@testin.cn' }

s.summary      = 'A delightful iOS framework.'
s.source       = { :git => 'https://github.com/abtesttestin/TestinDataAnalysis.git', :tag => s.version }

s.platform     = :ios, '7.0'

s.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
s.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
s.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/TestinDataAnalysis.h'

s.libraries    = 'sqlite3','icucore','z'
s.frameworks   = 'UIKit','Foundation'

end
