Pod::Spec.new do |s|
  s.name             = "ABCLive"
  s.version          = "1.2.2"
  s.summary          = "ABCLive."
  s.description      = "ABCLive of bing"
  s.homepage         = "http://www.abcpen.com"
  s.license          = 'MIT'
  s.author           = { "bing" => "bing@abcpen.com" }
  s.source           = { :git => 'https://github.com/abcpen-inc/ABCLiveKit.git',:tag => s.version}
  #s.source           = { :git => 'git@git.abcpen.com:pod_group/ABCLiveKit-Pod.git'}

  s.platform         = :ios,'9.0'
  s.requires_arc     = true
  s.swift_version    = '5.0'

  s.subspec 'ABCLiveCoreKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/ABCCoreKit.framework/Headers/ABCCoreKit.h'
    sp.source_files        = 'ABCLiveSDK/ABCCoreKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/ABCCoreKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
    sp.frameworks = "VideoToolbox", "AudioToolbox","AVFoundation","Foundation","UIKit"
    sp.dependency 'Masonry'
    sp.dependency 'SVProgressHUD'
    sp.dependency 'Socket.IO-Client-Swift'
    sp.dependency 'BFKit'
  end

  s.subspec 'ABCLiveUIKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/ABCUIKit.framework/Headers/ABCUIKit.h'
    sp.source_files        = 'ABCLiveSDK/ABCUIKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/ABCUIKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ABCLivePenKit' do |sp|
    sp.public_header_files = 'ABCLiveSDK/PenKit.framework/Headers/PenKit.h'
    sp.source_files        = 'ABCLiveSDK/PenKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ABCLiveSDK/PenKit.framework'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

end
