#pragma once

#include "MainWindow.g.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

		void OnCalcButtonClicked(ThirdCppWinRTAppv2::CalcButton const&, winrt::Windows::Foundation::IInspectable const&);

    private:
		bool m_isFKeyPressed{ false };
		bool m_isGKeyPressed{ false };
    };
}

namespace winrt::ThirdCppWinRTAppv2::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
