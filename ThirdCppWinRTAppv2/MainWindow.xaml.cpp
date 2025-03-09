#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	MainWindow::MainWindow()
	{
		InitializeComponent();

		for (auto const& child : CalcGrid().Children())
		{
			if (auto calcButton = child.try_as<ThirdCppWinRTAppv2::CalcButton>())
			{
				calcButton.CalcButtonClicked({ get_weak(), &MainWindow::OnCalcButtonClicked});
			};
		}
	}

	void MainWindow::OnCalcButtonClicked(ThirdCppWinRTAppv2::CalcButton const& sender, winrt::Windows::Foundation::IInspectable const& /* args */)
	{
		ThirdCppWinRTAppv2::CalcButton clickedButton = sender.try_as<ThirdCppWinRTAppv2::CalcButton>();

		if (clickedButton) {
			hstring name = clickedButton.Name();
			OutputDebugStringW(name.c_str());
		}
	}

}
