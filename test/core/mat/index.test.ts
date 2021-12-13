import { Mat } from '../../../index'

describe('[core] Mat', () => {
  describe('constructor', () => {
    it('initializes empty', () => {
      const mat = new Mat()

      expect(mat.rows).toStrictEqual(0)
      expect(mat.cols).toStrictEqual(0)
    })

    it('initializes with rows and cols', () => {
      const mat = new Mat(10, 20)

      expect(mat.rows).toStrictEqual(10)
      expect(mat.cols).toStrictEqual(20)
    })
  })
})
