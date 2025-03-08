#pragma once

#include "CalcButton.g.h"

namespace winrt::ThirdCppWinRTAppv2::implementation
{
	struct CalcButton : CalcButtonT<CalcButton>
	{
		CalcButton()
		{
			// Xaml objects should not call InitializeComponent during construction.
			// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
		};

		void myCalcButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& args);
		static void OnPropertyChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e);

		hstring TopText();
		void TopText(hstring const& value);

		hstring BottomText();
		void BottomText(hstring const& value);


		static winrt::Microsoft::UI::Xaml::DependencyProperty TopTextProperty();
		static winrt::Microsoft::UI::Xaml::DependencyProperty BottomTextProperty();

		//event_token PropertyChanged(Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
		//{
		//    return _propertyChanged.add(handler);
		//};

		//void PropertyChanged(event_token const& token)
		//{
		//	_propertyChanged.remove(token);
		//};


	private:
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_topTextProperty;
		static winrt::Microsoft::UI::Xaml::DependencyProperty m_bottomTextProperty;

		//hstring m_topText;
		//hstring m_bottomText;

		//event<PropertyChangedEventHandler> m_clickToken;

		//void RaisePropertyChanged(hstring const& propertyName)
		//{
		//	_propertyChanged(*this, PropertyChangedEventArgs(propertyName));
		//};

	};
}

namespace winrt::ThirdCppWinRTAppv2::factory_implementation
{
	struct CalcButton : CalcButtonT<CalcButton, implementation::CalcButton>
	{
	};
}
