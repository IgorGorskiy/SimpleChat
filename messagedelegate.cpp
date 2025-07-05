#include "messagedelegate.h"

MessageDelegate::MessageDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

void MessageDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    painter->save();

    // Получаем данные из модели
    QString text = index.data(MessageModel::TextRole).toString();
    QString sender = index.data(MessageModel::SenderRole).toString();
    QString time = index.data(MessageModel::TimestampRole).toDateTime().toString("hh:mm");
    bool isOutgoing = index.data(MessageModel::IsOutgoingRole).toBool();
    int status = index.data(MessageModel::StatusRole).toInt();

    // Настраиваем стиль
    QRect rect = option.rect.adjusted(5, 5, -5, -5);
    QColor bubbleColor = isOutgoing ? QColor("#DCF8C6") : QColor("#FFFFFF");
    QColor textColor = Qt::black;

    // Рисуем "пузырь" сообщения
    painter->setBrush(bubbleColor);
    painter->setPen(Qt::NoPen);
    painter->drawRoundedRect(rect, 10, 10);

    // Рисуем текст
    painter->setPen(textColor);
    QFont font = painter->font();
    font.setPointSize(10);
    painter->setFont(font);

    // Настройка переноса текста
    QTextOption textOption;
    textOption.setWrapMode(QTextOption::WordWrap);
    // Прямоугольник для текста с отступами
    QRect textRect = rect.adjusted(10, 10, -10, -10);
    painter->drawText(textRect, text, textOption);

    // Рисуем статус и время
    QString statusText;
    switch(status) {
    case Message::Sending: statusText = "🕒"; break;
    case Message::Sent: statusText = "✓"; break;
    case Message::Delivered: statusText = "✓✓"; break;
    case Message::Error: statusText = "❌"; break;
    case Message::None: statusText = ""; break;
    case Message::CommandOutput: statusText = "ℹ️"; break;
    }

    painter->drawText(rect.bottomRight() - QPoint(80, 5),
                      QString("%1 %2").arg(time, statusText));

    painter->restore();
}

QSize MessageDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QString text = index.data(MessageModel::TextRole).toString();
    QFontMetrics fm(option.font);

    // Ширина текста = ширина ListView минус отступы
    int textWidth = option.rect.width() - 40; // 20px слева + 20px справа

    // Вычисляем высоту с учетом переноса слов
    QRect textRect = fm.boundingRect(QRect(0, 0, textWidth, 0),
                                     Qt::TextWordWrap, text);

    return QSize(option.rect.width(), textRect.height() + 40); // + отступы
}
