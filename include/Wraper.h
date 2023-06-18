#pragma once

template <class T>
class Wraper
{
public:
	void operator=(T *pWrapedObj)
	{
		m_pWrapedObj = pWrapedObj;
	}

	void operator=(T &pWrapedObj)
	{
		m_pWrapedObj = &pWrapedObj;
	}

	T *operator()(void)
	{
		return m_pWrapedObj;
	}

	operator T **()
	{
		return &m_pWrapedObj;
	}

	operator T *()
	{
		return m_pWrapedObj;
	}

	T *m_pWrapedObj = nullptr;
};