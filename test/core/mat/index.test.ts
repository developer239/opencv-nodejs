import { Mat, DATA_TYPE } from '../../../index'
import { expect } from '@jest/globals'

describe('[core] Mat', () => {
  describe('constructor', () => {
    it('initializes empty', () => {
      const mat = new Mat()

      expect(mat.rows).toStrictEqual(0)
      expect(mat.cols).toStrictEqual(0)
      expect(mat.type()).toStrictEqual(0)
    })

    it('initializes with rows and cols', () => {
      const mat = new Mat(10, 20)

      expect(mat.rows).toStrictEqual(10)
      expect(mat.cols).toStrictEqual(20)
      expect(mat.type()).toStrictEqual(DATA_TYPE.CV_8UC3)
    })

    it('initializes with rows and cols and type', () => {
      const mat = new Mat(10, 20, DATA_TYPE.CV_8UC4)

      expect(mat.rows).toStrictEqual(10)
      expect(mat.cols).toStrictEqual(20)
      expect(mat.type()).toStrictEqual(DATA_TYPE.CV_8UC4)
    })

    it('initializes with rows and cols and type and fill value', () => {
      const mat = new Mat(10, 20, DATA_TYPE.CV_8UC3, [255, 254, 253])

      expect(mat.rows).toStrictEqual(10)
      expect(mat.cols).toStrictEqual(20)
      expect(mat.type()).toStrictEqual(DATA_TYPE.CV_8UC3)

      expect(mat.at(0, 0)).toStrictEqual(255)
      expect(mat.at(0, 1)).toStrictEqual(254)
      expect(mat.at(0, 2)).toStrictEqual(253)
    })
  })
})
