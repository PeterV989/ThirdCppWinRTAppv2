#include "pch.h"
#include <locale>
#include <sstream>
#include <Windows.h>
#include "CalcButton.xaml.h"
#include "CalcButton.g.cpp"


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
		InitializeDefaultBrushes();

		m_topTextBlock = FindName(L"TopTextBlock").as<Microsoft::UI::Xaml::Controls::TextBlock>();
		if (!m_topTextBlock)
		{
			throw hresult_error(E_POINTER, L"TopTextBlock not found");
		}
		m_bottomTextBlock = FindName(L"BottomTextBlock").as<Microsoft::UI::Xaml::Controls::TextBlock>();
		if (!m_bottomTextBlock)
		{
			throw hresult_error(E_POINTER, L"bottomTextBlock not found");
		}
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

	// DependencyProperty Getters and Setters

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

	winrt::Windows::UI::Text::FontWeight CalcButton::TopTextFontWeight()
	{
		return winrt::unbox_value<winrt::Windows::UI::Text::FontWeight>(GetValue(m_topTextFontWeightProperty));
	}

	void CalcButton::TopTextFontWeight(winrt::Windows::UI::Text::FontWeight const& value)
	{
		SetValue(m_topTextFontWeightProperty, winrt::box_value(value));
	}

	winrt::Windows::UI::Text::FontWeight CalcButton::BottomTextFontWeight()
	{
		return winrt::unbox_value<winrt::Windows::UI::Text::FontWeight>(GetValue(m_bottomTextFontWeightProperty));
	}

	void CalcButton::BottomTextFontWeight(winrt::Windows::UI::Text::FontWeight const& value)
	{
		SetValue(m_bottomTextFontWeightProperty, winrt::box_value(value));
	}

	// DependencyProperty Property Getters
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

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::TopTextFontWeightProperty()
	{
		return m_topTextFontWeightProperty;
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::BottomTextFontWeightProperty()
	{
		return m_bottomTextFontWeightProperty;
	}

	winrt::event_token CalcButton::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}

	void CalcButton::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}

	void CalcButton::RaisePropertyChanged(winrt::hstring const& propertyName)
	{
		m_propertyChanged(*this, winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ propertyName });
	}

	void CalcButton::OnPropertyChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
	{
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv2::implementation::CalcButton>())
		{
			if (e.Property() == m_topTextFontWeightProperty)
			{
				control->RaisePropertyChanged(L"TopTextFontWeight");
			}
			else if (e.Property() == m_bottomTextFontWeightProperty)
			{
				control->RaisePropertyChanged(L"BottomTextFontWeight");
			}
			else if (e.Property() == m_topTextProperty)
			{
				control->RaisePropertyChanged(L"TopText");
			}
			else if (e.Property() == m_bottomTextProperty)
			{
				control->RaisePropertyChanged(L"BottomText");
			}
			else if (e.Property() == m_buttonBackgroundProperty)
			{
				control->RaisePropertyChanged(L"ButtonBackgroundBrush");
			}
			else if (e.Property() == m_bottomTextForegroundProperty)
			{
				control->RaisePropertyChanged(L"BottomTextForeground");
			}
			else if (e.Property() == m_topTextForegroundProperty)
			{
				control->RaisePropertyChanged(L"TopTextForeground");
			}
		}
	}

	void CalcButton::OnButtonBackgroundChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&)
	{
		// Get the current button
		if (auto control = d.try_as<winrt::ThirdCppWinRTAppv2::CalcButton>())
		{
			try
			{
				auto background = control.ButtonBackground();
				control.Background(background);
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
						auto foreground = control.TopTextForeground();
						top.Foreground(foreground);
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
						auto foreground = control.BottomTextForeground();
						bottom.Foreground(foreground);

					}
				}
				catch (winrt::hresult_error const& ex)
				{
					winrt::hstring message = ex.message();
				}
			};
		};
	}

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
	bool CalcButton::m_isFirstTime = true;
	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::m_buttonBackgroundDefaultBrush{nullptr};
	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::m_topTextForegroundDefaultBrush{nullptr};
	winrt::Microsoft::UI::Xaml::Media::Brush CalcButton::m_bottomTextForegroundDefaultBrush{nullptr};
	winrt::Windows::UI::Text::FontWeight CalcButton::m_boldFontWeight{};
	winrt::Windows::UI::Text::FontWeight CalcButton::m_normalFontWeight{};

	void CalcButton::InitializeDefaultBrushes()
	{
		if (m_isFirstTime)
		{
			try {
				auto temp = winrt::Windows::UI::ColorHelper::FromArgb(255, 65, 61, 60);
				temp = winrt::Windows::UI::ColorHelper::FromArgb(255, 0, 255, 0);
				m_buttonBackgroundDefaultBrush = winrt::Microsoft::UI::Xaml::Media::SolidColorBrush{ temp };
				if (const auto cbb = m_buttonBackgroundBrush.try_as<winrt::Microsoft::UI::Xaml::Media::SolidColorBrush>())
				{
					const auto cb = cbb.Color();
					std::wstringstream colors;
					colors << L"Button Background Brush Colors (" << cb.A << L", " << cb.R << L", " << cb.G << L", " << cb.B << L")\n";
					OutputDebugStringW(colors.str().c_str());
				}
			}
			catch (const std::exception& e)
			{
				std::string message = e.what();
				int size_needed = MultiByteToWideChar(CP_UTF8, 0, message.c_str(), (int)message.size(), NULL, 0);
				std::wstring wide_message(size_needed, 0);
				MultiByteToWideChar(CP_UTF8, 0, message.c_str(), (int)message.size(), &wide_message[0], size_needed);
				OutputDebugString(wide_message.c_str());
			}
			try {
				auto temp = winrt::Windows::UI::ColorHelper::FromArgb(255, 255, 255, 255);
				m_topTextForegroundDefaultBrush = winrt::Microsoft::UI::Xaml::Media::SolidColorBrush{ temp };
				if (const auto cbb = m_topTextForegroundBrush.try_as<winrt::Microsoft::UI::Xaml::Media::SolidColorBrush>())
				{
					const auto cb = cbb.Color();
					std::wstringstream colors;
					colors << L"Top Text Foreground Brush Colors (" << cb.A << L", " << cb.R << L", " << cb.G << L", " << cb.B << L")\n";
					OutputDebugStringW(colors.str().c_str());
				}
			}
			catch (const std::exception& e)
			{
				std::string message = e.what();
				int size_needed = MultiByteToWideChar(CP_UTF8, 0, message.c_str(), (int)message.size(), NULL, 0);
				std::wstring wide_message(size_needed, 0);
				MultiByteToWideChar(CP_UTF8, 0, message.c_str(), (int)message.size(), &wide_message[0], size_needed);
				OutputDebugString(wide_message.c_str());
			}
			try {
				auto temp = winrt::Windows::UI::ColorHelper::FromArgb(255, 88, 173, 201);
				m_bottomTextForegroundDefaultBrush = winrt::Microsoft::UI::Xaml::Media::SolidColorBrush{ temp };
				if (const auto cbb = m_bottomTextForegroundBrush.try_as<winrt::Microsoft::UI::Xaml::Media::SolidColorBrush>())
				{
					const auto cb = cbb.Color();
					std::wstringstream colors;
					colors << L"Bottom Text Foreground Brush Colors (" << cb.A << L", " << cb.R << L", " << cb.G << L", " << cb.B << L")\n";
					OutputDebugStringW(colors.str().c_str());
				}
			}
			catch (const std::exception& e)
			{
				std::string message = e.what();
				int size_needed = MultiByteToWideChar(CP_UTF8, 0, message.c_str(), (int)message.size(), NULL, 0);
				std::wstring wide_message(size_needed, 0);
				MultiByteToWideChar(CP_UTF8, 0, message.c_str(), (int)message.size(), &wide_message[0], size_needed);
				OutputDebugString(wide_message.c_str());
			}
			m_boldFontWeight = winrt::Windows::UI::Text::FontWeights::Bold();
			m_normalFontWeight = winrt::Windows::UI::Text::FontWeights::Normal();
			m_isFirstTime = (m_buttonBackgroundDefaultBrush == nullptr) || (m_topTextForegroundDefaultBrush == nullptr) || (m_bottomTextForegroundDefaultBrush == nullptr);
		};
		if (!m_isFirstTime)
		{
			SetValue(m_buttonBackgroundProperty, m_buttonBackgroundDefaultBrush);
			SetValue(m_topTextForegroundProperty, m_topTextForegroundDefaultBrush);
			SetValue(m_bottomTextForegroundProperty, m_bottomTextForegroundDefaultBrush);
		SetValue(m_topTextFontWeightProperty, winrt::box_value(m_boldFontWeight));
		SetValue(m_bottomTextFontWeightProperty, winrt::box_value(m_normalFontWeight));
		};
	}

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_buttonBackgroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"ButtonBackground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ nullptr, Microsoft::UI::Xaml::PropertyChangedCallback{&CalcButton::OnButtonBackgroundChanged}}
		);
	// box_value(L"#413D3C")

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextForegroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopTextForeground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ nullptr, Microsoft::UI::Xaml::PropertyChangedCallback{&CalcButton::OnTextForegroundChanged}}
		);
	// box_value(L"FFFFFF")

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextForegroundProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomTextForeground",
			winrt::xaml_typename<winrt::Microsoft::UI::Xaml::Media::Brush>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ nullptr, Microsoft::UI::Xaml::PropertyChangedCallback{&CalcButton::OnTextForegroundChanged}}
		);
	// box_value(L"58ADC9")

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_topTextFontWeightProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"TopTextFontWeight",
			winrt::xaml_typename<winrt::Windows::UI::Text::FontWeight>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ nullptr, Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPropertyChanged } });

	winrt::Microsoft::UI::Xaml::DependencyProperty CalcButton::m_bottomTextFontWeightProperty =
		winrt::Microsoft::UI::Xaml::DependencyProperty::Register(
			L"BottomTextFontWeight",
			winrt::xaml_typename<winrt::Windows::UI::Text::FontWeight>(),
			winrt::xaml_typename<ThirdCppWinRTAppv2::CalcButton>(),
			Microsoft::UI::Xaml::PropertyMetadata{ nullptr, Microsoft::UI::Xaml::PropertyChangedCallback{ &CalcButton::OnPropertyChanged } });
}
