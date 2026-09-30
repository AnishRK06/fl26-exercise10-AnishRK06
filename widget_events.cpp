// widget_events.cpp
#include "widget_events.hpp"

#include <QEvent>
#include <QMetaEnum>

#include <iostream>
#include <string>

WidgetEvent::WidgetEvent(QWidget *parent) : QWidget(parent) {}

bool WidgetEvent::event(QEvent *e) {
  // Reverse lookup: QEvent::Type is registered with Qt's meta-object
  // system, so we can turn the enum value back into its name.
  static const QMetaEnum typeEnum = QMetaEnum::fromType<QEvent::Type>();

  const char *name = typeEnum.valueToKey(e->type());
  std::cout << "Event: " << (name ? name : "Unknown")
            << " (" << static_cast<int>(e->type()) << ")" << std::endl;

  // Step 14: uncomment to experiment with a blocking call
  // std::string mystring;
  // std::cin >> mystring;

  return true;
}