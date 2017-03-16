Pod::Spec.new do |s|
  s.name = 'LittlstarSDK'
  s.version = '2.3.5'
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2017 Littlstar. All rights reserved.
      LICENSE
  }
  s.summary = 'LittlstarSDK_iOS containing components for panorama video'
  s.homepage = 'https://github.com/littlstar/littlstar-ios-sdk'
  s.author = { 'Littlstar dev. team' => 'dev@littlstar.com' }
  s.platforms = { :ios => "8.0", :tvos => "9.0" }
  s.source = { :git => 'git@github.com:littlstar/littlstar-ios-sdk.git', :tag => "#{s.version}" }
  s.source_files = 'LittlstarSDK/Headers/*.h'
  s.ios.preserve_paths = 'LittlstarSDK/libLittlstarSDK.a'
  s.ios.vendored_libraries = 'LittlstarSDK/libLittlstarSDK.a'
  s.ios.frameworks = 'UIKit', 'Foundation', 'CoreMotion', 'OpenAL', 'AudioToolbox'
  s.tvos.preserve_paths = 'LittlstarSDK/libLittlstarSDK_tvOS.a'
  s.tvos.vendored_libraries = 'LittlstarSDK/libLittlstarSDK_tvOS.a'
  s.tvos.frameworks = 'UIKit', 'Foundation'
  s.requires_arc = true
  s.library = 'stdc++'
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/LittlstarSDK"', 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/Headers/LittlstarSDK"' }
end
