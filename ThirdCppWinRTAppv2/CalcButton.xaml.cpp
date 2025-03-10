#include "pch.h"
#include "CalcButton.xaml.h"
#if __has_include("CalcButton.g.cpp")
#include "CalcButton.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	CalcButton::CalcButton()
	{
		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
		InitializeComponent();

		m_topTextBlock = FindName(L"TopTextBlock").as<Microsoft::UI::Xaml::Controls::TextBlock>();
		m_bottomTextBlock = FindName(L"BottomTextBlock").as<Microsoft::UI::Xaml::Controls::TextBlock>();
	};

	void CalcButton::myCalcButton_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args)
	{
		m_clickToken(*this, args);
	}

	winrt::event_token CalcButton::CalcButtonClicked(winrt::Windows::Foundation::TypedEventHandler<ThirdCppWinRTAppv2::CalcButton, winrt::Microsoft::UI::Xaml::RoutedEventArgs> const& handler)
	{
		return m_clickToken.add(handler);
	}

	void CalcButton::CalcButtonClicked(winrt::event_token const& token) noexcept
	{
		m_clickToken.remove(token);
	}

	winrt::hstring CalcButton::TopText()
	{
		return winrt::unbox_value<winrt::hstring>(GetValue(m_topTextProperty));
	}

	void CalcButton::TopText(winrt::hstring const& value)
	{
		SetValue(m_topTextProperty, winrt::box_value(value));
	}

	winrt::hstring CalcButton::BottomText()
	{
		return winrt::unbox_value<winrt::hstring>(GetValue(m_bottomTextProperty));
	}

	void CalcButton::BottomText(winrt::hstring const& value)
	{
		SetValue(m_bottomTextProperty, winrt::box_value(value));
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::ButtonBackground()
	{
		return winrt::unbox_value<winrt::Microsoft::UI::Xaml::Media::Brush>(GetValue(m_buttonBackgroundProperty));
	}

	void CalcButton::ButtonBackground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		SetValue(m_buttonBackgroundProperty, winrt::box_value(value));
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::TopTextForeground()
	{
		return winrt::unbox_value<winrt::Microsoft::UI::Xaml::Media::Brush>(GetValue(m_topTextForegroundProperty));
	}

	void CalcButton::TopTextForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		SetValue(m_topTextForegroundProperty, winrt::box_value(value));
	}

	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::BottomTextForeground()
	{
		return winrt::unbox_value<winrt::Microsoft::UI::Xaml::Media::Brush>(GetValue(m_bottomTextForegroundProperty));
	}

	void CalcButton::BottomTextForeground(winrt::Microsoft::UI::Xaml::Media::Brush const& value)
	{
		SetValue(m_bottomTextForegroundProperty, winrt::box_value(value));
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopTextProperty()
	{
		return m_topTextProperty;
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomTextProperty()
	{
		return m_bottomTextProperty;
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::ButtonBackgroundProperty()
	{
		return m_buttonBackgroundProperty;
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopTextForegroundProperty()
	{
		return m_topTextForegroundProperty;
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomTextForegroundProperty()
	{
		return m_bottomTextForegroundProperty;
	}

	void CalcButton::OnPropertyChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&)
	{
		if (auto button = d.try_as<winrt::ThirdCppWinRTAppv2::CalcButton>())
		{
		}
	}

	void CalcButton::OnButtonBackgroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&)
	{
		// Get the current button
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv2::CalcButton>())
		{
			try
			{
				control.Background(control.ButtonBackground());
			}
			catch (winrt::hresult_error const& ex)
			{
				winrt::hstring message = ex.message();
			}
		};
	}

	void CalcButton::OnTextForegroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		// Get the current button
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv2::CalcButton>())
		{
			if (e.Property() == m_topTextForegroundProperty)
			{
				try
				{
					if (auto top = control.FindName(L"TopTextBlock").try_as<winrt::Microsoft::UI::Xaml::Controls::TextBlock>())
					{
						top.Foreground(control.TopTextForeground());
					}
				}
				catch (winrt::hresult_error const& ex)
				{
					winrt::hstring message = ex.message();
				}
			}
			else if (e.Property() == m_bottomTextForegroundProperty)
			{
				try
				{
					if (auto bottom = control.FindName(L"BottomTextBlock").try_as<winrt::Microsoft::UI::Xaml::Controls::TextBlock>())
					{
						bottom.Foreground(control.BottomTextForeground());
					}
				}
				catch (winrt::hresult_error const& ex)
				{
					winrt::hstring message = ex.message();
				}
			};
		};
	}

	/*winrt::Windows::UI::Color CalcButton::StringToColor(winrt::hstring const& color)
	{
		if (color.empty())
		{
			return winrt::Windows::UI::Colors::White();
		}
		if ((color.size() != 7) || (color[0] != L'#'))
		{
			return winrt::Windows::UI::Colors::White();
		}
		UINT32 colorValue = wcstoul(color.c_str() + 1, nullptr, 16);
		UINT8 r = (colorValue >> 16) & 0xFF;
		UINT8 g = (colorValue >> 8) & 0xFF;
		UINT8 b = colorValue & 0xFF;
		return winrt::Windows::UI::ColorHelper::FromArgb(255, r, g, b);
	}*/

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopText",
			winrt::xaml_typename<winrt::hstring>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ box_value(L"Default Top"), Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPropertyChanged } });

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomText",
			winrt::xaml_typename<winrt::hstring>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ box_value(L"Default Bottom"), Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPropertyChanged } });

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_buttonBackgroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"ButtonBackground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::SolidColorBrush>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ NULL, Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnButtonBackgroundChanged } }
		);
	// box_value(L"#413D3C")
	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextForegroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopTextForeground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::SolidColorBrush>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ NULL, Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTextForegroundChanged } }
		);
	// box_value(L"FFFFFF")

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextForegroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomTextForeground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::SolidColorBrush>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ NULL, Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnTextForegroundChanged } }
		);
	// box_value(L"58ADC9")
}
