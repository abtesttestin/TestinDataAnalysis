#
#  Be sure to run `pod spec lint TestinDataAnalysis.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

s.name         = 'TestinDataAnalysis'
s.version      = '4.0.5'
s.license      = { :type => 'MIT' }
s.homepage     = 'https://github.com/abtesttestin/TestinDataAnalysis'
s.authors      = { 'Testin' => 'abtest@testin.cn' }
s.summary      = 'A delightful iOS framework.'
s.source       = { :git => 'https://github.com/abtesttestin/TestinDataAnalysis.git', :tag => s.version }
s.platform     = :ios, '7.0'
s.source_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/*.{h}'
s.vendored_frameworks = 'TestinDataAnalysis/TestinDataAnalysis.framework'
s.public_header_files = 'TestinDataAnalysis/TestinDataAnalysis.framework/Headers/TestinDataAnalysis.h'
s.libraries    = 'sqlite3','icucore'
s.frameworks   = 'UIKit','Foundation'

end