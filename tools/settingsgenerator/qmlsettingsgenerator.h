#ifndef QMLSETTINGSGENERATOR_H
#define QMLSETTINGSGENERATOR_H

#include "settingsgeneratorimpl.h"
#include <tuple>

class QmlSettingsGenerator : public SettingsGeneratorImpl
{
public:
	QmlSettingsGenerator(const QString &hdrPath,
						 const QString &srcPath);

	void process(const QString &inPath);

private:
	QFile _hdrFile;
	QFile _srcFile;

	QTextStream _hdr;
	QTextStream _src;

	QString _cppName;
	QString _name;
	QString _prefixName;
	QHash<QString, QString> _typeMappings;

	void writeHeader(const SettingsType &settings, const QString &inHdrPath);

	void writeListTypeBaseClass();

	std::tuple<int, QList<int>> writeNodeContentClasses(const NodeContentGroup &node, const QStringList &keyList, int offset = 0);
	int writeNodeClass(const NodeType &node, QStringList keyList, int offset);
	int writeListEntryElementClass(const ListEntryType &entry, QStringList keyList, int offset);

	void writeProperties(const NodeContentGroup &node,
						 const QStringList &keyList,
						 QList<int> &childOffsets,
						 QList<int> &listEntries,
						 QList<QPair<QString, int>> &childConstructs);
	void writeNodeProperty(const NodeType &entry, int classIndex, QList<QPair<QString, int>> &childConstructs, const QString &overwriteName = {});
	void writeEntryProperty(const EntryType &entry, QStringList keyList, int classIndex, QList<QPair<QString, int>> &childConstructs);
	void writeListEntryProperty(const ListEntryType &entry, QStringList keyList, int listIndex, int classIndex, QList<QPair<QString, int>> &childConstructs);

	void writeMemberInits(const QStringList &keyList, const QList<QPair<QString, int>> &childConstructs);
	void writeEntryPropertySignalConnects(const NodeContentGroup &node, const QStringList &keyList, int classIndex, QList<int> &listEntries);
	void writeEntryPropertySignalConnect(const EntryType &entry, QStringList keyList, int classIndex);
	void writeListEntryPropertySignalConnect(const ListEntryType &entry, QStringList keyList, QList<int> &listEntries);

	void writeSource(const SettingsType &settings);

	void writeQmlRegistration(const SettingsType &settings);
};

#endif // QMLSETTINGSGENERATOR_H