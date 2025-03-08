#pragma once

#include "App.xaml.g.h"
#include "BgLabelControl.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
